//
//  boardPlanar.cpp
//  Board Game
//
//  Created by Matthew Beaudouin on 7/18/15.
//  Copyright (c) 2015 Matthew Beaudouin. All rights reserved.
//

#include "boardPlanar.h"
#include <iostream>


boardPlanar::boardPlanar()
{
    for (int i=0; i<8; i++)         // fill the board with 0s
    {
        for (int j=0; j<3; j++)
        {
            field[i][j] = 0;
        }
    }
}

size_t* boardPlanar::queryPosition()        // Returns an array with two elements, the x and y components
{
    
    size_t positions [2];
    
    // Temproary command line:
    std::cout << "Where do you want to place the pawn?: " << std::endl;
    std::cin >> positions[0] >> positions[1];
    
    return positions;
}

void boardPlanar::startGame() // Starts the game (i.e. startup phase where players set their pawns)
{
    for (int i=0; i<3; i++)
    {
        size_t* playerInput;    // Psst: it's actually used as an array. I know it'll have exactly 2 elements.
        
        do
        {
            // Ask player 1 for input
            playerInput = queryPosition();
            
        }  while ( field[playerInput[0]][playerInput[1]] != 0 ); // Check if it's a-ok
        
        field[playerInput[0]][playerInput[1]] = 1;               // 1 for Player 1
        
        // NOTE: The pawns could be distinguished i is assigned to the position rather than 1 (could be useful for algorithms?)
        
        do
        {
            // Ask player 2 for input
            playerInput = queryPosition();
            
        }  while ( field[playerInput[0]][playerInput[1]] != 0 ); // Check if it's a-ok
        
        field[playerInput[0]][playerInput[1]] = 2;          // 2 for Player 2

    }
}       // This leaves us with everyone's pawn in the right place. Dandy.

bool boardPlanar::gameWinCheck()        // Checks the entire board for a winning situation.
{
    // We'll effectively check around each square with this loop:
    for (int j=0; j<3; j++)
    {
        for (int i=0; i<8; i+2)
        {
            if ( field[i][j] == field[i][j+1] && field[i][j] == field[(i+3)%7][j] ) // The modulo enables wrap around
            {
                // Do whatever you want, I just couted because that'll be easy to track later
                std::cout << "Player " << field[j][i] << " wins!" << std::endl;
                return true;
            }
        }
    }
    
    // Now to check the lines connecting the 'layers'
    for (int k=1; k<8; k+2)
    {
        if ( field[k][1] == field[k][2] && field[k][3])
        {
            std::cout << "Player " << field[k][1] << " wins!" << std::endl;
            return true;
        }
    }
    
    return false;
}


bool boardPlanar::islegal(size_t a, size_t b, size_t x, size_t y)
// Checks wether moving from (a,b) to (x,y) is legal
{
    
    /*/ THIS IS ACTUALLY USELESS SORRY
    // Check whether I'm being fucked with (I don't want the pawn to stay in place)
    if ( (a==x) && (b==y) )
    {
        return false;
        // Return true because the player shouldn't loose his turn for being an idiot. I'm very forward thinking that way
    }
    /*/
    
    if (!field[a][b] || field[x][y])    // If (a,b) is empty (no pawn) or (x,y) is not empty, STOP
    {
        return false;
    }
    
    // This looks worse than it is. I decided to separate the cases rather than make a single long-as-fuck statement because I don't hate humans.
    
    if (a % 2)          // If a is even ...
    {
        if (b == y && ( (abs(a-x) == 1)/* || (abs(a-x) == 0) */ ) )
            // then the pawn is only allowed to move horizontally (ie: b/y doesn't change)
            // and make sure we're only moving by 1.
        {
            return true;
        }
    }
    else // a is odd
    {
        
        if ( (b == 0 && y == 1) || (b == 1 && (y == 0 || y == 2)) || (b == 2 && y == 1) )
        {
            return true;
        }
        
         /*/ THE HUMAN FRIENDLY VERISION
        if (b == 0 && y == 1)   // If it's initially up top, it can only go down 1.
        {
            return true;
        }
        else if (b == 1 && (y == 0 || y == 2))  // If it's in the middle, it can go up or down
        {
            return true;
        }
        else if (b == 2 && y == 1)  // If it's on the bottom, it can only move 1 up.
        {
            return true;
        }
         /*/
    }
    
    return false;
}