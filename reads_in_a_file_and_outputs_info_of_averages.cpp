/* Name: Daniel Hinga;
*  Description: Write a C++ program that reeds in a file and outputs info .
*  Input: user to read all files, yes or no and number of records.
*  Output:age,min,max,avg, wage,min,max,avg. and out put to new file  */

/*
 * enter a file name to process, if wrong entered try, again using while
 * then ask if user to process whole file or not, then initialize certain variables
 * if not, how many records and how to initialize certain
 * then output all results to each yes or no .
 *
 *
 */

#include<iostream>
#include<fstream>
#include <iomanip>

using namespace std;
int main() {
    ofstream ofile;
    ifstream infile;

    string lines (75, '-');
    string stars (75, '*');
    string instreame (38, '>');
    string outstream (38, '<');

    string name, outputname, first, last;
    double wage, maxwage, minwage, averagewage, sumwage, averageage;
    double age, minage, maxage, sumage, percentage, percentwage;
    int birthyear, id;

    int records = 0;
    int today = 2019;
    int counter = 0;
    int x = 0;
    char c;

    cout << "enter a file name: ";
    cin >> name;
    infile.open(name.c_str());

    // while loop to keep going if wrong name is input
    while (!infile.is_open()) {
        cout << "file did not open" << endl;
        infile.clear();
        cout << "enter a file name: ";
        cin >> name;
        infile.open(name.c_str());
    }

    //output for txt file to write in
    cout<< "enter output file name: ";
    cin >> outputname;
    ofile.open(outputname);
    while(!ofile.is_open()){
        cout<< "error opening file "<< endl;
        ofile.clear();
        cout << "enter an output file name: ";
        cin>> outputname;
        ofile.open(outputname);
    }
    ofile.close();


    cout << "process entire file? (y/n): ";
    cin >> c;


    //loop for only choices
    while (c != 'y' and c != 'Y' and c != 'N' and c != 'n') {
        cout << "invalid entry\n" << endl;
        cout << "process entire file? (y/n)" << endl;
        cin.clear();
        cin.ignore(30, '\n');
        cin >> c;
    }
    //loop for yes
    if (c == 'y' or c == 'Y') {
        ofile.open(outputname);
        ofile << left << setw(15) << "employee id: "<< left<< setw(15) <<"first name: " <<
             left<< setw(15) << "last name: " << left << setw(10) << "wage: " <<
             left << setw(10) <<"% avgA:"<<left << setw(8)<<"age: " <<
             left << setw(5) << " % avgWage:\n";

        //while this file is open
        while (!infile.eof()) {
            //what items to read
            infile >> id >> first >> last >> wage >> birthyear;
            //age needs to be calculated
            age = today - birthyear;


            if (counter == 0) {
                minwage = wage;
                maxwage = wage;
                minage = age;
                maxage = age;
            }
            if (infile) {
                if (wage >= maxwage)
                    maxwage = wage;
                if (wage <= minwage)
                    minwage = wage;
                if (age >= maxage)
                    maxage = age;
                if (age <= minage)
                    minage = age;

                ++counter;
                //calculations for when user runs it all
                sumwage += wage;
                averagewage = (sumwage / counter);
               percentwage = (wage / averagewage) * 100;
                sumage += age;
                averageage = sumage / counter;
                percentage = (age / averageage) * 100;

                ofile << fixed << setprecision(2);
                ofile  << right << setw(10) << id << right << setw(15) << first <<
                      right << setw(15) << last << right << setw(10) << wage <<
                      right << setw(10) << static_cast<int>(percentage) <<
                      right << setw(8) << static_cast<int>(age) <<
                      right << setw(13) << static_cast<int>(percentwage)<< "\n";
            }
        }
        cout << "max record count reached:" << counter << endl;

    } else if (c == 'n' or c == 'N') {
        cout << "please enter number of record to process: ";
        cin >> records;
        while (cin.fail()) {
            cout << "error- non numerical value detected- try again\n" << endl;
            cout << "please enter number of records to process: ";
            cin.clear();
            cin.ignore(40, '\n');
            cin >> records;
        }
        ofile.open(outputname);
        ofile << left << setw(15) << "employee id: "<< left<< setw(15) <<"first name: " <<
              left<< setw(15) << "last name: " << left << setw(10) << "wage: " <<
              left << setw(10) <<"% avgA:"<<left << setw(8)<<"age: " <<
              left << setw(5) << " % avgWage:\n";

        for (x = 0; x < records and !infile.eof(); x++) {
            infile >> id >> first >> last >> wage >> birthyear;
            age = today - birthyear;

            if (infile) {
                counter++;

                if (x == 0) {
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
                averagewage = (sumwage / counter);
                percentwage = (averagewage/ wage) * 100;
                sumage += age;
                averageage = sumage / counter;
                percentage = (age / averageage) * 100;

                ofile << fixed << setprecision(2);
                ofile  << right << setw(10) << id << right << setw(15) << first <<
                       right << setw(15) << last << right << setw(10) << wage <<
                       right << setw(10) << static_cast<int>(percentage) <<
                       right << setw(8) << static_cast<int>(age) <<
                       right << setw(13) << static_cast<int>(percentwage)<< "\n";
            }
        }
        //report to user end of file count
            cout << "max record count reached: " << counter <<  endl;
    }
    cout << "\nprogram complete "<< endl;
    cout << instreame<< outstream <<  endl;

    ofile << "\n" << stars<<  endl;
    ofile << "number of records read " << counter << endl;
    ofile << stars << endl;
    //total results
    ofile << fixed << setprecision(2);
    ofile << "\nwage statistic" << endl;
    ofile << lines << endl;
    ofile << left << setw(2) << "maxwage: " <<
         right << setw(2) << maxwage <<
         left << setw(2) << "\tminwage: " <<
         right << setw(2) << minwage <<
         left << setw(2) << "\taverage wage: " <<
         right << setw(2) << averagewage << endl;

    ofile << "\nage statistics" << endl;
    ofile << lines << endl;
    ofile << left << setw(2) << "maxage: " <<
         right << setw(2) << maxage <<
         left << setw(2) << "\tminage: " <<
         right << setw(2) << minage <<
         left << setw(2) << "\taverage age: " <<
         right << setw(2) << averageage << endl;
    return 0;
}