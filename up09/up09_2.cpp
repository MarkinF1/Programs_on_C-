#include <iostream>

enum state {H, A, AB, AC, ABC, AS, ABS, ACS, ABCS, ERR};

bool chek(state CS)
{
    return (CS == AS || CS == ABS || CS == ACS || CS == ABCS);
}

int main()
{
    std::string str;
    state CS;
    while (std::cin >> str) {
        CS = H;
        size_t i = 0;
        do {
            switch (CS) {
                case H:
                case A:
                    if (str[i] == '0') {
                        ++i;
                        CS = A;
                    } else if (str[i] == '1') {
                        ++i;
                        CS = AB;
                    } else {
                        CS = ERR;
                    } 
                    break;
                case ABS:
                case AB:
                    if (str[i] == '0') {
                        ++i;
                        CS = AC;
                    } else if (str[i] == '1') {
                        ++i;
                        CS = ABC;
                    } else {
                        CS = ERR;
                    }
                    break;
                case ACS:
                case AC:
                    if (str[i] == '0') {
                        ++i;
                        CS = AS;
                    } else if (str[i] == '1') {
                        ++i;
                        CS = ABS;
                    } else {
                        CS = ERR;
                    }
                    break;
                case ABCS:
                case ABC:
                    if (str[i] == '0') {
                        ++i;
                        CS = ACS;
                    } else if (str[i] == '1') {
                        ++i;
                        CS = ABCS;
                    } else {
                        CS = ERR;
                    }
                    break;
                case AS:
                    if (str[i] == '0') {
                        ++i;
                        CS = A;
                    } else if (str[i] == '1') {
                        ++i;
                        CS = AB;
                    } else {
                        CS = ERR;
                    }
                    break;
                default:
                    CS = ERR;
            }
        } while (i < str.size() && CS != ERR);
        std::cout << chek(CS) << std::endl;
    }
}

