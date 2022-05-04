#pragma once
#include "Offer.h"

class OfferTest
{
public:
	static void runAllTests();
private:
	static int get_setIDTest();
	static int get_setDepLocationTest();
	static int get_setDesLocationTest();
	static int get_setStartDateTest();
	static int get_setEndDateTest();
	static int get_setPriceTest();
	static int get_setTypeTest();
	static int creationDefault();
	static int creationWithParameters();
	static int operatorEqualsTest();
};

