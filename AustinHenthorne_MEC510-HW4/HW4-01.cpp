// Austin Henthorne MEC 510: HW4-01
/* This program reads from a text file, raw wind speed data from a MET tower and 
computes the the mean and standard deviation */

#include<iostream>
#include<cmath>
#include<fstream> // stream class for reading and writing a file 
#include<iomanip>
#include<string>

using namespace std;


// Creating a class for Wind
class Wind
{
private:	// wind speed member data declared as private

	string data[10000];		// data array size is 10000 to obtain all the strings in the file
	float averageX;			// These average variables are the average wind speeds for x, y and z
	float averageY;
	float averageZ;



public:
	const float numberofpoints = 1200;	// declaring the number of points as a constant global variable

	void readData()	// member function to read wind data from file
	{
		ifstream towerData;
		towerData.open("mettower.txt");

		if (towerData.is_open())
		{
			for (int i = 0; i < 10000; i++)
			{
				towerData >> data[i];
			}
		}
		towerData.close();
	}



	void windAverage()	// memeber function to compute the time-averaged values
	{
		float totalX = 0;
		float totalY = 0;
		float totalZ = 0;

		// This loop obtains the x-direction wind speeds and calculates the sum of the speeds.
		// The loop starts at the first x-direction speed string which is 18. 
		// The increment is +6 because the next x-direction speed is after 6 string values continously throughout the read file.
		// The condition is 7218 because since the number of speeds are 1200;   (1200*6)+18 = 7218
		for (int i = 18; i < 7218; i = i + 6)	
		{
			data[i];

			totalX = totalX + stof(data[i]);		// stof function turns a string into a float
		} 

		averageX = totalX / numberofpoints;
		cout << "The average velocity for the x-direction winds are: " << averageX << endl;



		// This loop stores the y-direction wind speeds
		// This loop starts at 19 as opposed to the x-direction
		for (int i = 19; i < 7219; i = i + 6)
		{
			data[i];

			totalY = totalY + stof(data[i]);
		}

		averageY = totalY / numberofpoints;
		cout << "The average velocity for the y-direction winds are: " << averageY << endl;



		// This loop stores the z-direction wind speeds
		// This loop starts at 20 
		for (int i = 20; i < 7220; i = i + 6)
		{
			data[i];

			totalZ = totalZ + stof(data[i]);
		}

		averageZ = totalZ / numberofpoints;
		cout << "The average velocity for the z-direction winds are: " << averageZ << endl << endl;

	}



	void windStandardDev()	// memeber function to compute the standard deviation values
	{
		float XsumSD = 0;
		float YsumSD = 0;
		float ZsumSD = 0;

		// The standard deviation for the x-direction
		for (int i = 18; i < 7218; i = i + 6)
		{
			data[i];

			XsumSD = XsumSD + pow( ( stof(data[i]) - averageX ), 2);
		}

		float xSD = sqrt(XsumSD / numberofpoints);
		cout << "The standard deviation for the x-direction is: " << xSD << endl;



		// The standard deviation for the y-direction
		for (int i = 19; i < 7219; i = i + 6)
		{
			data[i];

			YsumSD = YsumSD + pow((stof(data[i]) - averageY), 2);
		}

		float ySD = sqrt(YsumSD / numberofpoints);
		cout << "The standard deviation for the y-direction is: " << ySD << endl;



		// The standard deviation for the z-direction
		for (int i = 20; i < 7219; i = i + 6)
		{
			data[i];

			ZsumSD = ZsumSD + pow((stof(data[i]) - averageZ), 2);
		}

		float zSD = sqrt(ZsumSD / numberofpoints);
		cout << "The standard deviation for the z-direction is: " << zSD << endl;

	}
};

		


	
int main()
{
	Wind wind1;
	cout << "This program reads from a text file raw wind speed data from a MET tower," << endl << "and computes the the mean and standard deviation." << endl << endl;
	wind1.readData();
	wind1.windAverage();
	wind1.windStandardDev();
	return 0;
}