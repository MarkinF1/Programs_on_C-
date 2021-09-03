#include <iostream>

/*
    eror = 0 - constructor is correct and after it there is null
    eror = 1 - constructor is correct and after it there is space
    eror = 2 - constructor is correct and after it end of file
    eror = 3 - constructor isn't correct and we went to space
    eror = 4 - constructor isn't correct and we went to eof
    eror = 5 - constructor isn't correct because got only spaces
*/

int next(char c)
{
    while (!isspace(c) && c != EOF && (c = getchar())) {}
    return isspace(c) ? 3 : 4;
}

class St
{
    int c = 0, eror = 0, nul = 0, edi = 0;
public:
    St (int a = 0): nul(a)
    {
        if (!nul) {
            while ((c = getchar()) && isspace(c)) {}
            if (c == EOF && (eror = 5)) {
                return;
            }
            if (c != '0' && (eror = next(c))) {
                return;
            }
            ++nul;
        }
        while ((c = getchar()) == '0' && ++nul) {}
        if (c != '1' && (eror = next(c))) {
            return;
        }
        ++edi;
        while ((c = getchar()) == '1' && ++edi) {}
        if (c != EOF && c != '0' && !isspace(c) && (eror = next(c))) {
        } else if ((c == EOF && (eror = 2)) || (isspace(c) && (eror = 1))) {}
    }
    int get_eror() {
        return eror;
    }
    int get_nul() {
        return nul;
    }
    int get_edi() {
        return edi;
    }
};

void fun(int n1, int n2, int e1, int e2)
{
    if (n1 == n2 && e1 == e2) {
        std::cout << '1' << std::endl;
    } else {
        std::cout << '0' << std::endl;
    }
}

int main()
{
    while (true) {
        St head;
        switch (head.get_eror()) {
            case 0:
                while (true) {
                    int test = 0;
                    St body(1);
                    switch (body.get_eror()) {
                        case 0:
                            if (head.get_nul() == body.get_nul() && head.get_edi() == body.get_edi()){
                            } else {
                                std::cout << '0' << std::endl;
                                ++test;
                                if (next('0') == 4) {
                                    return 0;
                                }
                            }
                            break; 
                        case 1:
                            fun (head.get_nul(), body.get_nul(), head.get_edi(), body.get_edi());
                            ++test;
                            break;
                        case 2:
                            fun (head.get_nul(), body.get_nul(), head.get_edi(), body.get_edi());
                            return 0;
                        case 3:
                            ++test;
                            std::cout << '0' << std::endl;
                            break;
                        default:
                            std::cout << '0' << std::endl;
                            return 0;
                    }
                    if (test) {
                        break;
                    }
                }
                break;
            case 1: 
                std::cout << '1' << std::endl;
                break;
            case 2: 
                std::cout << '1' << std::endl;
                return 0;
            case 3: 
                std::cout << '0' << std::endl;
                break;
            case 4: 
                std::cout << '0' << std::endl;
            default: 
                return 0;
        }
    }
}

