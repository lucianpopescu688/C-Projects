#include "FilteringCriteria.h"
#include <iostream>
using namespace std;

DynamicArray<Offer> FilteringCriteria::filter(DynamicArray<Offer>& data)
{
	DynamicArray<Offer> result;
	for (int i = 0; i < data.getLength(); i++)
	{
		if (this->match(data.get_at_index(i)))
			result.append(data.get_at_index(i));
	}
	return result;
}

bool FilterByPrice::match(Offer offer)
{
	return offer.getPrice() <= this->price;
}

FilterByPrice::FilterByPrice(float price)
{
	this->price = price;
}

bool FilterByType::match(Offer offer)
{
	return offer.getType() == this->filterType;
}

FilterByType::FilterByType(Type filterType)
{
	this->filterType = filterType;
}

bool FilterByDeparture::match(Offer offer)
{
	return offer.getDeplocation() == this->Departure;
}

FilterByDeparture::FilterByDeparture(string Departure)
{
	this->Departure = Departure;
}
