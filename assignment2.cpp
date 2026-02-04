/* Name: Daniel Hinga; 
* Description: Write a C++ program to calculate and display the period of a conical pendulum.
* Input: Angle, Degrees.
* Output:Display the period of a conical pendulum. */

#include <iostream>
#include <cmath>
using namespace std;

const double g = 9.80665;
const double pi = 3.14159;

int main()
{
 double angle;
 double length;
 double radius;
 double time;
 double radians;


cout << "enter angle in degrees"<< endl;
cin >> angle;
cout << "you entered " << angle << " degrees" << endl;
// convert angle into radians
radians = angle * (pi/ 180);


cout << "Enter pendulum length in meters" << endl;
cin >> length;
cout <<"You entered "<< length << " for radius" <<  endl;
// use the length or (hypotenuses) with sin(opp/hypot) to find radius
radius = length * sin(radians);


// the final equation to find the period of the period of pendulum;
time = (2 * pi) * sqrt(radius / (g * tan(radians)));

cout << "The period of your conical pendulum is " << time << endl;
}
