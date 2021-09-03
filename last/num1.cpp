#include <iostream>
#include <vector>

void process (std::vector <uint64_t> &v, uint32_t s)
{
    std::vector <uint64_t> v1(v);
    uint64_t sum = 0;
    size_t count = 0;
    v.resize(v.size() + v.size() / s);
    for (size_t i = 0; i < v1.size(); ++i) {
        sum += v1[i];
        auto mas = v.begin();
        mas[i + count] = v1[i];
        if (i > 0 && i % s == s - 1) {
            ++count;
            mas[i + count] = sum;
        }
    }
}

int main()
{
    std::vector <uint64_t> v1 = {10,10,10,10,10,10};
    uint32_t s = 2;
    process(v1, s);
std::cout << v1.size() << std::endl;
    for (auto n : v1) {
        std::cout << n << ' ';
    }
    std::cout << std::endl;
}
