#include "FilteringTest.h"
#include "DynamicArray.h"
#include "Offer.h"
#include "FilteringCriteria.h"
#include "FilteringCriteriaAnd.h"
#include "FilteringCriteriaOr.h"
#include <cassert>
#include <iostream>

int FilteringTest::filterByPriceTest()
{
	DynamicArray<Offer>arr, arr_copied, arr_checked;
	arr.append(Offer("Lufthansa-1R4S", "Cluj-Napoca", "Berlin", "13-04-2022 22:30", "14-04-2022 00:30", cruise, 150));
	arr.append(Offer("British AirWays-R2D2", "London", "Manchester", "13-04-2022 12:30", "13-04-2022 13:30", all_inclusive, 110));
	arr.append(Offer("American Airlines-12RD", "New York", "Los Angeles", "13-04-2022 23:30", "14-04-2022 06:00", circuit, 280));
	arr.append(Offer("Swiss-R21E", "Berlin", "Zurich", "13-04-2022 10:30", "13-04-2022 12:05", city_break, 75));
	arr.append(Offer("Rynair-TY12", "Barcelona", "Copenhagen", "13-04-2022 16:30", "13-04-2022 19:35", city_break, 120));

	arr_checked.append(Offer("British AirWays-R2D2", "London", "Manchester", "13-04-2022 12:30", "13-04-2022 13:30", all_inclusive, 110));
	arr_checked.append(Offer("Swiss-R21E", "Berlin", "Zurich", "13-04-2022 10:30", "13-04-2022 12:05", city_break, 75));
	arr_checked.append(Offer("Rynair-TY12", "Barcelona", "Copenhagen", "13-04-2022 16:30", "13-04-2022 19:35", city_break, 120));

	arr_copied = arr;
	FilterByPrice fp = FilterByPrice(130);
	arr_copied = fp.filter(arr_copied);
	
	assert(arr_copied == arr_checked);
	return 0;
}

int FilteringTest::filterByTypeTest()
{
	DynamicArray<Offer>arr, arr_copied, arr_checked;
	arr.append(Offer("Lufthansa-1R4S", "Cluj-Napoca", "Berlin", "13-04-2022 22:30", "14-04-2022 00:30", cruise, 150));
	arr.append(Offer("British AirWays-R2D2", "London", "Manchester", "13-04-2022 12:30", "13-04-2022 13:30", all_inclusive, 110));
	arr.append(Offer("American Airlines-12RD", "New York", "Los Angeles", "13-04-2022 23:30", "14-04-2022 06:00", circuit, 280));
	arr.append(Offer("Swiss-R21E", "Berlin", "Zurich", "13-04-2022 10:30", "13-04-2022 12:05", city_break, 75));
	arr.append(Offer("Rynair-TY12", "Barcelona", "Copenhagen", "13-04-2022 16:30", "13-04-2022 19:35", city_break, 120));
	
	arr_checked.append(Offer("Swiss-R21E", "Berlin", "Zurich", "13-04-2022 10:30", "13-04-2022 12:05", city_break, 75));
	arr_checked.append(Offer("Rynair-TY12", "Barcelona", "Copenhagen", "13-04-2022 16:30", "13-04-2022 19:35", city_break, 120));
	
	arr_copied = arr;
	FilterByType ft = FilterByType(city_break);
	arr_copied = ft.filter(arr_copied);
	
	assert(arr_copied == arr_checked);
	return 0;
}

