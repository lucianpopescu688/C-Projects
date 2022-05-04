#include <math.h>
#include <stdio.h>

#include "complex_number.h"

Complex complex_create(float real, float imag)
{
	Complex c;
	c.real = real;
	c.imag = imag;
	return c;
}

float get_real(Complex c)
{
	return c.real;
}

float get_imag(Complex c)
{
	return c.imag;
}

void set_real(Complex* c, float real)
{
	c->real = real;
}

void set_imag(Complex* c, float imag)
{
	c->imag = imag;
}

Complex complex_conjugate(Complex c)
{
	return complex_create(c.real, c.imag * (-1));
}

Complex complex_add(Complex c1, Complex c2)
{
	Complex add;
	add.real = c1.real + c2.real;
	add.imag = c1.imag + c2.imag;
	return add;
}

Complex complex_subtract(Complex c1, Complex c2)
{
	Complex subtract;
	subtract.real = c1.real - c2.real;
	subtract.imag = c1.imag - c2.imag;
	return subtract;
}

Complex complex_multiply(Complex c1, Complex c2)
{
	Complex multiply;
	multiply.real = (c1.real * c2.real - c1.imag * c2.imag);
	multiply.imag = (c1.real * c2.imag + c1.imag * c2.real);
	return multiply;
}

void complex_scalar_mult(Complex* c, float s)
{
	c->real = c->real * s;
	c->imag = c->imag * s;
}

bool complex_equals(Complex c1, Complex c2)
{
	if (c1.real == c2.real && c1.imag == c2.imag)
		return 1;
	else
		return 0;
}

float complex_mag(Complex c)
{
	float magnitude = 0;
	magnitude = sqrt(pow(c.real, 2) + pow(c.imag, 2));
	return magnitude;
}

float complex_phase(Complex c)
{
	float phase;
	phase = atan2(c.imag, c.real);
	return phase;
}

void complex_to_polar(Complex c, float* r, float* theta)
{
	*r = sqrt((c.real * c.real) + (c.imag * c.imag));
	if (c.real < 0)
	{
		*theta = atan(c.imag / c.real);
		*theta = *theta * 180;
		*theta /= 3.14;
	}
	else if (c.real > 0)
	{
		*theta = atan(c.imag / c.real);
	}
	else if (c.real == 0 && c.imag == 0)
	{
		*theta = 0;
	}
}

void complex_display(Complex c)
{
	printf("The complex number is c = %.1f %.1f * i", c.real, c.imag);
}
