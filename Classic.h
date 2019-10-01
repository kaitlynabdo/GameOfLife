#include <iostream>
#include "Game.h"
#ifndef CLASSIC_H
#define CLASSIC_H

class Classic : public Game{
    public:
        Classic(int r, int c);
        ~Classic();
        void topLeftCorner(int r, int c);
        void topEdge(int r, int c);
        void topRightCorner(int r, int c);
        void leftEdge(int r, int c);
        void rightEdge(int r, int c);
        void bottomEdge(int r, int c);
        void bottomLeftCorner(int r, int c);
        void bottomRightCorner(int r, int c);
        void playGame(int fileVSconsole, string filename);

};
#endif
