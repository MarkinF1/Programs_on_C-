#include <iostream>

using namespace std;

class Sub {
private:
    long long a;
    long long b;
public:
    Sub(long long a, long long b = 0) {
        this -> a = a;
        this -> b = b;
    }
    Sub(Sub x, long long b) {
        this -> a = x.value();
        this -> b = b;
    }
    Sub(long long a, Sub x) {
        this -> b = x.value();
        this -> a = a;
    }
    long long value() const {
        return this -> a - this -> b;
    }
};