int FilteringTest::filterByDepartureTest()
{
	DynamicArray<Offer>arr, arr_copied, arr_checked;
	arr.append(Offer("Lufthansa-1R4S", "London", "Berlin", "13-04-2022 22:30", "14-04-2022 00:30", cruise, 150));
	arr.append(Offer("British AirWays-R2D2", "Cluj-Napoca", "Manchester", "13-04-2022 12:30", "13-04-2022 13:30", all_inclusive, 110));
	arr.append(Offer("American Airlines-12RD", "New York", "Los Angeles", "13-04-2022 23:30", "14-04-2022 06:00", circuit, 280));
	arr.append(Offer("Swiss-R21E", "London", "Zurich", "13-04-2022 10:30", "13-04-2022 12:05", city_break, 75));
	arr.append(Offer("Rynair-TY12", "London", "Copenhagen", "13-04-2022 16:30", "13-04-2022 19:35", city_break, 120));

	arr_checked.append(Offer("Lufthansa-1R4S", "London", "Berlin", "13-04-2022 22:30", "14-04-2022 00:30", cruise, 150));
	arr_checked.append(Offer("Swiss-R21E", "London", "Zurich", "13-04-2022 10:30", "13-04-2022 12:05", city_break, 75));
	arr_checked.append(Offer("Rynair-TY12", "London", "Copenhagen", "13-04-2022 16:30", "13-04-2022 19:35", city_break, 120));

	arr_copied = arr;
	FilterByDeparture fd = FilterByDeparture("London");
	arr_copied = fd.filter(arr_copied);
	
	assert(arr_copied == arr_checked);
		return 0;
}


int FilteringTest::filterByTypeAndPriceTest()
{
	DynamicArray<Offer>arr, arr_copied, arr_checked, arr2;
	arr.append(Offer("Lufthansa-1R4S", "Cluj-Napoca", "Berlin", "13-04-2022 22:30", "14-04-2022 00:30", cruise, 150));
	arr.append(Offer("British AirWays-R2D2", "London", "Manchester", "13-04-2022 12:30", "13-04-2022 13:30", city_break, 110));
	arr.append(Offer("American Airlines-12RD", "New York", "Los Angeles", "13-04-2022 23:30", "14-04-2022 06:00", circuit, 280));
	arr.append(Offer("Swiss-R21E", "Berlin", "Zurich", "13-04-2022 10:30", "13-04-2022 12:05", city_break, 75));
	arr.append(Offer("Rynair-TY12", "Barcelona", "Copenhagen", "13-04-2022 16:30", "13-04-2022 19:35", city_break, 120));

	arr_checked.append(Offer("British AirWays-R2D2", "London", "Manchester", "13-04-2022 12:30", "13-04-2022 13:30", city_break, 110));
	arr_checked.append(Offer("Swiss-R21E", "Berlin", "Zurich", "13-04-2022 10:30", "13-04-2022 12:05", city_break, 75));
	arr_checked.append(Offer("Rynair-TY12", "Barcelona", "Copenhagen", "13-04-2022 16:30", "13-04-2022 19:35", city_break, 120));

	arr_copied = arr;
	arr2 = arr;
	FilterByPrice fp = FilterByPrice(130);
	arr_copied = fp.filter(arr_copied);
	FilterByType ft = FilterByType(city_break);
	arr_copied = ft.filter(arr_copied);
	arr2 = FilterByTypeAndPrice(city_break, 130).filter(arr2);
	
	assert(arr_copied == arr_checked);
	assert(arr2 == arr_checked);
	return 0;
}

