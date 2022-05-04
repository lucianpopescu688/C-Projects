#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "complex_number.h"

int sort_by_real(const void* A, const void* B)
{
	Complex* a = (Complex*)A;
	Complex* b = (Complex*)B;
	if (a->real == b->real)
	{
		float dif = a->imag - b->imag;
		return (dif <= 0) ? -1 : 1;
	}
	else
	{
		float dif = a->real - b->real;
		return (dif <= 0) ? -1 : 1;
	}
}

int sort_by_imag(const void* A, const void* B)
{
	Complex* a = (Complex*)A;
	Complex* b = (Complex*)B;
	float maga = complex_mag(*a);
	float magb = complex_mag(*b);

	if (a->imag == b->imag)
	{
		float dif = maga - magb;
		return (dif <= 0) ? -1 : 1;
	}
	else
	{
		float dif = a->imag - b->imag;
		return (dif <= 0) ? -1 : 1;
	}
}

int sort_by_mag(const void* A, const void* B)
{
	Complex* a = (Complex*)A;
	Complex* b = (Complex*)B;
	float maga = complex_mag(*a);
	float magb = complex_mag(*b);

	float dif = maga - magb;
	return (dif <= 0) ? -1 : 1;
}
//sortari array 

void reading(long* numbers_count, Complex** array)
{
	const char* paths[] = {"in1.txt", "in2.txt", "in3.txt", "in4.txt" , "in5.txt" };
	FILE* fds[5];
	long lenghts[5];
	for (int i = 0; i < 5; i++)
	{
		fds[i] = fopen(paths[i], "r");
		long number; 
		fscanf(fds[i], "%ld", &number);
		*numbers_count += number;
		lenghts[i] = number;
	}
	*array = (Complex*)malloc(*numbers_count * sizeof(Complex));
	long index = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < lenghts[i]; j++)
		{
			float real, imag;
			fscanf(fds[i], "%f %f", &real, &imag);
			(* array)[index++] = complex_create(real, imag);
		}
	}	
}
//reading

bool is_sorted(Complex* array, long numbers_count, int (*cmp)(const void*, const void*))
{
	for (long i = 0; i < numbers_count - 1; i++)
	{
		int rez = (*cmp)(&array[i], &array[i + 1]);
		if (rez != -1)
		{
			return false;
		}

	}
	return true;
}

void test_sort_real(long numbers_count, Complex* array)
{
	qsort(array, numbers_count, sizeof(Complex), sort_by_real);
	/*Complex aux = array[numbers_count - 1];
	array[numbers_count - 1] = array[0];
	array[0] = aux;
	*/
	printf("Array is sorted by real part -> %d\n", is_sorted(array, numbers_count, sort_by_real));
}

void test_sort_imag(long numbers_count, Complex* array)
{
	qsort(array, numbers_count, sizeof(Complex), sort_by_imag);
	printf("Array is sorted by imaginary part -> %d\n", is_sorted(array, numbers_count, sort_by_imag));
}

void test_sort_mag(long numbers_count, Complex* array)
{
	qsort(array, numbers_count, sizeof(Complex), sort_by_mag);
	printf("Array is sorted by mag part -> %d\n", is_sorted(array, numbers_count, sort_by_mag));
}

void test_sorting()
{
	long numbers_count = 0;
	Complex* array;

	reading(&numbers_count, &array);
	test_sort_real(numbers_count, array);
	test_sort_imag(numbers_count, array);
	test_sort_mag(numbers_count, array);
	free(array);
}
// test by real



