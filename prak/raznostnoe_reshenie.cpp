#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
    
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
    reverse(y.begin(), y.end());
    if (print) {
        cout << "\nvector y = ";
        for (double out : y)
            cout << out << ' ';
        cout << endl;
    }
    return y;
}   
     
double F (double x = 0.0, double t = 0.0) {
    return 0.0;
}    
double k (double x = 0.0) {
    return 1.0;
}   
double fi (double x = 0.0) {
    return sin(M_PI * x);
} 
double m1 (double t = 0.0) {
    return 0.0;
}    
double m2 (double t = 0.0) {
    return 0.0;
}   
double analit_reshen(double x, double t) {
    return pow(M_E, -M_PI * M_PI * t) * sin(M_PI * x);
} 
vector <vector <double>> y;

void raznost (int n, double (*F) (double x, double t), double (*k) (double x), 
    double (*fi) (double x), double (*m1) (double t), double (*m2) (double t), double sigma,              double h, double tay, double T_max)
{   
    int t = T_max / tay + 1, cost = sigma * tay / (h * h);
    y.resize(t);
    for (int i = 0; i < t; i++)
        y[i].resize(n + 1);
    vector <double> a, b, c, f;
    y[0][0] = (*m1) (0);
    y[0][n] = (*m2) (0);
    for (int i = 0; i < n - 1; i++) {
        a.push_back((cost * (*k) (i + 0.5)));
        b.push_back((cost * (*k) (i + 1.5)));
        c.push_back(a[i] + b[i] + 1.0);
        y[0][i + 1] = (*fi) (h * (i + 1));
    }
    for (int i = 1; i < t; i++) {
        for (int l = 0; l < n - 1; l++) {
            f.push_back(tay * (sigma * (*F) (h * (l + 1), tay * i) + (1 - sigma) * 
            (*F) (h * (l + 1), tay * (i - 1))) + tay * (1 - sigma) / (h * h) * (((*k) (l + 1.5) * 
            (y[i - 1][l + 2] - y[i - 1][l + 1]) -
            (*k) (l + 0.5) * (y[i - 1][l + 1] - y[i - 1][l]))) + y[i - 1][l + 1]);
        }
        y[i] = progonka(n, a, b, c, f, 0.0, 0.0, m1(i * tay), m2(i * tay));
        f.erase(f.begin(), f.end());
    }
}   
    
int main()
{     
    double sig = 0.75, h = 0.01, tay = 0.00005, T_max = 3, max = 0, count;
    int n = 100, t = T_max / tay + 1;
    raznost(n, F, k, fi, m1, m2, sig, h, tay, T_max);
    for (int i = 0; i < t; i++)
        for (int l = 0; l < n + 1; l++)
            if (abs(y[i][l] - analit_reshen(h * l, i * tay)) > max)
                max = abs(y[i][l] - analit_reshen(h * l, i * tay));
    cout << "max = " << max << endl;
}     
