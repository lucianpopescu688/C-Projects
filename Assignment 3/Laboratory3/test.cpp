#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "complex_number.h"
#include "test.h"

void stack_tester(Complex st)
{
	// stack testing
	float mag = complex_mag(st);
	float phase = complex_phase(st);
	float r;
	float theta;
	complex_to_polar(st, &r, &theta);
	Complex conj = complex_conjugate(st);
	complex_scalar_mult(&st, 3);
	printf("%.1f\n", mag);
	printf("%.1f\n", phase);
	printf("%.1f %.1f\n", r, theta);
	printf("%.1f %.1f\n", conj.real, conj.imag);
	printf("%.1f %.1f\n", st.real, st.imag);
}

void heap_tester(Complex* he)
{
	// heap testing
	float mag = complex_mag(*he);
	float phase = complex_phase(*he);
	float r;
	float theta;
	complex_to_polar(*he, &r, &theta);
	Complex conj = complex_conjugate(*he);
	complex_scalar_mult(he, 3);
	printf("%.1f\n", mag);
	printf("%.1f\n", phase);
	printf("%.1f %.1f\n", r, theta);
	printf("%.1f %.1f\n", conj.real, conj.imag);
	printf("%.1f %.1f\n", he->real, he->imag);
	printf("\n");
}

void testing_operations(Complex st, Complex* he)
{
	Complex multiplication = complex_multiply(st, *he);
	Complex addition = complex_add(st, *he);
	Complex substraction = complex_subtract(st, *he);
	
	float numerator1 = (st.real * he->real) + (st.imag * he->real);
	float numerator2 = (st.imag * he->real) - (st.real * he->imag);
	float denominator = pow(he->real, 2) + pow(he->imag, 2);
	float index1 = 0, index2 = 0;
	index1 = numerator1 / denominator;
	index2 = numerator2 / denominator;
	Complex division = complex_create(index1, index2);

	printf("%.1f %.1f\n", multiplication.real, multiplication.imag);
	printf("%.1f %.1f\n", addition.real, addition.imag);
	printf("%.1f %.1f\n", substraction.real, substraction.imag);
	printf("%.1f %.1f\n", division.real, division.imag);
	printf("\n");
	free(he);
}