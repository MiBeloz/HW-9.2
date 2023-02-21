#include "Fraction.h"


Fraction::Fraction() : numerator{ 0 }, denominator{ 1 } {};

Fraction::Fraction(const int _numerator, const int _denominator) {
    if (_denominator == 0) {
        throw std::exception("Ошибка создания дроби! Знаменатель не должен быть равен 0!");
    }
    
    numerator = _numerator;
    denominator = _denominator;
}

bool Fraction::operator<(const Fraction& other) const {
    int commonDenominator = findCommonDenominator(denominator, other.denominator);
    return (numerator * commonDenominator / denominator) < (other.numerator * commonDenominator / other.denominator);
}

bool Fraction::operator>(const Fraction& other) {
    return other < *this;
}

bool Fraction::operator<=(const Fraction& other) const {
    return !(other < *this);
}

bool Fraction::operator>=(const Fraction& other) {
    return !(*this < other);
}

bool Fraction::operator==(const Fraction& other) {
    int commonDenominator = findCommonDenominator(denominator, other.denominator);
    return (numerator * commonDenominator / denominator) == (other.numerator * commonDenominator / other.denominator);
}

bool Fraction::operator!=(const Fraction& other) {
    return !(*this == other);
}

Fraction Fraction::operator+(const Fraction& other) {
    int commonDenominator = findCommonDenominator(denominator, other.denominator);
    int tempNumerator = (numerator * commonDenominator / denominator) + (other.numerator * commonDenominator / other.denominator);
    Fraction tempFraction(tempNumerator, commonDenominator);
    reduceFraction(tempFraction);
    return tempFraction;
}

Fraction Fraction::operator+(const int other) {
    Fraction tempFraction(other, 1);
    tempFraction = *this + tempFraction;
    return tempFraction;
}

Fraction Fraction::operator-(const Fraction& other) {
    
    int commonDenominator = findCommonDenominator(denominator, other.denominator);
    int tempNumerator = (numerator * commonDenominator / denominator) - (other.numerator * commonDenominator / other.denominator);
    Fraction tempFraction(tempNumerator, commonDenominator);
    reduceFraction(tempFraction);
    return tempFraction;
}

Fraction Fraction::operator-(const int other) {
    Fraction tempFraction(other, 1);
    tempFraction = *this - tempFraction;
    return tempFraction;
}

Fraction Fraction::operator*(const Fraction& other) {
    Fraction tempFraction;
    tempFraction.numerator = numerator * other.numerator;
    tempFraction.denominator = denominator * other.denominator;
    reduceFraction(tempFraction);
    return tempFraction;
}

Fraction Fraction::operator/(const Fraction& other) {
    Fraction tempFraction;
    tempFraction.numerator = numerator * other.denominator;
    tempFraction.denominator = denominator * other.numerator;
    if (denominator * other.numerator == 0) {
        throw std::exception("Деление невозможно!");
    }
    reduceFraction(tempFraction);
    return tempFraction;
}

Fraction Fraction::operator--() {
    numerator -= denominator;
    return *this;
}

Fraction Fraction::operator--(int) {
    Fraction tempFraction = *this;
    numerator -= denominator;
    return tempFraction;
}

Fraction Fraction::operator++() {
    numerator += denominator;
    return *this;
}

Fraction Fraction::operator++(int) {
    Fraction tempFraction = *this;
    numerator += denominator;
    return tempFraction;
}

int Fraction::findCommonDenominator(const int a, const int b) const {
    for (int i = a;; i++) {
        if (!(i % a) && !(i % b)) {
            return i;
        }
    }
}

void Fraction::reduceFraction(Fraction& other) {
    int a{}, b{};
    other.numerator > 0 ? a = other.numerator : a = other.numerator * -1;
    other.denominator > 0 ? b = other.denominator : b = other.denominator * -1;

    if (a != 0) {
        while (a != b) {
            if (a > b) {
                a = a - b;
            }
            else {
                b = b - a;
            }
        }

        other.numerator /= a;
        other.denominator /= a;
    }
    else {
        other.denominator = 1;
    }
}

std::ostream& operator<<(std::ostream& os, const Fraction& obj) {
    if (obj.numerator == 0) {
        os << 0;
    }
    else if (obj.denominator == 1) {
        os << obj.numerator;
    }
    else if (obj.numerator == obj.denominator) {
        os << 1;
    }
    else {
        os << obj.numerator << "/" << obj.denominator;
    }
    return os;
}

