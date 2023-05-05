// save_status.cpp
#include <iostream>
#include "save_status.h"
#include <fstream>
using namespace std;


void save_status(int phealth, int parmor, int pweapon, int pcard[10], int chealth, int carmor, int cweapon, int ccard[10]){
    // This function is used for saving the data.
    ofstream fout;
    fout.open("game_status.txt");
    if (fout.fail()){
        cout << "Error in saving game status, please make sure that the round is over and you have correctly save the game status." << endl;
    }
    else{
        fout << phealth << endl;
        fout << parmor << endl;
        fout << pweapon << endl;
        for (int i = 0; i < 10; i++){
            fout << pcard[i] << " ";
        }
        fout << endl;
        fout << chealth << endl;
        fout << carmor << endl;
        fout << cweapon << endl;
        for (int i = 0; i < 10; i++){
            fout << ccard[i] << " ";
        }
    }
}
