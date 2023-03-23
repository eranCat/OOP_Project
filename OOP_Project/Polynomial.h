#pragma once
#include<iostream>

using namespace std;

class Polynomial
{
private:
	static int _maxDegree;
	int _degree;

	double* _coeffs;
public :
	static int getMaxDegree();
	static int _alloc;
	static void incAlloc() {
		/*cout << "\nAlloc:" << _alloc<<"\n";
		_alloc++;*/
	}

	Polynomial(int degree = 0);
	Polynomial(double a[],int degree);

	~Polynomial();

	int getDegree(bool what) const;
	double getCoeff(int index) const;//x at index

	void setCoeff(int degree, double coeff);

	void print()const;
};

