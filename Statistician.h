#pragma once
#include <iostream>
using namespace std;

class Statistician
{
private:
	double smallest;
	double largest;
	double sum;
	int length;
public:

	Statistician(); // constructor

	void next_number(double number); // function to add a number to the statistician
	double getLargest() const; // function to get the largest number
	double getSmallest() const; // function to get the smallest number
	double getMean() const; // function to get the mean of the numbers
	double getSum() const; // function to get the sum of the numbers
	void erase(); // function to reset the statistician

	//function to overload the << operator to display the Statistician object
	friend ostream& operator<<(ostream& out, Statistician& obj);
};


