#include "daycount/Thirty360.hpp"
#include <algorithm>
#include <chrono>
#include <iostream>

namespace ibsom::daycount
{
    using namespace std::chrono;

    static int
    get_day(year_month_day ymd)
    {
        return static_cast<unsigned>(ymd.day());
    }

    static int
    get_month(year_month_day ymd)
    {
        return static_cast<unsigned>(ymd.month());
    }

    static int
    get_year(year_month_day ymd)
    {
        return static_cast<int>(ymd.year());
    }

    int
    Thirty360::daysBetween(const sys_days& start, const sys_days& end) const
    {
        year_month_day d1 = year_month_day(start);
        year_month_day d2 = year_month_day(end);

        int d1_day = get_day(d1);
        int d2_day = get_day(d2);

        d1_day = std::min(d1_day, 30);

        if(d1_day > 29)
        {
            d2_day = std::min(d2_day, 30);
        }

        int days = (get_year(d2) - get_year(d1)) * 360
            + (get_month(d2) - get_month(d1)) * 30
            + (d2_day - d1_day);

        return days;
    }

    double
    Thirty360::yearFraction(const sys_days& start, const sys_days& end) const
    {
        return static_cast<double>(daysBetween(start, end)) / 360.0;
    }
} // namespace ibsom::daycount
