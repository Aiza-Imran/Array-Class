#include <iostream>     //For input and output
#include<stdarg.h>      //For variable length argument list
#include"Array.h"       //Header file of array class
using namespace std;


//tells whether given index is valid or out of range.
bool Array::isValidIndex(int index) const       
{
	return index >= 0 && index < capacity;
}

//Constructor. First argument tells the number of arguments that will be passed to this constructor. Then, values for array elements are passed.
Array::Array(int argCount, ...)
{
	if (argCount <= 0)
	{
		capacity = 0;
		data = nullptr;
		return;
	}

	capacity = argCount;
	data = new int[capacity];

	va_list vl;
	va_start(vl, argCount);
	for (int i = 0; i < capacity; i++)     //copies all the elements to array.
	{
		data[i]= va_arg(vl, int);
	}
	va_end(vl);

}

//Copy constructor
Array::Array(const Array& ref) :Array()    
{
	*this = ref;  //using copy assignment, deeply copies passed array's contents into the new array.
}

//copies an instance of a class deeply into another instance. Deep copy means copying the actual data of the object to another object.
Array& Array::operator = (const Array& ref)    
{
	if (this == &ref)       //if passed object is same as 'this' object, return as it is.
		return *this;

	this->~Array();         //Calling destructor to empty array.

	if (!ref.data)          //if passed array object is null, return empty array.
		return *this;

	capacity = ref.capacity;
	data = new int[capacity];
	for (int i = 0; i < capacity; i++)    //copies all the elements to 'this' array.
	{
		data[i] = ref.data[i];
	}
	return *this;

}

//Destructor
Array::~Array()   
{
	//frees memory on heap if occupied
	if (data)
	{
		delete[] data;
	}
	capacity = 0;
	data = nullptr;
}

//Move constructor. 
Array::Array(Array&& ref)     
{
	data = ref.data;
	capacity = ref.capacity;
	ref.data = nullptr;
}

//Move assignment. Shallow copies an object. Shallow copy means pointing to the already existing object in the memory rather than copying all elements.
Array& Array::operator = (Array&& ref)
{
	if (this == &ref)
		return *this;

	this->~Array();

	data = ref.data;
	capacity = ref.capacity;
	ref.data = nullptr;

	return *this;
}

//Index operator overloading. Allows index operator to be used with user defined array.
//Returns const parameter. Also, cannot change any data member's value because of the const used at end of function header.
const int& Array:: operator[](int ind) const
{
	if (isValidIndex(ind))
	{
		return data[ind];
	}
	exit(0);
}

//Index operator overloading. It can change value of any data member but it's not recommended.
int& Array::operator[](int ind)
{
	if (isValidIndex(ind))
	{
		return data[ind];
	}
	exit(0);
}

//Returns the total capacity of the array, not the size of array.
int Array::getCapacity()
{
	return capacity;
}

//resizes array to the new capacity given as argument.
void Array::reSize(int newCapacity)
{
	if (newCapacity <= 0)     //if new capacity is 0, empty existing array and return.
	{
		this->~Array();
		return;
	}

	int* temp = new int[newCapacity];
	for (int i = 0; i < newCapacity && i < capacity; i++)  //The reason for this condition(i < newCapacity && i < capacity) is that if new capacity is smaller than existing capacity, then copy elements according to the new capacity.
	{
		temp[i] = data[i];
	}
	this->~Array();

	data = temp;
	capacity = newCapacity;
}

//displays all the elements of array on screen.
void Array::display()
{
	for (int i = 0; i < capacity; i++)
	{
		cout << data[i] << " ";
	}
	cout << endl;
}