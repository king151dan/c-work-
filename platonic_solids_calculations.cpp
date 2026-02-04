/* Name: Daniel Hinga;
*  Description: Write a C++ program that calculate
 *  various values associated with different platonic solids.
*  Input: which switch statement to use, and edge length .
*  Output:dimensions of the type of calculation chosen. */

/*algorithm
 *print title using \t for tab, then types to use, and prompt user what choices to pic
 * declare a char and user cin in variable
 * enter case statements, and if statements sor each case,
 * print heading, for the case, then add the equations
 * print results
 * default in case of nothing entered
 */

#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
cout<<"\t \t ***********************************************"<< endl;
cout<<"\t \t * program to calculate the area and of volume *"<< endl;
cout<<"\t \t *           of platonic solids                *"<< endl;
cout<<"\t \t ***********************************************"<< endl;
cout<<""<< endl;

cout<<"\t \t T/t   Tetrahedron   (4 faces )"<< endl;
cout<<"\t \t H/h   Hexahedron    (6 faces )"<< endl;
cout<<"\t \t O/o   Octahedron    (8 faces )"<< endl;
cout<<"\t \t D/d   Dodecahedron  (12 faces)"<< endl;
cout<<"\t \t I/i   Icosahedron   (20 faces)"<< endl;
cout<<" "<<endl;
cout<< "\t \t enter a choice from above: ";

char c;
cin>>c;

