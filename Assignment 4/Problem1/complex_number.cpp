
#include "complex_number.h"
#include <sstream>
#include <iomanip>
#include<math.h>
using namespace std;

//Default constructor
Complex::Complex()
{
	real = 0;
	imag = 0;
}

//Constructor that initializes a complex number with the real and imaginary parts 
Complex::Complex(float real_part, float imag_part) {
	real = real_part;
	imag = imag_part;
}

//Getters
float Complex::getReal() const
{
	return real;
}

float Complex::getImag() const
{
	return imag;
}

//Setters
void Complex::setReal(float r)
{
	real = r;
}

void Complex::setImag(float i)
{
	imag = i;
}

//Default Operations
Complex Complex::conjugate() const
{
	return Complex(real, imag * (-1));
}

Complex Complex::add(Complex a) const
{
	Complex add;
	add.real = this->real + a.real;
	add.imag = this->imag + a.imag;
	return add;
}

Complex Complex::subtract(Complex c) const
{
	Complex subtract;
	subtract.real = this->real - c.real;
	subtract.imag = this->imag - c.imag;
	return subtract;
}

Complex Complex::multiply(Complex c) const
{
	Complex multiply;
	multiply.real = (this->real * c.real - this->imag * c.imag);
	multiply.imag = (this->real * c.imag + this->imag * c.real);
	return multiply;
}

Complex Complex::division(Complex c) const
{
	Complex result;
	float denominator;
	denominator = float(pow(c.real, 2)) + float(pow(c.imag, 2));
	result.real = float(((this->real * c.real) - (this->imag * c.imag))) / denominator;
	result.imag = float(((this->real * c.imag) + (this->imag * c.real))) / denominator;
	return result;
}
//Complex Operations
void Complex::multiply(float s)
{
	this->real *= s;
	this->imag *= s;
}

bool Complex::equals(Complex other) const
{
	if (this->real == other.real && this->imag == other.imag)
		return 1;
	else
		return 0;
}

float Complex::magnitude()
{
	float magnitude = 0;
	magnitude = sqrt(pow(this->real, 2) + pow(this->imag, 2));
	return magnitude;
}

float Complex::phase()
{
	float phase;
	phase = atan2(this->imag, this->real);
	return phase;
}

void Complex::toPolar(float* r, float* theta)
{
	*r = sqrt((this->real * this->real) + (this->imag * this->imag));
	if (this->real < 0)
	{
		*theta = atan(this->imag / this->real);
		*theta = *theta * 180;
		*theta /= 3.14;
	}
	else if (this->real > 0)
	{
		*theta = atan(this->imag / this->real);
	}
	else if (this->real == 0 && this->imag == 0)
	{
		*theta = 0;
	}
}

//Complex to String
string Complex::toString() const
{
	string ns;
	ostringstream str;

	if (this->real == 0 && this->imag == 0)
		return "0";

	str << setprecision(2) << fixed;

	if (this->imag == 0) {
		str << this->real;
		return str.str();
	}

	if (this->imag < 0)
		str << this->real << this->imag << "i";
	else
		str << this->real << "+" << this->imag << "i";
	return str.str();
}

//Overloaders for equal and not equal operators
bool Complex::operator == (const Complex& c) const
{
	return (this->real == c.real && this->imag == c.imag);
}

bool Complex::operator != (const Complex& c) const
{
	return (this->real != c.real || this->imag != c.imag);
}

//Overloaders for common operators
Complex operator + (const Complex& c1, const Complex& c2)
{
	return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

Complex Complex::operator - (const Complex& c) const
{
	Complex result{ this->real - c.real, this->imag - c.imag
	};
	return result;
}

Complex Complex::operator / (const Complex& c) const 
{
	Complex result;
	float denominator;
	denominator = float(pow(c.real, 2)) + float(pow(c.imag, 2));
	result.real = float(((this->real * c.real) - (this->imag * c.imag))) / denominator;
	result.imag = float(((this->real * c.imag) + (this->imag * c.real))) / denominator;
	return result;
}


Complex Complex::operator * (const Complex& c) const
{
	Complex result;
	result.real = (this->real * c.real) - (this->imag * c.imag);
	result.imag = (this->real * c.imag) + (this->imag * c.real);
	return result;
}


istream& operator >> (istream& is, Complex& c) {
	float n = 0, m = 0;
	if(is >> n)
	c.setReal(n);
	is >> m;
	c.setImag(m);
	return is;
}

ostream& operator << (ostream& out, const Complex& c) {
	out << c.real << "+" << c.imag << "i" << endl;
	return out;
}


