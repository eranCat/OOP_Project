#pragma once
#include<iostream>

using namespace std;

class Polynomial
{
private:
	static int _maxDegree;
	int _degree;
	//int coeff_degree;
	double* _coeffs;
public:
	static int getMaxDegree();

	Polynomial();
	Polynomial(int degree);
	Polynomial(double a[], int degree);

	~Polynomial();

	int getDegree(bool what) const;
	double getCoeff(int index) const;//x at index

	void setCoeff(int degree, double coeff);

	void print()const;
};
