#include <iostream>
#include "Game.h"
using namespace std;

Game::Game(int r, int c){ // constructor for game class
    curr = new Grid(r, c);
    future = new Grid(r, c);
    countNeigh = 0;
    currGen = curr->getArray();
    futureGen = future->getArray();
    row = r;
    col = c;
}

Game::~Game(){
    delete curr, future;
}

char** Game::getCurrArr(){
    return currGen;
}
char** Game::getFutArr(){
    return futureGen;
}


void Game::zeroOneNeigh(int r, int c){ //dies of loneliness because 0 or 1 neighvors
    futureGen[r][c] = '-';
}

void Game::twoNeigh(int r, int c){ //stays stable w 2 neighbors
    if (currGen[r][c] == '-'){
        futureGen[r][c] = '-';
    }
    else if (currGen[r][c] == 'X'){
        futureGen[r][c] = 'X';
    }
}

void Game::threeNeigh(int r, int c){ // growth for 3 neighbors
    futureGen[r][c] = 'X';
}

void Game::fourMoreNeigh(int r, int c){ //dies of overcrowding for 4 or more neighbors
    futureGen[r][c] = '-';
}

void Game::makeNextGen(int count, int r, int c){ // determining the fate of cell for next generation
    if (count <= 1){
        zeroOneNeigh(r, c);
    }

    else if (count == 2){
        twoNeigh(r, c);
    }

    else if (count == 3){
        threeNeigh(r, c);
    }

    else if (count >= 4){
        fourMoreNeigh(r, c);
    }
}

void Game::middle(int r, int c){ //middle cells because they will be the same across all modes
    int count = 0;
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
    if(currGen[r][c-1] == 'X'){
        count++;
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

bool Game::isEmpty(){
    int count = 0;
    for (int i = 0; i < row; ++i){
        for (int j = 0; j < col; ++j){
            if (currGen[i][j] == '-'){ // counting all the empty cells
                count++;
            }
        }
    }
    if (count == row * col){ // if all the cells are empty
        return true;
    }
    else{
        return false;
    }
}
bool Game::isStable(){
    int count = 0;
    for (int i = 0; i < row; ++i){
        for (int j = 0; j < col; ++j){
            if (currGen[i][j] == futureGen[i][j]){ // counting all the empty cells
                count++;
            }
        }
    }
    if (count == row * col){ // if all the cells are empty
        return true;
    }
    else{
        return false;
    }
}
