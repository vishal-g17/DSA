#include<iostream> 
using namespace std;

#define PI 3.14

int main() {

    int r = 5;
    //double pi = 3.14;

    double area = PI * r * r;

    cout << "Area is " << area << endl;

    return 0;
}


// C program to illustrate macros
#include <stdio.h>

// Macro definition
#define LIMIT 5

// Driver Code
int main()
{
	// Print the value of macro defined
	printf("The value of LIMIT"
		" is %d",
		LIMIT);

	return 0;
}




// C program to illustrate macros
#include <stdio.h>

// Macro definition
#define AREA(l, b) (l * b)

// Driver Code
int main()
{
	// Given lengths l1 and l2
	int l1 = 10, l2 = 5, area;

	// Find the area using macros
	area = AREA(l1, l2);

	// Print the area
	printf("Area of rectangle"
		" is: %d",
		area);

	return 0;
}



// C program to illustrate macros
#include <stdio.h>

// Macro definition
#define DATE 31

// Driver Code
int main()
{
	// Print the message
	printf("Lockdown will be extended"
		" upto %d-MAY-2020",
		DATE);

	return 0;
}



// C program to illustrate macros
#include <stdio.h>

// Macro definition
#define INSTAGRAM FOLLOWERS
#define FOLLOWERS 138

// Driver Code
int main()
{
	// Print the message
	printf("Geeks for Geeks have %dK"
		" followers on Instagram",
		INSTAGRAM);

	return 0;
}


// C program to illustrate macros
#include <stdio.h>

// Multi-line Macro definition
#define ELE 1, \
			2, \
			3

// Driver Code
int main()
{

	// Array arr[] with elements
	// defined in macros
	int arr[] = { ELE };

	// Print elements
	printf("Elements of Array are:\n");

	for (int i = 0; i < 3; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}


// C program to illustrate macros
#include <stdio.h>

// Function-like Macro definition
#define min(a, b) (((a) < (b)) ? (a) : (b))

// Driver Code
int main()
{

	// Given two number a and b
	int a = 18;
	int b = 76;

	printf("Minimum value between"
		" %d and %d is %d\n",
		a, b, min(a, b));

	return 0;
}


#include <iostream>
using namespace std;
#define PI 3.1416
#define AREA(r) (PI*(r)*(r))

int main() {
	
	float r = 7; // radius of circle
	
	cout<<"Area of Circle with radius " << r <<": "<< AREA(r);

	return 0;
}

// This code is contributed by balbiriitbombay3602
