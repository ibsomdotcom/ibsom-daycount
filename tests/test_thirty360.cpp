#include <boost/test/unit_test.hpp>

#include "daycount/Thirty360.hpp"
#include <chrono>

using namespace std::chrono;
using namespace ibsom::daycount;

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
 * Dec 30     | Jan 1    | Dec 30         | Jan 1        | 1    | Complete
 * Dec 30     | Jan 31   | Dec 30         | Jan 30       | 30   | Complete
 * Dec 31     | Jan 1    | Dec 30         | Jan 1        | 1    | Complete
 * Dec 31     | Jan 31   | Dec 30         | Jan 30       | 30   | Complete
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
 * Dec 30     | Jan 1    | Dec 30         | Jan 1        | 1    | Completed
 * Dec 30     | Jan 31   | Dec 30         | Jan 30       | 30   | Completed
 * Dec 31     | Jan 1    | Dec 30         | Jan 1        | 1    | Completed
 * Dec 31     | Jan 31   | Dec 30         | Jan 30       | 30   | Completed
 *
 ******************************************************************************/

/*******************************************************************************
 *
 * 2024 Tests
 *
 ******************************************************************************/

BOOST_AUTO_TEST_CASE(thirty_360_days_between_2024_jan29_feb28)
{
    Thirty360 dc;
    sys_days start = 2024y/1/29;
    sys_days end   = 2024y/2/28;
    BOOST_CHECK_EQUAL(dc.daysBetween(start, end), 29);
}

BOOST_AUTO_TEST_CASE(thirty_360_year_fraction_2024_jan29_feb28)
{
    Thirty360 dc;
    sys_days start = 2024y/1/29;
    sys_days end   = 2024y/2/28;

    double expected = 29.0 / 360.0;
    BOOST_CHECK_CLOSE(dc.yearFraction(start, end), expected, 1e-10);
}

BOOST_AUTO_TEST_CASE(thirty_360_days_between_2024_jan29_feb29)
{
    Thirty360 dc;
    sys_days start = 2024y/1/29;
    sys_days end   = 2024y/2/29;
    BOOST_CHECK_EQUAL(dc.daysBetween(start, end), 30);
}

BOOST_AUTO_TEST_CASE(thirty_360_year_fraction_2024_jan29_feb29)
{
    Thirty360 dc;
    sys_days start = 2024y/1/29;
    sys_days end   = 2024y/2/29;

    double expected = 30.0 / 360.0;
    BOOST_CHECK_CLOSE(dc.yearFraction(start, end), expected, 1e-10);
}

BOOST_AUTO_TEST_CASE(thirty_360_days_between_2024_jan29_mar1)
{
    Thirty360 dc;
    sys_days start = 2024y/1/29;
    sys_days end   = 2024y/3/1;
    BOOST_CHECK_EQUAL(dc.daysBetween(start, end), 32);
}

BOOST_AUTO_TEST_CASE(thirty_360_year_fraction_2024_jan29_mar1)
{
    Thirty360 dc;
    sys_days start = 2024y/1/29;
    sys_days end   = 2024y/3/1;

    double expected = 32.0 / 360.0;
    BOOST_CHECK_CLOSE(dc.yearFraction(start, end), expected, 1e-10);
}

BOOST_AUTO_TEST_CASE(thirty_360_days_between_2024_jan30_feb28)
{
    Thirty360 dc;
    sys_days start = 2024y/1/30;
    sys_days end   = 2024y/2/28;
    BOOST_CHECK_EQUAL(dc.daysBetween(start, end), 28);
}

BOOST_AUTO_TEST_CASE(thirty_360_year_fraction_2024_jan30_feb28)
{
    Thirty360 dc;
    sys_days start = 2024y/1/30;
    sys_days end   = 2024y/2/28;

    double expected = 28.0 / 360.0;
    BOOST_CHECK_CLOSE(dc.yearFraction(start, end), expected, 1e-10);
}

BOOST_AUTO_TEST_CASE(thirty_360_days_between_2024_jan30_feb29)
{
    Thirty360 dc;
    sys_days start = 2024y/1/30;
    sys_days end   = 2024y/2/29;
    BOOST_CHECK_EQUAL(dc.daysBetween(start, end), 29);
}

