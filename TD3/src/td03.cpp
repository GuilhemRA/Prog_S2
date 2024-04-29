#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <iterator>
#include <cctype>

#include <stack>

#include "td03.hpp"

std::vector<std::string> split_string(std::string const& s) {
    std::istringstream in(s); // transforme une chaîne en flux de caractères, cela simule un flux comme l'est std::cin
    // l’itérateur va lire chaque element de "in", comme un flux d'entrée, chaque élément est séparé par un espace
    return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>()); 
}

bool is_floating(std::string const& s) {
    for(char n : s) {
        if(n!='.'&& !std::isdigit(n)) {
            return false;
            break;
        }
    }
    return true;
}

float npi_evaluate(std::vector<std::string> const& tokens) {
    std::stack<float> stack;
    for(std::string n : tokens) {
        if(is_floating(n)==true) {
            stack.push(std::stof(n));
        } else {
            // Je récupère l'élément en haut de la pile
            float rightOperand { stack.top() };
            // Je l'enlève de la stack (la méthode top ne fait que lire l’élément en dessus de la pile)
            stack.pop();
            // Je récupère l'élément en bas de la pile
            float leftOperand { stack.top() };
            stack.pop();

            // Il faut ensuite en fonction de l'opérateur calculer le résultat pour le remettre dans la pile
            if(n=="+") {
                float result = leftOperand + rightOperand;
                stack.push(result);
            }
            if(n[0]=='-') {
                float result = leftOperand - rightOperand;
                stack.push(result);
            }
            if(n=="*") {
                float result = leftOperand * rightOperand;
                stack.push(result);
            }
            if(n[0]=='/') {
                float result = leftOperand / rightOperand;
                stack.push(result);
            }
        }
    }

    return stack.top();
}


Token make_token(float value) {
    Token result;
    result.type = TokenType::OPERAND;
    result.value = value;
    return result;
}
Token make_token(Operator op) {
    Token result;
    result.type = TokenType::OPERATOR;
    result.op = op;
    return result;
}

std::vector<Token> tokenize(std::vector<std::string> const& words) {
    std::vector<Token> vectToken();
    for(std::string n : words) {
        vectToken.push_back(make_token(words));
    }
}