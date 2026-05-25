#include <iostream>
#include <Eigen/Dense>
#include "gradiente_coniugato.hpp"

using namespace std;
int main(){
    unsigned int n;
    double res_tol = 1.0e-12;
    cout << "inserire la dimensione della matrice con cui si desidera testare l'algoritmo: ";
    cin >> n;
    cout << "\ninserire la tolleranza sul residuo con cui si desidera testare l'algoritmo: ";
    cin >> res_tol;
    cout << "\n\n";

    Eigen::MatrixXd B = Eigen::MatrixXd::Random(n, n);
    Eigen::MatrixXd A = B.transpose() * B;
    Eigen::VectorXd x_ex = Eigen::VectorXd::Ones(n);
    Eigen::VectorXd b = A * x_ex;
    
    Eigen::VectorXd x = gradiente_coniugato(A, b, res_tol, x_ex);

    return 0;
}