#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

bool is_sorted(std::vector<float> const& vec);
void selection(std::vector<int>& vec);
void display(std::vector<float> const& vec); 
int minInVector(std::vector<float> const& vec,int i);
int valeurMediane(std::vector<int> const& vec);

size_t quick_sort_partition(std::vector<float> & vec, size_t left, size_t right);
void quick_sort(std::vector<float> & vec, size_t const left, size_t const right);
void quick_sort(std::vector<float> & vec);

std::vector<int> generate_random_vector(size_t const size, int const max = 100);
int search(std::vector<float> & vec, int const val);