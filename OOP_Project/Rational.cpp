#include "Rational.h"

Rational::Rational() {
	_numerator = Polynomial();
	_denominator = Polynomial(new double{ 1 }, 0);
}

Rational::Rational(Polynomial p1, Polynomial p2)
{
	_numerator = p1;
	_denominator = p2;
}


const Polynomial& Rational::getNom() const
{
	return _numerator;
}

const Polynomial& Rational::getDenom() const
{
	return _denominator;
}

void Rational::print()const {

	_numerator.print();
	cout << "--------------------------" << endl;
	_denominator.print();
}

Rational::~Rational()
{
	/*cout << "Rational destruct\n";*/
}