// Austin Henthorne MEC 510 HW:1-02
// This program will convert temperature from degrees Celcius to Fahrenheit

#include<iostream>
#include<cmath>

using namespace std;
int main()
{
	cout << "This program converts degrees celcius to degrees fahrenheit" << endl << endl;
	float tempCelcius, tempFahren;
	cout << "Please enter the temperature in degrees celcius: ";
	cin >> tempCelcius;

	tempFahren = (tempCelcius * 1.8) + 32;

	cout << "The temperature in degrees fahrenheit is: " << tempFahren << endl;
	return 0;
}
