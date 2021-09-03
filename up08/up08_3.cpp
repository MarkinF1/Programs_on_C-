#include <iostream>

struct Test_gram
{
    int s = 0; // 0 - noone 'S'
    int s_r = 0;
    int first = 1;
};

struct Musk
{ 
    int kind1 = 23;
    int kind2 = 2;
    int kind3 = 0;
};

int main()
{
    Test_gram t;
    Musk m;
    std::string str;
    while (getline(std::cin, str)) {
        if (t.first) {
            --t.first;
        }
        //-------------------------------------------
        if (str[0] == 'S' && isspace(str[1])) {    ///
            t.s = 1;                                ///
            if (str[2] == '_') {                     ///
                ++m.kind3;                            /// - test for 'S'
                std::cout << 2 << std::endl;
                return 0;
            }                                        ///  
            continue;                               ///
        }                                          ///
        //------------------------------------------
        size_t i = 0, ne_term = 0;
        //-----------------------------------------------
        while (!isspace(str[i]) && i != str.size()) {  ///
            if (str[i] >= 'A' && str[i] <= 'Z') {       ///
                ++ne_term;                               ///
            }                                             ///
            ++i;                                           /// - test for ne_term symbol
        }                                                 ///
        if (!ne_term || i == str.size()) {               ///
            std::cout << "-1" << std::endl;             /// 
            return 0;                                  ///  
        }                                             ///   
        //---------------------------------------------
        size_t k = i + 1;                             ///
        while (!isspace(str[k]) && k != str.size()) {  ///
            if (str[k] == 'S') {                        ///    
                ++t.s_r;                                 /// - test for 'S' in right part    
            }                                           ///    
            ++k;                                       ///        
        }                                             /// 
        //------------------------------------------------------------
        if (str.size() - i - 1 - (str[str.size() - 1] == '_' ? 1 : 0) < i) { ///
            m.kind1 = 2;                                                      /// - test for 2 or 23
        }                                                                    ///
        //------------------------------------------------------------
        if (ne_term != i) {
            m.kind2 = 10;
        }
    }
    if (t.first || !t.s) {
        std::cout << "-1" << std::endl;
    } else {
        if (m.kind2 == 10) {
            std::cout << 10 << std::endl;
        } else {
            std::cout << m.kind1 << std::endl;
        }
    }
    return 0;
}
