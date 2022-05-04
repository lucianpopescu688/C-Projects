#pragma once
#include "FilteringCriteria.h"

class FilteringTest
{
public:
	static void runAllTests();
private:
	static int filterByPriceTest();
	static int filterByTypeTest();
	static int filterByDepartureTest();
	static int filterByTypeAndPriceTest();
	static int filterByDepartureAndPriceTest();
	static int filterByDepartureAndTypeTest();
	static int filterByDoubleDepartureTest();
};

