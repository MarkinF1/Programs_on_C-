#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

class String
{
    std::string str;
public:
    String (std::string x)
    {
        str = x.substr(0, x.size());
    }
    ~String ()
    {
        std::cout << str << std::endl;
    }
};

void fun ()
{
    std::string str;
    if (std::cin >> str) {
        String x(str);
        fun();
    } else {
        throw 1;
    }
}

int main()
{
    try {
        fun();
    }
    catch (int) {} 
}
