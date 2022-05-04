#pragma once
#include <exception>
#include <iostream>
#include <sstream>
#include <string>

class MyOutOfBoundException : public std::exception
{
public:
	MyOutOfBoundException();
	MyOutOfBoundException(int lowerBound, int upperBound, int index);
	const char* what() const throw();
private:
	int lowerBound;
	int upperBound;
	int index;
	mutable std::string msg;
};

class MyArrayIsEmpty : public std::exception
{
public:
	MyArrayIsEmpty();
	const char* what() const throw();	
};

