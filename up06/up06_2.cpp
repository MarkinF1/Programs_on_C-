#include <iostream>

template <class A>
class Coord {
public:
    typedef A value_type;
    value_type row, col;
    Coord (const Coord &X): row(X.row), col(X.col) {}
    Coord (value_type a = value_type(), value_type b = value_type()): row(a), col(b) {}
    Coord balance(const Coord &X) const
    {
        return Coord(row >= 0 ? row % X.row : row % X.row + X.row, 
            col >= 0 ? col % X.col : col % X.col + X.col);
    }
};

template <class T>
typename T::value_type dist(const T &range, const T &p1, const T &p2)
{
    T fst1, fst2;
    fst1 = p1.balance(range);
    fst2 = p2.balance(range);
    typename T::value_type min_row = abs(fst1.row - fst2.row) > range.row - abs(fst1.row - fst2.row) ?
        range.row - abs(fst1.row - fst2.row) : abs(fst1.row - fst2.row);
    typename T::value_type min_col = abs(fst1.col - fst2.col) > range.col - abs(fst1.col - fst2.col) ?
        range.col - abs(fst1.col - fst2.col) : abs(fst1.col - fst2.col);
    return min_row > min_col ? min_row : min_col;
}
