#include <iostream>
#include "Game.h"
#ifndef DONUT_H
#define DONUT_H

class Donut : public Game{
    public:
        Donut(int r, int c);
        ~Donut();
        void topLeftCorner(int r, int c, int totRow, int totCol);
        void topEdge(int r, int c, int totRow, int totCol);
        void topRightCorner(int r, int c, int totRow, int totCol);
        void leftEdge(int r, int c, int totRow, int totCol);
        void rightEdge(int r, int c, int totRow, int totCol);
        void bottomEdge(int r, int c, int totRow, int totCol);
        void bottomLeftCorner(int r, int c, int totRow, int totCol);
        void bottomRightCorner(int r, int c, int totRow, int totCol);
        void playGame(int fileVSconsole, string filename);
};
#endif
