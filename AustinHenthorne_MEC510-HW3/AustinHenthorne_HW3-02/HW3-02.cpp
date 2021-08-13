// Austin Henthorne MEC 510: HW3-02
/* This program calculates the power of two wind turbines. One turbine recieves the full wind speed, 
while the other turbine is downwind of the first turbine which recieves less wind*/

/* The program will prompt the user to input: incoming wind speed, rotor radius, inducation factor, 
and the distance between the turbines */


#include<iostream>
#include<cmath>
using namespace std;

const float alpha = 0.1;
const float ro = 1.225;
const float pi = 3.14159265;

float wakeVel(float velocity, float factor, float radius, float Distance);

class Turbine
{
private:
	float rotorRadius;		// rotor radius
	float axialFactor;		// axial induction factor
	float incomingWind;		// incoming wind speed
	float distance;		// distance between rotors

public:
	void setdata(float r, float a, float u, float x)
	{
		rotorRadius = r;
		axialFactor = a;
		incomingWind = u;
		distance = x;
	}

	void Power()
	{
		float P;
		P = 0.5 * (4 * axialFactor*pow((1 - axialFactor), 2)) * ro * pi * pow(rotorRadius, 2) * pow(incomingWind, 3);
		cout << P << "Watts" << endl;
	}
};

int main()
{
	Turbine turbine1, turbine2;
	float V, R, A, X;
	float u2;

	cout << "This program calculates the power of two inline wind turbines" << endl << endl;

	cout << "Please enter the incoming wind speed: " << endl;
	cin >> V;
	cout << "Please enter the rotor radius: " << endl;
	cin >> R;
	cout << "Please enter the axial induction factor: " << endl;
	cin >> A;
	cout << "Please enter the distance between the rotors: " << endl;
	cin >> X;

	turbine1.setdata(R, A, V, X);

	u2 = wakeVel(V, A, R, X);
	turbine2.setdata(R, A, u2, X);

	cout << "The Power of the first turbine is: "; turbine1.Power();
	cout << "The Power of the second turbine is: "; turbine2.Power();

}


float wakeVel(float velocity, float factor, float radius, float Distance)
{
	float r;
	r = radius + (alpha*Distance);

	float Vel;
	Vel = velocity * (1 - (2 * factor*(pow((radius / r), 2))));
	return Vel;
}