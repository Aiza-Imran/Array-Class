#include <iostream>
#include<cstdarg>
using namespace std;


#include "Array.h"

int main()
{
	Array s(4,1,2,3,5);   //The first argument (4) tells the capacity of the array. Even if we pass more arguments than 4, array will only consist of first for elements.
	
	s.display();        // Displays "1 2 3 5"

	cout << s.getCapacity() << '\n';     //4

	s.reSize(8);        //changes the capacity to 8. Elements remain same.
	cout << s.getCapacity() << '\n';     //8

	s[4] = 1;
	s[5] = 56;
	s[6] = 65;
	s[7] = 7;
	
	s.display();        //Displays "1 2 3 5 1 56 65 7"
	
	Array a1(6, 2, 4, 8, 1, 6, 9);
	a1.display();       //Displays "2 4 8 1 6 9"

	Array a2 = a1;
	a2.display();       //Displays "2 4 8 1 6 9"
	return 0;
}