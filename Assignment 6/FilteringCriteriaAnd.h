#pragma once
#include "FilteringCriteria.h"
#include <cstring>

class FilteringCriteriaAnd : public FilteringCriteria
{
public:
	virtual bool match(Offer offer) final;
	virtual bool firstMatch(Offer offer) = 0;
	virtual bool secondMatch(Offer offer) = 0;
};


class FilterByTypeAndPrice : public FilteringCriteriaAnd
{
public:
	FilterByTypeAndPrice(Type type, float price);
	virtual bool firstMatch(Offer offer);
	virtual bool secondMatch(Offer offer);

private:
	float price;
	Type type;
};

class FilterByDepartureAndPrice : public FilteringCriteriaAnd
{
public:
	FilterByDepartureAndPrice(string Departure, float price);
	virtual bool firstMatch(Offer offer);
	virtual bool secondMatch(Offer offer);

private:
	string Departure;
	float price;
};

class FilterByDepartureAndType :public FilteringCriteriaAnd
{
public:
	FilterByDepartureAndType(string Departure, Type type);
	virtual bool firstMatch(Offer offer);
	virtual bool secondMatch(Offer offer);

private:
	string Departure;
	Type type;
};


