#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

struct X
{
    double sum = 0;
    int count = 0;
    void operator()(double k)
    {
        sum += k;
        count++;
    }
};

int 
main()
{
    std::vector <double> vec;
    double num = 0;
    int count = 0; 
    while (std::cin >> num) {
        count++;
        vec.push_back(num);
    }
    std::sort(vec.begin() + count / 10, vec.end() - count / 10);
    X dec = std::for_each(vec.begin() + count * 18 / 100, vec.end() - count * 18 / 100, X());
    std::cout << std::setprecision(10) << dec.sum / dec.count << std::endl;
}
