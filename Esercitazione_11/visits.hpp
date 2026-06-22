#pragma once
#include "fifo_lifo.hpp"
#include "undirected_edges.hpp"
#include "undirected_graph.hpp"
#include <unordered_map>
#include <queue>
#include <map>
#include <limits>   /* utilizzato per avere un concetto di infinito dell'algoritmo di dijkstra */
#include <fstream>  /* utilizzato per generare i file .dot per graphviz */
using namespace std;

template<typename I>
void to_dot(const undirected_graph<I>& G, const string& filename){
    ofstream f(filename);
    f << "graph G {\n";
    for(auto& arco : G.all_edges())
        f << "    " << arco.from() << " -- " << arco.to() << ";\n";
    f << "}\n";
}

/* per alberi di visita (diretti) */
template<typename I>
void to_dot_directed(const undirected_graph<I>& G, const string& filename){
    ofstream f(filename);
    f << "digraph G {\n";
    for(auto& arco : G.all_edges())
        f << "    " << arco.from() << " -> " << arco.to() << ";\n";
    f << "}\n";
}

/* Container deve essere un contenitore con metodi put(), get(), empty() come fifo o lifo definiti in fifo_lifo.hpp */
template<typename I, typename Container>
undirected_graph<I> graph_visit(undirected_graph<I>& G, const I& initial_node, Container& c){
    if(!G.all_nodes().contains(initial_node)){
        cerr << "Errore: nodo sorgente non presente nel grafo\n";
        return undirected_graph<I>{};   //sentinella per segnalare nodo sorgente della visita non presente nel grafo
    }
    undirected_graph<I> tree;
    unordered_map<I, bool> reached;
    for(auto& node : G.all_nodes()){ reached[node]=false; }
    c.put(initial_node);
    reached[initial_node]=true;
    while(!c.empty()){
        I node=c.get();
        //reached[node]=true;
        for(auto& neigh : G.neighbours(node)){
            if(!reached[neigh]){
                c.put(neigh);
                reached[neigh]=true;
                undirected_edge<I> e(node, neigh);
                tree.add_edge(e);
            }
        }
    }
    return tree;
}

template<typename I>
void recursive_dfs_aux(undirected_graph<I>& G, const I& initial_node, undirected_graph<I>& tree, unordered_map<I, bool>& reached){
    reached[initial_node]=true;
    for(auto& neigh : G.neighbours(initial_node)){
        if(!reached[neigh]){
            undirected_edge<I> e(initial_node, neigh);
            tree.add_edge(e);
            recursive_dfs_aux(G, neigh, tree, reached);
        }
    }
}

template<typename I>
undirected_graph<I> recursive_dfs(undirected_graph<I>& G, const I& initial_node){
    if(!G.all_nodes().contains(initial_node)){
        cerr << "Errore: nodo sorgente non presente nel grafo\n";
        return undirected_graph<I>{};   //sentinella per segnalare nodo sorgente della visita non presente nel grafo
    }
    undirected_graph<I> tree;
    unordered_map<I, bool> reached;
    for(auto& node : G.all_nodes()){ reached[node]=false; }
    reached[initial_node]=true;
    recursive_dfs_aux(G, initial_node, tree, reached);
    return tree;
}

template<typename I>
map<I, double> dijkstra(undirected_graph<I>& G, const I& source, map<I, I>& pred){  /* restituisce in output le distanze di ogni nodo rispetto al nodo source
    nella mappa dist e passa by reference i predecessori nella mappa pred per poter ricostruire i cammini */
    if(!G.all_nodes().contains(source)){
        cerr << "Errore: nodo sorgente non presente nel grafo\n";
        return map<I, double>{};   //sentinella per segnalare nodo sorgente della SSSP non presente nel grafo
    }
    map<I, double> dist;
    dist[source]=0.0;
    pred[source]=source;
    priority_queue<pair<double, I>, vector<pair<double, I>>, greater<pair<double, I>>> PQ;
    PQ.push({0.0, source});
    while(!PQ.empty()){
        auto [d,u]=PQ.top();
        PQ.pop();
        if(dist.contains(u) && d>dist[u]) continue;
        for(auto& v : G.neighbours(u)){
            undirected_edge<I> e(u,v);
            double weight=1.0;  //per ipotesi in questa implementazione
            if(!dist.contains(v) || dist[u]+weight<dist[v]){    // !dist.contains(v) gestione alternativa alle distanze infinite
                dist[v]=dist[u]+weight;
                PQ.push({dist[v],v});
                pred[v]=u;
            }
        }
    }
    return dist;
}