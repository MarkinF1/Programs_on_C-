#include <iostream>
#include <vector>

namespace numbers
{
    complex eval(const std::vector<std::string> &args, const complex &z)
    {
        complex_stack stk;
        complex x, y;
        auto e_mas = args.end();
        for (auto b_mas = args.begin(); b_mas != e_mas; ++b_mas) {
            switch ((*b_mas)[0]) {
                case 'z':
                    stk = stk << z;
                    break;
                case '(':
                    stk = stk << complex(*b_mas);
                    break;
                case '+':
                    x = +stk;
                    stk = ~stk;
                    x += +stk;
                    stk = ~stk << x;
                    break;
                case '-':
                    x = +stk;
                    stk = ~stk;
                    x -= +stk;
                    stk = ~stk << -x;
                    break;
                case '*':
                    x = +stk;
                    stk = ~stk;
                    x *= +stk;
                    stk = ~stk << x;
                    break;
                case '/':
                    x = +stk;
                    stk = ~stk;
                    y = +stk / x;
                    stk = ~stk << y;
                    break;
                case '!':
                    stk = stk << +stk;
                    break;
                case ';':
                    stk = ~stk;
                    break;
                case '~':
                    stk = ~stk << ~(+stk);
                    break;
                case '#':
                    stk = ~stk << -(+stk);
                    break;
                default:
                    return 1;
            }
        }
        return +stk;
    }
}
