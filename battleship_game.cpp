/* Name: Daniel Hinga;
*  Description: Write a C++ program that plays battleship.
*  Input: user to enter location of battleship.
*  Output:the screen of the grid. */

/*algorithm
 *
 * inititalize grid using a for loop and use enum to set to equal
 *set the modes and the differences in mode types in print screen
 *for game over set it always to false but changes when done
 * check play covert the inputs to different enums
 * place battleship not close to edges by using ship size and grid size
 *
 */
#include<iostream>
#include<cstdio>
#include <ctime>
#include <string>
using namespace std;

enum cellType{EMPTY, SHIP, MISSED, HIT};
enum modeType{DEMO, SILENT, NORMAL};

const int GRID_SIZE = 10;
const int SHIP_SIZE = 5;

void initializeGrid(cellType igrid[][GRID_SIZE]);
void printGrid(cellType igrid[][GRID_SIZE], modeType mode);
bool gameover (cellType igrid[][GRID_SIZE]);
void checkPlay ( cellType igrid[][GRID_SIZE], int x, int y);
void placeBattleship(cellType igrid[][GRID_SIZE]);
void playGame(cellType igrid[][GRID_SIZE], modeType mode);

int main(int argc, char *argv[]){

    modeType mode;
    string str;
mode = DEMO;

    if (argc == 1 or str == "normal") {
        mode = DEMO;
    }else if(argc > 1) {
        str = argv[1];

        if (str == "normal") {
            mode = NORMAL;
        } else if (str == "demo") {
            mode = DEMO;
        } else if (str == "silent") {
            mode = SILENT;
        } //else
            //mode = NORMAL;
    }


    int x, y;
cellType igrid [GRID_SIZE][GRID_SIZE];
initializeGrid(igrid);
placeBattleship(igrid);
printGrid(igrid,mode);
playGame(igrid,mode);
gameover (igrid);
checkPlay (igrid, x, y);



}

void initializeGrid(cellType igrid[][GRID_SIZE]){
    for(int i = 0; i < GRID_SIZE; i++) {
        for (int l = 0; l < GRID_SIZE; l++) {
            igrid[i][l] = EMPTY;
        }
    }
}

void placeBattleship(cellType igrid[][GRID_SIZE]) {
   srand(time(0));
    int place;
    int position;
    position = rand() % GRID_SIZE;
    place = rand() % 4;

    for (int i = 0; i < SHIP_SIZE; i++) {
        if (position > (GRID_SIZE - SHIP_SIZE)) {
            if (place == 0 or place == 1) {

                igrid[position][position - i] = SHIP;


            }else if (place == 2 or place == 3) {

                igrid[position - i][position] = SHIP;
            }
        } else if (position < SHIP_SIZE) {
            if (place == 0 or place == 1) {

                igrid[position][position + i] = SHIP;

            }else if (place == 2 or place == 3) {

                igrid[position + i][position] = SHIP;
            }
        }else
            if (place == 0) {

                igrid[position - i][position] = SHIP;

            }else if (place == 1) {

                igrid[position + i][position] = SHIP;

            } else if (place == 2) {

                igrid[position][position + i] = SHIP;

            }else if (place == 3) {

                igrid[position][position - i] = SHIP;
            }
        //}
    }
}

bool gameover (cellType igrid[][GRID_SIZE]){
    bool done = false;
            for (int i = 0; i < GRID_SIZE; i++)
                for(int j = 0; j < GRID_SIZE; j++){
                    if(igrid[i][j] == SHIP)
                        done = true;
                }
    return done;
}

void checkPlay ( cellType igrid[][GRID_SIZE], int x, int y){
    if(igrid[x][y] == EMPTY) {
        igrid[x][y] = MISSED;

    }
    if(igrid[x][y] == SHIP){
        igrid[x][y] = HIT;

    }
    if (igrid[x][y] == MISSED or igrid[x][y] == HIT)
        return;
}

void playGame(cellType igrid[][GRID_SIZE], modeType mode){
    int x , y;

    do {
        cout << "enter gridpoints, row: ";
        cin >> x;
        cout << "enter gridpoints, colum: ";
        cin >> y;
        while(cin.fail() or (x > GRID_SIZE) or (y > GRID_SIZE)){
            cin.clear();
            cin.ignore(10, '\n');
            cout << "re-enter grid points, row ";
            cin>> x;
            cout << "re-enter grid points, colum:  ";
            cin>> y;

        }
        checkPlay(igrid, x, y);
        printGrid(igrid, mode);
        gameover(igrid);
    }while(gameover(igrid));

        cout<< "ship is sunk!!  \ngame is over"<< endl;
        exit(0);
}

void printGrid(cellType igrid[][GRID_SIZE], modeType mode) {
// silent mode doesnt see the grid
    if (mode == SILENT) {
        return;
    }
    // normal is regular play cant see the ship
    else if (mode == NORMAL) {
                cout << "\033[2J\033[1;1H";
                cout << "     ";

                for(int k = 0; k < GRID_SIZE; k++ ){
                    cout<<"  "<< k ;
                    if (k == GRID_SIZE-1)
                        cout << endl;
                }

                for (int i = 0; i < GRID_SIZE; i++) {
                    cout << i;
                    for (int j = 0; j < GRID_SIZE; j++) {
                        if(igrid[i][j] == SHIP){
                            cout<< " - ";
                        }else if (igrid[i][j] == EMPTY) {
                            cout << " - ";
                        }else if (igrid[i][j] = MISSED) {
                            cout << " m ";
                        }else if (igrid[i][j] == HIT) {
                            cout << " X ";
                        }
                    }
                }
            }
            // demo mode shows the ship
            else if (mode == DEMO) {
                // to make a list to show lines
                for(int k = 0; k < GRID_SIZE; k++ ){
                    cout<<"  "<< k ;
                    if (k == GRID_SIZE-1)
                        cout << endl;
                }

                for (int i = 0; i < GRID_SIZE; i++) {
                    cout << i<< " ";

                    for (int j = 0; j < GRID_SIZE; j++) {

                        if (igrid[i][j] == SHIP) {
                            cout << " s ";
                        } else if (igrid[i][j] == EMPTY) {
                            cout << " - ";
                        } else if (igrid[i][j] == MISSED) {
                            cout << " m ";
                        } else if (igrid[i][j] == HIT) {
                            cout << " x ";
                        }
                        // makes new rows
                        if (j % GRID_SIZE == GRID_SIZE-1)
                            cout << endl;

                    }
                }

            }
            //here

}
