#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int
main()
{
    long double num, last, sum = 0, sum1 = 0;
    double count = 0;
    while (cin >> num) {
        sum1 += num * num;  
        sum += num;
        count++;
    }
    last = - sum * sum / count + sum1;
    last = pow(last / count, 0.5);
    cout << fixed;
    cout << setprecision(10) << sum / count << endl;
    cout << setprecision(10) << last << endl;
}
