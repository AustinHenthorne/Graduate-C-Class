// Austin Henthorne MEC510: HW2-02
// This program calculates the power produced by a wind turbine.
// The user will enter the winds speeds (u,v,w) and the yaw angle for the wind turbine


#include<iostream>
#include<cmath>

using namespace std;

struct Cmpnts
{
	double x, y, z;
};

struct Wind
{
	Cmpnts velocity;
	Cmpnts direction;
	double airdensity;
};

struct Turbine
{
	double R, CP, V, yaw, power;
	Cmpnts direction;
};

int main()
{
	double degYaw, u, v, w;
	double pi = 3.1415926535897;

	Turbine Turbine1;
	Wind Wind1;

	Turbine1.R = 48;
	Turbine1.CP = 0.46;
	Wind1.airdensity = 1.225;


	cout << "This Progam calculates the power of a wind turbine as a function of the yaw angle and wind velocities." << endl << endl;

	// Wind velocity for x, y and z directions 
	cout << "Please enter the wind velocity in m/s for the north-south direction (u): ";
	cin >> u;
	cout << "Please enter the wind velocity in m/s for the west-east direction (v): ";
	cin >> v;
	cout << "Please enter the wind velocity in m/s for the vertical direction (w): ";
	cin >> w;

	Wind1.velocity.x = u;
	Wind1.velocity.y = v;
	Wind1.velocity.z = w;


	// Yaw angle in degrees
	cout << "Please enter the yaw angle in degrees: " ;
	cin >> degYaw;

	// Converting the yaw to radians
	Turbine1.yaw = degYaw*(pi / 180);
	

	// Wind direction for x, y and z
	Wind1.direction.x = u / (sqrt(pow(u, 2) + pow(v, 2) + pow(w, 2)));
	Wind1.direction.y = v / (sqrt(pow(u, 2) + pow(v, 2) + pow(w, 2)));
	Wind1.direction.z = w / (sqrt(pow(u, 2) + pow(v, 2) + pow(w, 2)));

	// Turbine pointing direction
	Turbine1.direction.x = (Wind1.direction.x * cos(Turbine1.yaw)) - (Wind1.direction.y * sin(Turbine1.yaw));
	Turbine1.direction.y = (Wind1.direction.x * sin(Turbine1.yaw)) + (Wind1.direction.y * cos(Turbine1.yaw));
	Turbine1.direction.z = 0;

	// Incoming Wind speed for the turbine
	Turbine1.V = (u * Turbine1.direction.x) + (v * Turbine1.direction.y);

	Turbine1.power = 0.5 * Wind1.airdensity * Turbine1.CP * pi * pow(Turbine1.R, 2) * pow(Turbine1.V, 3);

	cout << "The power output of the wind turbine is: " << Turbine1.power << " Watts" << endl;

	return(0);
}