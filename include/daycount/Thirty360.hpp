
#pragma once

#include "DayCountConvention.hpp"

namespace ibsom::daycount
{
    using namespace std::chrono;
    /**
     * @class Thirty360
     * @brief 30/360 (Bond Basis) day count convention implementation. 
     *
     * ISDA 2006 Definitions, Section 4.16(f)
     *
     * if "30/360", "360/360", or "Bond Basis" is specified, the number of days
     * in the Calculation Period or Compounding Period in respect of which
     * payment is being made divided by 360, calculated on a formula basis as
     * follows:
     *
     * \f[
     *     \frac{360 * (Y_{2} - Y_{1}) + 30 * (M_{2} - M_{1}) + (D_{2} - D_{1})}
     *          {360}
     * \f]
     *
     * where:
     *
     * \f$Y_{1}\f$ is the year, expressed as a number, in which the first day of
     * the Calculation Period or Compounding Period falls;
     *
     * \f$Y_{2}\f$ is the year, expressed as a number, in which the day
     * immediately folowing the last day included in the Calculation Period or
     * Compounding Period falls;
     * 
     * \f$M_{1}\f$ is the calendar month, expressed as a number, in which the
     * first day of the Calculation Period or Compounding Period falls;
     * 
     * \f$M_{2}\f$ is the calendar month, expressed as number, in which the day
     * immediately following the last day included in the the Calculation Period
     * or Compounding Period falls;
     *
     * \f$D_{1}\f$ is the first calendar day, expressed as a number, of the
     * Calculation Period or Compounding Period, unless such number would be 31,
     * in which case \f$D_{1}\f$ will be 30; and
     * 
     * \f$D_{2}\f$ is the calendar day, expressed as a number, immediately
     * following the last day included in the Calculation Period or Compounding
     * Period, unless such number would be 31 and \f$D_{1}\f$ is greater than
     * 29, in which case \f$D_{2}\f$ will be 30;
     */
    class Thirty360 : public DayCountConvention
    {
    public:
        /// Calculate number of days between two dates using 30/360 (Bond Basis)
        int
        daysBetween(const sys_days& start, const sys_days& end) const override;

        /// Calculate the year fraction using 30/360 (Bond Basis)
        double
        yearFraction(const sys_days& start, const sys_days& end) const override;
    };
} // namespace ibsom::daycount
