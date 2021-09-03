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
    std::reverse(y.begin(), y.end());
    if (print) {
        cout << "\nvector y = ";
        for (double out : y)
            cout << out << ' ';
        cout << endl;
    }
    return y;
}

double F(double x, double t) {
    return 0;
}

double fi (double x) {
    return cos(M_PI * x);
}

double m1(double t) {
    return cos(M_PI * t);
}

double m2(double t) {
    return -cos(M_PI * t);
}

double psi(double x) {
    return 0;
}

double analit_reshen(double x, double t) {
    return cos(M_PI * x) * cos (M_PI * t);
}

int kolebania(int n, vector <double> &last, vector <double> &pres, double (*F) (double x, double t), 
                double (*m1) (double t), double (*m2) (double t), double sig, double tay, double h, 
                int t, int per) {
    for (auto out : last)
        cout << out << ' ';
    cout << endl;
    vector <double> a(n - 1), b(n - 1), c(n - 1), f;
    a.push_back(sig * tay * tay / (h * h));
    a.insert(a.begin() + 1, n - 2, a[0]);
    b.insert(b.begin(), n - 1, a[0]);
    c.insert(c.begin(), n - 1, 2 * a[0] + 1);
    for (int i = 2; i < t; i++) {
        for (int l = 0; l < n - 1; l++)
            f.push_back(2 * pres[l + 1] - last[l + 1] + tay * tay * (*F) (h * (l + 1), (i - 1) * tay)            + sig / (h * h) * tay * tay * (last[l] - 2 * last[l + 1] + last[l + 2]) + (1 - 2 * sig)
            / (h * h) * tay * tay * (pres[l] - 2 * pres[l + 1] + pres[l + 2]));
        last = pres;
        pres = progonka(n, a, b, c, f, 0.0, 0.0, (*m1) (i * tay), (*m2) (i * tay));
        if (!(i % (int) (t / per))) {
            for (auto out : pres)
                cout << out << ' ';
            cout << endl;
        }
    }
    return 0;
}

int main() {
    int n = 100, t = 3, per = 100;
    double sig = 0, h = 0.01, tay = 0.1, max = 0;
    vector <double> last, pres(n + 1);
    for (int i = 0; i <= n; i++)
        last.push_back(fi(i * h));
    pres[0] = m1(tay);
    pres[n] = m2(tay);
    for (int i = 1; i < n; i++)
        pres.push_back(tay * (psi(i * h) + 0.5 * tay / (h * h) * (last[i - 1] - 2 * last[i] 
        + last[i + 1]) + F(i * h, 0)) + last[i]);
    kolebania(n, last, pres, F, m1, m2, sig, tay, h, t, per);

    return 0;
}
