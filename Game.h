#include <iostream>
#include "Grid.h"
using namespace std;
#ifndef GAME_H
#define GAME_H

class Game {
    public:
        Game(int r, int c);
        ~Game();
        void zeroOneNeigh(int r, int c);
        void twoNeigh(int r, int c);
        void threeNeigh(int r, int c);
        void fourMoreNeigh(int r, int c);
        void makeNextGen(int count, int r, int c);
        void middle(int r, int c);
        Grid* getCurrGrid();
        Grid* getFutGrid();
        char** getCurrArr();
        char** getFutArr();
        bool isEmpty();
        bool isStable();

    protected:
        Grid* curr;
        Grid* future;
        int countNeigh;
        int row;
        int col;
        char** currGen;
        char** futureGen;
};
#endif
