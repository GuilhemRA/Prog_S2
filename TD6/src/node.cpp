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

#include "node.hpp"

void pretty_print_left_right(Node const& node, std::string const& prefix, bool is_left) {
    if (node.right) {
        pretty_print_left_right(*node.right, prefix + (is_left ? "|   " : "    "), false);
    }
    std::cout << prefix << (is_left ? "+-- " : "+-- ") << node.value << std::endl;
    if (node.left) {
        pretty_print_left_right(*node.left, prefix + (is_left ? "    " : "|   "), true);
    }
}

void pretty_print_left_right(Node const& node) {
    pretty_print_left_right(node, "", true);
}

Node* create_node(int value) {
    return new Node {value, nullptr, nullptr};
}

bool Node::is_leaf() const {
    return(left==nullptr && right==nullptr);
}

void Node::insert(int val) {
    if(val<value) {
        if(left==nullptr) {
            left=create_node(val);
        } else {
            left->insert(val);
        }
    } else {
        if(right==nullptr) {
            right=create_node(val);
        } else {
            right->insert(val);
        }
    }
}

int Node::height() const {
    int countleft{1},countright{1};
    if(left==nullptr) {
        return 1;
    } else {
        countleft += 1 + left->height();
    }
    if(right==nullptr) {
        return 1;
    } else {
        countright += 1 + right->height();
    }

    if(countleft>countright) {
        return countleft;
    } else {
        return countright;
    }
}

void Node::delete_childs() {
    if(is_leaf()) {
        return;
    } else {
        if(left!=nullptr) {
            left->delete_childs();
            delete left;
            left = nullptr;
        }
        if (right!=nullptr) {
            right->delete_childs();
            delete right;
            right = nullptr;
        }
    }
}

void Node::display_infixe() const {
    if(is_leaf()) {
        std::cout << value << ' ';
    } else {
        if(left!=nullptr) {
            left->display_infixe();
        }
        std::cout << value << ' ';
        if(right!=nullptr) {
            right->display_infixe();
        }
    }
}

std::vector<Node const*> Node::prefixe() const {
    std::vector<Node const*> VectNode{};
    VectNode.push_back(this);
    if(left!=nullptr) {
        std::vector<Node const*> leftVectNode  = left->prefixe();
        VectNode.insert(VectNode.end(), leftVectNode.begin(), leftVectNode.end());
    }
    if(right!=nullptr) {
        right->prefixe();
        std::vector<Node const*> rightVectNode  = right->prefixe();
        VectNode.insert(VectNode.end(), rightVectNode.begin(), rightVectNode.end());
    }
    return VectNode;
}

Node*& most_left(Node*& node) {
    if(node->is_leaf()) {
        return node;
    } else {
        return most_left(node->left);
    }
}

void delete_tree(Node* node) {
    node->delete_childs();
    delete node;
    node = nullptr;
}