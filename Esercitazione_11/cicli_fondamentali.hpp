#pragma once
#include <iostream>
#include <algorithm>    //per la funzione find()
#include "fifo_lifo.hpp"
#include "undirected_edges.hpp"
#include "undirected_graph.hpp"
#include "visits.hpp"
#include <vector>
#include <map>

using namespace std;

template<typename I>
class lifted_node
{
    I node;
    int sign;

public:
    /* Costruttore di default */
    lifted_node() : node(I{}), sign(1)
    {}

    /* Costruttore user-defined */
    lifted_node(const I& n, const int& s) : node(n), sign(s)
    {
        if(sign!=-1 && sign!=1){
            if(sign>=0) sign=1;
            else sign=-1;
        }
    }

    /* Costruttore di conversione */
    lifted_node(I node) : node(node), sign(1)
    {}

    /* Proiezione del solo membro nodo senza il segno */
    I no_sign() { return node; }

    /* Implementazione == */
    bool operator==(const lifted_node& other) const {
        return (node==other.node && sign==other.sign);
    }

    /* Implementazione < e altri operatori per avere la classe totally ordered */
    bool operator<(const lifted_node& other) const {
        if(node != other.node ) return node<other.node;
        else return sign<other.sign;
    }
    bool operator>(const lifted_node& other) const { return other < *this; }
    bool operator<=(const lifted_node& other) const { return !(other < *this); }
    bool operator>=(const lifted_node& other) const { return !(*this < other); }

    /* Costruttore di copia con cambio di segno */
    lifted_node change() const {
        lifted_node ret;
        ret.node = node;
        ret.sign = (-1)*sign;
        return ret;
    }

};

template<typename I>
vector<vector<undirected_edge<I>>> cicli_DFS(undirected_graph<I>& G){
    lifo<I> s;
    I source = *(G.all_nodes().begin());
    vector<vector<undirected_edge<I>>> ret;
    undirected_graph<I> T = graph_visit(G, source, s);
    undirected_graph<I> C = G - T;
    for(auto& edge : C.all_edges()){
        map<I,bool> visited;
        for(auto& node : T.all_nodes()) visited[node]=false;
        vector<undirected_edge<I>> cycle;
        vector<I> path;
        if(find_path(T, edge.from(), edge.to(), path, visited)){
            cycle.push_back(edge);
            while(path.size()>1){
                cycle.emplace_back(path.at(path.size()-2), path.at(path.size()-1));     //emplace_back crea direttamente l'arco mentre lo inserisce evitando inutli copie
                path.pop_back();
            }
            ret.push_back(cycle);
        }
    }
    return ret;
}

template<typename I>
bool find_path(undirected_graph<I>& T, const I& u, const I& v, vector<I>& path, map<I,bool>& visited){
    visited[u]=true;
    path.push_back(u);
    if(u==v) return true;
    for(auto& node : T.neighbours(u)){
        if(!visited[node]){
            if(find_path(T, node, v, path, visited)){
                return true;
            }
        }
    }
    path.pop_back();
    return false;
}

int prod_scal(vector<bool>& S, vector<bool>& P){
    if(S.size()!=P.size()) return -1;   //flag di errore, il prodotto scalare è definito solo su coppie di vettori di pari lunghezza
    int n=0;
    for(int i=0;i<S.size();i++) n += S.at(i)*P.at(i);
    return n%2;
}

vector<bool> diff_simm(vector<bool> S, vector<bool> P){
    if(S.size()!=P.size()) return vector<bool>{};   //flag di errore, la differenza simmetrica è definita solo su coppie di vettori di pari lunghezza
    vector<bool> ret(S.size(), 0);
    for(int i=0;i<S.size();i++) ret.at(i) = (S.at(i)!=P.at(i));
    return ret;
}

template<typename I>
vector<bool> de_pina_aux(undirected_graph<I>& G, vector<bool>& S_i){
    undirected_graph<lifted_node<I>> G_l;
    for(auto& e : G.all_edges()){
        lifted_node<I> u_p = e.from();
        lifted_node<I> v_p = e.to();
        auto u_m = u_p.change();
        auto v_m = v_p.change();
        auto all_e = G.all_edges();
        auto it = all_e.find(e);
        int ind = distance(all_e.begin(), it);
        if(S_i.at(ind)){
            undirected_edge<lifted_node<I>> e_new(u_p, v_m);
            G_l.add_edge(e_new);
            undirected_edge<lifted_node<I>> e_new2(u_m, v_p);
            G_l.add_edge(e_new2);
        }
        else{
            undirected_edge<lifted_node<I>> e_new(u_p, v_p);
            G_l.add_edge(e_new);
            undirected_edge<lifted_node<I>> e_new2(u_m, v_m);
            G_l.add_edge(e_new2);
        }
    }

    vector<bool> C_i;
    int min1 = G.all_edges().size()+1;
    for(auto& n : G.all_nodes()){
        lifted_node<I> source(n, -1);
        lifted_node<I> dest(n, 1);
        map<lifted_node<I>, lifted_node<I>> pred;
        auto dist = dijkstra(G_l, source, pred);
        vector<undirected_edge<lifted_node<I>>> path;
        while(source!=dest){
            undirected_edge<lifted_node<I>> e_new(pred.at(dest), dest);
            path.push_back(e_new);
            dest = pred.at(dest);
        }
        vector<bool> C_mu(G.all_edges().size(), 0);
        for(auto& e : path){
            undirected_edge<I> e2(e.from().no_sign(), e.to().no_sign());
            auto all_e = G.all_edges();
            auto it = all_e.find(e2);
            int i = distance(all_e.begin(), it);
            C_mu.at(i) = !C_mu.at(i);
        }
        int num1 = count(C_mu.begin(), C_mu.end(), 1);
        if(num1 < min1){
            min1 = num1;
            C_i = C_mu;
        }
    }
    return C_i;
}

template<typename I>
vector<vector<bool>> de_pina(undirected_graph<I>& G, vector<vector<bool>>& S){
    vector<undirected_edge<I>> edges;
    for(auto& e : G.all_edges()) edges.push_back(e);
    I source = *(G.all_nodes().begin());
    lifo<I> s;
    undirected_graph<I> T = graph_visit(G, source, s);
    undirected_graph<I> C = G - T;
    int k = C.all_edges().size();
    for(auto& e : C.all_edges()){
        vector<bool> v(G.all_edges().size(), 0);
        for(int i=0;i<G.all_edges().size();i++) v.at(i)=0;
        auto it = find(edges.begin(), edges.end(), e);
        int ind = distance(edges.begin(), it);
        v.at(ind)=1;
        S.push_back(v);
    }
    vector<vector<bool>> B;
    for(int i=0;i<k;i++){
        vector<bool> C = de_pina_aux(G, S.at(i));
        B.push_back(C);
        for(int j=i+1;j<k;j++){
            if(prod_scal(C, S.at(j)) == 1) S.at(j) = diff_simm(S.at(j), S.at(i));
        }
    }
    return B;
}