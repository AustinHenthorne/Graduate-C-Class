// Austin Henthorne MEC 510: HW3-01
/* This program calculates the wake radius and the velocity
in the wake at a given location for a wind turbine */

/* This program prompts the user to input the incoming 
wind speed, rotor radius, axial induction factor, and downward
distance from the rotor */

#include<iostream>
#include<cmath>
using namespace std;

void wakeRad (float initRad, float x, float&);
float wakeVel (float vel, float factor, float initRad, float Rad);

const float alpha = 0.1;

struct Turbine
{
	float r0;		// rotor radius
	float u;		// incoming wind speed
	float a;		// axial induction factor
	float x;		// downward distance from rotor
};

int main()
{
	float radWake;
	float velWake;

	Turbine turbine1;
	cout << "This program calculates the radius and the velocity in the wake of a wind turbine " << endl << endl;

	cout << "Please enter the incoming wind speed (m/s): " << endl;
	cin >> turbine1.u;

	cout << "Please enter the axial induction factor: " << endl;
	cin >> turbine1.a;

	cout << "Please enter the downward distance frome the turbine (m): " << endl;
	cin >> turbine1.x;

	cout << "Please enter the rotor radius: " << endl;
	cin >> turbine1.r0;

	wakeRad(turbine1.r0, turbine1.x, radWake);

	velWake = wakeVel(turbine1.u, turbine1.a, turbine1.r0, radWake);

	cout << "The radius of the wake is: " << radWake << " meters" << endl;
	cout << "The velocity of the wake is: " << velWake << " m/s" << endl;

}

// Function to calculate radius of the wake
// Radius of the wake if passed by reference
void wakeRad(float initRad, float x, float& radWake)
{
	radWake = initRad + (alpha*x);
}

// Function to calculate velocity
float wakeVel(float vel, float factor, float initRad, float Rad)
{
	float V;
	V = vel * (1 - ((2 * factor) * ( pow(initRad / Rad,2) )));
	return V;
}