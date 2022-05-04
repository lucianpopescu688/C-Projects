#include "FilteringCriteriaOr.h"

bool FilteringCriteriaOr::match(Offer offer)
{
	return this->firstMatch(offer) || this->secondMatch(offer);
}

FilterByDoubleDeparture::FilterByDoubleDeparture(string Departure1, string Departure2)
{
	this->Departure1 = Departure1;
	this->Departure2 = Departure2;
}

bool FilterByDoubleDeparture::firstMatch(Offer offer)
{
	return offer.getDeplocation() == this->Departure1;
}

bool FilterByDoubleDeparture::secondMatch(Offer offer)
{
	return offer.getDeplocation() == this->Departure2;
}
