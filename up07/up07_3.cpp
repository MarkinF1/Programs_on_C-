#include <iostream>
#include <utility>

class S 
{
    bool value1 = false, value2 = false, eof = true;
    int sum = 0, num = 0;
public:
    S() {
        if (scanf("%d", &num) != EOF) {
            sum += num;
            value1 = true;
        } else {
            value2 = true;
            eof = false;
        }
    }
    S(S &&X) {
        if (scanf("%d", &num) != EOF) {
            X.sum += num;
            X.value1 = true;
        } else {
            X.value2 = true;
            X.eof = false;
        }
    }
    ~S()
    {
        if (value1 && value2) {
            std::cout << sum << std::endl;
        }
    }
    explicit operator bool()  
    {
        return eof;
    }
};

using namespace std;

void func(S v) { if (v) { func(move(v)); }}
int main() { func(S()); }
