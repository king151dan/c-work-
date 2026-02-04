/* Name: Daniel Hinga;
*  Description: Write a C++ program that changes a certain value of a string in different calculations .
*  Input: degrees to change into radians.
*  Output: calculate values are used to change values when string is printed. */

/*cin degree with a while loop to put certain perimeters
 * then print header
 *for loop to increment the addition of 10 degrees per angle
 * change degrees to radians after addition
 * change them to integers for the string values
 * reset set values to original after its printed*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double degree, radians, angle;
    double pi = 3.14;
    int sine, cosine, count;
    string lines(46, '-');
    string blank (46,' ');

    cout<< "\nplease enter value in degrees (-+ 360): ";
    cin>> degree;

    //loop for an error at cin
    while(cin.fail() or  degree > 360 or degree < -360)
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout<< "error- enter value with degrees (-+ 360): ";
        cin>> degree;
    }

    //printed header
    cout<< lines<< endl;
    cout<< "ploting sine(x) and cosine(x)"<<endl;
    cout<< "* sine(x)  + cosine(x)"<< endl;
    cout<< "from "<< degree<< " to "<< (degree + 360)<< endl;
    cout << lines<< endl;

    //loop to change print and change values in string
    for(count= 0; angle != degree + 360; count++)
    {
        // all calculations for the loop
        angle = degree + (10 * count);
        radians = (angle) * (pi / 180);
        sine = static_cast<int>(sin(radians) * 20 + 25);
        cosine = static_cast<int>(cos(radians) * 20 + 25);

        //changing certain values in perticular string and prints
        blank[sine] = '*';
        blank[cosine] = '+';
        cout << blank << endl;

        //this resets the already changed values
        blank[sine] = ' ';
        blank[cosine] = ' ';
    }
}