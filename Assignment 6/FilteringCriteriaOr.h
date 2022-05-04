#pragma once
#include "FilteringCriteria.h"
#include <cstring>

class FilteringCriteriaOr : public FilteringCriteria
{
public:
	virtual bool match(Offer offer) final;
	virtual bool firstMatch(Offer offer) = 0;
	virtual bool secondMatch(Offer offer) = 0;
};

class FilterByDoubleDeparture : public FilteringCriteriaOr
{
public:
	FilterByDoubleDeparture(string Departure1, string Departure2);
	virtual bool firstMatch(Offer offer);
	virtual bool secondMatch(Offer offer);

private:
	string Departure1;
	string Departure2;
};
