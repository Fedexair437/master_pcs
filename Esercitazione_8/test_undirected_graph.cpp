#include <iostream>
#include "undirected_edges.hpp"
#include "undirected_graph.hpp"
#include <cstdlib>

using namespace std;

int main(){

    /* test su undirected_graph */

    undirected_graph<int> G;
    undirected_edge<int> a(1,2), b(1,3), c(2,3), d(2,4), e(3,4);
    G.add_edge(a);
    G.add_edge(b);
    G.add_edge(c);
    G.add_edge(d);
    G.add_edge(e);


    //all_nodes()
    auto nodi = G.all_nodes();
    if(nodi.size() != 4) return EXIT_FAILURE;


    //all_edges()
    auto archi = G.all_edges();
    if(archi.size() != 5) return EXIT_FAILURE;


    //neighbours()
    auto vicini2 = G.neighbours(2);
    if(!vicini2.contains(1) || !vicini2.contains(3) || !vicini2.contains(4)) return EXIT_FAILURE;
    if(vicini2.size() != 3) return EXIT_FAILURE;


    //edge_number() e edge_at()
    int num_a = G.edge_number(a);
    if(num_a == -1) return EXIT_FAILURE;
    undirected_edge<int> ritrovato = G.edge_at(num_a);
    if(!(ritrovato == a)) return EXIT_FAILURE;


    //edge_number() su arco non presente
    undirected_edge<int> assente(1,4);
    if(G.edge_number(assente) != -1) return EXIT_FAILURE;


    //costruttore di copia
    undirected_graph<int> G2(G);
    if(G2.all_edges().size() != G.all_edges().size()) return EXIT_FAILURE;


    //operator-
    
    undirected_graph<int> Gprime;
    undirected_edge<int> p(1,2), q(3,4);
    Gprime.add_edge(p);
    Gprime.add_edge(q);

    undirected_graph<int> diff = G - Gprime;
    auto archi_diff = diff.all_edges();
    if(archi_diff.size() != 3) return EXIT_FAILURE;
    if(archi_diff.contains(undirected_edge<int>(1,2)) || archi_diff.contains(undirected_edge<int>(3,4))) return EXIT_FAILURE;


    // G originale non deve essere modificato dall'operazione -
    if(G.all_edges().size() != 5) return EXIT_FAILURE;



    /* test con stringhe */
    undirected_graph<string> Gs;
    undirected_edge<string> es1("torino", "milano");
    undirected_edge<string> es2("milano", "roma");
    undirected_edge<string> es3("torino", "roma");
    Gs.add_edge(es1);
    Gs.add_edge(es2);
    Gs.add_edge(es3);


    if(Gs.all_nodes().size() != 3) return EXIT_FAILURE;
    

    if(!Gs.neighbours("milano").contains("torino") || !Gs.neighbours("milano").contains("roma")) return EXIT_FAILURE;


    cout << "Tutti i test superati.\n";
    return EXIT_SUCCESS;
}