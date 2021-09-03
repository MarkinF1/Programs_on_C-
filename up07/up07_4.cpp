#include <iostream>

/*
    v:
        0 - 'S'
        1 - 'A'
        2 - 'B'
        3 - 'C'
        4 - 'D'
*/

/*
    n:
        0 - '0'
        1 - '1'
        2 - '#'
*/

struct VALS
{
    int val = 0;
    int way = 0;
};

struct VALS fun(int v, char n)
{
    VALS obj;
    if (n == '#') {
        n = 2;
    }
    switch (v) {
        case 0:
            switch (n) {
                case '0':
                    ++obj.way;
                    break;
                case '1':
                    ++obj.val;
                    ++obj.way;
                    break;
                default:
                    ++obj.way;
                    break;
            }
            break;
        case 1:
            switch (n) {
                case '0':
                    ++obj.val;
                    ++obj.way;
                    break;
                case '1':
                    ++obj.way;
                    break;
                default:
                    obj.val = 2;
                    --obj.way;
            }
            break;
        case 2:
            switch (n) {
                case '0':
                case '1':
                    obj.val = 2;
                    --obj.way;
                    break;
                default:
                    obj.val = 3;
                    ++obj.way;
            }
            break;
        default:
            switch (n) {
                case '0':
                    obj.val = 3;
                    ++obj.way;
                    break;
                default:
                    obj.val = -1;
            }
    }
    return obj;    
}

int main()
{
    std::string str;
    while (std::cin >> str) {
        int i = 0;
        VALS x;
        while (i > -1 && i < (int) str.size()) {
            x = fun(x.val, str[i]);
            if (x.way == 1) {
                ++i;
            } else if (x.way == -1) {
                --i;
            } else {
                if (x.val == -1) {
                    str[i] = '0';
                }
                break;
            }
        }
        std::cout << str << std::endl;
    }
}
