#include <iostream>
#include <vector>
#include <cmath>
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
    reverse(y.begin(), y.end());
    if (print) {
        cout << "\nvector y = ";
        for (double out : y)
            cout << out << ' ';
        cout << endl;
    }
    return y;
}   

double F (double x, double t) { return 0.0; }
double k(double t) { return 1.0; }
double fi (double x) { return sin(M_PI * x); }
double m1 (double t) { return 0.0; }
double m2 (double t) { return 0.0; }
double analit_reshen (double x, double t) { return pow(M_E, -M_PI * M_PI * t) * sin(M_PI * x); }

double kvazi(int n, int S, int chas, double (*F) (double x, double t), double (*k) (double x), 
    double (*fi) (double x), double (*m1) (double t), double (*m2) (double t), double tay, double h, double t_max) {
    double max = 0.0, mdl, val = tay / (h * h);
    int t = (int) (t_max / tay) + 1;
    vector <double> a(n - 1), b(n - 1), c(n - 1), f(n - 1), res1(n + 1), res2(n + 2);
    for (int i = 0; i < n + 1; ++i) {
        res1[i] = (*fi) (i * h);
        res2[i] = res1[i];
        cout << res2[i] << ' ';
    }
    cout << endl;
    for (int i = 1; i < t; ++i) {
        for (int j = 1; j <= S; ++j) {
            for (int l = 0; l < n - 1; ++l) {
                a[l] = val * (*k) ((res2[l] + res2[i + 1]) / 2);
                b[l] = val * (*k) ((res2[l + 1] + res2[l + 2]) / 2);
                c[l] = a[l] + b[l] + 1.0;
                f[l] = res1[l + 1] + tay * ((*F) ((l + 1) * h, i * tay));
            }
            res2 = progonka(n, a, b, c, f, 0.0, 0.0, (*m1) (i * tay), (*m2) (i * tay));
        }
        res1 = res2;
        if (!(i % chas)) {
            for (int j = 0; j < n + 1; ++j)
                cout << res1[j] << ' ';
            cout << endl;
        }
    }
    return max;
}

int main() {
    double h = 0.01, tay = 0.01, t_max = 3.0;    
    int n = 100, S = 1, chas = 3, t = (int) ((t_max / tay) + 1);
    cout << kvazi(n , S, chas, F, k, fi, m1, m2, tay, h, t_max);
    return 0;

}

