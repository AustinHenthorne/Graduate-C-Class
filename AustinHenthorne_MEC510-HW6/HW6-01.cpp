// Austin Henthorne MEC510: HW#6-01
// This program uses inheritance to derive a class


/* create a derived class turbine_dev adding capability for computing incoming turbulence intensity of each turbine */
#include<iostream>
#include<cmath>
using namespace std;

double turb_intensity;
const double PI = acos(-1.0);
const double rho = 1.225;
double windspeed_freeincoming;

class turbine	// define a turbine class
{
protected:
	double turbinecoor; 		// location of the turbine
	double radius_rotor;		// rotor radius
	double inductionfactor_axis; 	// axial induction factor
	double coeff_power; 		// power coefficient
	double windspeed_incoming;	// incoming wind speed for this turbine
	double power;			// produced power
	double coeff_entrainment;	// entrainment coefficient
	int facefreewind;		// facing free wind: 1-yes, 0-no

public:
	double Sx;
	// ctor
	turbine() : coeff_entrainment(0.1) {  }

	// ask user to enter turbine characteristics
	void getturbine()
	{
		cout << "Enter turbine characteristics: " << endl;
		cout << "\t turbine location (m): "; cin >> turbinecoor;
		cout << "\t rotor radius (m): "; cin >> radius_rotor;
		cout << "\t axial induction factor: "; cin >> inductionfactor_axis;
		cout << "\t facing free wind?: "; cin >> facefreewind;
	}

	// compute wake radius at x downwind from this turbine
	double radius_wake(double x) { return (radius_rotor + coeff_entrainment * x); }

	// compute wake velocity at x downwind from this turbine
	double velocity_wake(double x)
	{
		return (windspeed_incoming * (1.0 - 2 * inductionfactor_axis*pow(radius_rotor / radius_wake(x), 2)));
	}

	// compute the incoming wind speed if this turbine facing undisturbed wind 
	void comput_incomingwind()
	{
		windspeed_incoming = windspeed_freeincoming;
	}

	// compute the incoming wind speed if this turbine in the downwind of Turbine_upwind 
	void comput_incomingwind(turbine Turbine_upwind)
	{
		Sx = fabs(turbinecoor - Turbine_upwind.turbinecoor);
		windspeed_incoming = Turbine_upwind.velocity_wake(Sx);
	}

	// compute power coefficient of this turbine
	double CP() { return 4. * inductionfactor_axis * pow(1. - inductionfactor_axis, 2.); }

	// compute power of this turbine
	void comput_power()
	{
		coeff_power = CP();
		power = 0.5 * coeff_power * rho * PI * pow(radius_rotor, 2) * pow(windspeed_incoming, 3);
	}

	// display the performance of this turbine
	void dispturbine() const
	{
		cout << "Turbine located at " << turbinecoor << " m" << endl;
		cout << "\t Incoming wind speed: " << windspeed_incoming << " m/s" << endl;
		cout << "\t Power output: " << power / 1e6 << " MW" << endl;
	}

};


/////////////////////////////////////////////////////////////////////////////////

class turbine_dev : public turbine
{
public:
	double i_t;
	double i;
	double dist;

	// member function to compute incoming turbulence intensity
	void intensity()
	{
		dist = Sx;		// downwind distance from turbine
				
		if (facefreewind == 1)		// This statement is for the first turbine
		{
			i_t = 0;		// Since it is the first turbine their is no added turbulence intensity
		}
		else
		{
			i_t = 0.73 * pow((inductionfactor_axis), 0.83) * (pow(turb_intensity, -0.0325)) * pow(((2 * radius_rotor) / dist), 0.32);
		}
		
		i = sqrt(pow(turb_intensity, 2) + pow(i_t, 2));

		cout << "The turbine-added turbulence intensity is: " << i_t << endl;
		cout << "The total turbulence intensity is: " << i << endl;
	}
};

// Obtaining the global variable ambient turbulence intensity
void get_turb()
{
	cout << "Enter the turbulence intensity: ";
	cin >> turb_intensity;
}

////////////////////////////////////////////////////////////////////////////////


// ask user to enter incoming wind info
void getwind()
{
	cout << "Enter undisturbed wind (m/s): "; cin >> windspeed_freeincoming;
}

int main()
{

	// create two turbine objects, Turbine2 in the downwind of Turbine1
	turbine Turbine1, Turbine2;
	turbine_dev turbine1, turbine2;		// 2 derived objects from the turbine class

	// get undisturbed wind speed
	getwind();

	// get turbulence intensity
	get_turb();

	// get turbine parameters
	turbine1.getturbine(); turbine2.getturbine();

	// compute incoming wind speed
	turbine1.comput_incomingwind();
	turbine2.comput_incomingwind(turbine1);

	// compute produced power
	turbine1.comput_power();
	turbine2.comput_power();

	// display turbine performance
	turbine1.dispturbine();
	turbine2.dispturbine();

	

	// display turbulence intensity
	cout << "For the first turbine:" << endl;
	turbine1.intensity();
	cout << "For the second turbine:" << endl;
	turbine2.intensity();

	return 0;
}


