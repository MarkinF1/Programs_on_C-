#include <iostream>
#include <complex>
#include <vector>
#include <array>

namespace Equations
{
    template <typename T>
    std::pair <bool, std::vector <T>> quadratic(std::array <T, 3> v)
    {
        std::pair <bool, std::vector <T>> out;
        bool out1 = false;
        std::vector <T> out2;
        T a = v[2], b = v[1], c = v[0], chek;
        T chet = 4, dva = 2;
        if (!(a == chek && b == chek)) {
            out1 = true;
            if (a != chek) {
                T dis = std::sqrt(b * b - (chet * a * c));
                out2.push_back((-b + dis) / (dva * a));
                out2.push_back((-b - dis) / (dva * a)); 
            } else {
                a = -c / b;
                out2.push_back(a);
            } 
        } else if (c != chek) {
            out1 = true;
        }
        out.first = out1;
        out.second = out2;
        return out;
    }
}
