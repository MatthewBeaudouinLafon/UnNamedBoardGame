//
//  boardCube.h
//  Board Game
//
//  The board is basically a 3x3x3 cube. However, the corners aren't vertically connected
//  (sorry that's the best I can do to describe it)
//
//  Created by Matthew Beaudouin on 7/18/15.
//  Copyright (c) 2015 Matthew Beaudouin. All rights reserved.
//

#ifndef __Board_Game__boardCube__
#define __Board_Game__boardCube__

#include <iostream>
#include <vector>

using namespace std;

class boardCube
{
private:
    vector<vector<vector<int>>> field;
    
public:
    boardCube();
    
    bool isEmpty(size_t a, size_t b, size_t c);  // Returns true if the position on the Board is empty
    
    void startGame(); // Starts the game (i.e. startup phase where players set their pawns)
    
};

#endif /* defined(__Board_Game__boardCube__) */
