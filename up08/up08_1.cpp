#include <iostream>

int main()
{
    std::string str;
    size_t k = 0;
    while (std::cin >> str) {
        k = 0;
        while (str[k] == '3' || str[k] == '4') {
            ++k;
        }
        if (k == str.size()) {
            std::cout << 1 << std::endl;
            continue;
        } else if (str[k] != '1' && str[k] != '2') {
            std::cout << 0 << std::endl;
            continue;
        }
        while (str[k] == '1' || str[k] == '2') {
            ++k;
        }
        if (k == str.size()) {
            std::cout << 1 << std::endl;
        } else {
            std::cout << 0 << std::endl;
        }
    }
}        

