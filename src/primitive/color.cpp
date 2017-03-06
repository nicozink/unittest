#include "color.h"

Color::Color()
{
    channels[0] = 0.0;
    channels[1] = 0.0;
    channels[2] = 0.0;
    channels[3] = 1.0;
}

Color::Color(double r, double g, double b, double a)
{
    channels[0] = r;
    channels[1] = g;
    channels[2] = b;
    channels[3] = a;
}

double& Color::r()
{
    return channels[0];
}

double Color::r() const
{
    return channels[0];
}

double& Color::g()
{
    return channels[1];
}

double Color::g() const
{
    return channels[1];
}

double& Color::b()
{
    return channels[2];
}

double Color::b() const
{
    return channels[2];
}

double& Color::a()
{
    return channels[3];
}

double Color::a() const
{
    return channels[3];
}

Color Color::operator+(const Color& other) const
{
    return Color(r() + other.r(), g() + other.g(), b() + other.b(), a());
}

Color Color::operator*(const double value) const
{
    return Color(r() * value, g() * value, b() * value, a());
}
