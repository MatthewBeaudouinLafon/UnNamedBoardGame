//
//  Board.h
//  Board Game
//
//  Created by Matthew Beaudouin on 7/17/15.
//  Copyright (c) 2015 Matthew Beaudouin. All rights reserved.
//

#ifndef __Board_Game__Board__
#define __Board_Game__Board__

#include <iostream>
#include <vector>

using namespace std;

class Board
{
private:
    vector<vector<vector<int>>> field;
    
public:
    Board();
    
    bool isEmpty(size_t a, size_t b, size_t c);  // Returns true if the position on the Board is empty
    
    
};

#endif /* defined(__Board_Game__Board__) */
