#pragma once

class quadratic
{
private:
    double a;
    double b;
    double c;
public:
	quadratic(); // Default constructor
	quadratic(double a_value, double b_value, double c_value); // Parameterized constructor
	void set_coefficients(double a_value, double b_value, double c_value); // Function to set the coefficients of the quadratic expression
    double get_a() const; // Function to get the value of coefficient a
	double get_b() const; // Function to get the value of coefficient b
	double get_c() const; // Function to get the value of coefficient c
	double evaluate(double x) const; // Function to evaluate the quadratic expression for a given value of x
	int number_of_real_roots() const; // Function to determine the number of real roots of the quadratic expression
	double real_root1() const; // Function to calculate the first real root of the quadratic expression
	double real_root2() const; // Function to calculate the second real root of the quadratic expression

};

quadratic operator +(const quadratic& q1, const quadratic& q2); // Overload the + operator for quadratic expressions

quadratic operator *(double r, const quadratic& q);  // Overload the * operator for scalar multiplication of a quadratic expression

