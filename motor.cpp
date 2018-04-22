#include "motor.h"
#include <fstream>

//location of 5 device tree overlays
#define MOTOR1 "/sys/devices/ocp.3/bs_pwm_test_P9_14.15/"
#define MOTOR2 "/sys/devices/ocp.3/bs_pwm_test_P9_16.16/"
#define MOTOR3 "/sys/devices/ocp.3/bs_pwm_test_P8_13.18/"
#define MOTOR4 "/sys/devices/ocp.3/bs_pwm_test_P8_19.19/"
#define MOTOR5 "/sys/devices/ocp.3/bs_pwm_test_P9_42.17/"

//overload constructor, sets polarity and period for all motors
motor::motor(int Period)
{
	ofstream period;
	ofstream polarity;
	int count = 1;
	while (count < 6)
	{
		//defining standard path
		const char * path = (adress(count));
		char buffer[256];

		if (count == 5)
		{
			//specifying standard path to period
			sprintf (buffer, "%speriod", path);
			period.open(buffer);

			period << Period;
			period.close();
		}

		//defining path and writing value for polarity
		sprintf (buffer, "%spolarity", path);
		polarity.open(buffer);
		polarity << 0;

		//closing period and polarity
		polarity.close();

		//incrementing count, so while loop adds next motor
		count++;
	}
}


const char * motor::adress(int count) {
	//choice of motor adress
	if 		(count == 1)return MOTOR1;
	else if (count == 2)return MOTOR2;
	else if (count == 3)return MOTOR3;
	else if (count == 4)return MOTOR4;
	else if (count == 5)return MOTOR5;
	else return "something went wrong with driver initialisation";
}

// set left
void motor::control(int duty, int motor) {
		ofstream pwm;

		//defining standard path for motor
		const char * path = (adress(motor));
		char buffer[256];

		//specifying standard path to pwm
		sprintf (buffer, "%sduty", path);
		pwm.open(buffer);

		//writing left value to pwm
		pwm << duty;
}

//Destructor
motor::~motor() {
}