BOOST_AUTO_TEST_CASE(thirty_360_year_fraction_2024_jan30_feb29)
{
    Thirty360 dc;
    sys_days start = 2024y/1/30;
    sys_days end   = 2024y/2/29;

    double expected = 29.0 / 360.0;
    BOOST_CHECK_CLOSE(dc.yearFraction(start, end), expected, 1e-10);
}

BOOST_AUTO_TEST_CASE(thirty_360_days_between_2024_jan30_mar1)
{
    Thirty360 dc;
    sys_days start = 2024y/1/30;
    sys_days end   = 2024y/3/1;
    BOOST_CHECK_EQUAL(dc.daysBetween(start, end), 31);
}

BOOST_AUTO_TEST_CASE(thirty_360_year_fraction_2024_jan30_mar1)
{
    Thirty360 dc;
    sys_days start = 2024y/1/30;
    sys_days end   = 2024y/3/1;

    double expected = 31.0 / 360.0;
    BOOST_CHECK_CLOSE(dc.yearFraction(start, end), expected, 1e-10);
}

BOOST_AUTO_TEST_CASE(thirty_360_days_between_2024_jan31_feb28)
{
    Thirty360 dc;
    sys_days start = 2024y/1/31;
    sys_days end   = 2024y/2/28;
    BOOST_CHECK_EQUAL(dc.daysBetween(start, end), 28);
}

BOOST_AUTO_TEST_CASE(thirty_360_year_fraction_2024_jan31_feb28)
{
    Thirty360 dc;
    sys_days start = 2024y/1/31;
    sys_days end   = 2024y/2/28;

    double expected = 28.0 / 360.0;
    BOOST_CHECK_CLOSE(dc.yearFraction(start, end), expected, 1e-10);
}

BOOST_AUTO_TEST_CASE(thirty_360_days_between_2024_jan31_feb29)
{
    Thirty360 dc;
    sys_days start = 2024y/1/31;
    sys_days end   = 2024y/2/29;
    BOOST_CHECK_EQUAL(dc.daysBetween(start, end), 29);
}

BOOST_AUTO_TEST_CASE(thirty_360_year_fraction_2024_jan31_feb29)
{
    Thirty360 dc;
    sys_days start = 2024y/1/31;
    sys_days end   = 2024y/2/29;

    double expected = 29.0 / 360.0;
    BOOST_CHECK_CLOSE(dc.yearFraction(start, end), expected, 1e-10);
}

BOOST_AUTO_TEST_CASE(thirty_360_days_between_2024_jan31_mar1)
{
    Thirty360 dc;
    sys_days start = 2024y/1/31;
    sys_days end   = 2024y/3/1;
    BOOST_CHECK_EQUAL(dc.daysBetween(start, end), 31);
}

BOOST_AUTO_TEST_CASE(thirty_360_year_fraction_2024_jan31_mar1)
{
    Thirty360 dc;
    sys_days start = 2024y/1/31;
    sys_days end   = 2024y/3/1;

    double expected = 31.0 / 360.0;
    BOOST_CHECK_CLOSE(dc.yearFraction(start, end), expected, 1e-10);
}

BOOST_AUTO_TEST_CASE(thirty_360_days_between_2024_feb28_feb28)
{
    Thirty360 dc;
    sys_days start = 2024y/2/28;
    sys_days end   = 2024y/2/28;

    BOOST_CHECK_EQUAL(dc.daysBetween(start, end), 0);
}

BOOST_AUTO_TEST_CASE(thirty_360_year_fraction_2024_feb28_feb28)
{
    Thirty360 dc;
    sys_days start = 2024y/2/28;
    sys_days end   = 2024y/2/28;

    double expected = 0.0 / 360.0;
    BOOST_CHECK_CLOSE(dc.yearFraction(start, end), expected, 1e-10);
}

BOOST_AUTO_TEST_CASE(thirty_360_days_between_2024_feb28_feb29)
{
    Thirty360 dc;
    sys_days start = 2024y/2/28;
    sys_days end   = 2024y/2/29;

    BOOST_CHECK_EQUAL(dc.daysBetween(start, end), 1);
}

BOOST_AUTO_TEST_CASE(thirty_360_year_fraction_2024_feb28_feb29)
{
    Thirty360 dc;
    sys_days start = 2024y/2/28;
    sys_days end   = 2024y/2/29;

    double expected = 1.0 / 360.0;
    BOOST_CHECK_CLOSE(dc.yearFraction(start, end), expected, 1e-10);
}

