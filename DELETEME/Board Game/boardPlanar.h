//
//  boardPlanar.h
//  Board Game
//
//  Created by Matthew Beaudouin on 7/18/15.
//  Copyright (c) 2015 Matthew Beaudouin. All rights reserved.
//

#ifndef __Board_Game__boardPlanar__
#define __Board_Game__boardPlanar__

#include <iostream>

class boardPlanar
{
private:
    int field[8][3];
public:
    boardPlanar();
    
    void startGame();
    
    size_t* queryPosition();        // Returns an array with two elements, the x and y components
    
    bool islegal(size_t a, size_t b, size_t x, size_t y);
    // Checks wether moving from (a,b) to (x,y) is legal
    
    bool gameWinCheck();        // Checks the entire board for a winning situation. 
    
};

#endif /* defined(__Board_Game__boardPlanar__) */
