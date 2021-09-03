#include <iostream>

int main()
{
    int out1 = 0, out2 = 0, m = 0, n = 0, a1 = 0, b1 = 0, a2 = 0, b2 = 0;
    std::cin >> m >> n;
    while (std::cin >> a1 >> b1 >> a2 >> b2) {
        if (a1 >= m) {
            a1 %= m;
        } else if (a1 < 0) {
            a1 %= m;
            a1 += m;
        }
        if (a2 >= m) {
            a2 %= m;
        } else if (a2 < 0) {
            a2 %= m;
            a2 += m;
        }
        if (b1 >= n) {
            b1 %= n;
        } else if (b1 < 0) {
            b1 %= n;
            b1 += n;
        }
        if (b2 >= n) {
            b2 %= n;
        } else if (b2 < 0) {
            b2 %= n;
            b2 += n;
        }
        out1 = abs(a1 - a2) > m - abs(a1 - a2) ? m - abs(a1 - a2) : abs(a1 - a2);
        out2 = abs(b1 - b2) > n - abs(b1 - b2) ? n - abs(b1 - b2) : abs(b1 - b2);
        std::cout << out1 + out2 << std::endl;
    }
}
