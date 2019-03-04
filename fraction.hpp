#pragma once

#include <iostream>

class Fraction
{
public:
    void setNumerator(const size_t &numerator);
    void setDenominator(const size_t &denominator);

    void reductFraction();

    Fraction operator +(const Fraction &f);
    Fraction operator -(const Fraction &f);
    Fraction operator *(const Fraction &f);
    Fraction operator /(const Fraction &f);

    friend std::ostream& operator <<(std::ostream& output, const Fraction &f);

private:
    size_t numerator   = 0;
    size_t denominator = 0;
};


