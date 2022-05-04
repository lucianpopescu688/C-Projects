#include "Offer.h"
#include <iostream>

//Setters
std::string Offer::getID() const
{
	return id;
}
std::string Offer::getDeplocation() const
{
	return departureLocation;
}
std::string Offer::getDeslocation() const
{
	return destinationLocation;
}
std::string Offer::getStartDate() const
{
	return startDate;
}
std::string Offer::getEndDate() const
{
	return endDate;
}
Type Offer::getType() const
{
	return type;
}
int Offer::getPrice() const
{
	return price;
}

void Offer::setID(std::string newID)
{
	id = newID;
}

void Offer::setDeplocation(std::string newDeplocation)
{
	departureLocation = newDeplocation;
}

void Offer::setDeslocation(std::string mewDeslocation)
{
	destinationLocation = mewDeslocation;
}

void Offer::setStartDate(std::string newStartdate)
{
	startDate = newStartdate;
}

void Offer::setEndDate(std::string newEndDate)
{
	endDate = newEndDate;
}

void Offer::setPrice(int newPrice)
{
	price = newPrice;
}

void Offer::setType(Type newType)
{
	type = newType;
}

Offer::Offer(std::string newID, std::string newDeplocation, std::string mewDeslocation, std::string newStartdate, std::string newEndDate, Type newType, int newPrice)
{
	id = newID;
	departureLocation = newDeplocation;
	destinationLocation = mewDeslocation;
	startDate = newStartdate;
	endDate = newEndDate;
	type = newType;
	price = newPrice;
}

void Offer::getdata()
{
	int type_number;
	std::cout << "FLIGHT READY" << "\n";
	std::cout << "Enter ID of the offer: ";
	std::cin >> id;
	std::cout << "Enter departure location of the flight: ";
	std::cin >> departureLocation;
	std::cout << "Enter destination location of the flight: ";
	std::cin >> destinationLocation;
	std::cout << "Enter the start date of the flight: ";
	std::cin >> startDate;
	std::cout << "Enter the end date of the flight: ";
	std::cin >> endDate;
	std::cout << "Enter the airplane type number: 0-circuit, 1-city_break, 2-cruise, 3-all_inclusive: ";
	std::cin >> type_number;
	switch (type_number)
	{
	case 0:
		type = circuit;	
		break;
		
	case 1:
		type = city_break;
		break;
	
	case 2:
		type = cruise;
		break;
	
	case 3:
		type = all_inclusive;
		break;
	}
	std::cout << "Enter the price of the ticket: ";
	std::cin >> price;
	std::cout << "\n";
}

Offer::Offer()
{
	id = '0';
	departureLocation = '0';
	destinationLocation = '0';
	price = 0;
	startDate = '0';
	endDate = '0';
	type = cruise;
}

bool operator==(const Offer& offer1, const Offer& offer2)
{
	if(offer1.getID() == offer2.getID())
	{
		if(offer1.getDeplocation() == offer2.getDeplocation())
		{
			if(offer1.getDeslocation() == offer2.getDeslocation())
			{
				if(offer1.getStartDate() == offer2.getStartDate())
				{
					if(offer1.getEndDate() == offer2.getEndDate())
					{
						if(offer1.getType() == offer2.getType())
						{
							if(offer1.getPrice() == offer2.getPrice())
							{
								return true;
							}
						}
					}
				}
			}
		}
	}
	return false;
}

bool operator!=(const Offer& offer1, const Offer& offer2)
{
	return (!(offer1 == offer2));
}

ostream& operator<<(std::ostream& os, const Offer& offer)
{
	os << "The flight with the name: " << offer.getID() << " takes off from the airport from: " << offer.getDeplocation();
	os << " with destination: " << offer.getDeslocation() << " departing on: " << offer.getStartDate();
	os << " and lands on: " << offer.getEndDate() << " with the type of flight: ";
	switch (offer.getType())
	{
	case 0:
		os << "circuit";
		break;

	case 1:
		os << "city_break";
		break;

	case 2:
		os << "cruise";
		break;

	case 3:
		os << "all_inclusive";
		break;
	}
	os << " and with the price of tickets: " << offer.getPrice() << " euro" << "\n";
	return os;
}
