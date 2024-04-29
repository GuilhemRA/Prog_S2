#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "td03.hpp"

int main()
{
    std::string pileNpi{};
    std::cout << "Entrez une expression NPI : ";

    std::getline(std::cin, pileNpi);
    std::vector splitPileNpi = split_string(pileNpi);

    for(std::string n : splitPileNpi) {
        std::cout << n << std::endl;
    }

    std::cout << npi_evaluate(splitPileNpi);

}