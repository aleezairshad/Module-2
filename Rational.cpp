#include "Rational.h"
#include <iostream>
#include <string>


//default constructor to initialize the rational number to 0/1
Rational::Rational()
{
	numerator = 0;
	denominator = 1;
}

//constructor to initialize the rational number with given numerator and denominator
Rational::Rational(int n, int d)
{
	numerator = n;
	denominator = (d == 0) ? 1 : d;
	//reduce();
}

//private helper function to calculate the greatest common divisor (GCD) of two integers
//precondition: a and b are integers
//postcondition: returns the GCD of a and b
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

//private helper function to reduce the rational number to its simplest form
//precondition: numerator and denominator are integers
//postcondition: reduces the rational number to its simplest form
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

// function to simplify the rational number
void Rational::simplify()
{
	reduce();
}

//public member functions to set and get the numerator and denominator
//precondition: n and d are integers
//postcondition: sets the numerator and denominator of the rational number
void Rational::setNumerator(int n)
{
	numerator = n;
	reduce();
}

//precondition: d is an integer
//postcondition: sets the denominator of the rational number, if d is not zero
void Rational::setDenominator(int d)
{
	if (d != 0)
		denominator = d;
	reduce();
}

//precondition: none
//postcondition: returns the numerator of the rational number
int Rational::getNumerator() const
{
	return numerator;
}

//precondition: none
//postcondition: returns the denominator of the rational number
int Rational::getDenominator() const
{
	return denominator;
}

//overloaded operators for arithmetic operations and comparisons
//precondition: rhs is a Rational object
//postcondition: returns the result of the arithmetic operation or comparison
Rational Rational::operator+(const Rational& rhs) const
{
	int n = (numerator * rhs.denominator) + (rhs.numerator * denominator);
	int d = denominator * rhs.denominator;

	Rational result(n, d);
	result.simplify();
	return result;
}

//precondition: rhs is a Rational object
//postcondition: returns the result of the arithmetic operation or comparison
Rational Rational::operator-(const Rational& rhs) const
{
	int n = (numerator * rhs.denominator) - (rhs.numerator * denominator);
	int d = denominator * rhs.denominator;
	Rational result(n, d);
	result.simplify();
	return result;
}

//precondition: rhs is a Rational object
//postcondition: returns the result of the arithmetic operation or comparison
Rational Rational::operator*(const Rational& rhs) const
{
	int n = numerator * rhs.numerator;
	int d = denominator * rhs.denominator;
	Rational result(n, d);
	result.simplify();
	return result;
}

//precondition: rhs is a Rational object
//postcondition: returns the result of the arithmetic operation or comparison
Rational Rational::operator/(const Rational& rhs) const
{
	int n = numerator * rhs.denominator;
	int d = denominator * rhs.numerator;
	Rational result(n, d);
	result.simplify();
	return result;
}

//precondition: rhs is a Rational object
//postcondition: returns true if the two rational numbers are equal, false otherwise
bool Rational::operator==(const Rational& rhs) const
{
	return (numerator * rhs.denominator) == (rhs.numerator * denominator);
}

//precondition: rhs is a Rational object
//postcondition: returns true if the left rational number is less than the right rational number, false otherwise
bool Rational::operator<(const Rational& rhs) const
{
	return (numerator * rhs.denominator) < (rhs.numerator * denominator);
}

//precondition: none
//postcondition: returns a string representation of the rational number in the form "numerator/denominator"
string Rational::toString() const
{
	return to_string(numerator) + "/" + to_string(denominator);
}

//overloaded << operator to output the rational number to an ostream
//precondition: out is an ostream object, r is a Rational object
//postcondition: outputs the string representation of the rational number to the ostream
ostream& operator<<(ostream& out, const Rational& r)
{
	out << r.toString();
	return out;
}