BOOST_AUTO_TEST_CASE(thirty_360_days_between_2024_feb28_mar1)
{
    Thirty360 dc;
    sys_days start = 2024y/2/28;
    sys_days end   = 2024y/3/1;

    BOOST_CHECK_EQUAL(dc.daysBetween(start, end), 3);
}

BOOST_AUTO_TEST_CASE(thirty_360_year_fraction_2024_feb28_mar1)
{
    Thirty360 dc;
    sys_days start = 2024y/2/28;
    sys_days end   = 2024y/3/1;

    double expected = 3.0 / 360.0;
    BOOST_CHECK_CLOSE(dc.yearFraction(start, end), expected, 1e-10);
}

BOOST_AUTO_TEST_CASE(thirty_360_days_between_2024_feb28_mar30)
{
    Thirty360 dc;
    sys_days start = 2024y/2/28;
    sys_days end   = 2024y/3/30;

    BOOST_CHECK_EQUAL(dc.daysBetween(start, end), 32);
}

BOOST_AUTO_TEST_CASE(thirty_360_year_fraction_2024_feb28_mar30)
{
    Thirty360 dc;
    sys_days start = 2024y/2/28;
    sys_days end   = 2024y/3/30;

    double expected = 32.0 / 360.0;
    BOOST_CHECK_CLOSE(dc.yearFraction(start, end), expected, 1e-10);
}

BOOST_AUTO_TEST_CASE(thirty_360_days_between_2024_feb28_mar31)
{
    Thirty360 dc;
    sys_days start = 2024y/2/28;
    sys_days end   = 2024y/3/31;

    BOOST_CHECK_EQUAL(dc.daysBetween(start, end), 33);
}

BOOST_AUTO_TEST_CASE(thirty_360_year_fraction_2024_feb28_mar31)
{
    Thirty360 dc;
    sys_days start = 2024y/2/28;
    sys_days end   = 2024y/3/31;

    double expected = 33.0 / 360.0;
    BOOST_CHECK_CLOSE(dc.yearFraction(start, end), expected, 1e-10);
}

BOOST_AUTO_TEST_CASE(thirty_360_days_between_2024_feb29_feb29)
{
    Thirty360 dc;
    sys_days start = 2024y/2/29;
    sys_days end   = 2024y/2/29;

    BOOST_CHECK_EQUAL(dc.daysBetween(start, end), 0);
}

BOOST_AUTO_TEST_CASE(thirty_360_year_fraction_2024_feb29_feb29)
{
    Thirty360 dc;
    sys_days start = 2024y/2/29;
    sys_days end   = 2024y/2/29;

    double expected = 0.0 / 360.0;
    BOOST_CHECK_CLOSE(dc.yearFraction(start, end), expected, 1e-10);
}

BOOST_AUTO_TEST_CASE(thirty_360_days_between_2024_feb29_mar1)
{
    Thirty360 dc;
    sys_days start = 2024y/2/29;
    sys_days end   = 2024y/3/1;

    BOOST_CHECK_EQUAL(dc.daysBetween(start, end), 2);
}

BOOST_AUTO_TEST_CASE(thirty_360_year_fraction_2024_feb29_mar1)
{
    Thirty360 dc;
    sys_days start = 2024y/2/29;
    sys_days end   = 2024y/3/1;

    double expected = 2.0 / 360.0;
    BOOST_CHECK_CLOSE(dc.yearFraction(start, end), expected, 1e-10);
}

BOOST_AUTO_TEST_CASE(thirty_360_days_between_2024_feb29_mar30)
{
    Thirty360 dc;
    sys_days start = 2024y/2/29;
    sys_days end   = 2024y/3/30;

    BOOST_CHECK_EQUAL(dc.daysBetween(start, end), 31);
}

BOOST_AUTO_TEST_CASE(thirty_360_year_fraction_2024_feb29_mar30)
{
    Thirty360 dc;
    sys_days start = 2024y/2/29;
    sys_days end   = 2024y/3/30;

    double expected = 31.0 / 360.0;
    BOOST_CHECK_CLOSE(dc.yearFraction(start, end), expected, 1e-10);
}