int FilteringTest::filterByDepartureAndPriceTest()
{
	DynamicArray<Offer>arr, arr_copied, arr_checked , arr2;
	arr.append(Offer("Lufthansa-1R4S", "London", "Berlin", "13-04-2022 22:30", "14-04-2022 00:30", cruise, 150));
	arr.append(Offer("British AirWays-R2D2", "London", "Manchester", "13-04-2022 12:30", "13-04-2022 13:30", city_break, 110));
	arr.append(Offer("American Airlines-12RD", "London", "Los Angeles", "13-04-2022 23:30", "14-04-2022 06:00", circuit, 280));
	arr.append(Offer("Swiss-R21E", "London", "Zurich", "13-04-2022 10:30", "13-04-2022 12:05", city_break, 75));
	arr.append(Offer("Rynair-TY12", "London", "Copenhagen", "13-04-2022 16:30", "13-04-2022 19:35", city_break, 120));

	arr_checked.append(Offer("British AirWays-R2D2", "London", "Manchester", "13-04-2022 12:30", "13-04-2022 13:30", city_break, 110));
	arr_checked.append(Offer("Swiss-R21E", "London", "Zurich", "13-04-2022 10:30", "13-04-2022 12:05", city_break, 75));
	arr_checked.append(Offer("Rynair-TY12", "London", "Copenhagen", "13-04-2022 16:30", "13-04-2022 19:35", city_break, 120));

	arr_copied = arr;
	arr2 = arr;
	FilterByDeparture fd = FilterByDeparture("London");
	arr_copied = fd.filter(arr_copied);
	FilterByPrice fp = FilterByPrice(130);
	arr_copied = fp.filter(arr_copied);

	arr2 = FilterByDepartureAndPrice("London", 130).filter(arr2);
	assert(arr_copied == arr_checked);
	assert(arr_checked == arr2);
	return 0;
}

int FilteringTest::filterByDepartureAndTypeTest()
{
	DynamicArray<Offer>arr, arr_copied, arr_checked, arr2;
	arr.append(Offer("Lufthansa-1R4S", "London", "Berlin", "13-04-2022 22:30", "14-04-2022 00:30", cruise, 150));
	arr.append(Offer("British AirWays-R2D2", "London", "Manchester", "13-04-2022 12:30", "13-04-2022 13:30", cruise, 110));
	arr.append(Offer("American Airlines-12RD", "London", "Los Angeles", "13-04-2022 23:30", "14-04-2022 06:00", circuit, 280));
	arr.append(Offer("Swiss-R21E", "Berlin", "Zurich", "13-04-2022 10:30", "13-04-2022 12:05", city_break, 75));
	arr.append(Offer("Rynair-TY12", "London", "Copenhagen", "13-04-2022 16:30", "13-04-2022 19:35", city_break, 120));

	arr_checked.append(Offer("Rynair-TY12", "London", "Copenhagen", "13-04-2022 16:30", "13-04-2022 19:35", city_break, 120));

	arr_copied = arr;
	arr2 = arr;
	FilterByType ft = FilterByType(city_break);
	arr_copied = ft.filter(arr_copied);
	FilterByDeparture fd = FilterByDeparture("London");
	arr_copied = fd.filter(arr_copied);

	arr2 = FilterByDepartureAndType("London", city_break).filter(arr2);
	assert(arr_copied == arr_checked);
	assert(arr_checked == arr2);
	return 0;
	return 0;
}

int FilteringTest::filterByDoubleDepartureTest()
{
	DynamicArray<Offer>arr, arr_copied, arr_checked, arr2;
	arr.append(Offer("Lufthansa-1R4S", "London", "Berlin", "13-04-2022 22:30", "14-04-2022 00:30", cruise, 150));
	arr.append(Offer("British AirWays-R2D2", "London", "Manchester", "13-04-2022 12:30", "13-04-2022 13:30", cruise, 110));
	arr.append(Offer("American Airlines-12RD", "Manchester", "Los Angeles", "13-04-2022 23:30", "14-04-2022 06:00", circuit, 280));
	arr.append(Offer("Swiss-R21E", "Berlin", "Zurich", "13-04-2022 10:30", "13-04-2022 12:05", city_break, 75));
	arr.append(Offer("Rynair-TY12", "Zurich", "Copenhagen", "13-04-2022 16:30", "13-04-2022 19:35", city_break, 120));

	arr2 = FilterByDoubleDeparture("London", "Zurich").filter(arr2);
	cout << arr2;
	return 0;
}
void FilteringTest::runAllTests()
{
	filterByPriceTest();
	filterByTypeTest();
	filterByDepartureTest();
	filterByTypeAndPriceTest();
	filterByDepartureAndPriceTest();
	filterByDepartureAndTypeTest();
	filterByDoubleDepartureTest();
	std::cout << "Filtering Tests run succesfully \n";
}
