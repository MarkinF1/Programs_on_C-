#include <iostream>

enum state {S, A, B, C, D, E, F, ERR};
int c;
int gc()
{
    c = getchar();
    while (isspace(c)) {
        c = getchar();
    }
    return c;
}

int main()
{
    state CS = S;
    while (CS != F && CS != ERR) {
        c = gc();
        switch (CS) {
            case S:
                if (c == 'a') {
                    CS = A;
                } else if (c == 'b') {
                    CS = B;
                } else {
                    CS = ERR;
                }
                break;
            case A:
                if (c == 'a') {
                    CS = S;
                } else if (c == 'b') {
                    CS = D;
                } else if (c == 'c') {
                    CS = C;
                } else {
                    CS = ERR;
                }
                break;
            case B:
                if (c == 'a') {
                    CS = S;
                } else {
                    CS = ERR;
                }
                break;
            case C:
                if (c == 'a') {
                    CS = E;
                } else if (c == 'b') {
                    CS = B;
                } else {
                    CS = ERR;
                }
                break;
            case D:
                if (c == EOF) {
                    CS = F;
                } else {
                    CS = ERR;
                }
                break;
            case E:
                if (c == 'a') {
                    CS = A;
                } else if (c == 'b') {
                    CS = B;
                } else if (c == EOF) {
                    CS = F;
                } else {
                    CS = ERR;
                }
                break;
            default: {}
        }
    }
    if (CS == F) {
        std::cout << 1 << std::endl;
    } else {
        std::cout << 0 << std::endl;
    }
}