BOOST_AUTO_TEST_CASE(thirty_360_days_between_2024_feb29_mar31)
{
    Thirty360 dc;
    sys_days start = 2024y/2/29;
    sys_days end   = 2024y/3/31;

    BOOST_CHECK_EQUAL(dc.daysBetween(start, end), 32);
}

BOOST_AUTO_TEST_CASE(thirty_360_year_fraction_2024_feb29_mar31)
{
    Thirty360 dc;
    sys_days start = 2024y/2/29;
    sys_days end   = 2024y/3/31;

    double expected = 32.0 / 360.0;
    BOOST_CHECK_CLOSE(dc.yearFraction(start, end), expected, 1e-10);
}

BOOST_AUTO_TEST_CASE(thirty_360_days_between_2024_jul29_aug30)
{
    Thirty360 dc;
    sys_days start = 2024y/7/29;
    sys_days end   = 2024y/8/30;

    BOOST_CHECK_EQUAL(dc.daysBetween(start, end), 31);
}

BOOST_AUTO_TEST_CASE(thirty_360_year_fraction_2024_jul29_aug30)
{
    Thirty360 dc;
    sys_days start = 2024y/7/29;
    sys_days end   = 2024y/8/30;

    double expected = 31.0 / 360.0;
    BOOST_CHECK_CLOSE(dc.yearFraction(start, end), expected, 1e-10);
}

BOOST_AUTO_TEST_CASE(thirty_360_days_between_2024_jul29_aug31)
{
    Thirty360 dc;
    sys_days start = 2024y/7/29;
    sys_days end   = 2024y/8/31;

    BOOST_CHECK_EQUAL(dc.daysBetween(start, end), 32);
}

BOOST_AUTO_TEST_CASE(thirty_360_year_fraction_2024_jul29_aug31)
{
    Thirty360 dc;
    sys_days start = 2024y/7/29;
    sys_days end   = 2024y/8/31;

    double expected = 32.0 / 360.0;
    BOOST_CHECK_CLOSE(dc.yearFraction(start, end), expected, 1e-10);
}

BOOST_AUTO_TEST_CASE(thirty_360_days_between_2024_jul30_aug30)
{
    Thirty360 dc;
    sys_days start = 2024y/7/30;
    sys_days end   = 2024y/8/30;

    BOOST_CHECK_EQUAL(dc.daysBetween(start, end), 30);
}

BOOST_AUTO_TEST_CASE(thirty_360_year_fraction_2024_jul30_aug30)
{
    Thirty360 dc;
    sys_days start = 2024y/7/30;
    sys_days end   = 2024y/8/30;

    double expected = 30.0 / 360.0;
    BOOST_CHECK_CLOSE(dc.yearFraction(start, end), expected, 1e-10);
}

BOOST_AUTO_TEST_CASE(thirty_360_days_between_2024_jul30_aug31)
{
    Thirty360 dc;
    sys_days start = 2024y/7/30;
    sys_days end   = 2024y/8/31;

    BOOST_CHECK_EQUAL(dc.daysBetween(start, end), 30);
}

BOOST_AUTO_TEST_CASE(thirty_360_year_fraction_2024_jul30_aug31)
{
    Thirty360 dc;
    sys_days start = 2024y/7/30;
    sys_days end   = 2024y/8/31;

    double expected = 30.0 / 360.0;
    BOOST_CHECK_CLOSE(dc.yearFraction(start, end), expected, 1e-10);
}

BOOST_AUTO_TEST_CASE(thirty_360_days_between_2024_jul31_aug30)
{
    Thirty360 dc;
    sys_days start = 2024y/7/31;
    sys_days end   = 2024y/8/30;

    BOOST_CHECK_EQUAL(dc.daysBetween(start, end), 30);
}

BOOST_AUTO_TEST_CASE(thirty_360_year_fraction_2024_jul31_aug30)
{
    Thirty360 dc;
    sys_days start = 2024y/7/31;
    sys_days end   = 2024y/8/30;

    double expected = 30.0 / 360.0;
    BOOST_CHECK_CLOSE(dc.yearFraction(start, end), expected, 1e-10);
}

