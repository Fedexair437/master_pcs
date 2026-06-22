#include <iostream>
#include "undirected_edges.hpp"
#include "undirected_graph.hpp"
#include "cicli_fondamentali.hpp"

using namespace std;

int main(){

    /*
     * Grafo di test:
     *   1 - 2
     *   |   |
     *   3 - 4 - 5
     *    \     /
     *      ---
     *
     * Archi: (1,2),(1,3),(2,4),(3,4),(3,5),(4,5)
     * n=5, m=6, cicli attesi: m-n+1 = 2
     */

    undirected_graph<int> G;
    undirected_edge<int> e12(1,2), e13(1,3), e24(2,4), e34(3,4), e35(3,5), e45(4,5);
    G.add_edge(e12);
    G.add_edge(e13);
    G.add_edge(e24);
    G.add_edge(e34);
    G.add_edge(e35);
    G.add_edge(e45);

    auto cicli = cicli_DFS(G);
    vector<vector<bool>> S;
    auto cicli_min = de_pina(G, S);

    cout << "cicli fondamentali trovati: " << cicli.size() << "\n";
    cout << "attesi: " << G.all_edges().size() - G.all_nodes().size() + 1 << "\n\n";

    for(int i=0; i<cicli.size(); i++){
        cout << "ciclo " << i+1 << ": ";
        for(auto& e : cicli[i]) cout << e << " ";
        cout << "\n";
    }

    vector<undirected_edge<int>> edges;
    for(auto& e : G.all_edges()) edges.push_back(e);
    cout << "\ncicli fondamentali minimi trovati: " << cicli_min.size() << "\n\n";
    for(int i=0; i<cicli_min.size(); i++){
        cout << "ciclo " << i+1 << ": ";
        for(int j=0; j<cicli_min[i].size(); j++){
            if(cicli_min[i][j]) cout << edges[j] << " "; 
        }
        cout << "\n";
    }

    return 0;
}