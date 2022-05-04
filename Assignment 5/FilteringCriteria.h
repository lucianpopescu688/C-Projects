#pragma once
#include "DynamicArray.h"
#include <cstring>
class FilteringCriteria
{
public:
	DynamicArray<Offer> filter(DynamicArray<Offer>& data);
	
	virtual bool match(Offer offer) = 0;
};

class FilterByPrice : public FilteringCriteria 
{
public:
	FilterByPrice(float price);
	virtual bool match(Offer offer);

private:
	float price;
};

class FilterByType : public FilteringCriteria
{
public:
	FilterByType(Type newType);
	virtual bool match(Offer offer);

private:
	Type filterType;
};

class FilterByDeparture : public FilteringCriteria
{
public:
	FilterByDeparture(string Departure);
	virtual bool match(Offer offer);

private:
	string Departure;
};