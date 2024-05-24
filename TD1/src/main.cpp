#include <iostream>
#include "fraction.hpp"

int main()
{
    Fraction f1 { 3, 4 };
    Fraction f2 { 1, 2 };

    std::cout << "f1 = ";
    f1.display();
    std::cout << " f2 = ";
    f2.display();
    std::cout << std::endl;

    std::cout << "f1 + f2 = ";
    std::cout << f1+f2;

    std::cout << std::endl << "f1 - f2 = ";
    std::cout << f1-f2;

    std::cout << std::endl << "f1 * f2) = ";
    std::cout << f1*f2;

    std::cout << std::endl << "f1 / f2 = ";
    std::cout << f1/f2;

    if((f1==f2) == true) {
        std::cout << std::endl << f1 << " et " << f2 << " sont egales" << std::endl;
    } else {
        std::cout << std::endl << f1 << " et " << f2 << " ne sont pas egales" << std::endl;
    }

    if((f1<f2) == true) {
        std::cout << std::endl << f1 << " est inferieure a " << f2 << std::endl;
    } else {
        std::cout << std::endl << f1 << " n'est pas inferieure a " << f2 << std::endl;
    }

    std::cout << to_float(f1);
    
    // std::cout << std::endl << "1/6 + 2/6 = ";
    // ({1, 6}+{2, 6}).display();

    return 0;
}