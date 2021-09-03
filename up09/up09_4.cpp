/*
    S -> AXD
    X -> AXD | BYC 
    Y -> BYC | _
    A -> a
    B -> b
    C -> c
    D -> d
*/
#include <iostream>

void X(int k, int n);
void Y(int n);
void A();
void B();
void C();
void D();

void S(int k, int n)
{
    if (!n) {
        return;
    }
    A();
    X(k - 1, --n);
    D();
    std::cout << std::endl;
    S(k, n);
}

void X(int k, int n)
{
    if (n) {
        A();
        X(k - 1, n - 1);
        D();
    } else { 
        B();
        Y(k - 1);
        C();
    }
}

void Y(int n)
{
    if (n) {
        B();
        Y(n - 1);
        C();
    }
}

void A()
{
    std::cout << 'a';
}

void B()
{
    std::cout << 'b';
}

void C()
{
    std::cout << 'c';
}

void D()
{
    std::cout << 'd';
}

int main()
{
    int k;
    std::cin >> k;
    if (k < 4 || k % 2) {
        return 0;
    }
    S(k / 2, k / 2 - 1);
}
