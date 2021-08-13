// Austin Henthorne, Glenn Ellis MEC 510: Final Project
/* This program reads from a text file, raw wind speed data from a MET tower and
computes the the mean and standard deviation */

#include<iostream>
#include<cmath>
#include<fstream> // stream class for reading and writing a file 
#include<iomanip>
#include<string>
#include<algorithm>

using namespace std;
const int PI = 3.14159265359;

// Creating a class for Wind
class Wind
{
private:	// wind speed member data declared as private

	float averageDirection;
	float averageSpeed;

	int startindex, endindex;


	string date1[1441], time1[1441];
	string speed1[1441], direction1[1441];

	string date2[1441], time2[1441];
	string speed2[1441], direction2[1441];

	string date3[1441], time3[1441];
	string speed3[1441], direction3[1441];

	string date4[1441], time4[1441];
	string speed4[1441], direction4[1441];

	string Speed[5761];
	string Direction[5761];



public:
	

	void readData()	// member function to read wind data from files
	{

		ifstream towerData, towerData2, towerData3, towerData4;
		

		// Read data from 5/3/17 excel file
			towerData.open("a170503.csv");

			if (towerData.is_open())
			{
				for (int i = 0; i < 1441; i++)
				{
					getline(towerData, date1[i], ',');
					getline(towerData, time1[i], ',');
					getline(towerData, speed1[i], ',');
					getline(towerData, direction1[i], '\n');

					// Block of code to deal with an empty data point to turn it into a 0
					if (speed1[i].empty())
					{
						speed1[i] = "0.0";
					}

					if (direction1[i].empty())
					{
						direction1[i] = "0.0";
					}
				}
			}
			towerData.close();

		

			// Read data from 5/4/17 excel file
			towerData2.open("a170504.csv");

			if (towerData2.is_open())
			{
				for (int i = 0; i < 1441; i++)
				{
					getline(towerData2, date2[i], ',');
					getline(towerData2, time2[i], ',');
					getline(towerData2, speed2[i], ',');
					getline(towerData2, direction2[i], '\n');

					// Block of code to deal with an empty data point to turn it into a 0
					if (speed2[i].empty())
					{
						speed2[i] = "0.0";
					}

					if (direction2[i].empty())
					{
						direction2[i] = "0.0";
					}
				}
			}
			towerData2.close();
		
			

			// Read data from 5/5/17 excel file
			towerData3.open("a170505.csv");

			if (towerData3.is_open())
			{
				for (int i = 0; i < 1441; i++)
				{
					getline(towerData3, date3[i], ',');
					getline(towerData3, time3[i], ',');
					getline(towerData3, speed3[i], ',');
					getline(towerData3, direction3[i], '\n');

					// Block of code to deal with an empty data point to turn it into a 0
					if (speed3[i].empty()) 
					{
						speed3[i] = "0.0";
					}

					if (direction3[i].empty())
					{
						direction3[i] = "0.0";
					}

				}
			}
			towerData3.close();
		

			// Read data from 5/6/17 excel file
			towerData4.open("a170506.csv");

			if (towerData4.is_open())
			{
				for (int i = 0; i < 1441; i++)
				{
					getline(towerData4, date4[i], ',');
					getline(towerData4, time4[i], ',');
					getline(towerData4, speed4[i], ',');
					getline(towerData4, direction4[i], '\n');

					// Block of code to deal with an empty data point to turn it into a 0
					if (speed4[i].empty())
					{
						speed4[i] = "0.0";
					}

					if (direction4[i].empty())
					{
						direction4[i] = "0.0";
					}
				}
			}
			towerData4.close();
		

		// concating the string arrays to store all the speed data into 1 array
			for (int i = 0; i < 1441; i++)
			{
				Speed[i] = speed1[i];
			}

			for (int i = 1441; i < 2881; i++)
			{
				Speed[i] = speed2[i - 1440];
			}

			for (int i = 2881; i < 4321; i++)
			{
				Speed[i] = speed3[i - 2880];
			}


			for (int i = 4321; i < 5761; i++)
			{
				Speed[i] = speed4[i - 4320];
			}

			// Display All the speed data
			/*for (int i = 0; i < 5761; i++)
			{
				cout << Speed[i] << endl;
			}*/


			// concating the string arrays to store all the direction data into 1 array
			for (int i = 0; i < 1441; i++)
			{
				Direction[i] = direction1[i];
			}

			for (int i = 1441; i < 2881; i++)
			{
				Direction[i] = direction2[i - 1440];
			}


			for (int i = 2881; i < 4321; i++)
			{
				Direction[i] = direction3[i - 2880];
			}


			for (int i = 4321; i < 5761; i++)
			{
				Direction[i] = direction4[i - 4320];
			}

			// Display All the direction data
			/*for (int i = 0; i < 5761; i++)
			{
			cout << Direction[i] << endl;
			}*/


			// User inputs
			string startDate;
			cout << "Please enter the start date (Ex; 5/3/17): " << endl;
			getline(cin, startDate);

			int startHour, startMinute;
			cout << "Enter the start hour (0-23): " << endl;
			cin >> startHour;
			cout << "Enter the start minute (0-59): " << endl;
			cin >> startMinute;
			cout << endl;

			string endDate;
			cout << "Please enter the end date (Ex; 5/4/17): " << endl;
			cin >> endDate;

			int endHour, endMinute;
			cout << "Enter the end hour (0-23): " << endl;
			cin >> endHour;
			cout << "Enter the end minute (0-59): " << endl;
			cin >> endMinute;

			// The start index number
			if (startDate == "5/3/17")
			{
				startindex = 1;
			}

			else if (startDate == "5/4/17")
			{
				startindex = 1441;
			}

			else if (startDate == "5/5/17")
			{
				startindex = 2881;
			}

			else if (startDate == "5/6/17")
			{
				startindex = 4321;
			}

			startindex = startindex + startMinute + (startHour * 60);
			

			// The end index number
			if (endDate == "5/3/17")
			{
				endindex = 1;
			}

			else if (endDate == "5/4/17")
			{
				endindex = 1441;
			}

			else if (endDate == "5/5/17")
			{
				endindex = 2881;
			}

			else if (endDate == "5/6/17")
			{
				endindex = 4321;
			}

			endindex = endindex + endMinute + (endHour * 60);

			
	}










