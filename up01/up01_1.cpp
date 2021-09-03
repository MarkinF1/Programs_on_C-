#include <iostream>

class Sum {
private:
    long long a;
    long long b;
public:
    Sum(long long a, long long b) {
        this -> a = a;
        this -> b = b;   
    }
    Sum(Sum x, long long b) {
        this -> a = x.get();
        this -> b = b;
    }
    long long get() const {
        return this -> a + this -> b;
    }
};
