#include <iostream>
#include <vector>

class String
{
    char man;
    std::string str;
    std::vector <char> vec;
public:
    bool chek;
    String (char a, std::string st)
    {
        man = a;
        chek = true;
        str = st;
        size_t i = 0;
        while (i < str.size()) {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                vec.push_back(str[i]);
            }
            ++i;
        }
    }
    char get_man()
    {
        return man;
    }
    std::string get_str()
    {
        return str;
    }
    std::vector <char> get_vec() 
    {
        return vec;
    }
};

int main()
{
    char c;
    std::string str;
    std::vector <String> vec;
    std::vector <char> vec1;
    bool chek = true;
    while (std::cin >> c) {
        std::cin >> str;
        vec.push_back(String(c, str));
    }
    if (!(vec.size())) {
        return 0;
    }
    vec1.push_back('S');
    while (chek) {
        chek = false;
        for (size_t i = 0; i < vec1.size(); ++i) {
            for (size_t k = 0; k < vec.size(); ++k) {
                if (vec[k].get_man() == vec1[i] && vec[k].chek) {
                    chek = true;
                    vec[k].chek = false;
                    std::vector <char> out = vec[k].get_vec();
                    size_t size = out.size();
                    while (size) {
                        vec1.push_back(out[--size]);
                    }
                    
                }
            }
        }
    }
    for (size_t i = 0; i < vec.size() ; ++i) {
        for (size_t k = 0; k < vec1.size(); ++k) {
            if (vec[i].get_man() == vec1[k]) {
                std::cout << vec[i].get_man() << ' ' << vec[i].get_str() << std::endl;
                break;
            }
        }
    }
    return 0;
}
