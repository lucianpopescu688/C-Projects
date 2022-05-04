#include "MyOutOfBoundException.h"
#include <string>
#include <iostream>
#include <sstream>

MyOutOfBoundException::MyOutOfBoundException()
{
	this->upperBound = 0;
	this->lowerBound = 0;
	this->index = 0;
}

MyOutOfBoundException::MyOutOfBoundException(int lowerBound, int upperBound, int index)
{
	this->upperBound = upperBound;
	this->lowerBound = lowerBound;
	this->index = index;
}

const char* MyOutOfBoundException::what() const throw()
{
	if (msg.empty())
	{
		std::stringstream ss;
		ss << "Index " << index << " is out of bound. The index should be between " << lowerBound << " and " << upperBound - 1;
		msg = ss.str();
	}
	return msg.c_str();
}

MyArrayIsEmpty::MyArrayIsEmpty()
{
}

const char* MyArrayIsEmpty::what() const throw()
{
	return "Array is empty. Operation of remove an element failed";
}
