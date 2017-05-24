// 
// Model.h
//  Model header file
//
// Created by Matthew Beaudouin-Lafon on 24/05/2017
//

#ifndef __Board_Game__Model__
#define __Board_Game__Model__

using namespace std;

class Model
{
private:
// The field looks like three of these rings stacked as a cube
//  /     /
// O--O--O
// |     |
// O     O
// |/    |/
// O--O--O
//    ^- Ring position  

    int [3][3][3] field; // int [ring level] [ring row] [ring col]
    
    int player;
    
public:
    Model();
    
    void run();
    
    // void reset(); // TODO: Keep score using a reset function instead of run again
    
    int getPlayer();
    
};

#endif /* defined(__Board_Game__Model__) */