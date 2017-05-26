// 
// Model.cpp
//   Contains Model in the context of Model-View-Controller paradigm
//
// Created by Matthew Beaudouin-Lafon on 24/05/2017
//

#include "Model.h"

Model::Model() {    
    for (int ring = 0; ring < 3; ring++) {
        for (int rrow = 0; rrow < 3; rrow++) {
            for (int rcol = 0; rcol < 3; rcol ++) {
                field[ring][rrow][rcol] = 0;
            }
        }
    }
}

void Model::run() {
    player = 1;
    int winner = 0;
    int pawns = 0;
    bool worthUpdating = false;
    
    int source [3]; // [ring, rrow, rcol];
    int target [3]; // [ring, rrow, rcol];
    
    // Phase 1: Players set pawns.
    while (pawns <= 6 and winner == 0) {
        //// Get input
        // Note: make sure rrow/rcol aren't 1 (ring center)
        
        //// Update model
        if (field[target[0]][target[1]][target[2]] == 0) {
            field[target[0]][target[1]][target[2]] = player;
            
            winner = getWinner();
            player = not(player - 1) + 1; // 1->2 and 2->1

            //// Update View
            
        }

    }
    
    // Phase 2: Players move them around until a winner is decided.
    while (winner == 0) {        
        //// Get input
        // Select Pawn
        
        // Select Target
        
        //// Update model
        if (field[target[0]][target[1]][target[2]] == 0) {
            // Move Pawn
            field[target[0]][target[1]][target[2]] = field[source[0]][source[1]][source[2]];            
            field[source[0]][source[1]][source[2]] = 0;
            
            // Check for win
            winner = getWinner();
            player = not(player - 1) + 1; // 1->2 and 2->1
            
            //// Update View
        }
    }
    
    player = not(player - 1) + 1; // Undo player switch (TODO: Refactor to avoid this?)
    // View winner

    return;
}

// Note: Find a more elegant of doing this? This looks bad, but for-loops aren't that much prettier for less than loops
//       There's probably some short circuiting to do (if a corner=0, then no need to check either side), but might look awful
int Model::getWinner() {
    // Check each ring
    for (int ring = 0; ring < 3; ring++) {
        // Check top row
        if ((field[ring][0][0] == field[ring][0][1] && field[ring][0][1] == field[ring][0][2]) && field[ring][0][0] != 0) {
            return field[ring][0][0];
        }
        
        // Check bottom row
        if ((field[ring][2][0] == field[ring][0][1] && field[ring][2][1] == field[ring][2][2]) && field[ring][2][0] != 0) {
            return field[ring][2][0];
        }
        
        // Check first column
        if ((field[ring][0][0] == field[ring][1][0] && field[ring][1][0] == field[ring][2][0]) && field[ring][0][0] != 0) {
            return field[ring][0][0];
        }
        
        // Check last column
        if ((field[ring][0][2] == field[ring][1][2] && field[ring][1][2] == field[ring][2][2]) && field[ring][0][2] != 0) {
            return field[ring][0][2];
        }
    }
    
    // Check top connector
    if ((field[0][0][1] == field[1][0][1] && field[1][0][1] == field[2][0][1]) && field[0][0][1] != 0) {
        return field[0][0][1];
    }
    
    // Check right connector
    if ((field[0][1][2] == field[1][1][2] && field[1][1][2] == field[2][1][2]) && field[0][1][2] != 0) {
        return field[0][1][2];
    }
    
    // Check bottom connector
    if ((field[0][2][1] == field[1][2][1] && field[1][2][1] == field[2][2][1]) && field[0][2][1] != 0) {
        return field[0][2][1];
    }
    
    // Check left connector
    if ((field[0][1][0] == field[1][1][0] && field[1][1][0] == field[2][1][0]) && field[0][1][0] != 0) {
        return field[0][1][0];
    }
    
    return 0;
}