BOOST_AUTO_TEST_CASE(thirty_360_days_between_2024_jul31_aug31)
{
    Thirty360 dc;
    sys_days start = 2024y/7/31;
    sys_days end   = 2024y/8/31;

    BOOST_CHECK_EQUAL(dc.daysBetween(start, end), 30);
}

BOOST_AUTO_TEST_CASE(thirty_360_year_fraction_2024_jul31_aug31)
{
    Thirty360 dc;
    sys_days start = 2024y/7/31;
    sys_days end   = 2024y/8/31;

    double expected = 30.0 / 360.0;
    BOOST_CHECK_CLOSE(dc.yearFraction(start, end), expected, 1e-10);
}

BOOST_AUTO_TEST_CASE(thirty_360_days_between_2024_dec30_jan1)
{
    Thirty360 dc;
    sys_days start = 2024y/12/30;
    sys_days end   = 2025y/1/1;

    BOOST_CHECK_EQUAL(dc.daysBetween(start, end), 1);
}

BOOST_AUTO_TEST_CASE(thirty_360_year_fraction_2024_dec30_jan1)
{
    Thirty360 dc;
    sys_days start = 2024y/12/30;
    sys_days end   = 2025y/1/1;

    double expected = 1.0 / 360.0;
    BOOST_CHECK_CLOSE(dc.yearFraction(start, end), expected, 1e-10);
}

BOOST_AUTO_TEST_CASE(thirty_360_days_between_2024_dec30_jan31)
{
    Thirty360 dc;
    sys_days start = 2024y/12/30;
    sys_days end   = 2025y/1/31;

    BOOST_CHECK_EQUAL(dc.daysBetween(start, end), 30);
}

BOOST_AUTO_TEST_CASE(thirty_360_year_fraction_2024_dec30_jan31)
{
    Thirty360 dc;
    sys_days start = 2024y/12/30;
    sys_days end   = 2025y/1/31;

    double expected = 30.0 / 360.0;
    BOOST_CHECK_CLOSE(dc.yearFraction(start, end), expected, 1e-10);
}

BOOST_AUTO_TEST_CASE(thirty_360_days_between_2024_dec31_jan1)
{
    Thirty360 dc;
    sys_days start = 2024y/12/31;
    sys_days end   = 2025y/1/1;

    BOOST_CHECK_EQUAL(dc.daysBetween(start, end), 1);
}

BOOST_AUTO_TEST_CASE(thirty_360_year_fraction_2024_dec31_jan1)
{
    Thirty360 dc;
    sys_days start = 2024y/12/31;
    sys_days end   = 2025y/1/1;

    double expected = 1.0 / 360.0;
    BOOST_CHECK_CLOSE(dc.yearFraction(start, end), expected, 1e-10);
}

BOOST_AUTO_TEST_CASE(thirty_360_days_between_2024_dec31_jan31)
{
    Thirty360 dc;
    sys_days start = 2024y/12/31;
    sys_days end   = 2025y/1/31;

    BOOST_CHECK_EQUAL(dc.daysBetween(start, end), 30);
}

BOOST_AUTO_TEST_CASE(thirty_360_year_fraction_2024_dec31_jan31)
{
    Thirty360 dc;
    sys_days start = 2024y/12/31;
    sys_days end   = 2025y/1/31;

    double expected = 30.0 / 360.0;
    BOOST_CHECK_CLOSE(dc.yearFraction(start, end), expected, 1e-10);
}

/*******************************************************************************
 *
 * 2025 Tests
 *
 ******************************************************************************/

BOOST_AUTO_TEST_CASE(thirty_360_days_between_2025_jan29_feb28)
{
    Thirty360 dc;
    sys_days start = 2025y/1/29;
    sys_days end   = 2025y/2/28;
    BOOST_CHECK_EQUAL(dc.daysBetween(start, end), 29);
}

BOOST_AUTO_TEST_CASE(thirty_360_year_fraction_2025_jan29_feb28)
{
    Thirty360 dc;
    sys_days start = 2025y/1/29;
    sys_days end   = 2025y/2/28;

    double expected = 29.0 / 360.0;
    BOOST_CHECK_CLOSE(dc.yearFraction(start, end), expected, 1e-10);
}

BOOST_AUTO_TEST_CASE(thirty_360_days_between_2025_jan29_mar1)
{
    Thirty360 dc;
    sys_days start = 2025y/1/29;
    sys_days end   = 2025y/3/1;
    BOOST_CHECK_EQUAL(dc.daysBetween(start, end), 32);
}

