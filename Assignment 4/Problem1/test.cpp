#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include "complex_number.h"
#include "test.h"

//Testing operators for equal and not equal 
void test_equal_operator(Complex stack_equal, Complex* heap_equal)
{
	if ((stack_equal.getReal() == heap_equal->getReal()) && (stack_equal.getImag() == heap_equal->getImag()))
	{
		std::cout << "Test Passed! Complex number(" << stack_equal.toString() << ") and complex number(" << heap_equal->toString() << ") are equal." << "\n";
	}
	else
	{
		std::cout << "Test Failed! Complex number(" << stack_equal.toString() << ") and complex number(" << heap_equal->toString() << ") are not equal." << "\n";
	}
}

void test_not_equal_operator(Complex stack_equal, Complex* heap_equal)
{
	if ((stack_equal.getReal() != heap_equal->getReal()) || (stack_equal.getImag() != heap_equal->getImag()))
	{
		std::cout << "Test Passed! Complex number(" << stack_equal.toString() << ") and complex number(" << heap_equal->toString() << ") are not equal." << "\n";
	}
	else
	{
		std::cout << "Test Failed! Complex number(" << stack_equal.toString() << ") and complex number(" << heap_equal->toString() << ") are equal." << "\n";
	}
}

//Testing methods/normal operations with variables allocated on the stack
void stack_tester_magnitude(Complex stack_variable_1)
{
	float mag = stack_variable_1.magnitude();
	std::cout << "\n";
	std::cout << "The magnitude of complex number(" << stack_variable_1.toString() << ") " << "is:" << std::setprecision(1) << std::fixed << mag << "\n";
}

void stack_tester_phase(Complex stack_variable_1)
{
	float phase = stack_variable_1.phase();
	std::cout << "The phase of complex number(" << stack_variable_1.toString() << ") " << "is:" << std::setprecision(1) << std::fixed << phase << "\n";
}

void stack_tester_toPolar(Complex stack_variable_1)
{
	float r, theta;
	stack_variable_1.toPolar(&r, &theta);
	std::cout << "The radius and the angle of complex number(" << stack_variable_1.toString() << ") is:" << std::setprecision(1) << std::fixed << r << " and " << std::setprecision(1) << std::fixed << theta << "\n";
}

void stack_tester_conjugate(Complex stack_variable_1)
{
	Complex conjugate = stack_variable_1.conjugate();
	std::cout << "The conjugate of complex numver(" << stack_variable_1.toString() << ") is:" << conjugate.toString() << "\n";
}

//Testing operations with variables allocated on the stack
void test_multiply_by_scalar(Complex stack_variable, float number)
{
	std::cout << "The complex number(" << stack_variable.toString() << ") multiply by " << number << " is complex number(";
	stack_variable.multiply(number);
	std::cout << stack_variable.toString() << "). \n";
}

void test_multiply(Complex stack_variable, Complex stack_variable_2)
{
	std::cout << "The complex number(" << stack_variable.toString() << ") multiply by complex number(" << stack_variable_2.toString() << ") is complex number(";
	Complex product = stack_variable.multiply(stack_variable_2);
	std::cout << product.toString() << "). \n";
}

void test_division(Complex stack_variable, Complex stack_variable_2)
{
	std::cout << "The complex number(" << stack_variable.toString() << ") divide by complex number(" << stack_variable_2.toString() << ") is complex number(";
	Complex result = stack_variable.division(stack_variable_2);
	std::cout << result.toString() << "). \n";
}

void test_add(Complex stack_variable, Complex stack_variable_2)
{
	std::cout << "The complex number(" << stack_variable.toString() << ") add with complex number(" << stack_variable_2.toString() << ") is complex number(";
	Complex result = stack_variable.add(stack_variable_2);
	std::cout << result.toString() << "). \n";
}

void test_subtract(Complex stack_variable, Complex stack_variable_2)
{
	std::cout << "The complex number(" << stack_variable.toString() << ") subtract by complex number(" << stack_variable_2.toString() << ") is complex number(";
	Complex result = stack_variable.subtract(stack_variable_2);
	std::cout << result.toString() << "). \n";
}


//Testing methods/normal operations with variables allocated on the stack
void heap_tester_magnitude(Complex* heap_variable_1)
{
	float mag = heap_variable_1->magnitude();
	std::cout << "\n";
	std::cout << "The magnitude of complex number(" << heap_variable_1->toString() << ") " << "is:" << std::setprecision(1) << std::fixed << mag << "\n";
}

void heap_tester_phase(Complex* heap_variable_1)
{
	float phase = heap_variable_1->phase();
	std::cout << "The phase of complex number(" << heap_variable_1->toString() << ") " << "is:" << std::setprecision(1) << std::fixed << phase << "\n";
}

void heap_tester_toPolar(Complex* heap_variable_1)
{
	float r, theta;
	heap_variable_1->toPolar(&r, &theta);
	std::cout << "The radius and the angle of complex number(" << heap_variable_1->toString() << ") is:" << std::setprecision(1) << std::fixed << r << " and " << std::setprecision(1) << std::fixed << theta << "\n";
}

void heap_tester_conjugate(Complex* heap_variable_1)
{
	Complex conjugate = heap_variable_1->conjugate();
	std::cout << "The conjugate of complex numver(" << heap_variable_1->toString() << ") is:" << conjugate.toString() << "\n";
}

//Testing operations with variables allocated on the stack
void test_multiply_by_scalar_heap(Complex* heap_variable, float number)
{
	std::cout << "The complex number(" << heap_variable->toString() << ") multiply by " << number << " is complex number(";
	heap_variable->multiply(number);
	std::cout << heap_variable->toString() << "). \n";
}

void test_multiply_heap(Complex* heap_variable, Complex* heap_variable_2)
{
	std::cout << "The complex number(" << heap_variable->toString() << ") multiply by complex number(" << heap_variable_2->toString() << ") is complex number(";
	Complex product = heap_variable->multiply(*heap_variable_2);
	std::cout << product.toString() << "). \n";
}

void test_division_heap(Complex* heap_variable, Complex* heap_variable_2)
{
	std::cout << "The complex number(" << heap_variable->toString() << ") divide by complex number(" << heap_variable_2->toString() << ") is complex number(";
	Complex result = heap_variable->division(*heap_variable_2);
	std::cout << result.toString() << "). \n";
}

void test_add_heap(Complex* heap_variable, Complex* heap_variable_2)
{
	std::cout << "The complex number(" << heap_variable->toString() << ") add with complex number(" << heap_variable_2->toString() << ") is complex number(";
	Complex result = heap_variable->add(*heap_variable_2);
	std::cout << result.toString() << "). \n";
}

void test_subtract_heap(Complex* heap_variable, Complex* heap_variable_2)
{
	std::cout << "The complex number(" << heap_variable->toString() << ") subtract by complex number(" << heap_variable_2->toString() << ") is complex number(";
	Complex result = heap_variable->subtract(*heap_variable_2);
	std::cout << result.toString() << "). \n";
}

