/* Name: Daniel Hinga; 
*  Description: Write a C++ program that plays 21 with user and computer.
*  Input: user to continue, yes or no.
*  Output:new number, total, and who wins computer or user. */

/* Give number  number added to sum give new number, add to sum use a do while.
In do  shw a number, and ask to continue switch statement 
In yes  have a new random number, add to totalway to break the loop when draws past 21
In nocomputer plays and stops at >= 17 or past 21 
In while conditions to keep playing if no one wins or busts and user keeps playing
After loop breaks announce winners and results */

#include<iostream>
#include<cstdlib>
#include<ctime>
#include <cstdio>
using namespace std;

int main() {

    srand(time(NULL));
    int player = 0;
    int computer = 0;
    int playern = 0;
    int computern = 0;
    int playertotal = 0;
    int comptotal = 0;
    int random = 0;
    int randomcomp = 0;

    //these bools will stop the program at certain points in do while.
    bool bust = false;
    bool win = false;
    bool keep = true;
    bool compdone = false;
    char x;

    cout << "\n----------------------"<< endl;
    cout << "welcome to the 21 game" << endl;
    cout << "----------------------\n"<<endl;

    playern = 1 + (rand() % 10);
    computern = 1 + (rand() % 10);
    cout << "first number" << endl;
    cout << "player:  " << playern << endl;
    cout << "computer: hidden \n"<< endl;


    player = 1 + (rand() % 10);
    computer = 1 + (rand() % 10);
    cout << "second number" << endl;
    cout << "player: " << player << endl;
    cout << "computer: "<< computer << endl;

    playertotal = player + playern;
    comptotal = computern + computer;

    do {

        //check to see if its 21 already
        if (playertotal == 21 or comptotal == 21) {
            keep = false;
        } else {

            cout << "\nplayer total is " << playertotal<< endl;
            cout << "draw another number? (y / n) ";

            // how to make the user choose
            cin >> x;
            switch (x) {
                case 'y':
                case 'Y':

                    random = 1 + (rand() % 10);
                    playertotal += random;
                    cout << "player draws: " << random << endl;

                    // check to see if the first hands are 21 already
                    if (playertotal > 21) {
                        bust = true;
                        cout << "\nplayer total: " << playertotal << endl;
                        cout << "player BUST" << endl;
                    }
                    break;

                case 'n':
                case 'N': {

                    // bool to ensure player doesnt keep playing on while loop
                    keep = false;
                    cout<<"\n-------------"<< endl;
                    cout<<"computer play"<< endl;
                    cout<<"-------------"<<endl;

                    cout << "\ncomputer hidden number: "<< computern<< endl;
                    cout << "computer total: " << comptotal << endl;
                    if(comptotal >= 17)
                        compdone = true;

                   //computer plays till the if statements are complete or true
                    while (!compdone) {
                        randomcomp = 1 + (rand() % 10);
                        comptotal += randomcomp;

                        //computer keeps playing  no bool to stop
                        if (comptotal <= 17) {
                            cout << "\ncomputer draws: " << randomcomp << endl;
                            cout << "computer total: " << comptotal << endl;
                        }
                        //stops the computer at 17 and up
                        if (comptotal >= 17) {
                            compdone = true;
                            cout << "\ncomputer draws: " << randomcomp << endl;
                            cout << "computer total: " << comptotal << endl;
                        }
                        //bust condition
                        if (comptotal > 21) {
                            bust = true;
                            cout << "\ncomputer bust" << endl;
                        }
                    }
                    break;
                }
                default:
                    cout << "invalid entry" << endl;
                    break;
            }
        }
        //conditions to keep playing
    }while (!win && !bust && keep);

    cout<< "\nplayer score: "<< playertotal <<endl;
    cout<< "computer score: "<< comptotal<< endl;
    cout<< "------------------"<< endl;
    cout<< "result of the game"<< endl;
    cout<< "------------------"<< endl;


    //this if statement shows winner
    if (((playertotal >= comptotal) and playertotal <= 21) or comptotal > 21)
        cout<<"player wins!!\n"<< endl;
    if (playertotal > 21 or (playertotal < comptotal and comptotal <= 21 ))
        cout<< "player loses!!\n"<< endl;

    return 0;
}