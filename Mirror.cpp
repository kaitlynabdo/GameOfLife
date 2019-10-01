#include <iostream>
#include <fstream>
#include <unistd.h>
#include "Mirror.h"

Mirror::Mirror(int r, int c) : Game::Game(r, c){

}

Mirror::~Mirror(){}

void Mirror::topLeftCorner(int r, int c){ //each function counts the number of neighbors of a cell
    int count = 3;
    if (currGen[r+1][c] == 'X'){
        count = count + 2;
    }

    if(currGen[r+1][c+1] == 'X'){
        count++;
    }

    if (currGen[r][c+1] == 'X'){
        count = count + 2;
    }
    makeNextGen(count, r, c);
}
void Mirror::topEdge(int r, int c){
    int count = 1;
    if(currGen[r][c-1] == 'X'){
        count = count + 2;
    }
    if (currGen[r][c+1] == 'X'){
        count = count + 2;
    }

    if(currGen[r+1][c-1] == 'X'){
        count++;
    }

    if(currGen[r+1][c] == 'X'){
        count++;
    }

    if(currGen[r+1][c+1] == 'X'){
        count++;
    }
    makeNextGen(count, r, c);
}
void Mirror::topRightCorner(int r, int c){
    int count = 3;
    if(currGen[r][c-1] == 'X'){
        count = count + 2;
    }

    if(currGen[r+1][c-1] == 'X'){
        count++;
    }

    if(currGen[r+1][c] == 'X'){
        count = count + 2;
    }
    makeNextGen(count, r, c);
}
void Mirror::leftEdge(int r, int c){
    int count = 1;
    if(currGen[r-1][c] == 'X'){
        count = count + 2;
    }
    if (currGen[r-1][c+1] == 'X'){
        count++;
    }

    if(currGen[r][c+1] == 'X'){
        count++;
    }

    if(currGen[r+1][c+1] == 'X'){
        count++;
    }

    if(currGen[r+1][c] == 'X'){
        count = count + 2;
    }

    makeNextGen(count, r, c);
}
void Mirror::rightEdge(int r, int c){
    int count = 1;
    if(currGen[r-1][c] == 'X'){
        count = count + 2;
    }
    if (currGen[r-1][c-1] == 'X'){
        count++;
    }

    if(currGen[r][c-1] == 'X'){
        count++;
    }

    if(currGen[r+1][c-1] == 'X'){
        count++;
    }

    if(currGen[r+1][c] == 'X'){
        count = count + 2;
    }

    makeNextGen(count, r, c);
}

void Mirror::bottomEdge(int r, int c){
    int count = 1;
    if(currGen[r][c-1] == 'X'){
        count = count + 2;
    }
    if (currGen[r-1][c-1] == 'X'){
        count++;
    }

    if(currGen[r-1][c] == 'X'){
        count++;
    }

    if(currGen[r-1][c+1] == 'X'){
        count++;
    }

    if(currGen[r][c+1] == 'X'){
        count = count + 2;
    }
    makeNextGen(count, r, c);
}

void Mirror::bottomLeftCorner(int r, int c){
    int count = 3;
    if (currGen[r-1][c] == 'X'){
        count = count + 2;
    }

    if(currGen[r-1][c+1] == 'X'){
        count++;
    }

    if (currGen[r][c+1] == 'X'){
        count = count + 2;
    }
    makeNextGen(count, r, c);
}
void Mirror::bottomRightCorner(int r, int c){
    int count = 3;
    if (currGen[r-1][c] == 'X'){
        count = count + 2;
    }

    if(currGen[r-1][c-1] == 'X'){
        count++;
    }

    if (currGen[r][c-1] == 'X'){
        count = count + 2;
    }
    makeNextGen(count, r, c);
}

void Mirror::playGame(int fileVSconsole, string filename){ // the game
    int countGen = 0;
    ofstream out_file(filename);
    while (!out_file){ //error checking out file
        cout << "Error. File was not created." << endl;
        cout << "Enter a new file name with .txt format. " << endl;
        cin >> filename;
        ofstream out_file(filename);
    }
    while(true){ // determining the number of neighbors for all cells and creating future gen
        for (int i = 0; i < row; ++i){
            for (int j = 0; j < col; ++j){
                if (i == 0 && j == 0){
                    topLeftCorner(i, j);

                }
                else if (i == 0 && j == col - 1){
                    topRightCorner(i, j);
                }
                else if(i == row - 1 && j == 0){
                    bottomLeftCorner(i, j);
                }
                else if(i == row - 1 && j == col - 1){
                    bottomRightCorner(i, j);
                }
                else if(i == 0){
                    topEdge(i, j);
                }
                else if(i == row - 1){
                    bottomEdge(i, j);
                }
                else if(j == 0){
                    leftEdge(i, j);
                }
                else if(j == col - 1){
                    rightEdge(i, j); // stable determines if the cell is stable
                }
                else{
                    middle(i, j);
                }
            }
        }
        if(fileVSconsole == 0){ // file output
            out_file << countGen << endl;
            for (int i = 0; i < row; ++i){
                for (int j = 0; j < col; ++j){
                    out_file << currGen [i][j];
                }
                out_file << endl;
            }
            ++countGen;
        }
        else if(fileVSconsole == 1 || fileVSconsole == 2){ // consol output
            if(fileVSconsole == 1){
                cout << countGen << endl;
                for (int i = 0; i < row; ++i){
                    for (int j = 0; j < col; ++j){
                        cout << currGen[i][j];
                    }
                    cout << endl; // enter output
                }
                cin.get(); // enter pause
                ++countGen;
            }
            if (fileVSconsole == 2){ // pause function
                cout << countGen << endl;
                for (int i = 0; i < row; ++i){
                    for (int j = 0; j < col; ++j){
                        cout << currGen[i][j];
                    }
                    cout << endl;
                }
                sleep(1); //brief pause
                ++countGen;
            }
        }

        if (isEmpty() == true || isStable() == true){ // if the grid is empty, the cycle is over
            break;
        }
        char** swap = currGen; // swapping current gen to future gen
        currGen = futureGen;
        futureGen = swap;
    }
}
