#include <iostream>

struct Info
{
    int count_term;
    int count_neterm;
    int count_epsi;
    int l_r;
    bool chek_S;
    Info (std::string str)
    {
        count_term = 0;
        count_neterm = 0;
        count_epsi = 0;
        chek_S = false;
        int count = 0;
        for (size_t i = 0; i < str.size(); ++i) {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                ++count_neterm;
                if (!i) {
                    count = 1;
                } else if (count % 10 == 2) {
                    count = count * 10 + 1;
                }
                if (str[i] == 'S') {
                    chek_S = true;
                }
            } else {
                if (str[i] == '_') {
                    ++count_epsi;
                } else {
                    ++count_term;
                }
                if (!i) {
                    count = 2;
                } else if (count % 10 == 1) {
                    count = count * 10 + 2;
                }
            }
        }
        if (count == 1 || count == 2) {
            l_r = 'n';
        } else if (count == 12) {
            l_r = 'l';
        } else if (count == 21) {
            l_r = 'r';
        } else {
            l_r = 0;
        }
    }
};

int main()
{
    std::string str_l, str_r;
    bool k = true, auto1 = false, auto2 = false, auto3 = false, automat = true, 
        left = true, right = true, regular = true, no_small = true;
    while (std::cin >> str_l) {
        bool chek = false;
        std::cin >> str_r;
        Info r(str_r);
        if (str_l == "S" && r.count_epsi) {
            auto1 = true;
            chek = true;
        }
        if (str_l == "S" && r.count_neterm == 1 && !r.count_term) {
            auto2 = true;
            chek = true;
        }
        if (r.chek_S) {
            auto3 = true;
        }
        if ((str_l != "S" && r.count_epsi) || (r.count_term != 1 && !chek) || 
            r.count_neterm > 1 || r.l_r == 0) {
            automat = false;
        }
        if (r.count_neterm > 1 || !r.l_r) {
            regular = false;
        }
        if (r.l_r == 'l') {
            right = false;
        } else if (r.l_r == 'r') {
            left = false;
        } else if (r.l_r == 'n') {
        } else {
            right = false;
            left = false;
        }
        if (str_l != "S" && r.count_epsi) {
            k = false;
        }
    }
    no_small = auto1;
    if (((auto1 || auto2) && !auto3) || (!auto1 && !auto2)) {
        auto1 = true;
    } else {
        auto1 = false;
    }
    if (regular && !left && !right) {
        regular = false;
    }
    if (regular) {
        if (left) {
            std::cout << 31;
        } else if (right) {
            std::cout << 32;
        }
        if (automat && auto1) {
            std::cout << 1;
        }
    } else {
        std::cout << 2;
        if ((!no_small || !auto3) && k) {
            std::cout << 1;
        }
    }
    std::cout << std::endl;
    return 0;
}
