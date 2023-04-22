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

	cout << *this;
}

Rational& Rational::operator=(Rational& other)
{
	this->_numerator = other._numerator;
	this->_denominator = other._denominator;
	return *this;
}

Rational& Rational::operator+(Rational& other)
{
	Rational* plus = new Rational(*this);

	plus->_numerator = this->_numerator * other._denominator + this->_denominator * other._numerator;
	plus->_denominator = this->_denominator * other._denominator;
	return *plus;
}

Rational& Rational::operator-(Rational& other)
{
	return * this + (-1) * other;
}

Rational& Rational::operator*(Rational& other)
{
	Polynomial* n = &(other._numerator * _numerator);
	Polynomial* d = &(other._denominator * _denominator);
	return *(new Rational(*n, *d));
}

Rational& operator*(const double a, const Rational& r)
{
	Polynomial* n = &(r._numerator * a);
	Polynomial* d = &(r._denominator * abs(a));
	return *(new Rational(*n, *d));
}

ostream& operator<<(ostream& output, const Rational& p)
{
	cout << p._denominator;
	for (int i = 0; i < 26; i++)
	{
		cout << "-";
	}
	cout << endl;
	cout << p._numerator;
	return output;
}

Rational::~Rational()
{
	
}