#include "quadratic.h"
#include <iostream>
#include <cmath>

using namespace std;

//precondition: NA
//postcondition: default constructor, set a, b, c to 0
quadratic::quadratic()
{
	a = 0;
	b = 0;
	c = 0;
}

//precondition: NA
//postcondition: parameterized constructor, set a, b, c to the given values
quadratic::quadratic(double a_value, double b_value, double c_value)
{
	a = a_value;
	b = b_value;
	c = c_value;
}

//precondition: NA
//postcondition: set the coefficients of the quadratic expression
void quadratic::set_coefficients(double a_value, double b_value, double c_value)
{
	a = a_value;
	b = b_value;
	c = c_value;
}

//precondition: NA
//postcondition: return the value of coefficient a
double quadratic::get_a() const
{
	return a;
}

//precondition: NA
//postcondition: return the value of coefficient b
double quadratic::get_b() const
{
	return b;
}

//precondition: NA
//postcondition: return the value of coefficient c
double quadratic::get_c() const
{
	return c;
}

//precondition: NA
//postcondition: evaluate the quadratic expression for a given value of x
double quadratic::evaluate(double x) const
{
	return a * x * x + b * x + c;
}

//precondition: NA
//postcondition: return the number of real roots of the quadratic expression
int quadratic::number_of_real_roots() const
{
	// Check the conditions for the number of real roots
	if (a == 0 && b == 0 && c == 0)
		return 3; // Infinite number of real roots
	else if (a == 0 && b == 0)
		return 0; // No real roots
	else if (a == 0)
		return 1; // One real root
	else
	{
		double discriminant = b * b - 4 * a * c;
		if (discriminant < 0)
			return 0; // No real roots
		else if (discriminant == 0)
			return 1; // One real root
		else
			return 2; // Two real roots
	}
}

//precondition: NA
//postcondition: return the first real root of the quadratic expression
double quadratic::real_root1() const
{
	const int TWO = 2, FOUR = 4;
	 
	if (a == 0 && b == 0 && c == 0)
	{
		return 0;
	}

	if (a == 0)
	{
		double root = -c / b;
		if (root == 0.0) // Handle negative zero case
			root = 0;
		return root;

	}

	double discriminant = b * b - FOUR * a * c;
	
	double root = (-b - sqrt(discriminant)) / (TWO * a);

	if (root == 0.0) // Handle negative zero case
		root = 0;

	return root;
}

//precondition: NA
//postcondition: return the second real root of the quadratic expression
double quadratic::real_root2() const
{
	const int TWO = 2, FOUR = 4;
	if (a == 0 && b == 0 && c == 0)
	{
		return 0;
	}

	if (a == 0)
	{

		double root = -c / b;
		if (root == 0.0) // Handle negative zero case
			root = 0;
		return root;
	}

	double discriminant = b * b - FOUR * a * c;

	double root = (-b + sqrt(discriminant)) / (TWO * a);
	if (root == 0.0) // Handle negative zero case
		root = 0;

	return root;

}

//precondition: NA
//postcondition: return the sum of 2 quadratic expressions
quadratic operator +(const quadratic& q1, const quadratic& q2)
{
	
	return quadratic(q1.get_a() + q2.get_a(), q1.get_b() + q2.get_b(), q1.get_c() + q2.get_c());
}

//precondition: NA
//postcondition: return the product of a scalar and a quadratic expression
quadratic operator *(double r, const quadratic& q)
{
	return quadratic(r * q.get_a(), r * q.get_b(), r * q.get_c());
}
