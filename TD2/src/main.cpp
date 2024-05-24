#include <iostream>
#include <vector>
#include <algorithm>
#include "td02.hpp"

int main()
{
    std::vector<float> array {54,56,76,43,24,87,96,93,21,23,32,41,52,61,100,73,84,94};

    // selection(array);
    quick_sort(array);
    display(array);

    if(is_sorted(array)) {
        std::cout << "Le tableau est trie" << std::endl;
    } else {
        std::cout << "Le tableau n'est pas trie" << std::endl;
    }

    int val = 94;
    std::cout << "La position de la valeur " << val << " dans le tableau est " << search(array,val) + 1 << std::endl;

}