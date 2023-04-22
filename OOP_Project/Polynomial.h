#pragma once
#include<iostream>
#include<stdio.h>

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

	Polynomial(int degree = 0);
	Polynomial(double a[], int degree);
	Polynomial(const Polynomial& src);
	Polynomial& operator=(const Polynomial& src);

	~Polynomial();

	int getDegree(bool what) const;
	double getCoeff(int index) const;//x at index

	void setCoeff(int degree, double coeff);

	void print()const;

	Polynomial operator+(const Polynomial& other)const;
	Polynomial operator-(const Polynomial& other)const;
	Polynomial operator*(const Polynomial& other)const;

	friend Polynomial operator*(const double a, const Polynomial& p);
	friend Polynomial operator*(const Polynomial& p, const double a) {
		//call the other in reverse
		return a * p;
	}

	//Read access to coeffs
	double operator[](int i) const;
	double& operator[](int i);
	friend ostream& operator<<(ostream& output, const Polynomial& p);
};

