#include <iostream>
#include "undirected_edges.hpp"
#include "undirected_graph.hpp"
#include <cstdlib>

using namespace std;

int main(){

    /* test su undirected_edge */

    // from() è sempre minore di to()
    undirected_edge<int> e1(3, 1);
    if(e1.from()>e1.to()){ return EXIT_FAILURE; }

    undirected_edge<double> e2(2.5, 7.01);
    if(e2.from()>e2.to()){ return EXIT_FAILURE; }


    // operator==
    undirected_edge<double> e3(2.5, 7.01);
    if(!(e2 == e3)){ return EXIT_FAILURE; }

    undirected_edge<int> e4(3, 4);
    if(e1 == e4){ return EXIT_FAILURE; }


    // operator <
    if(!(e1 < e4)){ return EXIT_FAILURE; }
    undirected_edge<int> e5(2, 3);
    if(e4 < e5){ return EXIT_FAILURE; }


    // operator <<
    cout << "Stampa arco e1: " << e1 << "\n";
    cout << "Stampa arco e3: " << e3 << "\n";

    

    cout << "Tutti i test superati.\n";
    return EXIT_SUCCESS;
}