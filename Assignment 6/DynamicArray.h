#pragma once
#include <string>
#include <ostream>
#include <iostream>
#include "Offer.h"
#include "MyOutOfBoundException.h"
using namespace std;

//typedef Offer ElementType;
template <typename ElementType>

class DynamicArray
{
public:
	DynamicArray(int capacity = 100)
	{
		length = 0;
		this->capacity = capacity;
		data = new ElementType[capacity]();

		if (data == nullptr) {
			cerr << "DynamicArray(): failed to allocate memory" << endl;
			exit(-1);
		}
	}
	
	~DynamicArray()
	{
		//free the allocated memory
		delete[] data;
	}
	
	DynamicArray(const DynamicArray& other)
	{
		// deep copy of other
		length = other.length;
		capacity = other.capacity;

		// !! data 
		// data = other.data; NOO! this is shallow copy
		// deep copy of data
		data = new ElementType[other.capacity + 1]();

		if (data == nullptr) {
			cerr << "DynamicArray(const DynamicArray& other): failed to allocate memory" << endl;
			exit(-1);
		}

		for (unsigned int i = 0; i < length; i++)
			data[i] = other.data[i];
	}

	DynamicArray& operator=(const DynamicArray& other)
	{
		if (this != &other) { // self assignment check
		// deep copy of other
			length = other.length;
			capacity = other.capacity;

			delete[] this->data;
			// !! data 
			// data = other.data; NOO! this is shallow copy
			// deep copy of data
			data = new ElementType[other.capacity + 1]();

			if (data == nullptr) {
				cerr << "operator=(): failed to allocate memory" << endl;
				exit(-1);
			}

			for (unsigned int i = 0; i < length; i++)
				data[i] = other.data[i];
		}
		return *this; // the type of this is DynamicArray* -> dereferencing
	}

	inline unsigned int getLength() const 
	{ 
		return length; 
	}

	inline unsigned int getCapacity() const 
	{ 
		return capacity; 
	}


	void append(ElementType v, bool* err = nullptr)
	{
		// todo 
		if (length == capacity) {
			// double the capacity
			resize(capacity * 2);
		}
		data[length] = v;
		length++;
	}

	ElementType popBack()
	{
		if (length == 0) 
		{
			throw new MyArrayIsEmpty();
		}
		ElementType v = data[length];
		length--;
		return v;
	}

	ElementType remove_at_index(unsigned int index)
	{
		if (index >= 0 && index < length) {
			ElementType v = data[index];
			for (unsigned int i = index; i < length - 1; i++)
				data[i] = data[i + 1];
			length--;
			return v;
		}
		else {
			throw new MyOutOfBoundException(0, length, index);
		}
	}

	ElementType& get_at_index(unsigned int index)
	{
		if (index >= 0 && index < length) 
		{
			return data[index];
		}
		else {

			throw new MyOutOfBoundException(0, length, index);
		}
	}

	friend ostream& operator<<(ostream& s, const DynamicArray& arr)
	{
		for (unsigned int i = 0; i < arr.length; i++)
		{
			s << arr.data[i];
			s << "\n";
		}
		return s;
	}
	
	friend bool operator == (const DynamicArray& arr1, const DynamicArray& arr2)
	{
		if (arr1.length != arr2.length)
			return false;
		for (unsigned int i = 0; i < arr1.length; i++)
			if (arr1.data[i] != arr2.data[i])
				return false;
		return true;
	}
	
	friend bool operator != (const DynamicArray& arr1, const DynamicArray& arr2)
	{
		return !(arr1 == arr2);
	}
	
	void resize(unsigned int newCapacity)
	{
		this->capacity = newCapacity;
		// no realloc  in c++

		ElementType* newData = new ElementType[newCapacity + 1]();
		if (newData == nullptr) {
			cerr << "resize(): failed to allocate memory" << endl;
			exit(-1);
		}
		// previous elements located in data
		// copy them in newData
		for (unsigned int i = 0; i < length; i++) {
			newData[i] = this->data[i];
		}

		delete[] this->data;
		this->data = newData;
	}


private:
	//static int count;
	unsigned int length;
	unsigned int capacity;
	ElementType* data;
};

