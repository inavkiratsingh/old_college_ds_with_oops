
#include <iostream>
using namespace std;
 
main()
{
 
	union intOrChar // Declaration of union;
	{
    	   char c[4];
    	   int x;
	}u1; //Declaration of Union_Object;
 
	u1.x = 'a'; // Assigning ‘a’ to x
 
	// Displaying the char array and integer value
	cout << "The value of c = " << u1.c[0] << "," << u1.c[1]
	     << "," << u1.c[2] << "," << u1.c[3]<< endl;
 
	cout << "The value of x = " << u1.x << endl;
 
	// Shifting the values one byte and adding ‘b’ to the int
	u1.x *= 256;
	u1.x += 'b';
 
	// Displaying the char array and integer value
	cout << "The value of c = " << u1.c[0] << "," << u1.c[1]
	     << "," << u1.c[2] << "," << u1.c[3]<< endl;
	cout << "The value of x = " << u1.x << endl;
 
	// Shifting the values one byte and adding ‘b’ to the int
	u1.x *= 256;
	u1.x += 'c';
 
	// Displaying the char array and integer value
	cout << "The value of c = " << u1.c[0] << "," << u1.c[1]
	     << "," << u1.c[2] << "," << u1.c[3]<< endl;
	cout << "The value of x = " << u1.x << endl;
 
	// Shifting the values one byte and adding ‘b’ to the int
	u1.x *= 256;
	u1.x += 'd';
 
	// Displaying the char array and integer value
	cout << "The value of c = " << u1.c[0] << "," << u1.c[1]
	     << "," << u1.c[2] << "," << u1.c[3]<< endl;
	cout << "The value of x = " << u1.x << endl;
 
	return 0;
}

