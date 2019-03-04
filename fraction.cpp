#include "fraction.hpp"

namespace  {

size_t binaryGCD(size_t u, size_t v) {

    size_t shl = 0;

    while ( u && v && u!=v ) {

      bool eu = !(u & 1);
      bool ev = !(v & 1);

      if ( eu && ev ) {

        ++shl;

        u >>= 1;
        v >>= 1;
      }
      else if ( eu && !ev ) u >>= 1;

      else if ( !eu && ev ) v >>= 1;

      else if ( u>=v ) u = (u-v)>>1;

      else {

        size_t tmp = u;

        u = (v-u)>>1;

        v = tmp;
      }
    }

    return !u? v<<shl : u<<shl;
}

}

void Fraction::setNumerator(const size_t &numerator) {

    if (numerator == 0) throw std::invalid_argument("numerator can't be zero");

    this->numerator = numerator;
}

void Fraction::setDenominator(const size_t &denominator) {

    if (denominator == 0) throw std::invalid_argument("denominator can't be zero");

    this->denominator = denominator;
}

Fraction Fraction::operator *(const Fraction &f) {

    Fraction result;

    result.numerator = this->numerator * f.numerator;

    result.denominator = this->denominator * f.denominator;

    return  result;
}

Fraction Fraction::operator /(const Fraction &f) {

    Fraction result;

    result.numerator = this->numerator * f.denominator;

    result.denominator = this->denominator * f.numerator;

    return  result;
}

Fraction Fraction::operator +(const Fraction &f) {

    Fraction result;

    if (this->denominator == f.denominator) {

        result.numerator = this->numerator + f.numerator;

        result.denominator = this->denominator;
    }

    else {

        result.denominator = this->denominator * f.denominator;

        result.numerator = (this->numerator * f.denominator) +

                           (this->denominator * f.numerator);
    }

    return  result;
}

Fraction Fraction::operator -(const Fraction &f) {

    Fraction result;

    if (this->denominator == f.denominator) {

        if (this->numerator < f.numerator)
            throw std::logic_error("resulting fraction numerator is less then 0");

        result.numerator = this->numerator - f.numerator;

        result.denominator = this->denominator;
    }
    else {

        result.denominator = this->denominator * f.denominator;

        if ( (this->numerator * f.denominator) - (this->denominator * f.numerator) < f.numerator) {

            throw std::logic_error("resulting fraction numerator is less then 0");
        }

        result.numerator = (this->numerator * f.denominator) -

                           (this->denominator * f.numerator);
    }

    return  result;
}

void Fraction::reductFraction() {

    if (numerator == 0) return;

    size_t GCD = binaryGCD(numerator,denominator);

    numerator /= GCD;

    denominator /= GCD;
}

std::ostream& operator <<(std::ostream& output, const Fraction &f) {

    if (f.numerator == 0) output << '0' << "\n";

    else output << f.numerator << '/' << f.denominator << "\n";

    return output;
}
