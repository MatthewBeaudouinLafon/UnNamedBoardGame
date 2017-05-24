// 
// Model.cpp
//   Contains Model in the context of Model-View-Controller paradigm
//
// Created by Matthew Beaudouin-Lafon on 24/05/2017
//

#include Model.cpp

Model::Model() {
    player = 1;
    
    for (size_t ring = 0; ring < 3; ring++) {
        for (size_t rrow = 0; rrow < 3; rrow++) {
            for (size_t rcol = 0; rcol < 3; rcol ++) {
                field[ring][rrow][rcol] = 0;
            }
        }
    }
}

Model::run() {
    int winner = 0;
    int pawns = 0;
    
    // Phase 1: Players set pawns.
    while (pawns <= 6) {
        // Get input
        
        // Update model
        
        // Update View

    }
    
    // Phase 2: Players move them around until a winner is decided.
    while (winner == 0) {        
        // Get input
        
        // Update model
        
        // Update View

    }
}