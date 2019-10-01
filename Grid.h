#include <iostream>
using namespace std;
#ifndef GRID_H
#define GRID_H

class Grid {
    public:
        Grid();
        Grid(int r, int c);
        ~Grid();
        void cellAdd(int c, int r);
        void cellDead(int c, int r);
        void printGrid();
        bool isAlive(int r, int c);
        int getRow();
        void setRow(int r);
        int getCol();
        void setCol(int c);
        void fillGrid();
        void copyGrid();
        char** getArray();

    private:
        char** grid;
        int row;
        int column;
};
#endif
