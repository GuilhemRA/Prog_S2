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
    std::cout << "Entrez une chaine de caractere : ";
    std::cin >> str;
    std::cout << "Entrez la valeur maximum de hash : ";
    std::cin >> max;
    std::cout << std::endl;

    std::cout << "Le hash correspondant est : " << folding_string_hash(str, max);
}


