#include "Polynomial.h"

int Polynomial::_maxDegree = 0;

Polynomial::Polynomial(int degree):Polynomial(NULL, degree) {

}

Polynomial::Polynomial(double a[], int degree) {
    this->_degree = degree;
    int i, tempMaxCurrentDegree;

    _coeffs = new double[_degree + 1]();//init with 0

    if (a != NULL)
    {
        for (i = 0; i < degree + 1; i++)
        {
            _coeffs[i] = a[i];
        }
    }

    tempMaxCurrentDegree = getDegree(true);
    if (Polynomial::_maxDegree < tempMaxCurrentDegree)
    {
        Polynomial::_maxDegree = tempMaxCurrentDegree;
    }
}

//Copy ctor
Polynomial::Polynomial(const Polynomial& src):Polynomial(src._coeffs,src._degree)
{
}

//static
int Polynomial::getMaxDegree() {
    return _maxDegree;
}

int Polynomial::getDegree(bool iterate) const
{
    if (!iterate)
        return _degree;

    int i = _degree;
    while (i > 0 && _coeffs[i] == 0)
        i--;

    return i;
}

double Polynomial::getCoeff(int index) const
{
    if (!(index >= 0 && index <= _degree))
        return -12345.5;

    if (_coeffs != NULL /* && index >= 0 && index <= _degree*/) {
        return _coeffs[index];
    }
}

void Polynomial::setCoeff(int degree, double coeff) {
    if (degree >= 0 && degree < _degree+1)
    {
        _coeffs[degree] = coeff;
    }
}

void Polynomial::print()const {
    int i,max = getDegree(true)+1;

    cout << "polynomial = " << _coeffs[0];
    for (i = 1; i < max; i++)
    {
        cout << "+" << _coeffs[i] << "X^" << i;
    }
    cout << "\n";
}

Polynomial::~Polynomial()
{
    //cout << "--------------Destruct " << _coeffs << "\n";
    //delete _coeffs;
}