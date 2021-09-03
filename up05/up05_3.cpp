#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

bool comp(Figure *a, Figure *b) {
    return (a->get_square() < b->get_square());
}

int main(){
    std::vector <Figure*> vec;
    Figure *out;
    std::string str1;
    while (getline(std::cin, str1)) {
        int i = -1;
        while (isspace(str1[++i])) {}
        std::string st = str1.substr(i + 1);
        if (str1[i] == 'R') {
            out = Rectangle::make(st);
        } else if (str1[i] == 'S') {
            out = Square::make(st);
        } else {
            out = Circle::make(st);
        }
        vec.push_back(out);
    }
    if (!vec.size()) {
        return 0;
    }
    std::stable_sort(vec.begin(), vec.end(), comp);
    auto adr = vec.begin();
    std::cout << (*adr)->to_string() << std::endl;
    delete *adr;
    while (++adr != vec.end()) {
        std::cout << (*adr)->to_string() << std::endl;
        delete *adr;
    }
    return 0;
} 
