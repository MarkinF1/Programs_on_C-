#include <iostream>
#include <vector>
#include <cmc_complex.h>
#include <cmc_complex_stack.h>
#include <cmc_complex_eval.h>

using namespace numbers;

complex new_com(complex c, double r, double kef)
{
    return complex(c.re() + r * cos(kef), c.im() + r * sin(kef));
}

int main(int argc, char *argv[])
{
    complex c(argv[1]), sum;
    int n = atoi(argv[3]);
    double r = atof (argv[2]), part = 2 * M_PI / n;
    std::vector <std::string> vec;
    for (int i = 4; i < argc; ++i) {
        vec.push_back(argv[i]);
    }
    for (int i = 0; i < n; ++i) { 
        complex x1 = new_com(c, r, part * i), x2 = new_com(c, r, part * (i + 1));
        sum += eval(vec, (x1 + x2) / 2) * (x2 - x1);
    }
    std::cout << sum.to_string() << std::endl;
}
