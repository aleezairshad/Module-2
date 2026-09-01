#pragma once
class Pseudorandom
{
private:
	int seed;
	int multiplier;
	int modulus;
	int increment;
public:
	Pseudorandom();

	int getSeed() const;
	void setSeed(int newSeed);

	int getMultiplier() const;
	void setMultiplier(int newMultiplier);

	int getModulus() const;
	void setModulus(int newModulus);

	int getIncrement() const;
	void setIncrement(int newIncrement);

	//next num, indirect next num, run experiment
	int getNextNumber();
	double getIndirectNextNumber();
	void getExperimentResult();
};
