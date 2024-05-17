#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <iterator>
#include <cctype>

#include <stack>

#include "td04.hpp"

int nbrDeLettrePremierMot (std::string const str) {
    std::string::const_iterator placePremierEspace = std::find(str.begin(), str.end(), ' ');
    return std::distance(str.begin(),placePremierEspace);
}

int nbrDeLettreMot (std::string const str) {
    return std::distance(str.begin(),str.end());
}

std::vector<std::string> split_string(std::string const& str) {
    std::vector<std::string> vectMots{};

    std::string::const_iterator placePremierEspace = std::find(str.begin(), str.end(), ' ');
    std::string newString(str.begin(), placePremierEspace);

    vectMots.push_back(newString);

    while(placePremierEspace != str.end()) {
        std::string::const_iterator placeEspaceSuivant = std::find(placePremierEspace + 1, str.end(), ' ');
        std::string newString(placePremierEspace + 1, placeEspaceSuivant);
        vectMots.push_back(newString);
        placePremierEspace = placeEspaceSuivant;
    }

    return vectMots;
}

bool palindrome(std::string const& mot) {
    return std::equal(std::begin(mot),std::end(mot),std::rbegin(mot));

    // int n{nbrDeLettreMot(mot)};
    // int count{0};
    // int verif{0};
    // while(count <= n/2) {
    //     if(*(mot.begin()+count) == *(mot.end()-count)) {
    //         verif++;
    //     }
    //     count++;
    //     std::cout << "verif = " << verif << std::endl;
    //     std::cout << "count = " << count << std::endl;
    // }
    // if(verif==count) {
    //     return true;
    // } else {
    //     return false;
    // }
}