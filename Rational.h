#pragma once
#include <iostream>
#include <string>
using namespace std;

class Rational
{
private:
	int numerator;
	int denominator;

	int gcd(int a, int b) const;
	void reduce();

public:
	Rational();
	Rational(int n, int d);

	void setNumerator(int n);
	void setDenominator(int d);
	int getNumerator() const;
	int getDenominator() const;

	Rational operator+(const Rational& rhs) const;
	Rational operator-(const Rational& rhs) const;
	Rational operator*(const Rational& rhs) const;
	Rational operator/(const Rational& rhs) const;
	bool operator==(const Rational& rhs) const;
	bool operator<(const Rational& rhs) const;

	string toString() const;
	friend ostream& operator<<(ostream& out, const Rational& r);
};
