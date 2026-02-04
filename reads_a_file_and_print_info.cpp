/* Name: Daniel Hinga;
*  Description: Write a C++ program that reads in a file and cout's info .
*  Input: user to read all files, yes or no and number of records.
*  Output:age,min,max,avg, wage,min,max,avg. */

/*
 * enter a file name to process, if wrong entered try, again using while
 * then ask if user to process whole file or not, then initialize certain variables
 * if not, how many records and how to initialize certain
 * then output all results.
 */

#include<iostream>
#include<fstream>
#include <iomanip>

using namespace std;
int main() {

    ifstream infile;
    string name, first, last;
    double wage, maxwage, minwage, averagewage, sumwage, averageage;
    double age, minage, maxage, sumage;
    int birthyear, id;
    int records = 0;
    int today = 2019;
    int counter = 0;
    int x = 0;
    char c;

    cout << "enter a file name" << endl;
    cin >> name;
    infile.open(name.c_str());

    // while loop to keep going if wrong name is input
    while (!infile.is_open()) {
        cout << "file did not open" << endl;
        infile.clear();
        cout << "enter a file name" << endl;
        cin >> name;
        infile.open(name.c_str());
    }
    cout << "process entire file? (y/n): ";
    cin >> c;

    //loop for only choices
    while(c != 'y' and c !='n'){
        cout<< "invalid entry\n"<<endl;
        cout<<"process entire file? (y/n)"<< endl;
        cin.clear();
        cin.ignore(30, '\n');
        cin>>c;
    }

    //loop for yes
    if (c == 'y' or c == 'Y')
    {
        //while this file is open
        while (!infile.eof())
        {
            //what items to read
            infile >> id >> first >> last >> wage >> birthyear;
            //age needs to be calculated
            age = today - birthyear;

            if (counter == 0)
            {
                minwage = wage;
                maxwage = wage;
                minage = age;
                maxage = age;
            }
            if (wage >= maxwage)
                maxwage = wage;
            if (wage <= minwage)
                minwage = wage;
            if (age >= maxage)
                maxage = age;
            if (age <= minage)
                minage = age;

            //calculations for when user runs it all
            sumwage += wage;
            averagewage = sumwage / (counter);
            sumage += age;
            averageage = sumage / (counter);
            counter++;
        }
        cout<< "end of file detected: "<< counter<<" records read\n"<<endl;
        cout <<"*******************************"<< endl;
        cout << "number of records read  " << counter << endl;
        cout <<"*******************************"<<endl;

    } else if (c == 'n' or c == 'N') {
        cout << "please enter number of record to process: ";
        cin >> records;
        while (cin.fail()) {
            cout << "error- non numerical value detected- try again\n" << endl;
            cout << "please enter number of records to process: ";
            cin.clear();
            cin.ignore(40,'\n');
            cin >> records;
        }
        for (x = 0; x < records and !infile.eof(); x++)
        {
                infile >> id >> first >> last >> wage >> birthyear;
                age = today - birthyear;
                counter++;

                if (x == 1) {
                    minwage = wage;
                    maxwage = wage;
                    minage = age;
                    maxage = age;
                }
//how to switch variables if lower or higher is found
                if (wage > maxwage)
                    maxwage = wage;
                else if (wage < minwage)
                    minwage = wage;
                else if (age > maxage)
                    maxage = age;
                else if (age < minage)
                    minage = age;
            //calcculations for all runs
                sumwage += wage;
                averagewage = sumwage / counter;
                sumage += age;
                averageage = sumage / counter;
        }
        //report to user end of file count
        if(infile.eof())
            cout<<"end of file detected: "<< counter<< " records read"<< endl;

        cout<<"\n******************************"<<endl;
        cout<<"number of records read "<<counter<< endl;
        cout<<"******************************"<<endl;
    }

//total results
        cout << fixed<< setprecision(2);
        cout<<"\nwage statistic"<< endl;
        cout<<"--------------------------------------------------------"<<endl;
        cout << left << setw(2) << "maxwage: "<<
                right<< setw(2) << maxwage <<
                left << setw(2) << "\tminwage: " <<
                right<< setw(2)<< minwage <<
                left << setw(2)<< "\taverage wage: " <<
                right<< setw(2) <<averagewage << endl;

        cout<<"\nage statistics"<< endl;
        cout<<"--------------------------------------------------------"<<endl;
        cout << left << setw(2)<< "maxage: " <<
                right<< setw(2)<< maxage <<
                left << setw(2)<< "\tminage: " <<
                right<< setw(2)<< minage <<
                left << setw(2) << "\taverage age: "<<
                right<< setw(2) << averageage << endl;
        return 0;

}