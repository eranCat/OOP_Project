#include "Polynomial.h"

int Polynomial::_maxDegree = 0;

int Polynomial::_alloc = 0;

Polynomial::Polynomial(int degree):Polynomial(new double[3],degree) {
    incAlloc();
}

Polynomial::Polynomial(double a[], int degree) {
    this->_degree = degree;
    int i;
    if (degree)
    {
        _coeffs = new double[_degree + 1];
        incAlloc();
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
    }
    else {
        _coeffs = new double[3];
        incAlloc();
        for (i = 0; i < 3; i++)
            _coeffs[i] = 0;
    }

    if (Polynomial::_maxDegree < degree)
    {
        Polynomial::_maxDegree = degree;
    }
}

//static
int Polynomial::getMaxDegree(){
    return _maxDegree;
}

int Polynomial::getDegree(bool iterate) const
{
    if (!iterate)
        return _degree;

    int i = _degree;
    while (i>0 && _coeffs[i])
        i--;

    return i;
}

double Polynomial::getCoeff(int index) const
{
    if (_coeffs != NULL && index >= 0 && index <= _degree) {
        return _coeffs[index];
    }
}

void Polynomial::setCoeff(int degree, double coeff) {
    
    if (degree >= 0 && degree <= _degree)
    {
        _coeffs[degree] = coeff;
    }
}

void Polynomial::print()const{

    bool isZero = false;
    int i;
    for ( i = 0; i < _degree+1; i++)
    {
        
    }

    if (getDegree(true)==0)
    {
        cout << "polynomial = 0\n";
        return;
    }

    cout << "polynomial = "<< _coeffs[0]<<"+";
    for (i = 1; i < _degree + 1;i++)
    {
        cout << _coeffs[i] << "X^" << i;
        if (i < _degree)
        {
            cout << "+";
        }
    }
    cout <<"\n";
}

Polynomial::~Polynomial()
{
    /*delete _coeffs;
    cout << "\nPolyD:" << _alloc<<"\n";
    _alloc--;
    _coeffs = NULL;*/
}
