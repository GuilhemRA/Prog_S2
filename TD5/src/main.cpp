#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include "td05.hpp"

int main()
{
    std::string str{};
    size_t max{};
    size_t p{};
    std::cout << "Entrez une chaine de caractere : ";
    std::cin >> str;
    std::cout << "Entrez la valeur p pour la puissance : ";
    std::cin >> p;    
    std::cout << "Entrez la valeur maximum de hash : ";
    std::cin >> max;
    std::cout << std::endl;

    std::cout << "Le hash correspondant est : " << polynomial_rolling_hash(str, p, max);
}