BOOST_AUTO_TEST_CASE(thirty_360_year_fraction_2025_jan29_mar1)
{
    Thirty360 dc;
    sys_days start = 2025y/1/29;
    sys_days end   = 2025y/3/1;

    double expected = 32.0 / 360.0;
    BOOST_CHECK_CLOSE(dc.yearFraction(start, end), expected, 1e-10);
}

BOOST_AUTO_TEST_CASE(thirty_360_days_between_2025_jan30_feb28)
{
    Thirty360 dc;
    sys_days start = 2025y/1/30;
    sys_days end   = 2025y/2/28;
    BOOST_CHECK_EQUAL(dc.daysBetween(start, end), 28);
}

BOOST_AUTO_TEST_CASE(thirty_360_year_fraction_2025_jan30_feb28)
{
    Thirty360 dc;
    sys_days start = 2025y/1/30;
    sys_days end   = 2025y/2/28;

    double expected = 28.0 / 360.0;
    BOOST_CHECK_CLOSE(dc.yearFraction(start, end), expected, 1e-10);
}

BOOST_AUTO_TEST_CASE(thirty_360_days_between_2025_jan30_mar1)
{
    Thirty360 dc;
    sys_days start = 2025y/1/30;
    sys_days end   = 2025y/3/1;
    BOOST_CHECK_EQUAL(dc.daysBetween(start, end), 31);
}

BOOST_AUTO_TEST_CASE(thirty_360_year_fraction_2025_jan30_mar1)
{
    Thirty360 dc;
    sys_days start = 2025y/1/30;
    sys_days end   = 2025y/3/1;

    double expected = 31.0 / 360.0;
    BOOST_CHECK_CLOSE(dc.yearFraction(start, end), expected, 1e-10);
}

BOOST_AUTO_TEST_CASE(thirty_360_days_between_2025_jan31_feb28)
{
    Thirty360 dc;
    sys_days start = 2025y/1/31;
    sys_days end   = 2025y/2/28;
    BOOST_CHECK_EQUAL(dc.daysBetween(start, end), 28);
}

BOOST_AUTO_TEST_CASE(thirty_360_year_fraction_2025_jan31_feb28)
{
    Thirty360 dc;
    sys_days start = 2025y/1/31;
    sys_days end   = 2025y/2/28;

    double expected = 28.0 / 360.0;
    BOOST_CHECK_CLOSE(dc.yearFraction(start, end), expected, 1e-10);
}

BOOST_AUTO_TEST_CASE(thirty_360_days_between_2025_jan31_mar1)
{
    Thirty360 dc;
    sys_days start = 2025y/1/31;
    sys_days end   = 2025y/3/1;
    BOOST_CHECK_EQUAL(dc.daysBetween(start, end), 31);
}

BOOST_AUTO_TEST_CASE(thirty_360_year_fraction_2025_jan31_mar1)
{
    Thirty360 dc;
    sys_days start = 2025y/1/31;
    sys_days end   = 2025y/3/1;

    double expected = 31.0 / 360.0;
    BOOST_CHECK_CLOSE(dc.yearFraction(start, end), expected, 1e-10);
}

BOOST_AUTO_TEST_CASE(thirty_360_days_between_2025_feb28_feb28)
{
    Thirty360 dc;
    sys_days start = 2025y/2/28;
    sys_days end   = 2025y/2/28;

    BOOST_CHECK_EQUAL(dc.daysBetween(start, end), 0);
}

BOOST_AUTO_TEST_CASE(thirty_360_year_fraction_2025_feb28_feb28)
{
    Thirty360 dc;
    sys_days start = 2025y/2/28;
    sys_days end   = 2025y/2/28;

    double expected = 0.0 / 360.0;
    BOOST_CHECK_CLOSE(dc.yearFraction(start, end), expected, 1e-10);
}

BOOST_AUTO_TEST_CASE(thirty_360_days_between_2025_feb28_mar1)
{
    Thirty360 dc;
    sys_days start = 2025y/2/28;
    sys_days end   = 2025y/3/1;

    BOOST_CHECK_EQUAL(dc.daysBetween(start, end), 3);
}

