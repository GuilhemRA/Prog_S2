#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include "td04.hpp"

int main()
{
    // std::vector<int> v(10);
    // for(int i = 0; i < v.size(); i++) {
    //     v[i]= rand()%101;
    //     std::cout << v[i] << " ";
    // }
    // std::cout << std::endl;
    // std::vector<int> v {1,14,54,76,24,79,56,67,45,65,3,2,2,4,5,6,4,7,8,2,43,43,54,76,87,54,54,3,3,45,86,42,63,79};

    // // Déclaration d'un itérateur permettant d'indiquer la fin d'un vecteur v
    // std::vector<int>::iterator end_iterator {v.end()};
    // // Parcours du vecteur avec l'itérateur
    // for (std::vector<int>::iterator it {v.begin()}; it != end_iterator; ++it) {
    //     std::cout << *it << std::endl;
    // }

    // int element{};
    // std::cout << "Entrez l'element a chercher : ";
    // std::cin >> element;
    // std::cout << std::endl;

    // // Recherche de l'élément "element" dans le vecteur v
    // auto it {std::find(v.begin(), v.end(), element)};
    // // On compare l'itérateur sur le dernier élément du vecteur
    // if(it != v.end()) {
    //     std::cout << "Le nombre " << *it << " est bien dans la liste";
    //     std::cout << std::endl;
    // } else {
    //     std::cout << "Element non trouve" << std::endl;
    //     std::cout << std::endl;
    // }
    // std::cout << std::endl;

    // std::vector<int> elementsCibles {};
    // int counter{};
    // std::cout << "Entrez le nombre d'elements different a compter : ";
    // std::cin >> counter;
    // std::cout << std::endl;
    // for (int i{0}; i < counter; i++) {
    //     if(i==0) {
    //         int element{};
    //         std::cout << "Entrez le 1er element a compter : ";
    //         std::cin >> element;
    //         elementsCibles.push_back(element);
    //         std::cout << std::endl;
    //     } else {
    //         int element{};
    //         std::cout << "Entrez le " << i+1 << "eme element a compter : ";
    //         std::cin >> element;
    //         elementsCibles.push_back(element);
    //         std::cout << std::endl;
    //     }
    // }

    // for (const int target : elementsCibles) {
    //     const int nbrElements = std::count(v.cbegin(),v.cend(),target);
    //     std::cout << "L'element " << target << " est " << nbrElements << " fois dans la liste" << '\n';
    // }
    // std::cout << std::endl;

    // // Tri du vecteur v
    // std::sort(v.begin(), v.end());

    // std::cout << "Le vecteur trie est :" << std::endl;
    // // Parcours du vecteur avec l'itérateur
    // for (int element : v)
    // {
    //     std::cout << element << " ";
    // }
    // std::cout << std::endl;

    // // Somme des éléments du vecteur v
    // int sum { std::accumulate(v.begin(), v.end(), 0, [](int acc, int current_element) { return acc + current_element; }) };
    // std::cout << "La somme de tous les elements de la liste donne " << sum << std::endl;



    // auto const is_space = [](char letter){ return letter == ' '; };

    std::string phrase{};
    std::cout << "Ecrivez une phrase : ";
    std::getline(std::cin, phrase);
    if(phrase=="Je suis un genie") {
        std::cout << std::endl;
        std::cout << "---> C'est vrai ! <---" << std::endl;
        std::cout << std::endl;
    }
    if(phrase=="JE SUIS UN GENIE") {
        std::cout << std::endl;
        std::cout << "---> C'est vrai ! <---" << std::endl;
        std::cout << std::endl;
    }
    // std::cout << "Le premier mot contient " << nbrDeLettrePremierMot(phrase) << " lettres";
    // std::cout << std::endl;
    std::vector<std::string> vectMots{split_string(phrase)};
    std::cout << "La liste de mots est : " << std::endl;
    for(std::string n : vectMots) {
        std::cout << n << std::endl;
    }

    std::string mot{};
    std::cout << "Ecrivez un palindrome : ";
    std::cin >> mot;
    bool reponse{palindrome(mot)};
    if(reponse==true) {
        std::cout << "Ce mot est un palindrome" << std::endl;
    } else {
        std::cout << "Ce mot n'est pas un palindrome" << std::endl;
    }
}


