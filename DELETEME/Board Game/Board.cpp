//
//  Board.cpp
//  Board Game
//
//  Created by Matthew Beaudouin on 7/17/15.
//  Copyright (c) 2015 Matthew Beaudouin. All rights reserved.
//

#include "Board.h"

Board::Board()
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

bool Board::isEmpty(size_t a, size_t b, size_t c)  // Returns true if the position on the Board is empty
{
    if (field[a][b][c] == 0)
    {
        return true;
    }
    
    return false;
}