BOOST_AUTO_TEST_CASE(thirty_360_year_fraction_2025_feb28_mar1)
{
    Thirty360 dc;
    sys_days start = 2025y/2/28;
    sys_days end   = 2025y/3/1;

    double expected = 3.0 / 360.0;
    BOOST_CHECK_CLOSE(dc.yearFraction(start, end), expected, 1e-10);
}

BOOST_AUTO_TEST_CASE(thirty_360_days_between_2025_feb28_mar30)
{
    Thirty360 dc;
    sys_days start = 2025y/2/28;
    sys_days end   = 2025y/3/30;

    BOOST_CHECK_EQUAL(dc.daysBetween(start, end), 32);
}

BOOST_AUTO_TEST_CASE(thirty_360_year_fraction_2025_feb28_mar30)
{
    Thirty360 dc;
    sys_days start = 2025y/2/28;
    sys_days end   = 2025y/3/30;

    double expected = 32.0 / 360.0;
    BOOST_CHECK_CLOSE(dc.yearFraction(start, end), expected, 1e-10);
}

BOOST_AUTO_TEST_CASE(thirty_360_days_between_2025_feb28_mar31)
{
    Thirty360 dc;
    sys_days start = 2025y/2/28;
    sys_days end   = 2025y/3/31;

    BOOST_CHECK_EQUAL(dc.daysBetween(start, end), 33);
}

BOOST_AUTO_TEST_CASE(thirty_360_year_fraction_2025_feb28_mar31)
{
    Thirty360 dc;
    sys_days start = 2025y/2/28;
    sys_days end   = 2025y/3/31;

    double expected = 33.0 / 360.0;
    BOOST_CHECK_CLOSE(dc.yearFraction(start, end), expected, 1e-10);
}

BOOST_AUTO_TEST_CASE(thirty_360_days_between_2025_jul29_aug30)
{
    Thirty360 dc;
    sys_days start = 2025y/7/29;
    sys_days end   = 2025y/8/30;

    BOOST_CHECK_EQUAL(dc.daysBetween(start, end), 31);
}

BOOST_AUTO_TEST_CASE(thirty_360_year_fraction_2025_jul29_aug30)
{
    Thirty360 dc;
    sys_days start = 2025y/7/29;
    sys_days end   = 2025y/8/30;

    double expected = 31.0 / 360.0;
    BOOST_CHECK_CLOSE(dc.yearFraction(start, end), expected, 1e-10);
}

BOOST_AUTO_TEST_CASE(thirty_360_days_between_2025_jul29_aug31)
{
    Thirty360 dc;
    sys_days start = 2025y/7/29;
    sys_days end   = 2025y/8/31;

    BOOST_CHECK_EQUAL(dc.daysBetween(start, end), 32);
}

BOOST_AUTO_TEST_CASE(thirty_360_year_fraction_2025_jul29_aug31)
{
    Thirty360 dc;
    sys_days start = 2025y/7/29;
    sys_days end   = 2025y/8/31;

    double expected = 32.0 / 360.0;
    BOOST_CHECK_CLOSE(dc.yearFraction(start, end), expected, 1e-10);
}

BOOST_AUTO_TEST_CASE(thirty_360_days_between_2025_jul30_aug30)
{
    Thirty360 dc;
    sys_days start = 2025y/7/30;
    sys_days end   = 2025y/8/30;

    BOOST_CHECK_EQUAL(dc.daysBetween(start, end), 30);
}

BOOST_AUTO_TEST_CASE(thirty_360_year_fraction_2025_jul30_aug30)
{
    Thirty360 dc;
    sys_days start = 2025y/7/30;
    sys_days end   = 2025y/8/30;

    double expected = 30.0 / 360.0;
    BOOST_CHECK_CLOSE(dc.yearFraction(start, end), expected, 1e-10);
}

BOOST_AUTO_TEST_CASE(thirty_360_days_between_2025_jul30_aug31)
{
    Thirty360 dc;
    sys_days start = 2025y/7/30;
    sys_days end   = 2025y/8/31;

    BOOST_CHECK_EQUAL(dc.daysBetween(start, end), 30);
}

BOOST_AUTO_TEST_CASE(thirty_360_year_fraction_2025_jul30_aug31)
{
    Thirty360 dc;
    sys_days start = 2025y/7/30;
    sys_days end   = 2025y/8/31;

    double expected = 30.0 / 360.0;
    BOOST_CHECK_CLOSE(dc.yearFraction(start, end), expected, 1e-10);
}

