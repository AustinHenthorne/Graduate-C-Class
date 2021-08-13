/* Austin Henthorne MEC510:HW 8-01
This program uses virtual functions to compute shape area */

#include<iostream>
#include<cmath>

using namespace std;

float PI = 3.14159;
// parent class
class Shape 
{
public:
	virtual void input() = 0;
	virtual void comput_area() = 0;
};

// derived class for square
class Square : public Shape
{
private:
	float width, area;
public:

	void input()	// member function for user input
	{
		cout << "Enter the width: " << endl;
		cin >> width;
	}

	void comput_area()	// member function to compute area
	{
		area = pow(width, 2);
		cout << "The area is: " << area << endl;
	}
};

// derived class for circle
class Circle : public Shape
{
private:
	float radius, area;
public:

	void input()
	{
		cout << "Enter the radius: " << endl;
		cin >> radius;
	}

	void comput_area()
	{
		area = PI * pow(radius,2);
		cout << "The area is: " << area << endl;
	}

};


int main()
{
	char ans, ans2;
	cout << "This program calculates the area of a circle and a square." << endl << endl;

	do
	{
		cout << "Enter 's' to calculate area of a square and 'c' for a circle (s/c): ";
		cin >> ans;
		Shape* ptrsp;	// pointer for virtual function


		if (ans == 's')
		{
			ptrsp = new Square;
			ptrsp->input();
			ptrsp->comput_area();
		}

		if (ans == 'c')
		{
			cout << "The following will compute the area for a circle." << endl;
			ptrsp = new Circle;
			ptrsp->input();
			ptrsp->comput_area();
		}

		cout << "Would you like to compute another?:(y/n) ";
		cin >> ans2;

	} while (ans2 == 'y');

	return 0;

}