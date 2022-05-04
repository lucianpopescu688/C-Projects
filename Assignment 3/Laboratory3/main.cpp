#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h>

#include "complex_test.h"
#include "test.h"
#include "dynamic_array.h"

int main(int argc, char** argv) {
	
	run_complex_tests(true);

	Complex st = complex_create(1, 1);
	Complex* he = (Complex*)malloc(sizeof(Complex));
	he->real = 2;
	he->imag = 1;

	stack_tester(st);
	heap_tester(he);
	testing_operations(st, he);

	test_sorting();

	_CrtDumpMemoryLeaks();
	return 0;
}