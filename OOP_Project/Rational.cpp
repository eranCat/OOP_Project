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

Rational Rational::operator=(const Rational& other)
{
	this->_numerator = other._numerator;
	this->_denominator = other._denominator;
	return *this;
}

Rational Rational::operator+(const Rational& other)
{
	Rational plus = Rational(*this);

	plus._numerator = this->_numerator * other._denominator + this->_denominator * other._numerator;
	plus._denominator = this->_denominator * other._denominator;
	return plus;
}

Rational Rational::operator-(const Rational& other)
{
	return *this + (-1) * other;
}

Rational Rational::operator*(const Rational& other)
{
	return Rational(other._numerator * _numerator, other._denominator * _denominator);
}

Rational operator*(const double a, const Rational& r)
{
	return  Rational(r._numerator * a, r._denominator * abs(a));
}

ostream& operator<<(ostream& output, const Rational& p)
{
	output <<"numerator=" << p._numerator;
	for (int i = 0; i < 26; i++)
	{
		output << "-";
	}
	output << endl;
	output <<"denominator=" << p._denominator;
	return output;
}

Rational::~Rational()
{
	
}