#include <iostream>
#include "Grid.h"
using namespace std;

Grid::Grid(int r, int c){
    grid = new char*[r]; //creating multidimenstional array
    for (int i = 0; i < r; ++i){
        grid[i] = new char[c];
    }
    row = r;
    column = c;
}

Grid::~Grid(){ //destructor
    for(int i = 0; i < row; i++){
        delete grid[i];
    }
    delete [] grid;
}

void Grid::cellAdd(int c, int r){
    grid[r][c] = 'X'; //creating a new cell
}

void Grid::cellDead(int c, int r){
    grid[r][c] = '-'; //killing off a cell
}

void Grid::printGrid(){
    for (int r = 0; r < row; ++r){ //print grid
        for (int c = 0; c < column; ++c){
            cout << grid[r][c];
        }
        cout << endl;
    }
}

//getter and setters for rows and columns
int Grid::getRow(){
    return row;
}
void Grid::setRow(int r){
    row = r;
}

int Grid::getCol(){
    return column;
}
void Grid::setCol(int c){
    column = c;
}

void Grid::fillGrid(){ // fill an empty grid
    for (int r = 0; r < row; ++r){
        for (int c = 0; c < column; ++c){
            grid[r][c] = '-';
        }
    }
}

char** Grid::getArray(){
    return grid;
}

void Grid::copyGrid(){

}

bool Grid::isAlive(int r, int c){ //checking status of cell
    if (grid[r][c] == 'X'){return true;}
    else{return false;}
}
