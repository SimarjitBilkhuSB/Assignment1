//this header file contains the Rational class declaration
//implementation in the Rational.cpp file (need both to use rational class)
#ifndef Rational_h
#define Rational_h
#include <iostream>
#include <string>

class Rational {
public:
	//constructor and member function prototypes public for use by client program
	Rational();//default constructor (no arguments)
	Rational(int, int);//regular constructor (int arguments passed for numerator and denominator)

	void setNumerator(int);//edit numerator variable in object
	void setDenominator(int);//edit denominator variable in object

	int getNumerator();//returns numerator as int value
	int getDenominator();//returns denominator as int value

	void reduce();//reduces to smallest fraction

	void add(Rational, Rational);//adds 2 fractions and stores in the object
	void subtract(Rational, Rational);//subtracts 2 fractions and stores in the object
	void multiply(Rational, Rational);//multiplies 2 fractions and stores in the object
	void divide(Rational, Rational);//dvides 2 fractions and stores in the object

	std::string toRationalString();//converts fraction to string in a/b form
	double toDouble();//coverts fraction to double and returns double value


private:
	//data members private to enforce encapsulation
	int numerator;
	int denominator;
};

#endif