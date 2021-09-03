#include <iostream>
namespace Game 
{
    template <class A>
    class Coord {
    public:
        typedef A value_type;
        value_type row, col;
        Coord (const Coord &X): row(X.row), col(X.col) {}
        Coord (value_type a = value_type(), value_type b = value_type()): row(a), col(b) {}
        bool operator !=(const Coord &b) const
        {
            return (row != b.row || col != b.col);
        }
        bool operator ==(const Coord &b) const
        {
            return (row == b.row && col == b.col);
        }
    };

    template <class T>
    typename T::value_type dist(const T &range, const T &p1, const T &p2)
    {
        T fst1 = p1;
        typename T::value_type sum = 0;
        while (fst1 != p2) {
            ++sum;
            if (fst1.col % 2) { // for nechet_numbers
                if (fst1.row > p2.row) {
                    --fst1.row;
                    if (fst1.col > p2.col) {
                        --fst1.col;
                    } else if (fst1.col < p2.col) {
                        ++fst1.col;
                    }
                } else {
                    if (fst1.col == p2.col) {
                        ++fst1.row;
                    } else if (fst1.col > p2.col) {
                        --fst1.col;
                    } else {
                        ++fst1.col;
                    }
                }
            } else { // for chet_numbers
                if (fst1.row < p2.row) {
                    ++fst1.row;
                    if (fst1.col < p2.col) {
                        ++fst1.col;
                    } else if (fst1.col > p2.col) {
                        --fst1.col;
                    }
                } else {
                    if (fst1.col == p2.col) {
                        --fst1.row;
                    } else if (fst1.col > p2.col) {
                        --fst1.col;
                    } else {
                        ++fst1.col;
                    }
                }
            }
        }
        return sum;
    }
}
