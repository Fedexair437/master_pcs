#include <iostream>
#include <fstream>
using namespace std;

int main()
{
cout << "Inserire il nome del file da processare:\n";
string name;
cin >> name;
ifstream ifs(name);
if(ifs.is_open()){
    string city;
    float mt, t1, t2, t3, t4;
    while(!ifs.eof()){
        ifs >> city >> t1 >> t2 >> t3 >> t4;
        mt=(t1+t2+t3+t4)/4;
        cout << city << "   " << mt << "\n";
    }
}
else{
    cout << "Errore con l'apertura del file";
    return 1;
}
return 0;
}