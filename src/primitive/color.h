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

    Color operator+(const Color& other) const;

    Color operator*(const double value) const;

    Color operator/(const double value) const;
	
	double& operator[](const int i);
	
	double operator[](const int i) const;
    
private:

        double channels[4];
};
