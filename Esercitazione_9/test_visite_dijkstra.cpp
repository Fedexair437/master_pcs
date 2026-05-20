#include <iostream>
#include <map>
#include <fstream>
#include "undirected_edges.hpp"
#include "undirected_graph.hpp"
#include "fifo_lifo.hpp"
#include "visits.hpp"

using namespace std;

int main(){

    undirected_graph<int> G;
    undirected_edge<int> e12(1,2), e13(1,3), e23(2,3), e24(2,4), e34(3,4), e35(3,5), e45(4,5);
    G.add_edge(e12);
    G.add_edge(e13);
    G.add_edge(e23);
    G.add_edge(e24);
    G.add_edge(e34);
    G.add_edge(e35);
    G.add_edge(e45);

    cout << "Grafo di partenza:\n";
    cout << "Nodi: ";
    for(auto& n : G.all_nodes()) cout << n << " ";
    cout << "\nArchi: ";
    for(auto& a : G.all_edges()) cout << a << " ";
    cout << "\n\n";
    int source = 1;


    /* BFS */
    cout << "BFS dalla sorgente 1:\n";
    fifo<int> q;
    auto bfsG = graph_visit(G, source, q);
    cout << "Archi albero BFS: ";
    for(auto& a : bfsG.all_edges()) cout << a << " ";
    cout << "\n\n";
    to_dot_directed(bfsG, "bfs.dot");

    /* DFS iterativa */
    cout << "DFS iterativa dalla sorgente 1:\n";
    lifo<int> s;
    auto dfsG = graph_visit(G, source, s);
    cout << "Archi albero DFS: ";
    for(auto& a : dfsG.all_edges()) cout << a << " ";
    cout << "\n\n";
    to_dot_directed(dfsG, "dfs.dot");

    /* DFS ricorsiva */
    cout << "DFS ricorsiva dalla sorgente 1:\n";
    auto rdfsG = recursive_dfs(G, source);
    cout << "Archi albero DFS ricorsiva: ";
    for(auto& a : rdfsG.all_edges()) cout << a << " ";
    cout << "\n\n";
    to_dot_directed(rdfsG, "dfs_ricorsiva.dot");

    /* Dijkstra */
    cout << "Dijkstra dalla sorgente 1:\n";
    map<int,int> pred;
    auto dist = dijkstra(G, source, pred);
    for(auto& [nodo, d] : dist){
        cout << "dist(1, " << nodo << ") = " << d << "\n";
        cout << "predecessore del nodo " << nodo << ": " <<pred[nodo] << "\n";
    }
    cout << "\n";

    to_dot(G, "grafo.dot");

    cout << "File .dot generati: grafo.dot, bfs.dot, dfs.dot, dfs_ricorsiva.dot\n";

    return EXIT_SUCCESS;
}