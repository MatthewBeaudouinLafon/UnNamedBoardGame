//
//  boardCube.cpp
//  Board Game
//
//  Created by Matthew Beaudouin on 7/18/15.
//  Copyright (c) 2015 Matthew Beaudouin. All rights reserved.
//

#include "boardCube.h"


boardCube::boardCube()
{
    for (size_t i=0; i<3; i++)              // Fill the board with 0s on initialization
    {
        for (size_t j=0; j<3; j++)
        {
            for (size_t k=0; k<3; k++)
            {
                field[i][j][k] = 0;
            }
        }
    }
}

bool boardCube::isEmpty(size_t a, size_t b, size_t c)  // Returns true if the position on the Board is empty
{
    if (field[a][b][c] == 0)
    {
        return true;
    }
    
    return false;
}

void boardCube::startGame()                // Starts the game (i.e. startup phase where players set their pawns)
{
    for (int i=0; i<3; i++)
    {
        
    }
}

bool placePawn(size_t a, size_t b, size_t c)    // Places pawn at (a,b,c)
{
    
}