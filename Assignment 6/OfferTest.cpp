#include "OfferTest.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <cassert>
#include <iostream>
using namespace std;

int OfferTest::get_setIDTest()
{
	Offer o1;
	o1.setID("1");
	assert(o1.getID() == "1");

	Offer c2;
	c2.setID("2");
	assert(c2.getID() == "2");
	
	return 0;
}

int OfferTest::get_setDepLocationTest()
{
	Offer o1;
	o1.setDeplocation("Spain");
	assert(o1.getDeplocation() == "Spain");

	Offer c2;
	c2.setDeplocation("Cluj-Napoca");
	assert(c2.getDeplocation() == "Cluj-Napoca");

	return 0;
}

int OfferTest::get_setDesLocationTest()
{
	Offer o1;
	o1.setDeslocation("Spain");
	assert(o1.getDeslocation() == "Spain");

	Offer c2;
	c2.setDeslocation("Cluj-Napoca");
	assert(c2.getDeslocation() == "Cluj-Napoca");

	return 0;
}

int OfferTest::get_setStartDateTest()
{
	Offer o1;
	o1.setStartDate("12/12/2022");
	assert(o1.getStartDate() == "12/12/2022");

	Offer c2;
	c2.setStartDate("13/04/2022");
	assert(c2.getStartDate() == "13/04/2022");

	return 0;
}

int OfferTest::get_setEndDateTest()
{
	Offer o1;
	o1.setEndDate("12/12/2022");
	assert(o1.getEndDate() == "12/12/2022");

	Offer c2;
	c2.setEndDate("13/04/2022");
	assert(c2.getEndDate() == "13/04/2022");

	return 0;
}

int OfferTest::get_setPriceTest()
{
	Offer o1;
	o1.setPrice(100);
	assert(o1.getPrice() == 100);

	Offer c2;
	c2.setPrice(200);
	assert(c2.getPrice() == 200);

	return 0;
}

int OfferTest::get_setTypeTest()
{
	Offer o1;
	o1.setType(circuit);
	assert(o1.getType() == 0);

	Offer c2;
	c2.setType(city_break);
	assert(c2.getType() == 1);

	Offer o3;
	o1.setType(cruise);
	assert(o1.getType() == 2);

	Offer c4;
	c2.setType(all_inclusive);
	assert(c2.getType() == 3);
	
	return 0;
}

int OfferTest::creationDefault()
{
	Offer o1;
	assert(o1.getID() == "0");
	assert(o1.getDeplocation() == "0");
	assert(o1.getDeslocation() == "0");
	assert(o1.getStartDate() == "0");
	assert(o1.getEndDate() == "0");
	assert(o1.getPrice() == 0);
	assert(o1.getType() == 2);
	return 0;
}

int OfferTest::creationWithParameters()
{
	Offer c = Offer("Lufthansa-1R4S", "Cluj-Napoca", "Berlin", "13-04-2022 22:30", "14-04-2022 00:30", cruise, 150);
	assert(c.getID() == "Lufthansa-1R4S");
	assert(c.getDeplocation() == "Cluj-Napoca");
	assert(c.getDeslocation() == "Berlin");
	assert(c.getStartDate() == "13-04-2022 22:30");
	assert(c.getEndDate() == "14-04-2022 00:30");
	assert(c.getType() == 2);
	assert(c.getPrice() == 150);
	return 0;
}

int OfferTest::operatorEqualsTest()
{
	Offer c1 = Offer("Lufthansa-1R4S", "Cluj-Napoca", "Berlin", "13-04-2022 22:30", "14-04-2022 00:30", cruise, 150);
	Offer c2 = Offer("Lufthansa-1R4S", "Cluj-Napoca", "Berlin", "13-04-2022 22:30", "14-04-2022 00:30", cruise, 150);
	assert(c1 == c2);
	
	Offer c3 = Offer("Lufthansa-1R5S", "Cluj-Napoca", "Berlin", "13-04-2022 22:30", "14-04-2022 00:30", cruise, 150);
	Offer c4 = Offer("Lufthansa-1R65S", "Acluj-Napoca", "Berlin", "13-04-2022 22:30", "14-04-2022 00:30", cruise, 150);
	assert(c3 != c4);
	return 0;
}
void OfferTest::runAllTests()
{
	get_setIDTest();
	get_setDepLocationTest();
	get_setDesLocationTest();
	get_setStartDateTest();
	get_setEndDateTest();
	get_setPriceTest();
	get_setTypeTest();
	creationDefault();
	creationWithParameters();
	operatorEqualsTest();
	std::cout << "Offer Tests runs succesfully \n";
}
