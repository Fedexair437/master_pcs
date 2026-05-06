#pragma once
#include <iostream>
#include <optional>
#include <vector>
#include <cmath>
using namespace std;

template<typename T>
bool is_sorted(const std::vector<T>& vec){
    if (vec.size() == 0) {
        return true;
    }
    for (int i = 0; i < vec.size()-1; i++) {
        if(vec.at(i)>vec.at(i+1)) return false;
    }
    return true;
}

template<typename T>
void bubble_sort(vector<T>& vec){
    if (vec.size() == 0) return;
    int l=vec.size();
    for(int i=0 ; i<=l-2 ; i++){
        for(int j=l-1 ; j>=i+1 ; j--){
            if(vec.at(j)<vec.at(j-1)){
                T temp = vec.at(j);
                vec.at(j)=vec.at(j-1);
                vec.at(j-1)=temp;
            }
        }
    }
}

template<typename T>
void insertion_sort(vector<T>& vec){
    if (vec.size() == 0) return;
    int l=vec.size();
    for(int j=1 ; j<=l-1 ; j++){
        T k=vec.at(j);
        int i=j-1;
        while(i>=0 && vec.at(i)>k){
            vec.at(i+1)=vec.at(i);
            i--;
        }
        vec.at(i+1)=k;
    }
}

template<typename T>
void selection_sort(vector<T>& vec){
    if (vec.size() == 0) return;
    int l=vec.size();
    for(int i=0 ; i<=l-2 ; i++){
        int min=i;
        for(int j=i ; j<=l-1 ; j++){
            if(vec.at(j)<vec.at(min)){
                min=j;
            }
        }
        T temp=vec.at(i);
        vec.at(i)=vec.at(min);
        vec.at(min)=temp;
    }
}


template<typename T>
void merge(vector<T>& vec, int sx, int c, int dx){
    int n1=c-sx+1;
    int n2=dx-c;
    vector<T> L(n1+1);
    vector<T> R(n2+1);
    for(int i=0;i<n1;i++){
        L[i]=vec[sx+i];
    }
    for(int i=0;i<n2;i++){
        R[i]=vec[c+i+1];
    }
    /* L[n1]=inf, R[n2]=inf      gestito invece con un controllo sul valore massimo degli indici di L ed R nel ciclo successivo per
    maggior versatilita' indipendentemente dal tipo T (intero, float, stringa,...) */
    int i=0, j=0;
    for(int k=sx;k<=dx;k++){
        if((L[i]<=R[j] || j>=n2) && i<n1){      /* if((L[i]<=R[i] oppure j oltre il suo  limite) e i entro il suo limite) */
            vec[k]=L[i];
            i++;
        }
        else{       /* vale a dire if((L[i]>R[i] e j entro il suo  limite) oppure i oltre il suo limite)*/
            vec[k]=R[j];
            j++;
        }
    }
}

template<typename T>
void merge_sort(vector<T>& vec, int sx, int dx){
    if (vec.size() == 0) return;
    if(sx<dx){
        int c=floor((sx+dx)/2);
        merge_sort(vec, sx, c);
        merge_sort(vec, c+1, dx);
        merge(vec, sx, c, dx);
    }
}

template<typename T>
int partition(vector<T>& vec, int sx, int dx){
    T x=vec[dx];
    int i=sx-1;
    for(int j=sx;j<dx;j++){
        if(vec[j]<=x){
            i++;
            T temp=vec[i];
            vec[i]=vec[j];
            vec[j]=temp;
        }
    }
    T temp=vec[i+1];
    vec[i+1]=vec[dx];
    vec[dx]=temp;
    return i+1;
}

template<typename T>
void quick_sort(vector<T>& vec, int sx, int dx){
    if (vec.size() == 0) return;
    if(sx<dx){
        int c=partition(vec, sx, dx);
        quick_sort(vec, sx, c-1);
        quick_sort(vec, c+1, dx);
    }
}

template<typename T>
void insertion_sort2(vector<T>& vec, int sx, int dx){
    if (vec.size() == 0) return;
    int l=dx-sx+1;
    for(int j=1+sx ; j<=l-1 ; j++){
        T k=vec.at(j);
        int i=j-1;
        while(i>=0 && vec.at(i)>k){
            vec.at(i+1)=vec.at(i);
            i--;
        }
        vec.at(i+1)=k;
    }
}

template<typename T>
void quick_sort2(vector<T>& vec, int sx, int dx){
    int threshold=150;
    if (vec.size() == 0) return;
    if(sx<dx){
        if(dx-sx+1<=threshold){
            insertion_sort2(vec, sx, dx);
        }
        else{
            int c=partition(vec, sx, dx);
            quick_sort(vec, sx, c-1);
            quick_sort(vec, c+1, dx);
        }
    }
}