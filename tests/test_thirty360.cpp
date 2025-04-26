#include <boost/test/data/test_case.hpp>
#include <boost/test/unit_test.hpp>

#include "daycount/Thirty360.hpp"
#include <chrono>
#include <iostream>

using namespace std::chrono;
using namespace ibsom::daycount;

struct DayCountTestCase
{
    std::chrono::year_month_day start;
    std::chrono::year_month_day end;
    int expected;
};

inline
std::ostream& operator<<(std::ostream& os, const DayCountTestCase& tc)
{
    os << "Start: "
       << static_cast<int>(tc.start.year())       << '-'
       << static_cast<unsigned>(tc.start.month()) << '-'
       << static_cast<unsigned>(tc.start.day())

       << ", End: "
       << static_cast<int>(tc.end.year())       << '-'
       << static_cast<unsigned>(tc.end.month()) << '-'
       << static_cast<unsigned>(tc.end.day())

       << ", Expected: "
       << tc.expected;

    return os;
}

/******************************************************************************
 *
 * Start Date | End Date | Adjusted Start | Adjusted End | Days | Status
 *
 * 2024 Tests - Leap Year
 * ======================
 * Start Date | End Date | Adjusted Start | Adjusted End | Days | Status
 * -----------+----------+----------------+--------------+------+-------
 * Jan 29     | Feb 28   | Jan 29         | Feb 28       | 29   | Complete
 * Jan 29     | Feb 29   | Jan 29         | Feb 29       | 30   | Complete
 * Jan 29     | Mar 1    | Jan 29         | Mar 1        | 32   | Complete
 * Jan 30     | Feb 28   | Jan 30         | Feb 28       | 28   | Complete
 * Jan 30     | Feb 29   | Jan 30         | Feb 29       | 29   | Complete
 * Jan 30     | Mar 1    | Jan 30         | Mar 1        | 31   | Complete
 * Jan 31     | Feb 28   | Jan 30         | Feb 28       | 28   | Complete
 * Jan 31     | Feb 29   | Jan 30         | Feb 29       | 29   | Complete
 * Jan 31     | Mar 1    | Jan 30         | Mar 1        | 31   | Complete
 * Feb 28     | Feb 28   | Feb 28         | Feb 28       | 0    | Complete
 * Feb 28     | Feb 29   | Feb 28         | Feb 29       | 1    | Complete
 * Feb 28     | Mar 1    | Feb 28         | Mar 1        | 3    | Complete
 * Feb 28     | Mar 30   | Feb 28         | Mar 30       | 32   | Complete
 * Feb 28     | Mar 31   | Feb 28         | Mar 31       | 33   | Complete
 * Feb 29     | Feb 29   | Feb 29         | Feb 29       | 0    | Complete
 * Feb 29     | Mar 1    | Feb 29         | Mar 1        | 2    | Complete
 * Feb 29     | Mar 30   | Feb 29         | Mar 30       | 31   | Complete
 * Feb 29     | Mar 31   | Feb 29         | Mar 31       | 32   | Complete
 * Jul 29     | Aug 30   | Jul 29         | Aug 30       | 31   | Complete
 * Jul 29     | Aug 31   | Jul 29         | Aug 31       | 32   | Complete
 * Jul 30     | Aug 30   | Jul 30         | Aug 30       | 30   | Complete
 * Jul 30     | Aug 31   | Jul 30         | Aug 30       | 30   | Complete
 * Jul 31     | Aug 30   | Jul 30         | Aug 30       | 30   | Complete
 * Jul 31     | Aug 31   | Jul 30         | Aug 30       | 30   | Complete
 *
 * 2025 Tests - Non-Leap Year
 * ==========================
 * Start Date | End Date | Adjusted Start | Adjusted End | Days | Status
 * -----------+----------+----------------+--------------+------+-------
 * Jan 29     | Feb 28   | Jan 29         | Feb 28       | 29   | Completed
 * Jan 29     | Mar 1    | Jan 29         | Mar 1        | 32   | Completed
 * Jan 30     | Feb 28   | Jan 30         | Feb 28       | 28   | Completed
 * Jan 30     | Mar 1    | Jan 30         | Mar 1        | 31   | Completed
 * Jan 31     | Feb 28   | Jan 30         | Feb 28       | 28   | Completed
 * Jan 31     | Mar 1    | Jan 30         | Mar 1        | 31   | Completed
 * Feb 28     | Feb 28   | Feb 28         | Feb 28       | 0    | Completed
 * Feb 28     | Mar 1    | Feb 28         | Mar 1        | 3    | Completed
 * Feb 28     | Mar 30   | Feb 28         | Mar 30       | 32   | Completed
 * Feb 28     | Mar 31   | Feb 28         | Mar 31       | 33   | Completed
 * Jul 29     | Aug 30   | Jul 29         | Aug 30       | 31   | Completed
 * Jul 29     | Aug 31   | Jul 29         | Aug 31       | 32   | Completed
 * Jul 30     | Aug 30   | Jul 30         | Aug 30       | 30   | Completed
 * Jul 30     | Aug 31   | Jul 30         | Aug 30       | 30   | Completed
 * Jul 31     | Aug 30   | Jul 30         | Aug 30       | 30   | Completed
 * Jul 31     | Aug 31   | Jul 30         | Aug 30       | 30   | Completed
 *
 * Non-Leap Into Leap (2023 Into 2024)
 * ===================================
 * Start Date | End Date | Adjusted Start | Adjusted End | Days | Status
 * -----------+----------+----------------+--------------+------+----------
 * Dec 29     | Jan 1    | Dec 29         | Jan 1        | 2    | Completed
 * Dec 29     | Jan 29   | Dec 29         | Jan 29       | 30   | Completed
 * Dec 29     | Jan 30   | Dec 29         | Jan 30       | 31   | Completed
 * Dec 29     | Jan 31   | Dec 29         | Jan 31       | 32   | Completed
 * Dec 30     | Jan 1    | Dec 30         | Jan 1        | 1    | Completed
 * Dec 30     | Jan 30   | Dec 30         | Jan 30       | 30   | Completed
 * Dec 30     | Jan 31   | Dec 30         | Jan 30       | 30   | Completed
 * Dec 31     | Jan 1    | Dec 30         | Jan 1        | 1    | Completed
 * Dec 31     | Jan 30   | Dec 30         | Jan 30       | 30   | Completed
 * Dec 31     | Jan 31   | Dec 30         | Jan 30       | 30   | Completed
 *
 * Leap Into Non-Leap (2024 Into 2025)
 * ===================================
 * Start Date | End Date | Adjusted Start | Adjusted End | Days | Status
 * -----------+----------+----------------+--------------+------+----------
 * Dec 29     | Jan 1    | Dec 29         | Jan 1        | 2    | Completed
 * Dec 29     | Jan 29   | Dec 29         | Jan 29       | 30   | Completed
 * Dec 29     | Jan 30   | Dec 29         | Jan 30       | 31   | Completed
 * Dec 29     | Jan 31   | Dec 29         | Jan 31       | 32   | Completed
 * Dec 30     | Jan 1    | Dec 30         | Jan 1        | 1    | Completed
 * Dec 30     | Jan 30   | Dec 30         | Jan 30       | 30   | Completed
 * Dec 30     | Jan 31   | Dec 30         | Jan 30       | 30   | Completed
 * Dec 31     | Jan 1    | Dec 30         | Jan 1        | 1    | Completed
 * Dec 31     | Jan 30   | Dec 30         | Jan 30       | 30   | Completed
 * Dec 31     | Jan 31   | Dec 30         | Jan 30       | 30   | Completed
 *
 * Non-Leap Into Non-Leap (2024 Into 2025)
 * =======================================
 * Start Date | End Date | Adjusted Start | Adjusted End | Days | Status
 * -----------+----------+----------------+--------------+------+----------
 * Dec 29     | Jan 1    | Dec 29         | Jan 1        | 2    | Completed
 * Dec 29     | Jan 29   | Dec 29         | Jan 29       | 30   | Completed
 * Dec 29     | Jan 30   | Dec 29         | Jan 30       | 31   | Completed
 * Dec 29     | Jan 31   | Dec 29         | Jan 31       | 32   | Completed
 * Dec 30     | Jan 1    | Dec 30         | Jan 1        | 1    | Completed
 * Dec 30     | Jan 30   | Dec 30         | Jan 30       | 30   | Completed
 * Dec 30     | Jan 31   | Dec 30         | Jan 30       | 30   | COmpleted
 * Dec 31     | Jan 1    | Dec 30         | Jan 1        | 1    | Completed
 * Dec 31     | Jan 30   | Dec 30         | Jan 30       | 30   | Completed
 * Dec 31     | Jan 31   | Dec 30         | Jan 30       | 30   | Completed
 *
 ******************************************************************************/

