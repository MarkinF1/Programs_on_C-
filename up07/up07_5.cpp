#include <iostream>
#include <boost/date_time/gregorian/gregorian.hpp>

int main()
{
    boost::gregorian::date second, first;
    boost::gregorian::date_duration sum, chek;
    int year = 0, mon = 0, day = 0;
    if (std::cin >> year >> mon >> day) {
        second = boost::gregorian::date(year, -mon, -day);
    }
    while (std::cin >> year >> mon >> day) {
        first = boost::gregorian::date(year, -mon, -day);
        sum += (second - first) < chek ? (first - second) : (second - first);
        second = boost::gregorian::date(year, -mon, -day);
    }
    std::cout << sum << std::endl;
}
