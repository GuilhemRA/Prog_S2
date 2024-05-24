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
    char r{};
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

// size_t folding_string_ordered_hash(std::string const& s, size_t max) {

// }
