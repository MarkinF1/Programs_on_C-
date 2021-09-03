#include <vector>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <functional>
#include <iostream>

template <typename A, typename B>
B myremove(A b_mas1, A e_mas1, B b_mas2, B e_mas2)
{   
    int siz1 = std::distance(b_mas1, e_mas1), siz2 = std::distance(b_mas2, e_mas2);
    if (!siz1) {
        return e_mas2;
    }
    std::vector <typename std::iterator_traits<A>::value_type> v3;
    while (b_mas1 != e_mas1) {
        v3.push_back(*b_mas1);
        ++b_mas1;
    }
    std::sort(v3.begin(), v3.end());
    auto end = std::unique(v3.begin(), v3.end());
    v3.resize(std::distance(v3.begin(), end));
    int i = 0;
    B mas2_1 = b_mas2;
    B mas2_2 = b_mas2;
    auto mas1 = v3.begin();
    siz1 = v3.size();
    for (;i < siz1; i++) {
        if (*(mas1++) >= 0) {
            break;
        }
    }
    mas1--;
    int offset = 0, count = -1;
    for (;i < siz1 && count < siz2; mas1++, i++) {
        while (++count < siz2 && *mas1 != count) {
            std::swap(*(mas2_1++), *(mas2_2++));
        }
        mas2_2++;
        offset++;
    }
    int off;
    off = count == siz2 ? offset - 1 : offset;
    for (;count < siz2; count++) {
        std::swap(*(mas2_1++), *(mas2_2++));
    }
    return b_mas2 + siz2 - off;
}
