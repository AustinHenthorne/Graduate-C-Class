/* Austin Henthorne MEC510:HW#7-01
This prorgam is an adaptation of an example program.
I will add the ability to sort user-entered english distances
in a descending order. */


/* English distance example: write two functions similar with
* "bsort" and "order" function in Example 23 to sort user-entered
* English distances in an decending order using "pointers to pointers"
* when passing an array of pointers to the sorting fuctions */
#include<iostream>
#include<cmath>
using namespace std;

class Distance	// define a class
{
protected:
	int feet;
	double inches;
public:
	Distance() : feet(0), inches(0) {}
	Distance(int ft, double in) : feet(ft), inches(in) {}

	void getdist() // get data from user
	{
		cout << "Enter feet: "; cin >> feet;
		cout << "Enter inches: "; cin >> inches;
	}

	void showdist() // show data
	{
		cout << feet << "\'-" << inches << "\"";
	}

	// function to return total distance for the bsort and order functions
	double dist()
	{
		double total = feet + inches / 12;
		return total;
	}

	// function declaration of overloaded <
	bool operator < (Distance) const;

};

//////////////////////////////////////////////////////////

void order(Distance** d1, Distance** d2) // function to order the distances
{
	if ((*d1)->dist() < (*d2)->dist())
	{
		Distance* tempptr = *d1; // swap 2 pointers
		*d1 = *d2;
		*d2 = tempptr;
	}
}


void bsort(Distance** d, int n)  // sort pointer to distances
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			order(d + i, d + j);
		}
	}
}

////////////////////////////////////////////////////////////

// compare this distance with dist2
bool Distance::operator < (Distance dist2) const
{
	double ft = feet + inches / 12;
	double ft2 = dist2.feet + dist2.inches / 12;
	return (ft < ft2) ? true : false;
}

int main()
{
	Distance* distPtr[100];

	int n = 0;		// number of persons in array
	char choice;		// inpur char

	do			// put persons in array
	{
		distPtr[n] = new Distance;
		distPtr[n]->getdist();
		n++;
		cout << "Continue (y/n)?"; cin >> choice;
	} while (choice != 'n');

	cout << "unsorted English distance list: \n";
	for (int i = 0; i<n; i++)
	{
		distPtr[i]->showdist();
		cout << endl;
	}

	bsort(distPtr, n);

	// sorted list
	cout << endl <<"Sorted List:" << endl;
	for (int i = 0; i < n; i++)
	{
		distPtr[i]->showdist();
		cout << endl;
	}

	return 0;
}


