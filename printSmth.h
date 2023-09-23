#include <iostream>
#include <vector>

template<typename T>
void printVec(const std::vector<T>& s){
    for (auto el : s){
        std::cout << el << ' ';
    }
    std::cout << std::endl;
}

template<typename T>
void print2DVec(const std::vector<std::vector<T>>& s){
    for (auto el_up: s) {
        for (auto el : el_up)
            std::cout << el << ' ';
        std::cout << std::endl;
    }
}