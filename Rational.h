#pragma once
#include <iostream>
using namespace std;


class Rational
{
private:
	int numerator;
	int denominator;

	int gcd(int a, int b) const;
	void reduce();

public:
	Rational(); // default constructor
	Rational(int n, int d); // constructor with parameters

	void setNumerator(int n); // sets the numerator of the rational number
	void setDenominator(int d); // sets the denominator of the rational number, if d is not zero
	int getNumerator() const; // returns the numerator of the rational number
	int getDenominator() const; // returns the denominator of the rational number
	void simplify();

	Rational operator+(const Rational& rhs) const; // overloads the + operator to add two rational numbers
	Rational operator-(const Rational& rhs) const; // overloads the - operator to subtract two rational numbers
	Rational operator*(const Rational& rhs) const; // overloads the * operator to multiply two rational numbers
	Rational operator/(const Rational& rhs) const; // overloads the / operator to divide two rational numbers
	bool operator==(const Rational& rhs) const; // overloads the == operator to compare two rational numbers for equality
	bool operator<(const Rational& rhs) const; // overloads the < operator to compare two rational numbers for less than

	string toString() const; // returns a string representation of the rational number in the form "numerator/denominator"
	friend ostream& operator<<(ostream& out, const Rational& r); // overloads the << operator to output the rational number to an ostream
};

