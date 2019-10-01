#include <iostream>
#include <fstream>
#include <unistd.h>
#include "Donut.h"

Donut::Donut(int r, int c) : Game::Game(r, c){

}

Donut::~Donut(){}

void Donut::topLeftCorner(int r, int c, int totRow, int totCol){//each function counts the number of neighbors of a cell
    int count = 0;
    if(currGen[r][c+1] == 'X'){
        count++;
    }
    if(currGen[r+1][c+1] == 'X'){
        count++;
    }
    if(currGen[r+1][c] == 'X'){
        count++;
    }
    if(currGen[r+1][totCol-1] == 'X'){
        count++;
    }
    if(currGen[r][totCol-1] == 'X'){
        count++;
    }
    if(currGen[totRow-1][totCol-1] == 'X'){
        count++;
    }
    if(currGen[totRow-1][c] == 'X'){
        count++;
    }
    if(currGen[totRow-1][c+1] == 'X'){
        count++;
    }
    makeNextGen(count, r, c);
}

void Donut::topEdge(int r, int c, int totRow, int totCol){
    int count = 0;
    if(currGen[r][c+1] == 'X'){
        count++;
    }
    if(currGen[r+1][c+1] == 'X'){
        count++;
    }
    if(currGen[r+1][c] == 'X'){
        count++;
    }
    if(currGen[r+1][c-1] == 'X'){
        count++;
    }
    if(currGen[r][c-1] == 'X'){
        count++;
    }
    if(currGen[totRow-1][c-1] == 'X'){
        count++;
    }
    if(currGen[totRow-1][c] == 'X'){
        count++;
    }
    if(currGen[totRow-1][c+1] == 'X'){
        count++;
    }
    makeNextGen(count, r, c);
}

void Donut::topRightCorner(int r, int c, int totRow, int totCol){
    int count = 0;
    if(currGen[r][c-1] == 'X'){
        count++;
    }
    if(currGen[r+1][c-1] == 'X'){
        count++;
    }
    if(currGen[r+1][c] == 'X'){
        count++;
    }
    if(currGen[r+1][0] == 'X'){
        count++;
    }
    if(currGen[0][0] == 'X'){
        count++;
    }
    if(currGen[totRow-1][0] == 'X'){
        count++;
    }
    if(currGen[totRow-1][c] == 'X'){
        count++;
    }
    if(currGen[totRow-1][c-1] == 'X'){
        count++;
    }
    makeNextGen(count, r, c);
}

void Donut::leftEdge(int r, int c, int totRow, int totCol){
    int count = 0;
    if(currGen[r-1][c] == 'X'){
        count++;
    }
    if(currGen[r+1][c-1] == 'X'){
        count++;
    }
    if(currGen[r-1][c+1] == 'X'){
        count++;
    }
    if(currGen[r][c+1] == 'X'){
        count++;
    }
    if(currGen[r+1][c+1] == 'X'){
        count++;
    }
    if(currGen[r+1][c] == 'X'){
        count++;
    }
    if(currGen[r+1][totCol-1] == 'X'){
        count++;
    }
    if(currGen[r][totCol-1] == 'X'){
        count++;
    }
    makeNextGen(count, r, c);

}

void Donut::rightEdge(int r, int c, int totRow, int totCol){
    int count = 0;
    if(currGen[r-1][c] == 'X'){
        count++;
    }
    if(currGen[r-1][c-1] == 'X'){
        count++;
    }
    if(currGen[r][c-1] == 'X'){
        count++;
    }
    if(currGen[r+1][c-1] == 'X'){
        count++;
    }
    if(currGen[r+1][c] == 'X'){
        count++;
    }
    if(currGen[r+1][0] == 'X'){
        count++;
    }
    if(currGen[r][0] == 'X'){
        count++;
    }
    if(currGen[r-1][0] == 'X'){
        count++;
    }
    makeNextGen(count, r, c);
}

void Donut::bottomEdge(int r, int c, int totRow, int totCol){
    int count = 0;
    if(currGen[r][c-1] == 'X'){
        count++;
    }
    if(currGen[r-1][c-1] == 'X'){
        count++;
    }
    if(currGen[r-1][c] == 'X'){
        count++;
    }
    if(currGen[r-1][c+1] == 'X'){
        count++;
    }
    if(currGen[r][c+1] == 'X'){
        count++;
    }
    if(currGen[0][c-1] == 'X'){
        count++;
    }
    if(currGen[0][c] == 'X'){
        count++;
    }
    if(currGen[0][c+1] == 'X'){
        count++;
    }
    makeNextGen(count, r, c);
}

void Donut::bottomLeftCorner(int r, int c, int totRow, int totCol){
    int count = 0, stable = 0;
    if(currGen[r-1][c] == 'X'){
        count++;
    }
    if(currGen[r-1][c+1] == 'X'){
        count++;
    }
    if(currGen[r][c+1] == 'X'){
        count++;
    }
    if(currGen[0][c+1] == 'X'){
        count++;
    }
    if(currGen[0][0] == 'X'){
        count++;
    }
    if(currGen[0][totCol-1] == 'X'){
        count++;
    }
    if(currGen[r][totCol-1] == 'X'){
        count++;
    }
    if(currGen[r-1][totCol-1] == 'X'){
        count++;
    }
    makeNextGen(count, r, c);
}

void Donut::bottomRightCorner(int r, int c, int totRow, int totCol){
    int count = 0;
    if(currGen[r-1][c] == 'X'){
        count++;
    }
    if(currGen[r-1][c-1] == 'X'){
        count++;
    }
    if(currGen[r][c-1] == 'X'){
        count++;
    }
    if(currGen[0][c-1] == 'X'){
        count++;
    }
    if(currGen[0][c] == 'X'){
        count++;
    }
    if(currGen[0][0] == 'X'){
        count++;
    }
    if(currGen[r][0] == 'X'){
        count++;
    }
    if(currGen[r-1][0] == 'X'){
        count++;
    }
    makeNextGen(count, r, c);
}

void Donut::playGame(int fileVSconsole, string filename){ // the game
    int countGen = 0;
    ofstream out_file(filename);
    while(true){ // determining the number of neighbors for all cells and creating future gen
        for (int i = 0; i < row; ++i){
            for (int j = 0; j < col; ++j){
                if (i == 0 && j == 0){
                    topLeftCorner(i, j, row, col);
                }
                else if (i == 0 && j == col - 1){
                    topRightCorner(i, j, row, col);
                }
                else if(i == row - 1 && j == 0){
                    bottomLeftCorner(i, j, row, col);
                }
                else if(i == row - 1 && j == col - 1){
                    bottomRightCorner(i, j, row, col);
                }
                else if(i == 0){
                    topEdge(i, j, row, col);
                }
                else if(i == row - 1){
                    bottomEdge(i, j, row, col);
                }
                else if(j == 0){
                    leftEdge(i, j, row, col);
                }
                else if(j == col - 1){
                    rightEdge(i, j, row, col); // stable determines if the cell is stable
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
