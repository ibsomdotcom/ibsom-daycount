#include "daycount/Actual365Fixed.hpp"
#include <chrono>

namespace ibsom::daycount
{
    int
    Actual365Fixed::daysBetween(
        const std::chrono::sys_days& start,
        const std::chrono::sys_days& end) const
    {
        return (end - start).count();
    }

    double
    Actual365Fixed::yearFraction(
        const std::chrono::sys_days& start,
        const std::chrono::sys_days& end) const
    {
        return static_cast<double>(daysBetween(start, end)) / 365.0;
    }
} // namespace ibsom::daycount
