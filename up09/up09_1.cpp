/*
    Type of language - 1
    New Gramma:
    S = aAB
    A = aAB | C
    C = 0D | 0CD
    DB = BD
    0B = 0b
    bB = bb
    bD = b1
    1D = 11
*/

#include <iostream>

int main()
{
    const std::string aX = "aX";
    std::string str;
    size_t a = 0, b = 0, nul = 0, ones = 0;
    while (std::cin >> str) {
        if (str == aX) {
            std::cout << 1 << std::endl;
            continue;
        }
        a = 0;
        b = 0;
        nul = 0;
        ones = 0;
        while (a < str.size() && str[a] == 'a' && ++a) {}
        if (!a || a >= str.size()) {
            std::cout << 0 << std::endl;
            continue;
        }
        while (a + nul < str.size() && str[a + nul] == '0' && ++nul) {}
        if (!nul || a + nul >= str.size()) {
            std::cout << 0 << std::endl;
            continue;
        }
        while (a + nul + b < str.size() && str[a + nul + b] == 'b' && ++b) {}
        if (!b || a + nul + b >= str.size()) {
            std::cout << 0 << std::endl;
            continue;
        }
        while (a + nul + b + ones < str.size() && str[a + nul + b + ones] == '1' && ++ones) {}
        if (a == b && nul == ones && a + nul + b + ones == str.size()) {
            std::cout << 1 << std::endl;
        } else {
            std::cout << 0 << std::endl;
        }
    }      
}
