#include <vector>
#include <iterator>
#include <functional>

template <typename A, typename B>
void myapply(A b_mas, A e_mas, B func)
{
    for (; b_mas != e_mas; ++b_mas) {
        func(*b_mas);
    }
    return;
}

template <typename A, typename B>
std::vector <std::reference_wrapper<typename std::iterator_traits<A>::value_type>>
myfilter2(A b_mas, A e_mas, B func) 
{
    std::vector <std::reference_wrapper<typename std::iterator_traits<A>::value_type>> vec;
    for (;b_mas != e_mas; ++b_mas) {
        if (func(*b_mas)) {
            vec.push_back(*b_mas);
        }
    }
    return vec;
}
