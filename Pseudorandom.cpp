#include "Pseudorandom.h"
#include <iostream>
#include <iomanip>
using namespace std;

Pseudorandom::Pseudorandom()
{
	seed = 1;
	multiplier = 40;
	modulus = 729;
	increment = 725;
}

int Pseudorandom::getSeed() const
{
	return seed;
}
void Pseudorandom::setSeed(int newSeed)
{
	seed = newSeed;
}

int Pseudorandom::getMultiplier() const
{
	return multiplier;
}
void Pseudorandom::setMultiplier(int newMultiplier)
{
	multiplier = newMultiplier;
}

int Pseudorandom::getModulus() const
{
	return modulus;
}
void Pseudorandom::setModulus(int newModulus)
{
	modulus = newModulus;
}

int Pseudorandom::getIncrement() const
{
	return increment;
}
void Pseudorandom::setIncrement(int newIncrement)
{
	increment = newIncrement;
}

int Pseudorandom::getNextNumber()
{
	int newNumber = (multiplier * seed + increment) % modulus;
	seed = newNumber;
	return newNumber;
}

double Pseudorandom::getIndirectNextNumber()
{
	return getNextNumber() / static_cast<double>(modulus);
}

void Pseudorandom::getExperimentResult()
{
	//random multiplier, increment, modulus  for experiment
	multiplier = rand() % 100000 + 1;
	increment = rand() % 100000 + 1;
	modulus = rand() % 100000 + 1;

	int interval = 0; // I want to turn the calculation of indirect next number to an integer to put in occurence
	const int OCCURENCE = 10;
	int occurenceCounter[OCCURENCE] = { 0 };

	const int FUNCTIONCALLS = 1000000;
	for (int i = 0; i < FUNCTIONCALLS; i++)
	{
		interval = getIndirectNextNumber() * 10;

		occurenceCounter[interval]++;
	}

	cout << "\n\tExperiment of pseudorandom with random multiplier, increment and modulus:\n";
	cout << "\n\t" << string(80, char(196));

	cout << "\n\tMultiplier = " << multiplier << ", increment = " << increment << ", modulus = " << modulus << "\n";

	cout << "\n\t" << setw(20) << left << "Range" << right << "Number of Occurrences";
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

	for (int i = 0; i < 12; i++)
	{
		sum += getIndirectNextNumber();
	}
}
