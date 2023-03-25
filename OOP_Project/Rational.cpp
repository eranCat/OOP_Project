#include "Rational.h"

Rational::Rational() {
	Polynomial p2(1);
	p2.setCoeff(0, 1);

	_numerator = Polynomial();
	_denominator = p2;
}

Rational::Rational(Polynomial& p1, Polynomial& p2)
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
	/*cout << "Rational destruct";*/
}