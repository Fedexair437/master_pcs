#include <iostream>
#include "vettori.hpp"
#include "timecounter.h"
#include "randfiller.h"
#include <thread>
#include <chrono>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    randfiller rf;
    timecounter tc;
    cout << "bubble sort:\n";
    for(int i=4 ; i<=8192 ; i*=2){
        vector<int> v;
        v.resize(i);
        rf.fill(v, -100, 100);
        tc.tic();
        bubble_sort(v);
        double t = tc.toc();
        cout << "il vettore di lunghezza " << i << " e' stato sortato in " << t << " millisecondi\n";
    }

    cout << "insertion sort:\n";
    for(int i=4 ; i<=8192 ; i*=2){
        vector<int> v;
        v.resize(i);
        rf.fill(v, -100, 100);
        tc.tic();
        insertion_sort(v);
        double t = tc.toc();
        cout << "il vettore di lunghezza " << i << " e' stato sortato in " << t << " millisecondi\n";
    }

    cout << "selection sort:\n";
    for(int i=4 ; i<=8192 ; i*=2){
        vector<int> v;
        v.resize(i);
        rf.fill(v, -100, 100);
        tc.tic();
        selection_sort(v);
        double t = tc.toc();
        cout << "il vettore di lunghezza " << i << " e' stato sortato in " << t << " millisecondi\n";
    }

    cout << "sort libreria standard:\n";
    for(int i=4 ; i<=8192 ; i*=2){
        vector<int> v;
        v.resize(i);
        rf.fill(v, -100, 100);
        tc.tic();
        sort( v.begin(), v.end() );
        double t = tc.toc();
        cout << "il vettore di lunghezza " << i << " e' stato sortato in " << t << " millisecondi\n";
    }

    return 0;
}