/*
 * Name: Daniel Hinga;
*  Description: Write a C++ program that This program will read in a large USDA1 database of foods,
 *  manufacturers, and ingredients and searches for them.
*  Input: name of the ingredient;
*  Output: database searched information of ingredient.
 */

/* alorithm
Write the infile with a while loop to check the function
Readfile function and use a get line function to get the lines put it in a while loop till theres an end of file
Use get quoted string to pick words and place them in specific vectors
To get quoted strings find the first set of quotations and begin after the quote and ends begor the next quote mark
To search for ingredients create a new vector then search through the original ingidient vector,
then sort the vector ( just used a bubble sort) but onlu of ot found the ingredient by the
bool function searching through the vector
 */


#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

struct itemType
{
    int itemNumber;
    string NDBNumber;
    string longName;
    string dataSource;
    string upc;
    string manufacturer;
    string dataModified;
    string dataAvailable;
    string ingredients;

};


// Prototypes for functions
void readFile( ifstream & inFile, vector<itemType> &item);
bool openInputFile( ifstream & inFile );
bool getQuotedString( string& line, int &index, string & subString);
bool findIngredient( itemType item, string ingredient);
string makeStringUpper( string s);
int searchForIngredient( vector<itemType> & itemType, string ingredient, bool printEnable );
void printRecord( itemType & item );
void sort(vector<itemType>& myList);


int main()
{
    // the dataBase
    // vector type is used because it's too big for an array.
    // (on my computer anyway)
    vector<itemType> dataBase;

    // input file
    ifstream inFile;

    // temporary strings
    string temp="";
    string tempUpper="";

    int found=0;
    string stars(40,'*');

    // open the input file
    if (openInputFile( inFile ) )
        cout << "File opened correctly "<<endl;
    else{
        cout << "Error opening file"<< endl << "Exiting...." << endl;
        return 0;
    }

    // read the entire dataBase
    readFile( inFile, dataBase);

    cout << dataBase.size() << " records read "<<endl;

    // prompt the user for the ingredient to search for.  q to quit
    cout << "Enter ingredient: ";

    //getline(cin, temp);

    cin>>temp;

    if ( temp != "q" or temp == "Q" ){
        cout << endl<< "Searching for items containing " << temp << endl;
    }else
        return 0;


    do{
        string ans = "";

        // search for the number of items that contain the ingredient
        found = searchForIngredient( dataBase, temp, false );

        cout << stars << endl;
        cout << found << " items found with the ingredient " << temp << endl;
        cout << stars << endl;

        // prompt the user to see if they want the items containing the ingredient listed.

        if( found != 0 ){
            cout <<"Would you like to see a list of items with "<< temp << " as an ingredient? (y/Y) ";
            cin >> ans;

            // clear endline
            cin.get();

            if ( ans == "y" or ans == "Y" ){
                // search for the number of items that contain the ingredient
                found = searchForIngredient( dataBase, temp, true );
            }
        }

        cout << endl << stars <<endl;
        cout << "New search"<<endl;
        cout << "Enter ingredient: ";

        cin>> temp;
        //getline(cin, temp );

        if ( temp != "q" ){
            cout << endl<< "Items containing " << temp << endl;
        }
    }  while ( temp != "q");

    return 0;
}


int searchForIngredient( vector<itemType> & dataBase, string ingredient, bool printEnable )
{
    vector<itemType> foundlist;
    itemType x;
    int count = 0;

    // changes the searched ingridient to uppercase, easier to search
    makeStringUpper(ingredient);

    // keep going till the end of the database.
    for( int i = 0; i < dataBase.size(); i++){

        // pulls a bool and if the ingridient is found excecute block
        if( findIngredient( dataBase[i], ingredient) == true){

            // stores it to a new item type if found ingridient
            x = dataBase[i];

            // how many times it found the ingridients in different databases
            count++;

            // add it to the new vector
           foundlist.push_back(x);

            if (printEnable == true){
                printRecord(x);
            }
        }
    }
    sort(foundlist);
    return count;
}


void printRecord( itemType &item )
{

    //set the width just for looks, and just call the item itself item.something..
    cout<< "\n"<<endl;
    cout<< left << setw(18) <<"Item #:  " << setw(15) <<item.itemNumber << endl;
    cout << left << setw(18) << "Name:  "   << item.longName << endl;
    cout<< left << setw(18) << "Manufacture:  "  <<item.manufacturer << endl;
    cout<< left << setw(18) <<  "UPC:  "   <<item.upc << endl;
    cout<< left << setw(18) << "Ingredients:   " <<item.ingredients << endl;

}


bool openInputFile( ifstream & inFile )
{

    string name;
    cout <<"enter name file:  ";
    // name of the input file to be opened
    cin>> name;
    inFile.open(name.c_str());

    // if the inital try fails the while loop will keep trying till the file opens
    while(!inFile.is_open()){
    cin.clear();
    cin.ignore(10, '\n');
    inFile.clear();
    cout<< "re_enter name of file; ";
    cin>> name;
    inFile.open(name.c_str());
}

    return true;

}


void readFile( ifstream & inFile, vector<itemType> &item){

    // line will store lines from a get line.
    string line;
    int count = 0;


    // while loop to keep getting lines till the end of file
    while(!inFile.eof()) {
     itemType x;

     // count will be the item number
     count++;
     getline(inFile, line, '\n');
     int index = 0;
     x.itemNumber = count;

     // below will grab a line , increase the index number
     // and add it to the respected item type
     getQuotedString(line, index, x.NDBNumber);
     getQuotedString(line, index, x.longName);
     getQuotedString(line, index, x.dataSource);
     getQuotedString(line, index, x.upc);
     getQuotedString(line, index, x.manufacturer);
     getQuotedString(line, index, x.dataModified);
     getQuotedString(line, index, x.dataAvailable);
     getQuotedString(line, index, x.ingredients);

     // this will make the ingidients upper case befpre storing it
     makeStringUpper(x.ingredients);
     item.push_back(x);
 }
}


void sort(vector<itemType>& myList)
{
    string temp;


    for (int i=1; i < myList.size(); i++)
        for(int l=0; l< myList.size() - i; l++ ){
            // for loop to help change the values
            if (myList[l].upc > myList[l + 1].upc){
                // the new variable stores the inital string
                temp = myList[l].upc;

                // replace the original to the next in line
                myList[l].upc = myList[l + 1].upc;

                // change the next in line with the original
                myList[l + 1].upc = temp;
            }
        }
}


bool  getQuotedString( string& line, int &index, string & subString)
{

    // always resets the substing to blank
    subString = "";
    // add past the first quotes
   index++;

   //while  the index is not a quote or a new line character
    while ( line[index] != '\"' and line[index] != '\n'  ){

        //adds the characters to the substring with exceptions
        subString += line[index];

        // adds to the next index to keep adding it to the substring
        index++;
    }
    // adds two characters for the first quote and the next
    index=index+2;

    // if index is dame as line length stop the function
    if(line.length() <= index){
        return false;
    }else
        return true;

}


bool findIngredient( itemType item, string ingredient) {

    size_t found = item.ingredients.find(ingredient);
    if(found != string::npos){
        return true;
    }else
        return false;

}


string makeStringUpper(string s)
{
    // incriments for the length of the string
    for(int i = 0; i < s.length(); i++){
        if(s[i] >= 97 and s[i] <= 122)
            // for ackii characters in the lower case subtract 32 to move it upper case
            s[i] = s[i] - 32;
    }
    return s;

}

