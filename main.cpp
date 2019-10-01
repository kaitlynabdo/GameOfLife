#include "Donut.h"
#include "Classic.h"
#include "Mirror.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(int argc, char **argv) {
    char input;
    cout << "Would you like to provide a map file or a random assignment?" << endl;
    cout << "Type 0 for map file and 1 for random assignment." << endl;
    cin >> input;
    if (input == '0'){
        ifstream in_file;
        string filename;
        cout << "Please enter the path of the file you wish to read from:" << endl;
        cin >> filename;
        in_file.open(filename);
        while(in_file.fail()){ // error checking the file
            cout << "Could not open file. Please try again." << endl;
            cout << "Please enter the path of the file you wish to read from:" << endl;
            cin >> filename;
            in_file.open(filename);
            if(in_file.is_open()){
                break;
            }
        }

        int rows = 0, cols = 0;
        in_file >> rows;
        in_file >> cols;
        Game* game1 = new Game(rows, cols);
        char** curr1 = game1->getCurrArr();
        char** future1 = game1->getFutArr();
        char x = ' ';
        while(!in_file.eof()){ // reading in from the file
            for(int i = 0; i < rows; ++i){
                for (int j = 0; j < cols; ++j) {
                    in_file.get(x);
                    if(x != '\n'){
                        curr1[i][j] = x;
                    }
                }
            }
            break;
        }
        in_file.close();

        int boundry = 0;
        cout << "Choose a boundry type. 0 for classic, 1 for mirror and 2 for donut." << endl;
        cin >> boundry;
        int outputType;
        cout << "Before we begin, would you like to have a file output, press enter or have a brief pause between generations?" << endl;
        cout << " For file output, type 0. For press enter, type 1. For brief pause, type 2." << endl;
        cin >> outputType;

        string outputFileName = "\0";
        if (outputType == 0){ // execution of the boundry types // error checking the file
            cout << "Please enter a file name to output to. " << endl;
            cin >> outputFileName;
        }

        if (boundry == 0){
            Classic* classic1 = static_cast<Classic*>(game1);
            classic1->playGame(outputType, outputFileName);
        }
        else if (boundry == 1){
            Mirror* mirror1 = static_cast<Mirror*>(game1);
            mirror1->playGame(outputType, outputFileName);
        }
        else if (boundry == 2){
            Donut* donut1 = static_cast<Donut*>(game1);
            donut1->playGame(outputType, outputFileName);
        }

        delete game1;
    }

    else if (input == '1'){ // random assignment
        int rows = 0, cols = 0, totalSquares = 0, numCellsInt = 0;
        float density = 0, numCellsFl = 0;
        cout << "Enter the number of rows of the grid." << endl;
        cin >> rows;
        cout << "Enter the number of columns of the grid." << endl;
        cin >> cols;

        cout << "Enter a random decimal value between 0 and 1. This will determine the initial density of the world." << endl;
        cin >> density;

        totalSquares = rows * cols; // calculates number of cells based on density
        numCellsFl = density * totalSquares;
        numCellsInt = (int)numCellsFl;
        srand(time(0));

        Game* game = new Game(rows, cols);
        char** curr = game->getCurrArr();
        char** future = game->getFutArr();
        int r = 0, c = 0;
        while(numCellsInt != 0){ // randomly adding the cells based on the density
            int r = rand()%rows;
            int c = rand()%cols;
            if(curr[r][c] != 'X'){
                curr[r][c] = 'X';
                --numCellsInt;
            }
        }
        for (int i = 0; i < rows; ++i){ // filling in the empty spaces so there is no seg faults
            for (int j = 0; j < cols; ++j) {
                if(curr[i][j] != 'X'){
                    curr[i][j] = '-';
                }
                future[i][j] = '-';
            }
        }
        int boundry = 0;
        cout << "Choose a boundry type. 0 for classic, 1 for mirror and 2 for donut." << endl;
        cin >> boundry;

        int outputType;
        cout << "Before we begin, would you like to have a file output, press enter or have a brief pause between generations?" << endl;
        cout << " For file output, type 0. For press enter, type 1. For brief pause, type 2." << endl;
        cin >> outputType;

        string outputFileName = "\0";
        if (outputType == 0){
            cout << "Please enter a file name to output to. Please use .txt format for the file" << endl;
            cin >> outputFileName;
        }

        if (boundry == 0){ // execution of game and boundry
            Classic* classic = static_cast<Classic*>(game); // downcasting
            classic->playGame(outputType, outputFileName);
        }
        else if (boundry == 1){
            Mirror* mirror = static_cast<Mirror*>(game);
            mirror->playGame(outputType, outputFileName);
        }
        else if (boundry == 2){
            Donut* donut = static_cast<Donut*>(game);
            donut->playGame(outputType, outputFileName);
        }
        delete game;
    }



    return 0;
}
