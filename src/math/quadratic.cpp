#include "quadratic.h"

#include <cmath>

bool Quadratic::solve(const double a, const double b, const double c, double &x1, double &x2)
{
    const double discriminant = b * b - 4 * a * c;

    if (discriminant < 0.0)
    {
        return false;
    }
    else if (discriminant == 0.0)
    {
        x1 = x2 = -b / (2.0 * a);

        return true;
    }
    else
    {
        x1 = (-b + sqrt(discriminant)) / (2.0 * a);
        x2 = (-b - sqrt(discriminant)) / (2.0 * a);

        return true;
    }
}
