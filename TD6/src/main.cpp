#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include "node.hpp"

int main()
{
    Node* root {create_node(45)};
    root->insert(40);
    root->insert(47);
    root->insert(39);
    pretty_print_left_right(*root);
    std::cout << "La hauteur de l'arbre est : " << root->height() << std::endl;
    // root->delete_childs();
    // pretty_print_left_right(*root);
    // std::cout << "La hauteur de l'arbre est : " << root->height();
    root->display_infixe();
    std::cout << std::endl;
    std::vector<Node const*> VectNode{root->prefixe()};
    for(Node const* N : VectNode) {
        std::cout << N->value << ' ';
    }
    std::cout << std::endl;
    int mostLeft = most_left(root)->value;
}



