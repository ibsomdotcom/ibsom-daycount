#pragma once

#include "DayCountConvention.hpp"

namespace ibsom::daycount
{
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
