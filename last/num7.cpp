#include <iostream>

int c;

int gc()
{
    c = getchar();
    while (isspace(c)) {
        c = getchar();
    }
    return c;
}

void ex()
{
    std::cout << 0 << std::endl;
    exit(0);
}

void A();
void B();

void S()
{
    if (c == 'a') {
        c = gc();
        A();
        if (c != 'b') {
            ex();
        }
        c = gc();
    } else if (c == 'c') {
        c = gc();
        B();
    } else {
        ex();
    }
    if (c == EOF) {
        std::cout << 1 << std::endl;
        return;
    }
    ex();
}

void A()
{
    if (c == 'c') {
        c = gc();
        A();
        if (c != 'd') {
            ex();
        }
        c = gc();
    } else if (c != 'e') {
        ex();
    } else {
        c = gc();
    }
}

void B()
{
    if (c == 'b') {
        c = gc();
        B();
    } else if (c != 'd' && c != EOF) {
        ex();
    } else {
        c = gc();
    }
}

int main()
{
    c = gc();
    S();
}

