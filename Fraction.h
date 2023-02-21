#pragma once

#include <iostream>


class Fraction {
public:
	Fraction();
	Fraction(const int _numerator, const int _denominator);

	bool operator<(const Fraction& other) const;
	bool operator>(const Fraction& other);
	bool operator<=(const Fraction& other) const;
	bool operator>=(const Fraction& other);
	bool operator==(const Fraction& other);
	bool operator!=(const Fraction& other);

	Fraction operator+(const Fraction& other);
	Fraction operator+(const int other);
	Fraction operator-(const Fraction& other);
	Fraction operator-(const int other);
	Fraction operator*(const Fraction& other);
	Fraction operator/(const Fraction& other);
	Fraction operator--();
	Fraction operator--(int);
	Fraction operator++();
	Fraction operator++(int);

private:
	int numerator;
	int denominator;

	int findCommonDenominator(const int a, const int b) const;
	void reduceFraction(Fraction& other);

	friend std::ostream& operator<<(std::ostream& os, const Fraction& obj);
};

