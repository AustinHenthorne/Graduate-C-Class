// Austin Henthorne MEC510 HW2-01
// This program is the snakes and ladders game


#include<iostream>
#include<cmath>
#include<cstdlib>

using namespace std;

int main()
{
	int position = 0;

	do
	{
		int roll = rand() % 6 + 1;
		cout << "Please press enter to roll the dice: " << endl;
		if (cin.get() == '\n')
		{
			cout << "You rolled a: " << roll << endl;
			position = position + roll;
			cout << "Your position is: " << position << endl;

			switch (position)
			{
				// Snake
			case 27:
				cout << "You have landed on a snake!" << endl;
				position = 1;
				cout << "Your new position is 1" << endl;
				break;
			case 21:
				cout << "You have landed on a snake!" << endl;
				position = 9;
				cout << "Your new position is 9" << endl;
				break;
			case 19:
				cout << "You have landed on a snake!" << endl;
				position = 7;
				cout << "Your new position is 7" << endl;
				break;
			case 17:
				cout << "You have landed on a snake!" << endl;
				position = 4;
				cout << "Your new position is 4" << endl;
				break;

				// Ladders
			case 5:
				cout << "You have landed on a ladder!" << endl;
				position = 8;
				cout << "Your new position is 8" << endl;
				break;
			case 3:
				cout << "You have landed on a ladder!" << endl;
				position = 22;
				cout << "Your new position is 22" << endl;
				break;
			case 11:
				cout << "You have landed on a ladder!" << endl;
				position = 26;
				cout << "Your new position is 26" << endl;
				break;
			case 20:
				cout << "You have landed on a ladder!" << endl;
				position = 29;
				cout << "Your new position is 29" << endl;
				break;

			}
			if (position > 30)
			{
				position = position - roll;
			}

		}


	} while (position != 30);
	cout << "Congratulations, you beat the game!!" << endl;
	
	return(0);
}