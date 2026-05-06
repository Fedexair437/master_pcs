#include <iostream>
#include "vettori2.hpp"
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
    vector<int> sizes(100, 0);
    rf.fill(sizes, 3, 20);
    for(int i=0 ; i<=99 ; i++){
        vector<int> v(sizes.at(i), 0);
        rf.fill(v, -100, 100);
        quick_sort2(v, 0, v.size()-1);
        print_vector(v);
        bool sorted=is_sorted(v);
        if(!sorted) return EXIT_FAILURE;
    }
    vector<string> vs = {"banana", "elefante", "mela", "zebra", "albicocca", "pera", "mango", "ciliegia", "fico", "uva"};
    quick_sort(vs, 0, vs.size()-1);
    bool sorted=is_sorted(vs);
    if(!sorted) return EXIT_FAILURE;
    return EXIT_SUCCESS;
}