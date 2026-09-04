#include "Pseudorandom.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// precondition: none
// postcondition: initializes the seed, multiplier, modulus, and increment to default values
Pseudorandom::Pseudorandom()
{
	seed = 1;
	multiplier = 40;
	modulus = 729;
	increment = 725;
}

// precondition: none
// postcondition: returns the current seed value
int Pseudorandom::getSeed() const
{
	return seed;
}
// precondition: none
// postcondition: sets the seed to a new value
void Pseudorandom::setSeed(int newSeed)
{
	seed = newSeed;
}

// precondition: none
// postcondition: returns the current multiplier value
int Pseudorandom::getMultiplier() const
{
	return multiplier;
}

// precondition: none
// postcondition: sets the multiplier to a new value
void Pseudorandom::setMultiplier(int newMultiplier)
{
	multiplier = newMultiplier;
}

// precondition: none
// postcondition: returns the current modulus value
int Pseudorandom::getModulus() const
{
	return modulus;
}

// precondition: none
// postcondition: sets the modulus to a new value
void Pseudorandom::setModulus(int newModulus)
{
	modulus = newModulus;
}

// precondition: none
// postcondition: returns the current increment value
int Pseudorandom::getIncrement() const
{
	return increment;
}

// precondition: none
// postcondition: sets the increment to a new value
void Pseudorandom::setIncrement(int newIncrement)
{
	increment = newIncrement;
}

// precondition: modulus > 0
// postcondition: generates the next pseudorandom number using the linear congruential generator formula
int Pseudorandom::getNextNumber()
{
	long long value = static_cast<long long>(multiplier) * seed + increment; // Use long long to prevent overflow

	long long newNumber = value % modulus; // Use long long to prevent overflow
	if (newNumber < 0) // Ensure newNumber is non-negative
	{
		newNumber += modulus;
	}


	seed = static_cast<int>(newNumber);

	return seed;
}

// precondition: modulus > 0
// postcondition: generates the next pseudorandom number and returns it as a double in the range [0, 1)
double Pseudorandom::getIndirectNextNumber()
{
	return getNextNumber() / static_cast<double>(modulus);
}

// precondition: none
// postcondition: runs an experiment to generate pseudorandom numbers and counts their occurrences in intervals
void Pseudorandom::getExperimentResult()
{
	//random multiplier, increment, modulus  for experiment
	multiplier = rand() % 100000 + 1; 
	increment = rand() % 100000 + 1;
	modulus = rand() % 100000 + 1;

	
	const int OCCURENCE = 10;
	int occurenceCounter[OCCURENCE] = { 0 }; // Initialize the occurrence counter array to zero

	const int FUNCTIONCALLS = 1000000;
	// Generate pseudorandom numbers and count their occurrences in intervals
	for (int i = 0; i < FUNCTIONCALLS; i++)
	{
		int interval = static_cast<int>(getIndirectNextNumber() * 10);
		if (interval >= 0 && interval < OCCURENCE)
		{
			occurenceCounter[interval]++;
		}


		//occurenceCounter[interval]++;
	}

	cout << "\n\tExperiment of pseudorandom with random multiplier, increment and modulus:\n";
	cout << "\n\t" << string(80, char(196));
	// Display the multiplier, increment, and modulus values used in the experiment
	cout << "\n\tMultiplier = " << multiplier << ", increment = " << increment << ", modulus = " << modulus << "\n";

	cout << "\n\t" << setw(20) << left << "Range" << right << "Number of Occurrences";
	// Display the occurrences of pseudorandom numbers in intervals
	for (int i = 0; i < OCCURENCE; i++)
	{
		if (i < 9)
		{
			cout << "\n\t[0." << i << " ... 0." << i + 1 << ")       " << occurenceCounter[i];
		}
		else
		{
			cout << "\n\t[0.9 ... 1.0)       " << occurenceCounter[i];
		}
	}
	cout << "\n";

	double sum = 0.0;
	const int MEANCOUNT = 10;
	const double MEANCOUNT_DOUBLE = 10.0;
	const double SUM_CONSTANT = 12.0;
	// Generate MEANCOUNT uniformly distributed random numbers and calculate their sum
	for (int i = 0; i < MEANCOUNT; i++)
	{
		sum += getIndirectNextNumber();
	}

	// Calculate the mean and deviation for the Gaussian distribution
	double mean =	SUM_CONSTANT / MEANCOUNT_DOUBLE;
	double deviation = sum - 5.0;
	double gaussian = fabs(sqrt(mean) * deviation);

	cout << "\n\tWith " << MEANCOUNT << " uniformly distributed random numbers in the range [0 ... 1.0),\n";
	cout << "\tThe approximate Gaussian distribution is " << gaussian << ".\n";
}