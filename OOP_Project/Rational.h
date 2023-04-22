#pragma once
#include"Polynomial.h"
#include<iostream>

class Rational
{
private:
	Polynomial _numerator;//top
	Polynomial _denominator;//bottom

public:
	Rational();
	Rational(const Rational& other);
	Rational(Polynomial p1, Polynomial p2);
	~Rational();

	const Polynomial& getNom()const;
	const Polynomial& getDenom()const;
	void print()const;

	Rational& operator=(const Rational& other);
	Rational& operator+(const Rational& other);
	Rational& operator-(const Rational& other);
	Rational& operator*(const Rational& other);
	friend Rational& operator*(const double a, const Rational& r);

	friend ostream& operator<<(ostream& output, const Rational& r);
};

