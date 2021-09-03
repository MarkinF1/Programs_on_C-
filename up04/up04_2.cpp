template <class T, class U>
T myfilter(const T &X, U func)
{
    T out;
    typename T::const_iterator b_mas = X.begin();
    typename T::const_iterator e_mas = X.end();
    typename T::iterator b_mas_out = out.end();
    while (b_mas != e_mas) {
        if (func(*b_mas)) {
            out.insert(b_mas_out, *b_mas);
        }
        b_mas_out = out.end();
        b_mas++;
    }
    return out;
}
