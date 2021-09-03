#include <iostream>
#include <vector>

class Way
{
    std::string cur;
    char ch;
    std::string neew;
public:
    Way (std::string s1, char s2, std::string s3): cur(s1), ch(s2), neew(s3) {}
    std::string get_cur()
    {
        return cur;
    }
    char get_ch()
    {
        return ch;
    }
    std::string get_neew()
    {
        return neew;
    }
};

int main()
{
    std::vector <Way> vec_rules;
    std::vector <std::string> vec_finih;
    std::string str1, str, state;
    char c = 0;
    int ch = 0;
    while (std::cin >> str1 && str1 != "END" && std::cin >> c && std::cin >> str) {
        vec_rules.push_back(Way(str1, c, str));
    }
    while (std::cin >> str1 && str1 != "END") {
        vec_finih.push_back(str1);
    }
    std::cin >> state;
    size_t i = 0, k = 0;
    bool chek = true;
    while ((ch = getchar())) {
        while (isspace(ch)) {
            ch = getchar();
        }
        if (ch == EOF) {
            break;
        }
        ++i;
        for (k = 0; k < vec_rules.size(); ++k) {
            if (vec_rules[k].get_ch() == ch && vec_rules[k].get_cur() == state) {
                state = vec_rules[k].get_neew();
                break;
            }
        }
        if (k == vec_rules.size()) {
            chek = false;
            break;
        }
    }
    if (!chek) {
        std::cout << 0 << std::endl << i - 1 << std::endl << state << std::endl;
    } else {
        for (k = 0; k < vec_finih.size(); ++k) {
            if (state == vec_finih[k]) {
                std::cout << 1 << std::endl << i << std::endl << state << std::endl;
                break;
            }
        }
        if (k == vec_finih.size()) {
            std::cout << 0 << std::endl << i << std::endl << state << std::endl;
        }
    }   
}
