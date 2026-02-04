/* Name: Daniel Hinga; 
*  Description: Write a C++ program that calculates the surface area, base area,
*  lateral surface area, volume, and slant length of a square pyramid.
*  Input: height, base.
*  Output:2 decimal places of multiple formulas of a pyramid. */

/*
 * algorithm!
 * enter llibrary * prompt user what the program is for
 * prompt user what to enter for height and base
 * cin height and base and prompt user what they entered
 * make a function to power of 2 for base and height
 * create functions
 * cout functions with set precision
*/

#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;


int main()
{
cout<< "Program to calculate parameters of a pyramid" << endl;
cout<< "" << endl;


double height;
cout<< "enter height in inches:" << endl;
cin >> height;
cout<< "you entered: "<< height << " inches" << endl;
double y = pow(height, 2);
cout<< "" << endl;


double base;
cout<< "enter the width of the base in inches: " <<  endl;
cin>> base;
cout<< "you entered: "<< base << " inches" << endl;
double x = pow(base, 2);
cout<< "" << endl;


double surface = x + ((2 * base) * sqrt((x / 4) + y));
double lat = surface - x;
double volume = x * (height/3);
double slant = sqrt(y + (x / 4));

cout<<fixed<< setprecision(2);
cout<< "Surface Area: " << surface << endl;
cout<< "Volume: " << volume << endl;
cout << "Base Area: "<< x << endl;
cout << "Lateral Surface Area: " << lat << endl;
cout << "Slant height: "<< slant << endl;


return 0;
}