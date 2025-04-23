/// @file Actual365Fixed.hpp
/// @brief Implementation of Actual / 365 day count convention.

#pragma once

#include "DayCountConvention.hpp"

namespace ibsom::daycount
{
    /// @class Actual365Fixed
    /// @brief Calculates day count and year fraction using Actual / 365
    class Actual365Fixed : public DayCountConvention
    {
    public:
        /// Calculate the number of calendar days between two dates.
        int
        daysBetween(
            const std::chrono::sys_days& start,
            const std::chrono::sys_days& end) const override;

        /// Calculate the year fraction using Actual / 365 (Fixed)
        double
        yearFraction(
            const std::chrono::sys_days& start,
            const std::chrono::sys_days& end) const override;
    };
} // namespace ibsom::daycount