BOOST_AUTO_TEST_CASE(thirty_360_days_between_2025_jul31_aug30)
{
    Thirty360 dc;
    sys_days start = 2025y/7/31;
    sys_days end   = 2025y/8/30;

    BOOST_CHECK_EQUAL(dc.daysBetween(start, end), 30);
}

BOOST_AUTO_TEST_CASE(thirty_360_year_fraction_2025_jul31_aug30)
{
    Thirty360 dc;
    sys_days start = 2025y/7/31;
    sys_days end   = 2025y/8/30;

    double expected = 30.0 / 360.0;
    BOOST_CHECK_CLOSE(dc.yearFraction(start, end), expected, 1e-10);
}

BOOST_AUTO_TEST_CASE(thirty_360_days_between_2025_jul31_aug31)
{
    Thirty360 dc;
    sys_days start = 2025y/7/31;
    sys_days end   = 2025y/8/31;

    BOOST_CHECK_EQUAL(dc.daysBetween(start, end), 30);
}

BOOST_AUTO_TEST_CASE(thirty_360_year_fraction_2025_jul31_aug31)
{
    Thirty360 dc;
    sys_days start = 2025y/7/31;
    sys_days end   = 2025y/8/31;

    double expected = 30.0 / 360.0;
    BOOST_CHECK_CLOSE(dc.yearFraction(start, end), expected, 1e-10);
}

BOOST_AUTO_TEST_CASE(thirty_360_days_between_2025_dec30_jan1)
{
    Thirty360 dc;
    sys_days start = 2025y/12/30;
    sys_days end   = 2026y/1/1;

    BOOST_CHECK_EQUAL(dc.daysBetween(start, end), 1);
}

BOOST_AUTO_TEST_CASE(thirty_360_year_fraction_2025_dec30_jan1)
{
    Thirty360 dc;
    sys_days start = 2025y/12/30;
    sys_days end   = 2026y/1/1;

    double expected = 1.0 / 360.0;
    BOOST_CHECK_CLOSE(dc.yearFraction(start, end), expected, 1e-10);
}

BOOST_AUTO_TEST_CASE(thirty_360_days_between_2025_dec30_jan31)
{
    Thirty360 dc;
    sys_days start = 2025y/12/30;
    sys_days end   = 2026y/1/31;

    BOOST_CHECK_EQUAL(dc.daysBetween(start, end), 30);
}

BOOST_AUTO_TEST_CASE(thirty_360_year_fraction_2025_dec30_jan31)
{
    Thirty360 dc;
    sys_days start = 2025y/12/30;
    sys_days end   = 2026y/1/31;

    double expected = 30.0 / 360.0;
    BOOST_CHECK_CLOSE(dc.yearFraction(start, end), expected, 1e-10);
}

BOOST_AUTO_TEST_CASE(thirty_360_days_between_2025_dec31_jan1)
{
    Thirty360 dc;
    sys_days start = 2025y/12/31;
    sys_days end   = 2026y/1/1;

    BOOST_CHECK_EQUAL(dc.daysBetween(start, end), 1);
}

BOOST_AUTO_TEST_CASE(thirty_360_year_fraction_2025_dec31_jan1)
{
    Thirty360 dc;
    sys_days start = 2025y/12/31;
    sys_days end   = 2026y/1/1;

    double expected = 1.0 / 360.0;
    BOOST_CHECK_CLOSE(dc.yearFraction(start, end), expected, 1e-10);
}

BOOST_AUTO_TEST_CASE(thirty_360_days_between_2025_dec31_jan31)
{
    Thirty360 dc;
    sys_days start = 2025y/12/31;
    sys_days end   = 2026y/1/31;

    BOOST_CHECK_EQUAL(dc.daysBetween(start, end), 30);
}

BOOST_AUTO_TEST_CASE(thirty_360_year_fraction_2025_dec31_jan31)
{
    Thirty360 dc;
    sys_days start = 2025y/12/31;
    sys_days end   = 2026y/1/31;

    double expected = 30.0 / 360.0;
    BOOST_CHECK_CLOSE(dc.yearFraction(start, end), expected, 1e-10);
}

