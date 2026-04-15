#pragma once
#include <iostream>
#include <optional>
#include <vector>
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