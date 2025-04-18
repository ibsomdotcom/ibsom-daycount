#pragma once

#include <chrono>

namespace ibsom::daycount
{
    class DayCountConvention
    {
    public:
        virtual ~DayCountConvention() = default;

        virtual int
        daysBetween(
            const std::chrono::sys_days& start,
            const std::chrono::sys_days& end) const = 0;

        virtual double
        yearFraction(
            const std::chrono::sys_days& start,
            const std::chrono::sys_days& end) const = 0;
    };
}
