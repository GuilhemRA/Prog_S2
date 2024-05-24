#include <iostream>
#include <vector>
#include <algorithm>
#include "td02.hpp"

//vérifie si un tableau est trié par ordre croissant
bool is_sorted(std::vector<float> const& vec) {return std::is_sorted(vec.begin(),vec.end());}

//tri par sélection
void selection(std::vector<float>& vec) {
    for(int i{0}; i<vec.size(); i++) {
        int j = i;
        int min = minInVector(vec,i);
        while(j<vec.size()) {
            if(vec[j]==min) {
                std::swap(vec[i],vec[j]);
                break;
            }
            j++;
        }
    }
}

int minInVector(std::vector<float> const& vec,int i) {
    return *std::min_element(vec.begin()+i,vec.end());
}

void display(std::vector<float> const& vec) {
    for(int count : vec) {
        std::cout << count << ", ";
    }
    std::cout << std::endl;
}

// int valeurMoyenne(std::vector<int> const& vec) {
//     int sum;
//     int siz = vec.size();
//     for (int val : vec) {
//         sum = sum + val;
//     }
//     return (sum/siz);
// }

//tri rapide
// l'idée de cette fonction est de prendre le vecteur sur lequel on va travailler en paramètre et de prendre deux index (left et right) qui indiquent la partie du tableau pour laquelle on va répartir les valeurs (inférieur au pivot à gauche supérieur à droite du pivot réciproquement à droite) et la valeur du pivot
size_t quick_sort_partition(std::vector<float> & vec, size_t left, size_t right) {
    // On choisit le pivot comme étant le dernier élément de la partition
    size_t const pivot_index {right};
    float const pivot_value {vec[pivot_index]};
    // On garde l'index du premier élément plus grand que le pivot
    size_t first_bigger_element_index {left};
    // On parcourt les éléments de la partition pour les répartir
    for (size_t i {left}; i < right ;i++) {
        // Si l'élément actuel est plus petit que le pivot, on l'échange avec le dernier élément plus petit que le pivot
        if (pivot_value > vec[i]) {
            std::swap(vec[i],vec[first_bigger_element_index]);
            // on incrémente l'index du premier élément plus grand que le pivot (car on vient de le déplacer et placer un élément plus petit que le pivot à sa place)
            first_bigger_element_index += 1;
        }
    }
    // on échange le pivot (qui est positionné à la fin) pour qu'il soit positionné ente les deux sous partitions (des éléments plus petits et plus grand que le pivot)
    std::swap(vec[pivot_index],vec[first_bigger_element_index]);

    // on retourne l'index du pivot
    return (first_bigger_element_index);
}

void quick_sort(std::vector<float> & vec, size_t const left, size_t const right) {
    if (left >= right) {
        return;
    }
    // 1. On partitionne le vecteur et on récupère l'index du pivot grâce à la fonction quick_sort_partition
    size_t pivotIndex = quick_sort_partition(vec, left, right);
    // 2. appels récursifs sur les deux sous parties gauche et droite du pivot
    quick_sort(vec,left,pivotIndex-1);
    quick_sort(vec,pivotIndex+1,right);
    // Attention à la condition d'arrêt de la récursivité
}

// Surcharge de la fonction qui permet d'appeler la fonction en passant seulement le vecteur et définir les index left et right pour cibler la totalité du tableau à trier automatiquement
void quick_sort(std::vector<float> & vec) {
    quick_sort(vec, 0, vec.size() - 1);
}

// Tableau d'entiers aléatoires
// std::vector<int> generate_random_vector(size_t const size, int const max = 100) {
//     std::vector<int> vec(size);
//     std::generate(vec.begin(), vec.end(), [&max]() { return std::rand() % max;} );
//     return vec;
// }


int search(std::vector<float> & vec, int const val) {
    int left = 0;
    int right = vec.size();
    int middle = 0;
    while(vec[middle]!=val) {
        middle = (left + right)/2;
        if(vec[middle]==val) {
            return middle;
            break;
        }
        if(vec[middle]<val) {
            left=middle;
        }
        else {
            right=middle;
        }
        if(right==left) {
            return (-1);
            break;
        }
    }
}














































    // std::vector<int> chiffre{};

    // std::string comptage{};
    // std::cout << "Entrez une suite de 10 chiffres : ";

    // std::getline(std::cin, comptage);
    
    // for(char n : comptage)
    // {
    //     if(n!=' ')
    //     {
    //         chiffre.push_back(n-'0');
    //     }
    // }

    // std::vector<int> reponse{};
    // int counter{};
    // for(int count : chiffre)
    // {
    //     if(count!=3)
    //     {
    //         reponse.push_back(count);
    //         counter++;
    //     }
    // }