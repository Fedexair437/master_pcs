#include <iostream>
#include "vettori2.hpp"
#include "timecounter.h"
#include "randfiller.h"
#include <thread>
#include <chrono>
#include <vector>
#include <algorithm>

using namespace std;

void riempimento(vector<vector<int>>& V, int size_internal){
    int size=V.size();
    randfiller rf;
    for(int j=0;j<size;j++){     //ciclo di riempimento di ogni vettore interno
            V[j].resize(size_internal);
            rf.fill(V[j], -100, 100);
        }
}

int main(){
    timecounter tc;

    vector<double> t_bs(398, 0), t_is(398, 0), t_ss(398, 0), t_qs(398, 0), t_ms(398,0), t_std(398,0);
    vector<vector<int>> V(400);

    for(int i=2 ; i<=399 ; i++){     //ciclo sulla dimensione comune dei vettori interni
        
        riempimento(V, i);
        tc.tic();
        for(int j=0;j<400;j++){     //ciclo di misurazione del tempo con bubble-sort
            bubble_sort(V[j]);
        }
        t_bs[i-2] += tc.toc();
        t_bs[i-2] /= 400;

        riempimento(V, i);
        tc.tic();
        for(int j=0;j<400;j++){     //ciclo di misurazione del tempo con insertion-sort
            insertion_sort(V[j]);
        }
        t_is[i-2] += tc.toc();
        t_is[i-2] /= 400;

        riempimento(V, i);
        tc.tic();
        for(int j=0;j<400;j++){     //ciclo di misurazione del tempo con selection-sort
            selection_sort(V[j]);
        }
        t_ss[i-2] += tc.toc();
        t_ss[i-2] /= 400;

        riempimento(V, i);
        tc.tic();
        for(int j=0;j<400;j++){     //ciclo di misurazione del tempo con merge-sort
            merge_sort(V[j], 0, V[j].size()-1);
        }
        t_ms[i-2] += tc.toc();
        t_ms[i-2] /= 400;

        riempimento(V, i);
        tc.tic();
        for(int j=0;j<400;j++){     //ciclo di misurazione del tempo con quick-sort
            quick_sort(V[j], 0, V[j].size()-1);
        }
        t_qs[i-2] += tc.toc();
        t_qs[i-2] /= 400;

        riempimento(V, i);
        tc.tic();
        for(int j=0;j<400;j++){     //ciclo di misurazione del tempo con quick-sort
            sort(V[j].begin(), V[j].end());
        }
        t_std[i-2] += tc.toc();
        t_std[i-2] /= 400;
    }

    cout<<"bubblesort:\n";
    for(int i=2;i<=399;i++){
        cout<<t_bs[i-2]*1000<<" ";
    }
    cout<<"\n";

    cout<<"insertionsort:\n";
    for(int i=2;i<=399;i++){
        cout<<t_is[i-2]*1000<<" ";
    }
    cout<<"\n";

    cout<<"selectionsort:\n";
    for(int i=2;i<=399;i++){
        cout<<t_ss[i-2]*1000<<" ";
    }
    cout<<"\n";

    cout<<"quicksort:\n";
    for(int i=2;i<=399;i++){
        cout<<t_qs[i-2]*1000<<" ";
    }
    cout<<"\n";

    cout<<"mergesort:\n";
    for(int i=2;i<=399;i++){
        cout<<t_ms[i-2]*1000<<" ";
    }
    cout<<"\n";

    cout<<"std::sort:\n";
    for(int i=2;i<=399;i++){
        cout<<t_std[i-2]*1000<<" ";
    }
    cout<<"\n";

    /*
    for(int i=2 ; i<=99 ; i++){
        cout << "con bubble-sort i vettori di lunghezza " << i << " sono stato sortati in media in " << t_bs[i-2]*1000 << " millisecondi\n";
        cout << "con insertion-sort i vettori di lunghezza " << i << " sono stato sortati in media in " << t_is[i-2]*1000 << " millisecondi\n";
        cout << "con selection-sort i vettori di lunghezza " << i << " sono stato sortati in media in " << t_ss[i-2]*1000 << " millisecondi\n";
        cout << "con merge-sort i vettori di lunghezza " << i << " sono stato sortati in media in " << t_ms[i-2]*1000 << " millisecondi\n";
        cout << "con quick-sort i vettori di lunghezza " << i << " sono stato sortati in media in " << t_qs[i-2]*1000 << " millisecondi\n";
        cout << "con std::sort i vettori di lunghezza " << i << " sono stato sortati in media in " << t_std[i-2]*1000 << " millisecondi\n\n";
    }
    */

    return 0;
}