// Austin Henthorne MEC510: HW5-02
// This program adds a conversion operator to convert "time12" objects to "time24" objects
// This program builds on example16 code.


/*
* Two kinds of time case: conversion between objects of different classes
* one-arg constructor in destination object
*/
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

/** military time */
class time24
{
private:
	int hours;	// 0 - 23 
	int minutes;	// 0 - 59
	int seconds;	// 0 - 59
public:
	time24() : hours(0), minutes(0), seconds(0) {} 				// no-arg constructor
	time24(int h, int m, int s) : hours(h), minutes(m), seconds(s) {} 	// three-arg constructor
	void display()
	{
		cout << setw(2) << setfill('0') << hours << ':';
		cout << setw(2) << setfill('0') << minutes << ':';
		cout << setw(2) << setfill('0') << seconds;
	}

	//operator time12() const;						// conversion operator
	int gethrs() const { return hours; };
	int getmins() const { return minutes; };
	int getsecs() const { return seconds; };
};

/** civilian time */
class time12
{
private:
	bool pm;	// true: pm; false: am 
	int hrs;	// 1 - 12
	int mins;	// 0 - 59
public:
	time12() : pm(true), hrs(0), mins(0) {} // no-arg constructor
	time12(bool ap, int h, int m) : pm(ap), hrs(h), mins(m) {} // three-arg constructor
	time12(time24); // one-arg constructor
	void display()
	{
		cout << hrs << ':';
		cout << setw(2) << setfill('0') << mins << ' ';;
		string am_pm = pm ? "p.m. " : "a.m. ";
		cout << am_pm;
	}

	operator time24() const;	// conversion operator
};

////////////////////////////////////////////////////////////////////////////////
// Converting "time12" type objects to "time24" type objects 
time12::operator time24() const		// conversion operator
{
	int hrs12 = hrs;
	if (pm == true && hrs12 >= 1 && hrs12 < 12)
	{
		hrs12 = hrs12 + 12;
	}

	if (pm == true && hrs12 == 12)
	{
		hrs12 = hrs12;
	}

	if (pm == false && hrs12 == 12)
	{
		hrs12 = 0;
	}

	if (pm == false)
	{
		hrs12 = hrs12;
	}

	return time24(hrs12, mins, 00);
}



///////////////////////////////////////////////////////////////////////////////




time12::time12(time24 t24)
{
	int hrs24 = t24.gethrs();
	pm = (hrs24<12) ? false : true;

	mins = t24.getsecs() < 30 ? t24.getmins() : t24.getmins() + 1; 	// round seconds

	if (mins == 60)					// carry mins 
	{
		mins = 0;
		++hrs24;
		if (hrs24 == 12 || hrs24 == 24) pm = (pm == true) ? false : true; // carry hrs? yes toggle pm/am
	}

	hrs = (hrs24 > 13) ? hrs24 - 12 : hrs24;
	if (hrs == 0) { hrs = 12; pm = false; }
}

int main()
{
	int h, m, s;
	cout << "enter hour (0-23): "; cin >> h;
	cout << "enter minutes (0-59): "; cin >> m;
	cout << "enter seconds (0-59): "; cin >> s;
	time24 t24(h, m, s);
	cout << "24-hour time: "; t24.display(); cout << endl;

	time12 t12 = t24;

	cout << "12-hour time: "; t12.display(); cout << endl;


	// Creating a new time24 object
	time24 T24 = t12;		// converts the 12 hour time back to 24

	cout << endl << "The converted time back to 24 from the 12-hour time" << endl;
	cout << "24-hour time: "; T24.display(); cout << endl;		

	return 0;
}
