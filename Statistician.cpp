#include "Statistician.h"

//Constructor
//Precondition: NA 
Statistician::Statistician()
{
	erase();
}


//Precondition: number must valid 
//Postcondition: change the largest, smallest, increment length by 1, and add the nubmer to sum
void Statistician::next_number(double number)
{
	if (length == 0) //needed or not
	{
		smallest = number;
		largest = number;
	}

	if (smallest > number)
		smallest = number;

	if (largest < number)
		largest = number;

	length++;
	sum += number;
}

//Precondition: NA
//Postcondition: return the largest number
double Statistician::getLargest() const
{
	return largest;
}

//Precondition: NA
//Postcondition: return the smallest number
double Statistician::getSmallest() const
{
	return smallest;
}

//Precondition: NA
//Postcondition: return the mean of the numbers
double Statistician::getMean() const
{
	if (length == 0)
		return 0.0;
	else
		return sum / length;
}

//Precondition: NA
//Postcondition: return the sum of the numbers
double Statistician::getSum() const
{
	return sum;
}

//Precondition: NA
//Postcondition: reset the Statistician object
void Statistician::erase()
{
	smallest = 0.0;
	largest = 0.0;
	sum = 0.0;
	length = 0;
}

//precondition: NA
//postcondition: display the Statistician object
ostream& operator<<(ostream& out, Statistician& obj)
{
	out << "\n\tlargest  : " << obj.getLargest();
	out << "\n\tsmallest : " << obj.getSmallest();
	out << "\n\tsum      : " << obj.getSum();
	out << "\n\tmean     : " << obj.getMean();

	return out;
}
