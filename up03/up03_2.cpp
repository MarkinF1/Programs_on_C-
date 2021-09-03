#include <vector>

using namespace std;

void process(vector <long long> &vec, long long line)
{
    int siz = vec.size(), count = 0;
    vec.resize(2 * siz);
    auto mas = vec.rbegin();
    auto mas1 = vec.begin();
    mas += siz;
    for (int i = 0; i < siz; i++) {
        if (*mas >= line) {
            *(mas1 + siz + count++) = *mas;
        }
        mas++;
    }
    vec.resize(siz + count);
}
