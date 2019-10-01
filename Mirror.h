#include <iostream>
#include "Game.h"
#ifndef MIRROR_H
#define MIRROR_H

class Mirror : public Game{
    public:
        Mirror(int r, int c);
        ~Mirror();
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
