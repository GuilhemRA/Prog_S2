#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <iterator>
#include <cctype>

#include <stack>

#include <unordered_map>
#include <map>
#include <set>

#include "td05.hpp"

size_t folding_string_hash(std::string const& s, size_t max) {
    char r{0};
    for(char c : s) {
        if (c != ' ') {
            r = r + c;
        }
    }
    if(r>max) {
        r = r%max;
    }
    return (size_t)r;
}

size_t folding_string_ordered_hash(std::string const& s, size_t max) {
    char r{0};
    int i{1};
    for(char c : s) {
        if (c != ' ') {
            r = r + c*i;
            i++;
        }
    }
    if(r>max) {
        r = r%max;
    }
    return (size_t)r; 
}

size_t polynomial_rolling_hash(const std::string& s, size_t p, size_t m) {
    char r{0};
    int pow{1};
    for(char c : s) {
        if (c != ' ') {
            r = r + (c*pow*p%m);
            pow = pow*p;
        }
    }
    return (size_t)r;
}

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

std::string random_name(size_t size) {
    std::string name {""};
    // Optimisation pour que la chaîne de caractère ne réalloue pas de la mémoire à chaque caractère ajouté
    name.reserve(size);
    for(size_t i {0}; i < size; ++i) {
        name.push_back('A' + std::rand() % 26);
    }
    return name;
}

std::vector<std::pair<std::string, float>> get_robots_fix(size_t size) {
    std::vector<std::pair<std::string, float>> robots_fix {};
    // Meme optimisation que dans random_name()
    robots_fix.reserve(size);
    for (size_t i {0}; i < size; ++i) {
        // random name 
        std::string robotName { random_name(2) };
        // random cost
        float cost {static_cast<float>(std::rand()) / RAND_MAX * 1000.0f};
        robots_fix.push_back(std::make_pair(robotName, cost));
    }
    return robots_fix;
}

// J'aimerai être capable de lister pour un robot donné l'ensemble des réparations effectuées pour ce robot. Par exemple, pour le robot "AB",
// j'aimerai avoir la liste des réparations effectuées pour ce robot.
// 1. Pour cela, je vous demande d'écrire une fonction qui prend en paramètre la liste des réparations effectuées et qui retourne une table
// associative (std::unordered_map) qui associe à chaque nom de robot la liste des réparations effectuées pour ce robot (sous forme de 
// std::vector<float>).
std::unordered_map<std::string, std::vector<float>> robots_fixes_map(std::vector<std::pair<std::string, float>> const& robots_fixes) {
    std::unordered_map<std::string, std::vector<float>> umap;
    for(std::pair<std::string, float> f : robots_fixes) {
        float val = f.second;
        if(umap.find("f.first")==umap.end()) {
            std::string key = f.first;
            umap.insert({key,{val}});
        } else {
            umap["key"].push_back(val);
        }
    }
    return umap;
}

float cout_reparations(std::vector<float> vecfloat) {
    float f{0};
    for (float i : vecfloat) {
        f = f+i;
    }
    return f;
}


// 2. Écrire une fonction qui prend en un std::vector<float> et qui retourne la somme des éléments de ce vecteur.

// 3. Utiliser les deux fonctions précédentes pour afficher la somme des réparations effectuées pour chaque robot.
// (à partir de la liste des réparations effectuées obtenue avec la fonction get_robots_fix).