const std::vector<DayCountTestCase> testCases =
{
    /* 2024 Test Cases */
    {2024y/1/29,  2024y/2/28, 29},
    {2024y/1/29,  2024y/2/29, 30},
    {2024y/1/29,  2024y/3/1,  32},
    {2024y/1/30,  2024y/2/28, 28},
    {2024y/1/30,  2024y/2/29, 29},
    {2024y/1/30,  2024y/3/1,  31},
    {2024y/1/31,  2024y/2/28, 28},
    {2024y/1/31,  2024y/2/29, 29},
    {2024y/1/31,  2024y/3/1,  31},
    {2024y/2/28,  2024y/2/28,  0},
    {2024y/2/28,  2024y/2/29,  1},
    {2024y/2/28,  2024y/3/1,   3},
    {2024y/2/28,  2024y/3/30, 32},
    {2024y/2/28,  2024y/3/31, 33},
    {2024y/2/29,  2024y/2/29,  0},
    {2024y/2/29,  2024y/3/1,   2},
    {2024y/2/29,  2024y/3/30, 31},
    {2024y/2/29,  2024y/3/31, 32},
    {2024y/7/29,  2024y/8/30, 31},
    {2024y/7/29,  2024y/8/31, 32},
    {2024y/7/30,  2024y/8/30, 30},
    {2024y/7/30,  2024y/8/31, 30},
    {2024y/7/31,  2024y/8/30, 30},
    {2024y/7/31,  2024y/8/31, 30},

    /* 2025 Test Cases */
    {2025y/1/29,  2025y/2/28, 29},
    {2025y/1/29,  2025y/3/1,  32},
    {2025y/1/30,  2025y/2/28, 28},
    {2025y/1/30,  2025y/3/1,  31},
    {2025y/1/31,  2025y/2/28, 28},
    {2025y/1/31,  2025y/3/1,  31},
    {2025y/2/28,  2025y/2/28,  0},
    {2025y/2/28,  2025y/3/1,   3},
    {2025y/2/28,  2025y/3/30, 32},
    {2025y/2/28,  2025y/3/31, 33},
    {2025y/7/29,  2025y/8/30, 31},
    {2025y/7/29,  2025y/8/31, 32},
    {2025y/7/30,  2025y/8/30, 30},
    {2025y/7/30,  2025y/8/31, 30},
    {2025y/7/31,  2025y/8/30, 30},
    {2025y/7/31,  2025y/8/31, 30},

    /*
     * Monthly
     * 2023 to 2024 Test Cases
     * Non-Leap Into Leap
     */
    {2023y/12/29, 2024y/1/1,   2},
    {2023y/12/29, 2024y/1/29, 30},
    {2023y/12/29, 2024y/1/30, 31},
    {2023y/12/29, 2024y/1/31, 32},
    {2023y/12/30, 2024y/1/1,   1},
    {2023y/12/30, 2024y/1/30, 30},
    {2023y/12/30, 2024y/1/31, 30},
    {2023y/12/31, 2024y/1/1,   1},
    {2023y/12/31, 2024y/1/30, 30},
    {2023y/12/31, 2024y/1/31, 30},

    /*
     * Monthly
     * 2024 to 2025 Test Cases
     * Leap Into Non-Leap
     */
    {2024y/12/29, 2025y/1/1,   2},
    {2024y/12/29, 2025y/1/29, 30},
    {2024y/12/29, 2025y/1/30, 31},
    {2024y/12/29, 2025y/1/31, 32},
    {2024y/12/30, 2025y/1/1,   1},
    {2024y/12/30, 2025y/1/30, 30},
    {2024y/12/30, 2025y/1/31, 30},
    {2024y/12/31, 2025y/1/1,   1},
    {2024y/12/31, 2025y/1/30, 30},
    {2024y/12/31, 2025y/1/31, 30},

    /*
     * Monthly
     * 2025 to 2026 Test Cases
     * Non-Leap Into Non-Leap
     */
    {2025y/12/29, 2026y/1/1,   2},
    {2025y/12/29, 2026y/1/29, 30},
    {2025y/12/29, 2026y/1/30, 31},
    {2025y/12/29, 2026y/1/31, 32},
    {2025y/12/30, 2026y/1/1,   1},
    {2025y/12/30, 2026y/1/30, 30},
    {2025y/12/30, 2026y/1/31, 30},
    {2025y/12/31, 2026y/1/1,   1},
    {2025y/12/31, 2026y/1/30, 30},
    {2025y/12/31, 2026y/1/31, 30}
};

