#include "FilteringCriteriaAnd.h"

bool FilteringCriteriaAnd::match(Offer offer)
{
	return this->firstMatch(offer) && this->secondMatch(offer);
}

FilterByTypeAndPrice::FilterByTypeAndPrice(Type type, float price)
{
	this->price = price;
	this->type = type;
}

bool FilterByTypeAndPrice::firstMatch(Offer offer)
{
	return offer.getPrice() <= this->price;
}

bool FilterByTypeAndPrice::secondMatch(Offer offer)
{
	return offer.getType() == this->type;
}

FilterByDepartureAndPrice::FilterByDepartureAndPrice(string Departure, float price)
{
	this->Departure = Departure;
	this->price = price;
}

bool FilterByDepartureAndPrice::firstMatch(Offer offer)
{
	return offer.getDeplocation() == this->Departure;
}

bool FilterByDepartureAndPrice::secondMatch(Offer offer)
{
	return offer.getPrice() <= this->price;
}

FilterByDepartureAndType::FilterByDepartureAndType(string Departure, Type type)
{
	this->Departure = Departure;
	this->type = type;
}

bool FilterByDepartureAndType::firstMatch(Offer offer)
{
	return offer.getDeplocation() == this->Departure;
}

bool FilterByDepartureAndType::secondMatch(Offer offer)
{
	return offer.getType() == this->type;
}
