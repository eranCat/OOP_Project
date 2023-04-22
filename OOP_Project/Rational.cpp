#include "Rational.h"

Rational::Rational() {
	_numerator = Polynomial();
	_denominator = Polynomial(new double{ 1 }, 0);
}

Rational::Rational(const Rational& other)
{
	this->_numerator = other._numerator;
	this->_denominator = other._denominator;
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

	cout << _numerator;
	for (int i = 0; i < 26; i++)
	{
		cout << "-";
	}
	cout << endl;
	cout << _denominator;
}

Rational& Rational::operator=(const Rational& other)
{
	this->_numerator = other._numerator;
	this->_denominator = other._denominator;
	return *this;
}

Rational& Rational::operator+(const Rational& other)
{
	Rational* plus = new Rational(*this);

	plus->_numerator = this->_numerator * other._denominator + this->_denominator * other._numerator;
	plus->_denominator = this->_denominator * other._denominator;
	return *plus;
}

Rational& Rational::operator-(const Rational& other)
{
	return *this + (-1) * other;
}

Rational& Rational::operator*(const Rational& other)
{
	Rational *r = new Rational(other._numerator * _numerator, other._denominator * _denominator);
	return *r;
}

Rational& operator*(const double a, const Rational& r)
{
	 Rational *mult = new Rational(r._numerator * a, r._denominator * abs(a));
	 return *mult;
}

ostream& operator<<(ostream& output, const Rational& r)
{
	output <<"numerator=" << r._numerator;
	for (int i = 0; i < 26; i++)
	{
		output << "-";
	}
	output << endl;
	output <<"denominator=" << r._denominator;
	return output;
}

Rational::~Rational()
{
	
}