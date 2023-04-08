#include "Polynomial.h"
#include<string>

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

Polynomial& Polynomial::operator=(const Polynomial& other)
{
    if (this == &other)//compare addresses to prevent x=x
    {
        return *this;
    }

    this->_degree = other._degree;
    if (other._coeffs == NULL)
    {
        this->_coeffs = NULL;
    }
    else {
        this->_coeffs = new double[_degree + 1]();
        memcpy(this->_coeffs, other._coeffs, (_degree + 1) * sizeof(double));
    }

    return *this;
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
    if (_coeffs == NULL || !(index >= 0 && index <= _degree))
        return -12345.5;

    return _coeffs[index];
}

void Polynomial::setCoeff(int degree, double coeff) {
    if (degree >= 0 && degree < _degree+1)
    {
        _coeffs[degree] = coeff;
    }
}

double& Polynomial::operator[](int i) {
    return _coeffs[i];
}

string Polynomial::toString() const{
    int i, max = getDegree(true) + 1;

    string str = "polynomial = " + to_string( _coeffs[0]);
    
    for (i = 1; i < max; i++)
    {
        str += "+" + to_string(_coeffs[i]) + "X^" + to_string(i);
    }
    str+= "\n";
    return str;
}

void Polynomial::print()const {
    cout << toString();
}

Polynomial::~Polynomial()
{
    //cout << "--------------Destruct Poly" << _coeffs << "\n";
    delete[] _coeffs;
}