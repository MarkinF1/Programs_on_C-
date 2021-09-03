template <class T>
typename T::value_type process(const T &X)
{
    typename T::value_type sum = typename T::value_type();
    if (X.empty()) {
        return sum;
    }
    typename T::const_reverse_iterator e_mas = X.rbegin();
    typename T::const_reverse_iterator b_mas = X.rend();
    for (int i = 0; i < 3 && e_mas != b_mas; i++) {
        sum += *e_mas;
        ++e_mas;
        if (e_mas == b_mas) {
            break;
        }
        ++e_mas;
    } 
    return sum;
}
