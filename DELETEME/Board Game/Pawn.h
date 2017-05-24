//
//  Pawn.h
//  Board Game
//
//  Created by Matthew Beaudouin on 7/17/15.
//  Copyright (c) 2015 Matthew Beaudouin. All rights reserved.
//

#ifndef __Board_Game__Pawn__
#define __Board_Game__Pawn__

#include <iostream>

class pawn
{
private:
    // The player the pawn belongs to
    int player;
    
    // Access to the board
    
    
    // Position
    size_t x;
    size_t y;
    size_t z;
    
public:
    // Future fun project: make constructor private by actually making files and shit. Right now, I'm a dirty little programmer
    pawn(int player_input, size_t x_input, size_t y_input, size_t z_input): player(player_input), x(x_input), y(y_input), z(z_input) {}
    
    bool move(size_t a, size_t b, size_t c);     // Returns 1 if the move is legal , 0 if not.
    
};

#endif /* defined(__Board_Game__Pawn__) */
