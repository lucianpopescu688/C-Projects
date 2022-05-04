#include "DynamicArrayTest.h"
#include <cassert>
#include <iostream>

int DynamicArrayTest::defaultCreationWithCapacityTest()
{
	DynamicArray<Offer>testArray;
	assert(testArray.getCapacity() == 100);
	assert(testArray.getLength() == 0);
	
	testArray = DynamicArray<Offer>(10);
	assert(testArray.getCapacity() == 10);
	assert(testArray.getLength() == 0);
	return 0;
}

int DynamicArrayTest::copyConstuctorTest()
{
	DynamicArray<Offer>array1;
	array1.append(Offer("Swiss-R21E", "Berlin", "Zurich", "13-04-2022 10:30", "13-04-2022 12:05", city_break, 75));
	array1.append(Offer("Rynair-TY12", "Barcelona", "Copenhagen", "13-04-2022 16:30", "13-04-2022 19:35", city_break, 120));
	DynamicArray<Offer>arr = array1;
	assert(arr == array1);
	return 0;
}

int DynamicArrayTest::copyAssignmentOperatorTest()
{
	DynamicArray<Offer>array1;
	array1.append(Offer("Swiss-R21E", "Berlin", "Zurich", "13-04-2022 10:30", "13-04-2022 12:05", city_break, 75));
	array1.append(Offer("Rynair-TY12", "Barcelona", "Copenhagen", "13-04-2022 16:30", "13-04-2022 19:35", city_break, 120));
	DynamicArray<Offer>arr;
	arr = array1;
	assert(arr == array1);
	return 0;
}

int DynamicArrayTest::getLengthTest()
{
	DynamicArray<Offer>array1;
	array1.append(Offer("Swiss-R21E", "Berlin", "Zurich", "13-04-2022 10:30", "13-04-2022 12:05", city_break, 75));
	assert(array1.getLength() == 1);

	array1.append(Offer("Rynair-TY12", "Barcelona", "Copenhagen", "13-04-2022 16:30", "13-04-2022 19:35", city_break, 120));
	assert(array1.getLength() == 2);
	
	return 0;
}

int DynamicArrayTest::getCapacityTest()
{
	DynamicArray<Offer>testArray;
	assert(testArray.getCapacity() == 100);
	assert(testArray.getLength() == 0);

	testArray = DynamicArray<Offer>(10);
	assert(testArray.getCapacity() == 10);
	assert(testArray.getLength() == 0);
	return 0;
}

int DynamicArrayTest::appendTest()
{
	DynamicArray<Offer>array1;
	array1.append(Offer("Swiss-R21E", "Berlin", "Zurich", "13-04-2022 10:30", "13-04-2022 12:05", city_break, 75));
	array1.append(Offer("Rynair-TY12", "Barcelona", "Copenhagen", "13-04-2022 16:30", "13-04-2022 19:35", city_break, 120));
	
	assert(array1.getCapacity() == 100);
	assert(array1.getLength() == 2);

	array1.append(Offer("Swiss-R21E", "Berlin", "Zurich", "13-04-2022 10:30", "13-04-2022 12:05", city_break, 75));
	array1.append(Offer("Rynair-TY12", "Barcelona", "Copenhagen", "13-04-2022 16:30", "13-04-2022 19:35", city_break, 120));
	array1.append(Offer("American Airlines-12RD", "New York", "Los Angeles", "13-04-2022 23:30", "14-04-2022 06:00", circuit, 280));

	assert(array1.getCapacity() == 100);
	assert(array1.getLength() == 5);
	return 0;
}

int DynamicArrayTest::popBackTest()
{
	DynamicArray<Offer>array1 , array2;
	array1.append(Offer("Swiss-R21E", "Berlin", "Zurich", "13-04-2022 10:30", "13-04-2022 12:05", city_break, 75));
	array1.append(Offer("Rynair-TY12", "Barcelona", "Copenhagen", "13-04-2022 16:30", "13-04-2022 19:35", city_break, 120));
	array2.append(Offer("Swiss-R21E", "Berlin", "Zurich", "13-04-2022 10:30", "13-04-2022 12:05", city_break, 75));
	array1.popBack();
	assert(array1 == array2);
	
	array1.popBack();
	array2.popBack();
	assert(array1 == array2);
	return 0;
}

