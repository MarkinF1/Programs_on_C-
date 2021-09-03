#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <double> progonka(int n, vector <double> &A, vector <double> &B, vector <double> &C, 
    vector <double> &F, double x1, double x2, double m1, double m2, bool print = false) {
    int i = -1;
    vector <double> a, b, y;
    a.push_back(x1);
    b.push_back(m1);
    while (++i < n - 1) {
        a.push_back(B[i] / (C[i] - A[i] * a[i]));
        b.push_back((F[i] + A[i] * b[i]) / (C[i] - A[i] * a[i]));
    }
    y.push_back((m2 + x2 * b[n - 1]) / (1 - x2 * a[n - 1])); 
    while (i >= 0)
        y.push_back(a[i] * y[n - 1 - i] + b[i--]);
    std::reverse(y.begin(), y.end());
    if (print) {
        cout << "\nvector y = ";
        for (double out : y)
            cout << out << ' ';
        cout << endl;
    }
    return y;
}
int main(){}
