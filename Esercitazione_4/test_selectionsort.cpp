#include <iostream>
#include "vettori.hpp"
#include "timecounter.h"
#include "randfiller.h"
#include <thread>
#include <chrono>
#include <vector>
#include <cstdlib>

using namespace std;

template<typename T>
void
print_vector(const vector<T>& v)
{
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << "\n";
}

int main(){
    randfiller rf;
    vector<int> sizes;
    sizes.resize(100);
    rf.fill(sizes, 3, 20);
    for(int i=0 ; i<=99 ; i++){
        vector<int> v;
        v.resize(sizes.at(i));
        rf.fill(v, -100, 100);
        selection_sort(v);
        print_vector(v);
        bool sorted=is_sorted(v);
        if(!sorted) return EXIT_FAILURE;
    }
    vector<string> vs = {"banana", "elefante", "mela", "zebra", "albicocca", "pera", "mango", "ciliegia", "fico", "uva"};
    selection_sort(vs);
    bool sorted=is_sorted(vs);
    if(!sorted) return EXIT_FAILURE;
    return EXIT_SUCCESS;
}