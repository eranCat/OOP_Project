#include "Polynomial.h"

int Polynomial::_maxDegree = 0;

Polynomial::Polynomial() {
    _degree = 0;
    _coeffs = NULL;
}

Polynomial::Polynomial(int degree) :Polynomial(NULL, degree) {

}

Polynomial::Polynomial(double a[], int degree) {
    this->_degree = degree;
    int i, tempMaxCurrentDegree;

    _coeffs = new double[_degree + 1];

    if (a == NULL)
    {
        for (i = 0; i < degree + 1; i++)
            _coeffs[i] = 0;
    }
    else {
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
    int i;
    //coeff_degree = degree;
    if (!_coeffs)return;

    if (degree >= 0 && degree <= _degree)
    {
        _coeffs[degree] = coeff;
    }
    for (i = degree - 1; i >= 0; i--)
    {
        _coeffs[i] = NULL;
    }

}

void Polynomial::print()const {

    bool isZero = true;
    int i, j;

    if (_degree == 0)
    {
        cout << "polynomial = 0\n";
        return;
    }

    for (i = _degree; i >= 0; i--)
    {
        if (_coeffs[i] != 0)
        {
            isZero = false;
            j = i;
            break;
        }
    }

    if (isZero)
    {
        cout << "polynomial = 0\n";
        return;
    }
    cout << "polynomial = " << _coeffs[0];
    for (i = 1; i <= j; i++)
    {
        cout << "+" << _coeffs[i] << "X^" << i;
    }
    cout << "\n";
}

Polynomial::~Polynomial()
{
    //if (_coeffs) {
    //    delete _coeffsn;
    //    _coeffs = NULL;
    //}
}