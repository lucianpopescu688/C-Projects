#pragma once
#include <stdbool.h>

//Testing operators for equal and not equal
void test_equal_operator(Complex stack_equal, Complex* heap_equal);
void test_not_equal_operator(Complex stack_equal, Complex* heap_equal);

//Testing methods/normal operations with variables allocated on the stack
void stack_tester_magnitude(Complex stack_variable);
void stack_tester_phase(Complex stack_variable);
void stack_tester_toPolar(Complex stack_variable);
void stack_tester_conjugate(Complex stack_variable);

//Testing operations with variables allocated on the stack
void test_multiply_by_scalar(Complex stack_variable, float number);
void test_multiply(Complex stack_variable_1, Complex stack_variable_2);
void test_division(Complex stack_variable_1, Complex stack_variable_2);
void test_add(Complex stack_variable, Complex stack_variable_2);
void test_subtract(Complex stack_variable, Complex stack_variable_2);

//Testing methods/normal operations with variables allocated on the heap
void heap_tester_magnitude(Complex* heap_variable);
void heap_tester_phase(Complex* heap_variable);
void heap_tester_toPolar(Complex* heap_variable);
void heap_tester_conjugate(Complex* heap_variable);

//Testing operations with variables allocated on the heap
void test_multiply_by_scalar_heap(Complex* heap_variable, float number);
void test_multiply_heap(Complex* heap_variable_1, Complex* heap_variable_2);
void test_division_heap(Complex* heap_variable_1, Complex* heap_variable_2);
void test_add_heap(Complex* heap_variable, Complex* heap_variable_2);
void test_subtract_heap(Complex* heap_variable, Complex* heap_variable_2);






