#include "Rational.h"
#include <iostream>
#include <iomanip>


int main()
{
	//Rational objects r1 and r2 created with regular constructor
	//Rational object r3 created with default constructor, used to store arithmetic results
	Rational r1(1, 3);
	Rational r2(7, 8);
	Rational r3;

	//toRationalString and toDouble functions used to display objects in a way that is easier to read

	//demonstration of add function
	std::cout << r1.toRationalString() << "+" << r2.toRationalString() << "=";
	r3.add(r1, r2);
	std::cout << r3.toRationalString() << "=" << r3.toDouble() << std::endl;

	//demonstration of subtract function
	std::cout << r1.toRationalString() << "-" << r2.toRationalString() << "=";
	r3.subtract(r1, r2);
	std::cout << r3.toRationalString() << "=" << r3.toDouble() << std::endl;
	
	//demonstration of multiply function
	std::cout << r1.toRationalString() << "*" << r2.toRationalString() << "=";
	r3.multiply(r1, r2);
	std::cout << r3.toRationalString() << "=" << r3.toDouble() << std::endl;

	//demonstration of divide function
	std::cout << r1.toRationalString() << "/" << r2.toRationalString() << "=";
	r3.divide(r1, r2);
	std::cout << r3.toRationalString() << "=" << r3.toDouble() << std::endl;

	//demonstration of getters, setters and reduce functions
	Rational r4(-3, 4);

	std::cout << std::endl << "Original fraction: " << r4.toRationalString() << std::endl;
	std::cout << "Numerator: " << r4.getNumerator() << std::setw(15) << "Denominator: " << r4.getDenominator() << std::endl;
	r4.setDenominator(5);
	r4.setNumerator(10);
	std::cout << "After denominator set to 5, numerator set to 10 and fraction reduced: " << std::endl;
	std::cout << "Numerator: " << r4.getNumerator() << std::setw(15) << "Denominator: " << r4.getDenominator() << std::endl;



	return 0;
}