void
check_days_between(
    const Thirty360& dc,
    const std::chrono::year_month_day& start,
    const std::chrono::year_month_day& end,
    const int expected
)
{
    int calculated = dc.daysBetween(sys_days(start), sys_days(end));
    BOOST_CHECK_EQUAL(calculated, expected);
}

void
check_year_fraction(
    const Thirty360& dc,
    const std::chrono::year_month_day& start,
    const std::chrono::year_month_day& end,
    const double expected
)
{
    double calculated = dc.yearFraction(sys_days(start), sys_days(end));
    BOOST_CHECK_CLOSE(calculated, expected, 1e-10);
}

BOOST_DATA_TEST_CASE(test_thirty_360_days_between, boost::unit_test::data::make(testCases), tc)
{
    Thirty360 dc;

    std::chrono::year_month_day start = tc.start;
    std::chrono::year_month_day end   = tc.end;
    int expected                      = tc.expected;

    check_days_between(dc, start, end, expected);
}

BOOST_DATA_TEST_CASE(test_thirty_360_year_fraction, boost::unit_test::data::make(testCases), tc)
{
    Thirty360 dc;

    std::chrono::year_month_day start = tc.start;
    std::chrono::year_month_day end   = tc.end;
    int expectedDays                  = tc.expected;

    double expected = static_cast<double>(expectedDays) / 360.0;

    check_year_fraction(dc, start, end, expected);
}
