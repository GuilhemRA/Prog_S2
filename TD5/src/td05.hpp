#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

size_t folding_string_hash(std::string const& s, size_t max);
size_t folding_string_ordered_hash(std::string const& s, size_t max);
size_t polynomial_rolling_hash(const std::string& s, size_t p, size_t m);

std::string random_name(size_t size);
std::vector<std::pair<std::string, float>> get_robots_fix(size_t size);
std::unordered_map<std::string, std::vector<float>> robots_fixes_map(std::vector<std::pair<std::string, float>> const& robots_fixes);
float reparations(std::vector<float>);