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

	Polynomial(int degree=0);
	Polynomial(double a[], int degree);
	Polynomial(const Polynomial& src);
	Polynomial& operator=(const Polynomial& src);

	~Polynomial();

	int getDegree(bool what) const;
	double getCoeff(int index) const;//x at index

	void setCoeff(int degree, double coeff);

	void print()const;
};
