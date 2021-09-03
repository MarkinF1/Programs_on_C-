#include <iostream>

class Result
{
    int number;
    long long res;
public:
    Result (int n = 0, long long r = 0): number(n), res(r) {}
    Result (const Result &X) 
    {
        this->number = X.number;
        this->res = X.res;
    }
    int get_num() const
    {
        return number;
    }
    long long get_res() const
    {
        return res;
    }
};

long long func(long long a, long long b, unsigned k)
{
    Result out;
    if (k == 0) {
        out = Result(1, a + b);
    } else if (k > 0 && b == 1) {
        out = Result(2, a);
    } else if (k > 0 && b > 1) {
        try {
            func(a, b - 1, k);
        }
        catch (Result y) {
            out = Result(3,func(a, y.get_res(), k - 1));
        }
    }
    throw out;
}

int main()
{
    long long a, b;
    unsigned k;
    while (std::cin >> a >> b >> k) {
        try {
            func(a, b, k);
        }
        catch (Result out) {
            std::cout << out.get_res() << std::endl;
        }
    }
}
