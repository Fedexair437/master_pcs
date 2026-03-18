# include <iostream>
int main()
{
    double ad[4] = {0.0, 1.1, 2.2, 3.3};
    float af[8] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
    int ai[3] = {0, 1, 2};

    int x = 1;
    float y = 1.1;

    std::cout << "\n" << x << "\n" << &x << "\n" << &y << "\n";

    (&y)[1] = 0;

    std::cout << x << "\n" << &x << "\n" << &y << "\n"; //l'istruzione (&y)[1] = 0 modifica i byte della variabile x, ma non il suo indirizzo

    return 0;
}