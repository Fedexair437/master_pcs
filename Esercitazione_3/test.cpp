#include <iostream>
#include "rational.hpp"
using namespace std;

int main(void)
{
    int numa, dena, numb, denb;
    cout << "inserire il numeratore del razionale a:\n";
    cin >> numa;
    cout << "\ninserire il denominatore del razionale a:\n";
    cin >> dena;
    cout << "\ninserire il numeratore del razionale b:\n";
    cin >> numb;
    cout << "\ninserire il denominatore del razionale b:\n";
    cin >> denb;
    rational<int> a(numa, dena);
    rational<int> b(numb, denb);
    
    rational<int> c = a+b;
    
    cout << "\nnumeratore e denominatore di c=a+b:\n" << c.num() << " " << c.den() << "\n";
    cout << "c:\n" << c << "\n";
    
    rational<int> p = c*b;
    rational<int> r = c/b;
    cout << "\np=c*b e r=c/b:\n";
    cout << p << "\n";
    cout << r << "\n";
    return 0;
}