switch(c){
    case 't':
    case 'T':
        {
            //the variables first that are to be used in entire case statement
            //extra cout to print space
            double a, y, z, height, area, face_area, volume;
            cout<<"\t \t ***************************************" <<endl;
            cout<<"\t \t * Calculating Values of a Tetrahedron *"<<endl;
            cout<<"\t \t ***************************************"<<endl;
            cout<< " "<< endl;
            cout << "\t \t enter the length oF an edge: ";
            cin >> a;
            // a is the edge length

            // make sure that the numbers entered are between 1 and 35
            if (a >= 1 and a <= 35) {

                //equations, y and z only here to have less char on a line
                y = pow(a, 2);
                z = pow(a, 3);
                height = (a / 3) * sqrt(6);
                area = y * sqrt(3);
                face_area = (sqrt(3) / 4) * y;
                volume = (z / 12) * sqrt(2);

                //set it to 3 decimal places,
                //left by 20 spaces for variable names
                // right by 15 spaces for result of equations
                cout << fixed<< setprecision(3);
                cout << left << setw(20) << "\t \t Edge Size: "<<
                        right<< setw(15) << a << endl;
                cout << left << setw(20) << "\t \t Height: " <<
                        right<< setw(15)<< height << endl;
                cout << left << setw(20)<< "\t \t Area: " <<
                        right<< setw(15) <<area << endl;
                cout << left << setw(20)<< "\t \t Face Area:" <<
                        right<< setw(15)<< face_area << endl;
                cout << left << setw(20)<< "\t \t Volume:" <<
                        right<< setw(15)<< volume << endl;
            }else {
                cout << "\t \t error-edge must be between 1.00 and 35.00"
                << endl;
            }
            break;

        }
        case 'h':
        case 'H': {
            // variables to be used in entire section
            double a, y, mainDiagonal, face_Diagonal, face_area, volume;
            cout << "\t \t **************************************" << endl;
            cout << "\t \t * Calculating Values of a Hexahedron *" << endl;
            cout << "\t \t **************************************" << endl;
            cout << "" << endl;
            cout << "\t \t enter edge size: " ;
            cin >> a;
            cout<<" "<< endl;
            // this makes sure the that it will run for numbers 5-55
            if (a >= 5.000 and a <= 55.000) {
                // equations for section
                y = pow(a, 2);
                face_area = 6 * y;
                volume = pow(a, 3);
                mainDiagonal = a * sqrt(3);
                face_Diagonal = a * sqrt(2);

                //set it to 3 decimals and have it print names left with 20 spaces
                // for results of equations set it to the right of names
                cout << fixed << setprecision(3);
                cout << left<< setw(20) << "\t \t Edge Size: " <<
                        right<< setw(15) << a << endl;
                cout << left<< setw(20) << "\t \t Face Area: " <<
                        right<< setw(15) << face_area << endl;
                cout << left<< setw(20) <<  "\t \t volume: " <<
                        right << setw(15)<< volume << endl;
                cout << left<< setw(20) << "\t \t Main Diagonal: " <<
                        right << setw(15) << mainDiagonal << endl;
                cout << left<< setw(20) << "\t \t Face Diagonal: " <<
                        right<< setw(15) << face_Diagonal << endl;
            }else{
            cout << "\t \t error-edge must be between 5.000 - 55.000" << endl;
        }
            break;
        }
        //comments above apply to all blocks of code in program
        case 'o':
        case 'O':
            {
                cout<<"\t \t **************************************"<<endl;
                cout<<"\t \t * Calculating Values of a Octahedron *"<< endl;
                cout<<"\t\t **************************************"<<endl;

            double a, face_area, volume, volume_diagonal, x, y;
            cout<<"\t \t enter edge length: ";
            cin>>a;

            if(a >= 3.00 and a <= 30.00) {

                x = pow(a, 2);
                y = pow(a, 3);
                face_area = (2 * x) * sqrt(3);
                volume = (y / 3) * sqrt(2);
                volume_diagonal = a * sqrt(2);

                cout << fixed << setprecision(3);
                cout << left<< setw(20) << "\t \t Edge Size: " <<
                        right<< setw(15) << a << endl;
                cout << left<< setw(20) << "\t \t Face Area: " <<
                        right<< setw(15) << face_area << endl;
                cout << left<< setw(20) << "\t \t Volume: " <<
                        right<< setw(15) << volume << endl;
                cout << left<< setw(20) << "\t \t volume diagonal: " <<
                        right<< setw(15) << volume_diagonal << endl;
            }else{
                cout << "\t \t error-edge must be between 3.00 - 30.00" << endl;
            }
            break;
        }
        case 'D':
        case 'd': {

            cout << "\t \t ****************************************" << endl;
            cout << "\t \t * Calculating Values of a Dodecahedron *" << endl;
            cout << "\t \t ****************************************" << endl;
            double a, x, y, z, face_area, volume, volume_diagonal;
            cout << "\t \t enter edge length: ";
            cin >> a;

            if(a >= 10 and a <= 45) {
                x = pow(a, 2);
                y = pow(a, 3);
                z = sqrt(5);
                face_area = ((3 * x) * sqrt(25 + (10 * z)));
                volume = ((y / 4) * ((15 + (7 * z))));
                volume_diagonal = 2 * (a / 4) * sqrt(3) * (1 + z);

                cout << fixed << setprecision(3);
                cout << left<< setw(20) << "\t \t edge size: " <<
                        right<< setw(15) << a << endl;
                cout << left<< setw(20) << "\t \t Face Area: " <<
                        right<< setw(15) << face_area << endl;
                cout << left<< setw(20) << "\t \t Volume: " <<
                        right<< setw(15) << volume << endl;
                cout << left<< setw(20) <<  "\t \t Volume Diagonal: " <<
                        right<< setw(15) << volume_diagonal << endl;
            }else{
                cout<<"\t \t error-edge must be between 10.00 - 45.00"<<endl;
            }
            break;
        }

    case 'I':
    case 'i':
        {
            cout<<"\t \t ***************************************"<<endl;
            cout<<"\t \t * Calculating values of a Icosahedron *"<< endl;
            cout<<"\t \t ***************************************"<<endl;

            double a, v, x, y, z, face_area, volume, volume_diagonal;
            cout<<"\t \t enter edge length: ";
            cin>> a;

            if(a >=2.00 and a <= 100) {

                x = pow(a, 2.0);
                y = pow(a, 3.0);
                z = sqrt(5.0);
                face_area = (5.0 * x) * sqrt(3.0);
                volume = ((5.0 / 12) * y) * (3 + z);
                volume_diagonal = ((2.0 * (a / 4.0)) * sqrt(10 + (2 * z)));

                cout << left<< setw(20) << fixed << setprecision(3);
                cout << left<< setw(20) <<  "\t \t Edge Size: " <<
                        right<< setw(15) << a << endl;
                cout << left<< setw(20) << "\t \t Face Area: " <<
                        right<< setw(15) << face_area << endl;
                cout << left<< setw(20) << "\t \t volume: " <<
                        right<< setw(15) << volume << endl;
                cout << left<< setw(20) << "\t \t Volume Diagonal: " <<
                        right<< setw(15) << volume_diagonal << endl;
            }else{
                cout<<"\t \t error-edge must be between 2.00 - 100.00"<<endl;
            }
            break;
        }
    default:
        cout<<"\t \t error - selection "<< c << " is not valid."<< endl;
}
}
