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
	Rational(Polynomial p1, Polynomial p2);
	~Rational();

	const Polynomial& getNom()const;
	const Polynomial& getDenom()const;
	void print()const;
};

