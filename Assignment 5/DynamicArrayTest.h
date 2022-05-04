#pragma once
#include "DynamicArray.h"

class DynamicArrayTest
{
public:
	static void runAllTests();
private:
	static int defaultCreationWithCapacityTest();
	static int copyConstuctorTest();
	static int copyAssignmentOperatorTest();
	static int getLengthTest();
	static int getCapacityTest();
	static int appendTest();
	static int popBackTest();
	static int removeAtIndexTest();
	static int getAtIndexTest();
	static int equalsOperatorTest();
	static int differentsOperatorTest();
	static int resizeTest();
};

