#include <fstream>
#include <iostream>
#include "motor.h"

using namespace std;

// duty 1 - 5 should be middle point of motors
int duty1 = 1500000;
int duty2 = 1500000;
int duty3 = 1500000;
int duty4 = 1500000;
int duty5 = 1500000;
int step = 20000;

//520000 lower duty limit for motor 1-4
//2200000 upper duty limit for motor 1-4

int main() {
	// sets values to be written into DeviceTree files
	// this period is for motor 5, since the 4 others cant be changed
	int Period = 1520000;

	motor motor(Period);

	while (1)
	{
		char control1;
		cin >> control1;

		//make motor 1 turn left
		if (control1 == 'a' && duty1 < 2200000)
		{
                    duty1 = duty1 + step;
                    cout << "making motor go 1 left " << duty1 << endl;
                    motor.control(duty1, 1);
                }

		//make motor 1 turn left
		else if (control1 == 'd' && duty1 > 520000)
		{
                        duty1 = duty1 - step;
                        cout << "making motor go 1 right" << duty1 << endl;
                        motor.control(duty1, 1);
                }

		//make motor 2 turn left
		if (control1 == 'w' && duty2 < 2200000)
		{
			duty2 = duty2 + step;
			cout << "making motor go 2 left" << duty2 << endl;
			motor.control(duty2, 2);
		}

		//make motor 2 turn right
		else if (control1 == 's' && duty2 > 520000)
		{
			duty2 = duty2 - step;
			cout << "making motor 2 go right" << duty2 << endl;
			motor.control(duty2, 2);
		}

		//make motor 3 turn left
		if (control1 == '8' && duty3 < 2200000)
		{
			duty3 = duty3 + step;
			cout << "making motor go 3 left" << duty3 << endl;
			motor.control(duty3, 3);
		}

		//make motor 3 turn right
		else if (control1 == '5' && duty3 > 520000)
		{
			duty3 = duty3 - step;
			cout << "making motor 3 go right" << duty3 << endl;
			motor.control(duty3, 3);
		}
		//make motor 4 turn left
		if (control1 == '4' && duty4 < 2200000)
		{
			duty4 = duty4 + step;
			cout << "making motor go 4 left" << duty4 << endl;
			motor.control(duty4, 4);
		}

		//make motor 4 turn left
		else if (control1 == '6' && duty4 > 520000)
		{
			duty4 = duty4 - step;
			cout << "making motor 4 go right" << duty4 << endl;
			motor.control(duty4, 4);
		}

		//make motor 5 open
		else if (control1 == 'n' && duty5 < 2200000)
		{
			duty5 = duty5 + step;
			cout << "making motor 5 go right" << duty5 << endl;
			motor.control(duty5, 5);
		}

		//make motor 5 close
		else if (control1 == 'm' && duty5 > 520000)
		{
			duty5 = duty5 - step;
			cout << "making motor 5 go left " << duty5 << endl;
			motor.control(duty5, 5);
		}

                
	}
	return 0;
}
