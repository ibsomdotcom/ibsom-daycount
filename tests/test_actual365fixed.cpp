#include <boost/test/unit_test.hpp>

#include "daycount/Actual365Fixed.hpp"
#include <chrono>

using namespace std::chrono;
using namespace ibsom::daycount;

BOOST_AUTO_TEST_CASE(test_days_between_actual_365_fixed)
{
    Actual365Fixed dc;
    sys_days start = 2023y/1/1;
    sys_days end   = 2023y/1/31;

    BOOST_CHECK_EQUAL(dc.daysBetween(start, end), 30);
}

BOOST_AUTO_TEST_CASE(test_year_fraction_actual_365_fixed)
{
    Actual365Fixed dc;
    sys_days start = 2023y/1/1;
    sys_days end   = 2023y/1/31;

    double expected = 30.0 / 365.0;
    BOOST_CHECK_CLOSE(dc.yearFraction(start, end), expected, 1e-10);
}
