#include <iostream>

using namespace std;

class A {
private:
    static int count;
    int n;
public:
    A(){
        count++;
        cin >> n;
    }
    A(const A &a) {
        int k;
        cin >> k;
        n = a.n + k;
    }
    ~A() {
        if (count-- > 0) {
            cout << n << endl;
        }
    }
};

int A::count = 0;
