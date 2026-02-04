/* Name: Daniel Hinga;
*  Description:Write a C++ program to generate a set of real numbers,
 *  calculate several statistics on the numbers, and display the results
*  Input: size of data sets.
*  Output:statistics and the data sets created*/

/*algorithmm
 * 
 * Get size first, set  a while loop to retry and set up a count that will end program after n times
Create data, for loop to load data in each slot
Display data, load statistics,  for loop that prints out each value in array  and stats
Standard diviation, for loop that adds the values in array, one variable for sum of array, and one to add array ^2 the n use diviation formular
Sum will just add all the numers in the array
Max,  value found by for loop and if statement to readjust to new max
Min,  value found by for loop and if statement to readjust to new max

 */


#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
using namespace std;

const int CMIN = 10;
const int CMAX = 1000;
const double multiple= 1.101;


int getSize();
void createData(double values[], int size);
void displayNumbers(double values[], int size);
void displaydata(double values[], int size);
void stats(double values[], int size, double & min, double & max,
        double & sum, double & ave, double & sd);
double standarddiviation(double values[],int size);
double Sum(double values[],int size);
double Max(double values[],int size);
double Min(double values[],int size);

int main(){
    int size;
    size = getSize();

    double values[size] = {0};
    createData( values, size);
    displaydata( values, size);

}

int getSize(){
    int size, count;
    cout<< "enter the data set size: ";
    cin>> size;

    // while loop to keep cin between cmax cmin
    while(size < CMIN or size > CMAX){

        cin.clear();
        cin.ignore(10, '\n');

        // count the number of tries
        count++;

        cout<< "illegal input "<< count<< "/3 try again "<< endl;
        cin>> size;

        //ends the trial after the 3rd try
        if(count == 3){
            cout<< "error no more tries"<< endl;
            exit(0);
        }
    }
return size;
}

void createData(double values[], int size){
    values[ size ] ;
    double data = 0;
    for (int i = 0; i< size; i++){

        //this will make random numbers for the data set
        data = (rand() % 1000) * multiple;
        values[i]=data;
    }
}

void displaydata(double values[], int size){
    double min, max, sum, ave, sd;
   stats( values, size, min, max, sum, ave, sd );
    for(int i = 0; i < size; i++ ) {

        // will print out values across.
        cout << fixed << setprecision(2);
        cout << right << setw(10) << values[i]<< " " ;

        // if statement to end each line printed.
        if ((i % 8) == 7 or i == (size -1)) {
            cout<< endl;
        }
    }

    cout << fixed << setprecision(2)<< left <<setw(7);
    cout << left << setw(8) << "minimum: "<<
        right<< setw(8) << min<< '\t'
        <<left << setw(8)<< "maximum: "<< right<< setw(8) << max << endl;

    cout << left << setw(8) << "sum: "<<
         right<< setw(9) << sum << '\t'
         << left<< setw(8) <<"average: "<< right << setw(8) <<ave << endl;

    cout << left << setw(10) << "sample standard diviation: "<<
         right<< setw(10) << sd << endl;

}

void stats(double values[], int size, double & min, double & max,
                  double & sum, double & ave, double & sd){
// this values would be passed by reference
    min = Min(values, size);
    max = Max(values, size);
    sum = Sum(values, size);
    sd = standarddiviation(values, size);
    ave = sum/ size;



}

double standarddiviation(double values[],int size){

    double sd;
    double sum1 = 0;
    double sum2 = 0;
    for (int i = 0; i < size; i++){

        // sum 1 is the sumation of the values squared
        // sum 2 is the sumation of the values
        sum1 += pow(values[i], 2);
        sum2 +=  values[i];
    }

    sd =sqrt((size * sum1) - ((pow(sum2, 2)) / (size * (size - 1))));

    return sd;
}

double Sum(double values[],int size){
    double total = 0;
    for(int i = 0; i < size; i++) {
        total += values[i];
    }
    return total;
}

double Max(double values[],int size){
    double nmax = values[0];

    for(int x = 0; x < size; x++){
        if ( values[x] > nmax) {
            nmax = values[x];
        }
    }
    return nmax;
}

double Min(double values[],int size){

    double nmin = values[0];

    for(int y = 0; y < size; y++){
        if(values[y] < nmin){
            nmin = values[y];
        }
    }

    return nmin;
}