int DynamicArrayTest::removeAtIndexTest()
{
	DynamicArray<Offer>arr, arr2, arr3;
	arr.append(Offer("Lufthansa-1R4S", "Cluj-Napoca", "Berlin", "13-04-2022 22:30", "14-04-2022 00:30", cruise, 150));
	arr.append(Offer("British AirWays-R2D2", "London", "Manchester", "13-04-2022 12:30", "13-04-2022 13:30", all_inclusive, 110));
	arr.append(Offer("American Airlines-12RD", "New York", "Los Angeles", "13-04-2022 23:30", "14-04-2022 06:00", circuit, 280));
	arr.append(Offer("Swiss-R21E", "Berlin", "Zurich", "13-04-2022 10:30", "13-04-2022 12:05", city_break, 75));
	arr.append(Offer("Rynair-TY12", "Barcelona", "Copenhagen", "13-04-2022 16:30", "13-04-2022 19:35", city_break, 120));
	
	arr2.append(Offer("Lufthansa-1R4S", "Cluj-Napoca", "Berlin", "13-04-2022 22:30", "14-04-2022 00:30", cruise, 150));
	arr2.append(Offer("British AirWays-R2D2", "London", "Manchester", "13-04-2022 12:30", "13-04-2022 13:30", all_inclusive, 110));
	arr2.append(Offer("American Airlines-12RD", "New York", "Los Angeles", "13-04-2022 23:30", "14-04-2022 06:00", circuit, 280));
	arr2.append(Offer("Rynair-TY12", "Barcelona", "Copenhagen", "13-04-2022 16:30", "13-04-2022 19:35", city_break, 120));
	
	arr3.append(Offer("Lufthansa-1R4S", "Cluj-Napoca", "Berlin", "13-04-2022 22:30", "14-04-2022 00:30", cruise, 150));
	arr3.append(Offer("Rynair-TY12", "Barcelona", "Copenhagen", "13-04-2022 16:30", "13-04-2022 19:35", city_break, 120));

	arr.remove_at_index(3);
	assert(arr == arr2);
	
	arr.remove_at_index(2);
	arr.remove_at_index(1);
	assert(arr == arr3);
	assert(arr.getLength() == 2);
	assert(arr.getCapacity() == 100);
	return 0;
}

int DynamicArrayTest::getAtIndexTest()
{
	Offer c1 = Offer("Lufthansa-1R4S", "Cluj-Napoca", "Berlin", "13-04-2022 22:30", "14-04-2022 00:30", cruise, 150);
	Offer c2 = Offer("Rynair-TY12", "Barcelona", "Copenhagen", "13-04-2022 16:30", "13-04-2022 19:35", city_break, 120);
	DynamicArray<Offer>arr;
	arr.append(Offer("Lufthansa-1R4S", "Cluj-Napoca", "Berlin", "13-04-2022 22:30", "14-04-2022 00:30", cruise, 150));
	arr.append(Offer("British AirWays-R2D2", "London", "Manchester", "13-04-2022 12:30", "13-04-2022 13:30", all_inclusive, 110));
	arr.append(Offer("American Airlines-12RD", "New York", "Los Angeles", "13-04-2022 23:30", "14-04-2022 06:00", circuit, 280));
	arr.append(Offer("Swiss-R21E", "Berlin", "Zurich", "13-04-2022 10:30", "13-04-2022 12:05", city_break, 75));
	arr.append(Offer("Rynair-TY12", "Barcelona", "Copenhagen", "13-04-2022 16:30", "13-04-2022 19:35", city_break, 120));
	Offer c3, c4;
	
	c3 = arr.get_at_index(0);
	c4 = arr.get_at_index(4);
	assert(c1 == c3);
	assert(c2 == c4);
	return 0;
}

int DynamicArrayTest::equalsOperatorTest()
{
	DynamicArray<Offer>arr1, arr2 , arr3, arr4;
	assert(arr1 == arr2);
	
	arr3.append(Offer("American Airlines-12RD", "New York", "Los Angeles", "13-04-2022 23:30", "14-04-2022 06:00", circuit, 280));
	arr4.append(Offer("American Airlines-12RD", "New York", "Los Angeles", "13-04-2022 23:30", "14-04-2022 06:00", circuit, 280));
	assert(arr3 == arr4);
	return 0;
}

int DynamicArrayTest::differentsOperatorTest()
{
	DynamicArray<Offer>arr1, arr2, arr3, arr4;
	arr2.append(Offer("American Airlines-12RD", "New York", "Los Angeles", "13-04-2022 23:30", "14-04-2022 06:00", circuit, 280));
	assert(arr1 != arr2);

	arr3.append(Offer("American Airlines-12RD", "New York", "Los Angeles", "13-04-2022 23:30", "14-04-2022 06:00", circuit, 280));
	arr3.append(Offer("British AirWays-R2D2", "London", "Manchester", "13-04-2022 12:30", "13-04-2022 13:30", all_inclusive, 110));
	arr4.append(Offer("American Airlines-12RD", "New York", "Los Angeles", "13-04-2022 23:30", "14-04-2022 06:00", circuit, 280));
	assert(arr3 != arr4);
	return 0;
}

int DynamicArrayTest::resizeTest()
{
	DynamicArray<Offer>arr, arr2;
	arr.append(Offer("British AirWays-R2D2", "London", "Manchester", "13-04-2022 12:30", "13-04-2022 13:30", all_inclusive, 110));
	assert(arr.getLength() == 1);
	assert(arr.getCapacity() == 100);
	
	arr.resize(1000);
	assert(arr.getLength() == 1);
	assert(arr.getCapacity() == 1000);
	return 0;
}

void DynamicArrayTest::runAllTests()
{
	defaultCreationWithCapacityTest();
	copyConstuctorTest();
	copyAssignmentOperatorTest();
	getLengthTest();
	getCapacityTest();
	appendTest();
	popBackTest();
	removeAtIndexTest();
	getAtIndexTest();
	equalsOperatorTest();
	differentsOperatorTest();
	resizeTest();
	std::cout << "Dynamic Array Tests run succesfully \n";
}
