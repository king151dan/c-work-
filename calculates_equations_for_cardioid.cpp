/* Name: Daniel Hinga;
*  Description: Write a C++ program that calculates the equations for a cardioid.  .
*  Input: user needs to input the output file name, and max value of a.
*  Output: x and y values from the program and writes in the output provided  */

/* create prototypes for future functions to be used in main
 * create int main and declare variable to be used to call the output
 * create void function to pass by reference the output file
 * create the functions to equate x and then new to calculate y
 * go back to int main and create for loops to actually calculate
 * finally output x and y to the outfile */
#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
using namespace std;

//pic(x/y) is the cardioid function name
void openofile(ofstream & ofile );
double picx(double a, double t);
double picy(double a, double t);

int main(){
    ofstream ofile;
    double x, y;
    double a, t, maxA;
    double PI = 3.14159;

    //open the oftream created by void
    openofile(ofile);

    cout<< "enter the Maximum value of A: ";
    cin>> maxA;

    //for loops to get it to auto calculate a and t values
    for(a = 0.1; a < maxA; a += 1.0) {
        for (t = 0; t < (2.0 * PI); t += ((2.0 * PI) / 1000)) {

            //new values x and y not the same as returned value..
            //..from the returned calucator variables
            // call funtion by using function name.
            x = picx(a, t);
            y = picy(a, t);

            //write x and y to the opened file
            ofile << x <<" "<< y << endl;
        }
    }
}

//this will open an ofstream and pass it by refernce
void openofile(ofstream & ofile){
    string output;
    cout<< "enter output file: ";
    cin>> output;
    ofile.open(output);
   //if(ofile.is_open() == false){
    while (ofile.fail() == true) {
        cout << "error please enter a new output file name" << endl;
        ofile.clear();
        cin.clear();
        cin.ignore(10,'\n');
        cout << "enter output file" << endl;
        cin >> output;
        ofile.open(output);
    }
//}
}

//function to calculate the x in a graph
double picx(double a, double t){
    double x = 0;
    x = a * (1+cos(t)) * cos(t);

    return x;
}

//function to calculate the y in a graph
double picy(double a, double t){
    double y = 0;
    y = (a * (1 + cos(t)) * sin(t));

    return y;
}