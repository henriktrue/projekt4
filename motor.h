#ifndef ISOSCELES_H
#define ISOSCELES_H

#include <iostream>
using namespace std;

class motor {
public:
	//overload constructor
	motor(int);

	const char * adress(int count);

	//sets left
	void control(int, int);

	//Destructor
	~motor();

private:
	//Member variables
};

#endif
