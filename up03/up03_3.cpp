#include <vector>
#include <algorithm>
#include <fstream>

void process(const std::vector <int> &v1, std::vector <int> &v2)
{
    int siz1 = v1.size(), siz2 = v2.size();
    if (!siz1) {
        return;
    }
    std::vector <int> v3(v1);
    std::sort(v3.begin(), v3.end());
    auto end = std::unique(v3.begin(), v3.end());
    v3.resize(std::distance(v3.begin(), end));
    int i = 0;
    auto mas2_1 = v2.begin();
    auto mas2_2 = v2.begin();
    auto mas1 = v3.begin();
    for (;i < siz1; i++) {
        if (*(mas1 + i) >= 0) {
            break;
        }
    }
    int offset = 0, count = -1;
    for (;i < siz1 && count < siz2; i++) {
        while (++count < siz2 && *(mas1 + i) != count) {
            *(mas2_1++) = *(mas2_2++ + offset);
        }
        offset++;
    }
    int off;
    off = count == siz2 ? offset - 1 : offset;
    for (;count < siz2; count++) {
        *(mas2_1++) = *(mas2_2++ + offset);
    }   
    v2.resize(siz2 - off);
}
