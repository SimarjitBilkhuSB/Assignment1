//Rational class implementation
//Rational.h is the header file with class declaration, must be included
#include "Rational.h"


//default constructor initializes data members with initializer list, no arguments passed
Rational::Rational() :numerator(0), denominator(1) {
	//std::cout << "Default constructor called" << std::endl;
}

//regular constructor initializes data members with int arguments passed
//1st int saved in numerator, 2nd in denominator
Rational::Rational(int a, int b) {
	//std::cout << "Regular constructor called" << std::endl;
	setNumerator(a);
	setDenominator(b);
	//reduce function called to make sure fraction is at it's simplest form
	reduce();
}

//numerator setter to edit numerator data member value
void Rational::setNumerator(int a) {
	numerator = a;
	//reduce function called to make sure fraction is at it's simplest form
	reduce();
}

//denominator setter with division by 0 prevention to edit denominator data member value
void Rational::setDenominator(int b) {
	//if/else statement prevents a 0 denominator and displays error code if it encounters one
	if (b != 0) {
		denominator = b;
		//reduce function called to make sure fraction is at it's simplest form
		//only inside scope of if statement because only necessary if the fraction is changed
		reduce();
	}
	else std::cout << "Invalid input: denominator can not be 0" << std::endl;
}

//numerator getter to access numerator data member, returns int
int Rational::getNumerator() {
	return numerator;
}

//denominator getter to access numerator data member, returns int
int Rational::getDenominator() {
	return denominator;
}

//fraction reducer function
//called whenever instantiating or performing changes on any object of Rational type
void Rational::reduce() {	
	unsigned int max;
	max = numerator * denominator;
	//used unsigned in as max value to feed into for loop in case numerator or denumerator is negative
	//without unsigned int type a negative value would skip over the for loop
	for (int i = 1; i <= max; i++) {
		//if statement checks if dividing numerator and denominator with a common value leaves a remainder
		if ((numerator % i == 0) && (denominator % i == 0)) {
			//if both remainders are 0 the current value of "i" is a common factor
			//both numerator and denominator are divided by the common factor if one exists
			numerator /= i;
			denominator /= i;
		}
	}	
}

//add function takes 2 rational numbers as arguments and adds them
//saves result in a 3rd rational object (the one used to call function)
void Rational::add(Rational r1, Rational r2) {
	//if the denominators are the same only the numerators have to be added
	if (r1.getDenominator() == r2.getDenominator()) {
		numerator = r1.getNumerator() + r2.getNumerator();
		denominator = r1.getDenominator();
		//reduce function called to make sure fraction is at it's simplest form
		reduce();
	}
	//otherwise the numbers have to be brought to the same denominator and added
	else {
		numerator = r1.getNumerator() * r2.getDenominator() + r1.getDenominator() * r2.getNumerator();
		denominator = r1.getDenominator() * r2.getDenominator();
		//reduce function called to make sure fraction is at it's simplest form
		reduce();
	}
}

//subtract function takes 2 rational numbers as arguments and subtracts the 2nd number from the 1st
//saves result in a 3rd rational object (the one used to call function)
void Rational::subtract(Rational r1, Rational r2) {
	if (r1.getDenominator() == r2.getDenominator()) {
		//if the denominators are the same only the numerators have to be subtracted
		numerator = r1.getNumerator() - r2.getNumerator();
		denominator = r1.getDenominator();
		//reduce function called to make sure fraction is at it's simplest form
		reduce();
	}
	//otherwise the numbers have to be brought to the same denominator and subtracted
	else {
		numerator = r1.getNumerator() * r2.getDenominator() - r1.getDenominator() * r2.getNumerator();
		denominator = r1.getDenominator() * r2.getDenominator();
		//reduce function called to make sure fraction is at it's simplest form
		reduce();
	}
}

//multiply function takes 2 rational numbers as arguments and multiplies them
//saves result in a 3rd rational object (the one used to call function)
void Rational::multiply(Rational r1, Rational r2) {
	//numerators and denominators from each number are multiplied with each other respectively
	numerator = r1.getNumerator() * r2.getNumerator();
	denominator = r1.getDenominator() * r2.getDenominator();
	//reduce function called to make sure fraction is at it's simplest form
	reduce();
}

//divide function takes 2 rational numbers as arguments and divides the 1st one by the 2nd one
//saves result in a 3rd rational object (the one used to call function)
void Rational::divide(Rational r1, Rational r2) {
	//numerator of the 1st number is multiplied by the denominator of the 2nd one
	//denominator of the 1st number is multiplied by the numerator of the 2nd one
	numerator = r1.getNumerator() * r2.getDenominator();
	denominator = r1.getDenominator() * r2.getNumerator();
	//reduce function called to make sure fraction is at it's simplest form
	reduce();
}

//toRationalString function converts rational number to string of a/b form
std::string Rational::toRationalString() {
	//string library used
	//4 different strings used to store the numerator, denominator, division bar and the fraction form
	std::string num, denom, bar, fraction;
	//to_string function used from string library to convert int to char type
	num = std::to_string(numerator);
	denom = std::to_string(denominator);
	bar = '/';
	//simple string concatenation
	fraction = num + bar + denom;
	return fraction;
}

//toDouble function returns the value of rational number used to call it as double type
double Rational::toDouble() {
	//local variables for temporary storage of the numerator and denominator
	//type double to make division of numerator by denumerator double
	double num, denum, result;

	//numerator and denominator of rational object cast as double into local variables
	num = static_cast<double>(numerator);
	denum = static_cast<double>(denominator);
	result = num / denum;//division saved in result

	//result returned as type double
	return result;
}
