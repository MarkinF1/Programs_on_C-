#include <iostream>
#include <vector>

using namespace std;

void process(const vector <unsigned long long> &vec1, vector <unsigned long long> &vec2, int step)
{
    auto mas1 = vec1.begin();
    auto mas2 = vec2.rbegin();
    int size1 = vec1.size();
    int size2 = vec2.size();
    for (int i = 0; i < size2 && i * step < size1; i++) {
        *mas2 += *mas1;
        mas2++;
        mas1 += step;
    }
}
int main(){}