	void windAverage()	// memeber function to compute the time-averaged values
	{
		float totalSpeed = 0;
		float totalDirection = 0;
		int numberofpoints = endindex - startindex;

		// Speed average
		for (int i = startindex; i <= endindex; i++)
		{
			Speed[i];

			totalSpeed = totalSpeed + stof(Speed[i]);		// stof function turns a string into a float
		}

		averageSpeed = totalSpeed / numberofpoints;
		cout << "The average velocity for the wind speeds are: " << averageSpeed << endl;
		

		// Direction average
		for (int i = startindex; i <= endindex; i++)
		{
			Direction[i];

			totalDirection = totalDirection + stof(Direction[i]);		// stof function turns a string into a float
		}

		averageDirection = totalDirection / numberofpoints;
		cout << "The average velocity for the wind directions are: " << averageDirection << endl;


	}


	// member function to return average speed for the Turbine class (calculate power)
	float windSpeed()
	{
		return averageSpeed;
	}



	void windStandardDev()	// memeber function to compute the standard deviation values
	{
		float SpeedsumSD = 0;
		float DirectionsumSD = 0;
		int numberofpoints = endindex - startindex;

		// The standard deviation for the wind speeds
		for (int i = startindex; i <= endindex; i++)
		{
			Speed[i];

			SpeedsumSD = SpeedsumSD + pow((stof(Speed[i]) - averageSpeed), 2);
		}

		float speedSD = sqrt(SpeedsumSD / numberofpoints);
		cout << "The root mean square for the wind speeds is: " << speedSD << endl;



		// The standard deviation for the wind directions
		for (int i = startindex; i <= endindex; i++)
		{
			Direction[i];

			DirectionsumSD = DirectionsumSD + pow((stof(Direction[i]) - averageDirection), 2);
		}

		float DirectionSD = sqrt(DirectionsumSD / numberofpoints);
		cout << "The root mean square for the wind directions is: " << DirectionSD << endl;

	}
};

// Class to calculate the power of the turbine
class Turbine
{
private: 
	float Power, density, Cp, rotor;

public:
	void power(float U)
	{
		cout << "Enter the air density: ";
		cin >> density;
		cout << "Enter the power coefficient: ";
		cin >> Cp;
		cout << "Enter the rotor radius: ";
		cin >> rotor;
		
		
		Power = 0.5 * density * Cp * PI * pow(rotor, 2) * pow(U, 2);
		cout << "The power of the turbine is: " << Power << endl;
	}


};





int main()
{
	Wind wind1;
	Turbine turbine1;
	cout << "This program reads from text files raw wind speed data from a MET tower," << endl << "and computes the mean and the root mean square for the speed and direction for a particular time period." << endl << endl;
	wind1.readData();		// Reads data and stores speed data into an array and direction data into another array
	wind1.windAverage();		// Calculates the average speed and direction values from user entered date range
	wind1.windStandardDev();	// Calculates the root mean square of speed and direction values from user entered date range

	float U = wind1.windSpeed();
	cout << endl << endl;
	cout << "The following computes the Power of the turbine based on the specified time period." << endl;
	turbine1.power(U);
	return 0;
}