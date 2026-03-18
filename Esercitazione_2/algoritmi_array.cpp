#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void){
    static const int N = 10;
    double arr[N], arrq[N];
    int i=0;
    double s=0, sq=0;
    double m=0;
    double M=0;
    for (i=0;i<N;i++){
        arr[i]=1.0/(i+1);
        arrq[i]=arr[i]*arr[i];
        s+=arr[i];
        sq+=arrq[i];
        if(i==0){
            M=arr[i];
            m=arr[i];
        }
        else{
            if(arr[i]>M) M=arr[i];
            if(arr[i]<m) m=arr[i];
        }
    }
    double avg=s/N;
    double stdev=sqrt((sq/N)-avg*avg);
    cout << "\nminimo:\n" << m << "\nmassimo:\n" << M << "\nmedia:\n" << avg << "\ndeviazione standard:\n" << stdev << "\n";

    double d=0.0;
    bool sort=0;
    while(!sort){
        sort=1;
        for(i=0;i<N-1;i++){
            if(arr[i]>arr[i+1]){
                sort=0;
                d=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=d;
            }
        }
    }
    cout << "\narray ordinato:\n";
    for(i=0;i<N;i++){
        cout << arr[i] << "\n";
    }
return 0;
}