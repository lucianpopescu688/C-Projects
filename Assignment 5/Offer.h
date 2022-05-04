#pragma once
#include <string>
#include <ostream>
#include <iostream>
using namespace std;
enum Type {
	circuit,
	city_break,
	cruise,
	all_inclusive
};
class Offer
{
public:
	//Getters
	std::string getID() const;
	std::string getDeplocation() const;
	std::string getDeslocation() const;
	std::string getStartDate() const;
	std::string getEndDate() const;
	Type getType() const;
	int getPrice() const;

	//Setters
	void setID(std::string newID);
	void setDeplocation(std::string newDeplocation);
	void setDeslocation(std::string mewDeslocation);
	void setStartDate(std::string newStartdate);
	void setEndDate(std::string newEndDate);
	void setPrice(int newPrice);
	void setType(Type newType);

	Offer();
	Offer(std::string newID, std::string newDeplocation, std::string mewDeslocation, std::string newStartdate, std::string newEndDate, Type newType, int newPrice);

	friend bool operator == (const Offer& offer1, const Offer& offer2);
	friend bool operator != (const Offer& offer1, const Offer& offer2);
	friend ostream& operator << (std::ostream& os, const Offer& offer);
	void getdata();

private:
	std::string id;
	std::string departureLocation;
	std::string destinationLocation;
	int price;
	std::string startDate;
	std::string endDate;
	Type type;
};
