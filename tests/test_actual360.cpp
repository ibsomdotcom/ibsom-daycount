#define BOOST_TEST_MODULE Actual360Test
#include <boost/test/included/unit_test.hpp>

#include "daycount/Actual360.hpp"
#include <chrono>

using namespace std::chrono;
using namespace ibsom::daycount;

BOOST_AUTO_TEST_CASE(test_days_between)
{
    Actual360 dc;
    sys_days start = 2023y/1/1;
    sys_days end   = 2023y/1/31;

    BOOST_CHECK_EQUAL(dc.daysBetween(start, end), 30);
}

BOOST_AUTO_TEST_CASE(test_year_fraction)
{
    Actual360 dc;
    sys_days start = 2023y/1/1;
    sys_days end   = 2023y/1/31;

    double expected = 30.0 / 360.0;
    BOOST_CHECK_CLOSE(dc.yearFraction(start, end), expected, 1e-10);
}
