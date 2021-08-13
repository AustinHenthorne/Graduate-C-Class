// Austin Henthorne MEC 510: HW5-01
// This program sorts dates into ascending order using an overloaded comparison operator
// The user will input random dates

#include<iostream>
#include<cmath>
using namespace std;


class Date
{
private:
	int month, year, day;
	int totaldays;

	int daysTotal;
	
public:
	Date() : month(0), year(0), day(0)		// constructor
	{	}

	Date(int mon, int yr, int d) : month(mon), year(yr), day(d)
	{	}

	void getdate()		// get date from user
	{
		cout << "Enter the month: ";
		cin >> month;
		cout << "Enter the day: ";
		cin >> day;
		cout << "Enter the year: ";
		cin >> year;
	}


	void showdate() const		// display date
	{
		cout << month << "/" << day << "/" << year;
	}


	////////////////////////////////////////////////////////////////////////////////


	// This member function obtains the total days for the date
	void numbDays()
	{
		int days_per_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		totaldays = day;
		for (int i = 0; i < month - 1; i++)
		{
			totaldays += days_per_month[i];
		}

		daysTotal = (364 * year) + (totaldays);

		cout << daysTotal;

	}




	// function declaration of overloaded <
	bool operator < (Date) const;
};

bool Date::operator < (Date date1) const
{

	int days_per_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	int totaldays, daysTotal;

	totaldays = day;
	for (int i = 0; i < month - 1; i++)
	{
		totaldays += days_per_month[i];
	}

	daysTotal = (364 * year) + (totaldays);





	date1.totaldays = date1.day;
	for (int i = 0; i < date1.month - 1; i++)
	{
		date1.totaldays += days_per_month[i];
	}

	date1.daysTotal = (364 * date1.year) + date1.totaldays;
	int totalClass = date1.daysTotal;

	int d1 = daysTotal;

	int d2 = totalClass;

	return (d1 < d2) ? true : false;
}

/////////////////////////////////////////////////////////////////////////////////////////


int main()
{
	Date date[100];
	Date tempdate;
	int n = 0;
	char ans;

	cout << "This program sorts dates in ascending order" << endl << endl;
	do
	{
		date[n++].getdate();
		cout << "Add a date? (y/n): ";
		cin >> ans;

	} while (ans != 'n');

	// Function to output the dates
	cout << "The dates entered are: " << endl;

	for (int i = 0; i < n; i++)
	{
		date[i].showdate();
		cout << endl;

	}



	// Function to calculate number of days for a given date
	cout << "The total number of days in the dates are: " << endl;

	for (int i = 0; i < n; i++)
	{
		cout << endl;
		date[i].numbDays();
		cout << endl;
	}



	cout << "The ascending order is: " << endl;

	//code to sort the date in ascending order
	for (int i = 0; i <= n-1; i++)
	{
		for (int j = 1; j < n-1; j++)
		{
			if (date[j] < date[i])
			{
				tempdate = date[j];
				date[j] = date[i];
				date[i] = tempdate;
			}
			else
			{
				continue;
			}

		}
		date[i].showdate();
		cout << endl;
	}

}