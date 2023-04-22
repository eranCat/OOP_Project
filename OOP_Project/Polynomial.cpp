#include "Polynomial.h"
int Polynomial::_maxDegree = 0;

Polynomial::Polynomial(int degree):Polynomial(NULL, degree) {

}

Polynomial::Polynomial(double a[], int degree) {
    this->_degree = degree;
    int i;

    _coeffs = new double[_degree + 1]();//init with 0

    if (a != NULL)
    {
        //copy
        for (i = 0; i < degree + 1; i++)
        {
            _coeffs[i] = a[i];
        }
    }

    updateMaxDegree();
}

void Polynomial::updateMaxDegree() {
    int tempMaxCurrentDegree = getDegree(true);
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

    /*if (other._degree > this->_degree) {
        delete[] _coeffs;
        this->_coeffs = new double[other._degree + 1]();
    }
    else
    {
        for (int i = 0; i <= _degree; i++)
            this->_coeffs[i] = 0;
    }*/
    this->_coeffs = new double[other._degree + 1]();
    this->_degree = other._degree;

    for (int i = 0; i <= _degree; i++)
    {
        this->_coeffs[i] = other.getCoeff(i);
    }

    updateMaxDegree();
    
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
    //if (_coeffs == NULL || !(index >= 0 && index <= _degree))
    //    return -1234.12;
    if (index < 0)
        return -1234.12;
    if (index > _degree)
        return 0;

    return _coeffs[index];
}

void Polynomial::setCoeff(int degree, double coeff) {
    if (degree >= 0 && degree < _degree+1)
    {
        _coeffs[degree] = coeff;
    }
}

double Polynomial::operator[](int i) const {
    return getCoeff(i);
}
double& Polynomial::operator[](int i) {
    return _coeffs[i];
}

Polynomial& Polynomial::operator+( const Polynomial&other) const
{
    int i;
    int P_MIN, P_MAX;
    double* minCo;
    double* maxCo;

    if (this->_degree < other._degree)
    {
        P_MIN = this->_degree;
        P_MAX = other._degree;
        minCo = this->_coeffs;
        maxCo = other._coeffs;
    }
    else
    {
        P_MIN = other._degree;
        P_MAX = this->_degree;
        minCo = other._coeffs;
        maxCo = this->_coeffs;
    }

    Polynomial* plus = new Polynomial(P_MAX);
    
    for ( i = 0; i < P_MIN + 1; i++)
    {
        plus->_coeffs[i] = minCo[i] + maxCo[i];
    }
    
    for (; i < P_MAX + 1; i++)
    {
        plus->_coeffs[i] = maxCo[i];
    }
    return *plus;
}

Polynomial& Polynomial::operator-(const Polynomial&  other) const
{
    return *this + (-1) * other;
}

Polynomial& Polynomial::operator*(const Polynomial& other) const
{
    Polynomial* mult = new Polynomial(_degree + other._degree);
    int i, j;
    for (i = 0; i < this->_degree + 1; i++)
    {
        for (j = 0; j < other._degree + 1; j++)
        {
            mult->_coeffs[i + j] += this->_coeffs[i] * other[j];
        }
    }

    return *mult;
}

Polynomial& operator*(const double a, const Polynomial& p)
{
    int i;
    Polynomial* new_p= new Polynomial(p);
    for (i = 0; i < p._degree + 1; i++)
    {
        new_p->_coeffs[i] = p[i] * a;
    }
    return *new_p;
}

Polynomial& operator*(const Polynomial& p, const double a) {
    //call the other in reverse
    return a * p;
}

ostream& operator<<(ostream& output, const Polynomial& p)
{
    int i, max = p.getDegree(true) + 1;

    output << "Polynomial = " << p.getCoeff(0);
    
    for (i = 1; i < max; i++)
    {
        output << "+(" << p.getCoeff(i) << ")*X^" << i;
    }
    output<< "\n";
    return output;
}

void Polynomial::print()const {
    cout << *this;
}

Polynomial::~Polynomial()
{
    delete[] _coeffs;
    _coeffs = NULL;
}


