#pragma once

#include "ofMain.h"
#include "map"
#include "tuple"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

        int getWinner();
        int* parseMousePosition(int* position);
        std::tuple<int, int, int> getBoardPosition(const int x, const int y);
		
        ofImage background;

        // The field looks like three of these rings stacked as a cube
        //    /
        // O--O--O
        // |/    |/
        // O     O
        // |   / |
        // O--O--O
        //    ^- Ring position (2,1)

        // int [ring level] [ring row] [ring col]
        int field [3][3][3];

        // Map mouse position to board position
        std::map<std::tuple<int, int>, std::tuple<int, int, int>> mouseToBoard;
        std::map<std::tuple<int, int, int>, std::tuple<int, int>> boardToMouse;

        // Winner
        int winner = 0;

        // Phase 1 when players set their pawns, phase 2 when they move them
        int turn = 0;

        // Number of pixels around the source of a button
        int hitbox = 40;

        // To move pawns in phase 2
        int selectedPawn = 0;
        int* selectedPawnPosition;

        int converter = 100; // TODO: Base this on window size

};
