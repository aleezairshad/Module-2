#pragma once
class Pseudorandom
{
private:
	int seed;
	int multiplier;
	int modulus;
	int increment;
public:
	Pseudorandom(); // Default constructor

	int getSeed() const; // Getter for seed
	void setSeed(int newSeed); // Setter for seed

	int getMultiplier() const; // Getter for multiplier
	void setMultiplier(int newMultiplier); // Setter for multiplier

	int getModulus() const; // Getter for modulus
	void setModulus(int newModulus); // Setter for modulus

	int getIncrement() const; // Getter for increment
	void setIncrement(int newIncrement); //	Setter for increment

	//next num, indirect next num, run experiment 
	int getNextNumber(); // Generates the next pseudorandom number using the linear congruential generator formula
	double getIndirectNextNumber(); // Generates the next pseudorandom number and returns it as a double in the range [0, 1)
	void getExperimentResult(); // Runs an experiment with different values of multiplier, increment, and modulus to demonstrate the effect on the generated pseudorandom numbers
};