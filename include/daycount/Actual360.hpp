/// @file Actual360.hpp
/// @brief Implementation of Actual / 360 day count convention.

#pragma once

#include "DayCountConvention.hpp"

namespace ibsom::daycount
{
    /// @class Actual360
    /// @brief Calculates day count and year fraction using Actual / 360
    class Actual360 : public DayCountConvention
    {
    public:
        int
        daysBetween(
            const std::chrono::sys_days& start,
            const std::chrono::sys_days& end) const override;

        double
        yearFraction(
            const std::chrono::sys_days& start,
            const std::chrono::sys_days& end) const override;
    };
}
