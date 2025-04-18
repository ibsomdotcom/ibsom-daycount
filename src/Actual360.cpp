#include "daycount/Actual360.hpp"
#include <chrono>

namespace ibsom::daycount
{
    int
    Actual360::daysBetween(
        const std::chrono::sys_days& start,
        const std::chrono::sys_days& end) const
    {
        return (end - start).count();
    }

    double
    Actual360::yearFraction(
        const std::chrono::sys_days& start,
        const std::chrono::sys_days& end) const
    {
        return static_cast<double>(daysBetween(start, end)) / 360.0;
    }
}
