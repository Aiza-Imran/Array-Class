#ifndef ARRAY_h
#define ARRAY_h

class Array
{
	int* data;       //stores pointer to array
	int capacity;    //capacity of the array
	bool isValidIndex(int index) const;
public:
	Array(int argCount = 0, ...);   //acts as both a default constructor and a parameterized constructor. 
	Array(const Array&);            //copy constructor
	Array& operator = (const Array&);   //copy assignment
	~Array();            //destructor
	Array(Array&&);      //move constructor
	Array& operator = (Array&&);      //move assignment
	const int& operator[](int)const;   //const index operator
	int& operator[](int);              //index operator
	//int& getSet(int index);
	int getCapacity();          //returns the capacity of the array
	void reSize(int newCapacity);      //resizes array when filled.
	void display();           //displays contents of array
};

#endif // !ARRAY_h

