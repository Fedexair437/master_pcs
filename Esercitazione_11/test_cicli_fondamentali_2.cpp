#include <iostream>
#include <string>
#include "undirected_edges.hpp"
#include "undirected_graph.hpp"
#include "cicli_fondamentali.hpp"

using namespace std;

template<typename I>
void stampa_cicli_DFS(undirected_graph<I>& G, const string& nome_grafo){
    cout << "=== " << nome_grafo << " ===\n";
    cout << "nodi: " << G.all_nodes().size() << "  archi: " << G.all_edges().size() << "\n";
    int attesi = G.all_edges().size() - G.all_nodes().size() + 1;
    cout << "cicli attesi (m - n + 1): " << attesi << "\n";

    auto cicli = cicli_DFS(G);
    cout << "cicli trovati: " << cicli.size() << "\n";
    for(int i = 0; i < cicli.size(); i++){
        cout << "  ciclo " << i+1 << " (" << cicli[i].size() << " archi): ";
        for(auto& e : cicli[i]) cout << e << "  ";
        cout << "\n";
    }
    cout << "\n";
}

template<typename I>
void stampa_de_pina(undirected_graph<I>& G, const string& nome_grafo){
    cout << "--- de Pina: " << nome_grafo << " ---\n";

    vector<undirected_edge<I>> edges;
    for(auto& e : G.all_edges()) edges.push_back(e);

    vector<vector<bool>> S;
    auto B = de_pina(G, S);

    cout << "cicli minimi trovati: " << B.size() << "\n";
    for(int i = 0; i < B.size(); i++){
        int peso = 0;
        for(bool b : B[i]) peso += b;
        cout << "  ciclo " << i+1 << " (peso " << peso << "): ";
        for(int j = 0; j < B[i].size(); j++)
            if(B[i][j]) cout << edges[j] << "  ";
        cout << "\n";
    }
    cout << "\n";
}

int main(){

    /* --- grafo 1: quadrato con diagonale, nodi interi ---
     *
     *  1 - 2
     *  |\  |
     *  | \ |
     *  3 - 4
     *
     *  archi: (1,2),(1,3),(1,4),(2,4),(3,4)
     *  n=4, m=5, cicli attesi: 2
     */
    undirected_graph<int> G1;
    undirected_edge<int> g1_12(1,2), g1_13(1,3), g1_14(1,4), g1_24(2,4), g1_34(3,4);
    G1.add_edge(g1_12); G1.add_edge(g1_13); G1.add_edge(g1_14); G1.add_edge(g1_24); G1.add_edge(g1_34);
    stampa_cicli_DFS(G1, "quadrato con diagonale (int)");
    stampa_de_pina(G1, "quadrato con diagonale (int)");

    /* --- grafo 2: K4 completo, nodi interi ---
     *
     *  tutti i 4 nodi connessi tra loro
     *  n=4, m=6, cicli attesi: 3
     */
    undirected_graph<int> G2;
    undirected_edge<int> g2_12(1,2), g2_13(1,3), g2_14(1,4), g2_23(2,3), g2_24(2,4), g2_34(3,4);
    G2.add_edge(g2_12); G2.add_edge(g2_13); G2.add_edge(g2_14); G2.add_edge(g2_23); G2.add_edge(g2_24); G2.add_edge(g2_34);
    stampa_cicli_DFS(G2, "K4 completo (int)");
    stampa_de_pina(G2, "K4 completo (int)");

    /* --- grafo 3: due triangoli che condividono un lato, nodi string ---
     *
     *  a - b - d
     *   \ / \ /
     *    c   e      (non c'e' arco c-e)
     *
     *  archi: (a,b),(a,c),(b,c),(b,d),(b,e),(d,e)
     *  n=5, m=6, cicli attesi: 2
     */
    undirected_graph<string> G3;
    undirected_edge<string> g3_ab("a","b"), g3_ac("a","c"), g3_bc("b","c"), g3_bd("b","d"), g3_be("b","e"), g3_de("d","e");
    G3.add_edge(g3_ab); G3.add_edge(g3_ac); G3.add_edge(g3_bc); G3.add_edge(g3_bd); G3.add_edge(g3_be); G3.add_edge(g3_de);
    stampa_cicli_DFS(G3, "due triangoli su lato comune (string)");
    stampa_de_pina(G3, "due triangoli su lato comune (string)");

    /* --- grafo 4: ciclo lungo + corda, nodi string ---
     *
     *  a - b - c
     *  | \     |
     *  f - e - d
     *      |
     *      a   (corda a-e)
     *
     *  archi: (a,b),(b,c),(c,d),(d,e),(e,f),(f,a),(a,e)
     *  n=6, m=7, cicli attesi: 2
     */
    undirected_graph<string> G4;
    undirected_edge<string> g4_ab("a","b"), g4_bc("b","c"), g4_cd("c","d"), g4_de("d","e"), g4_ef("e","f"), g4_fa("f","a"), g4_ae("a","e");
    G4.add_edge(g4_ab); G4.add_edge(g4_bc); G4.add_edge(g4_cd); G4.add_edge(g4_de); G4.add_edge(g4_ef); G4.add_edge(g4_fa); G4.add_edge(g4_ae);
    stampa_cicli_DFS(G4, "esagono con corda (string)");
    stampa_de_pina(G4, "esagono con corda (string)");

    return 0;
}
