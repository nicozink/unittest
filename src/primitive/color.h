#pragma once

class Color
{
public:

    Color();

    Color(double r, double g, double b, double a = 1.0);

    double& r();
    double r() const;
    
    double& g();
    double g() const;
    
    double& b();
    double b() const;
    
    double& a();
    double a() const;

private:

        double channels[4];
};
