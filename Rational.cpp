#include "Rational.h"

Rational::Rational()
{
	numerator = 0;
	denominator = 1;
}

Rational::Rational(int n, int d)
{
	numerator = n;
	denominator = (d == 0) ? 1 : d;
	reduce();
}

int Rational::gcd(int a, int b) const
{
	if (a < 0)
		a = -a;
	if (b < 0)
		b = -b;

	while (b != 0)
	{
		int temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

void Rational::reduce()
{
	if (denominator == 0)
		denominator = 1;

	if (denominator < 0)
	{
		numerator = -numerator;
		denominator = -denominator;
	}

	int g = gcd(numerator, denominator);
	if (g != 0)
	{
		numerator /= g;
		denominator /= g;
	}
}

void Rational::setNumerator(int n)
{
	numerator = n;
	reduce();
}

void Rational::setDenominator(int d)
{
	if (d != 0)
		denominator = d;
	reduce();
}

int Rational::getNumerator() const
{
	return numerator;
}

int Rational::getDenominator() const
{
	return denominator;
}

Rational Rational::operator+(const Rational& rhs) const
{
	int n = (numerator * rhs.denominator) + (rhs.numerator * denominator);
	int d = denominator * rhs.denominator;
	return Rational(n, d);
}

Rational Rational::operator-(const Rational& rhs) const
{
	int n = (numerator * rhs.denominator) - (rhs.numerator * denominator);
	int d = denominator * rhs.denominator;
	return Rational(n, d);
}

Rational Rational::operator*(const Rational& rhs) const
{
	int n = numerator * rhs.numerator;
	int d = denominator * rhs.denominator;
	return Rational(n, d);
}

Rational Rational::operator/(const Rational& rhs) const
{
	int n = numerator * rhs.denominator;
	int d = denominator * rhs.numerator;
	return Rational(n, d);
}

bool Rational::operator==(const Rational& rhs) const
{
	return (numerator * rhs.denominator) == (rhs.numerator * denominator);
}

bool Rational::operator<(const Rational& rhs) const
{
	return (numerator * rhs.denominator) < (rhs.numerator * denominator);
}

string Rational::toString() const
{
	return to_string(numerator) + "/" + to_string(denominator);
}

ostream& operator<<(ostream& out, const Rational& r)
{
	out << r.toString();
	return out;
}
