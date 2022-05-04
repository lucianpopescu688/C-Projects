#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "complex_test.h"
#include "test.h"



int main(int argc, char** argv) {

#if ENABLE_TESTS > 0
	run_complex_tests(true);
#endif
	
	//Stack Variables
	Complex stack_variable_1 = Complex(1, 1);
	istringstream sstr1("2.75-2.70i");
	Complex stack_variable_2;
	sstr1 >> stack_variable_2;
	Complex stack_equal = Complex(2, 2);


	//Heap Variables
	Complex* heap_variable_1 = new Complex(2, 1);
	istringstream sstr("2.5-3.5i");
	Complex* heap_variable_2 = new Complex();
	sstr >> *heap_variable_2;
	Complex* heap_equal = new Complex(2, 2);

	cout << "Variables on stack is:" << endl;
	cout << "1. stack_variable_1 = " << stack_variable_1.toString() << endl;
	cout << "2. stack_variable_2 = " << stack_variable_2.toString() << endl;
	cout << "3. stack_variable_equal = " << stack_equal.toString() << endl;
	cout << "Variables on heap is:" << endl;
	cout << "1. heap_variable_1 = " << heap_variable_1->toString() << endl;
	cout << "2. heap_variable_2 = " << heap_variable_2->toString() << endl;
	cout << "3. heap_equal = " << heap_equal->toString() << endl;
	cout << "\n";

	cout << "Testing operators for equal and not equal(TRUE will be printed if test will pass)" << "\n";
	test_equal_operator(stack_equal, heap_equal);
	int result = (stack_equal == *heap_equal);
	if (result == 1)
		cout << "TRUE" << "\n";
	else
		cout << "FALSE" << "\n";

	test_equal_operator(stack_equal, heap_variable_1);
	result = (stack_equal == *heap_variable_1);
	if (result == 1)
		cout << "TRUE" << "\n";
	else
		cout << "FALSE" << "\n";

	test_not_equal_operator(stack_equal, heap_variable_1);
	result = (stack_equal != *heap_variable_1);
	if (result == 1)
		cout << "TRUE" << "\n";
	else
		cout << "FALSE" << "\n";

	test_not_equal_operator(stack_equal, heap_equal);
	result = (stack_equal != *heap_equal);
	if (result == 1)
		cout << "TRUE" << "\n";
	else
		cout << "FALSE" << "\n";
	cout << "\n";

	cout << "Testing methods/normal operations with variables allocated on the stack";
	stack_tester_magnitude(stack_variable_1);
	stack_tester_phase(stack_variable_1);
	stack_tester_toPolar(stack_variable_1);
	stack_tester_conjugate(stack_variable_1);
	cout << "\n";

	cout << "Testing operations and operators with variables allocated on the stack \n";
	Complex complex_result;
	test_multiply_by_scalar(stack_variable_1, 2);
	test_multiply(stack_variable_1, stack_variable_2);
	complex_result = (stack_variable_1 * stack_variable_2);
	cout << "The * operator checker result " << complex_result.toString() << "\n";

	test_division(stack_variable_1, stack_variable_2);
	complex_result = (stack_variable_1 / stack_variable_2);
	cout << "The / operator checker result " << complex_result.toString() << "\n";

	test_add(stack_variable_1, stack_variable_2);
	complex_result = (stack_variable_1 + stack_variable_2);
	cout << "The + operator checker result " << complex_result.toString() << "\n";

	test_subtract(stack_variable_1, stack_variable_2);
	complex_result = (stack_variable_1 - stack_variable_2);
	cout << "The - operator checker result " << complex_result.toString() << "\n";
	cout << "\n";

	//----------------------------------------------------------------------------------//

	cout << "Testing methods/normal operations with variables allocated on the heap";
	heap_tester_magnitude(heap_variable_1);
	heap_tester_phase(heap_variable_1);
	heap_tester_toPolar(heap_variable_1);
	heap_tester_conjugate(heap_variable_1);
	cout << "\n";

	cout << "Testing operations and operators with variables allocated on the heap\n";
	test_multiply_by_scalar_heap(heap_variable_1, 3);

	test_multiply_heap(heap_variable_1, heap_variable_2);
	complex_result = (*heap_variable_1 * *heap_variable_2);
	cout << "The * operator checker result " << complex_result.toString() << "\n";

	test_division_heap(heap_variable_1, heap_variable_2);
	complex_result = (*heap_variable_1 / *heap_variable_2);
	cout << "The / operator checker result " << complex_result.toString() << "\n";

	test_add_heap(heap_variable_1, heap_variable_2);
	complex_result = (*heap_variable_1 + *heap_variable_2);
	cout << "The + operator checker result " << complex_result.toString() << "\n";

	test_subtract_heap(heap_variable_1, heap_variable_2);
	complex_result = (*heap_variable_1 - *heap_variable_2);
	cout << "The - operator checker result " << complex_result.toString() << "\n";
	cout << "\n";

	delete heap_variable_1;
	delete heap_variable_2;
	delete heap_equal;
	sstr.str("");
	sstr1.str("");
	
	_CrtDumpMemoryLeaks();
}