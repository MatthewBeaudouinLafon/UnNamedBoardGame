#include "ofApp.h"
#include "math.h"

//--------------------------------------------------------------
void ofApp::setup(){
    background.load("images/Board.png");
    ofSetWindowTitle("Board Game");

    // Initialize Board to Mouse Map
    //   mouseToBoard [x, y] -> [ring, rrow, rcol]
    //   boardToMouse [ring, rrow, rcol] -> [x, y]

    int x, y = 1;

    for (int ring = 0; ring < 3; ring++) {
        x = ring + 1;
        y = ring + 1;

        for (int rrow = 0; rrow < 3; rrow++) {
            for (int rcol = 0; rcol < 3; rcol++) {
                if (!(x == 4 && y == 4)) {
                    std::cout << converter * x << ", " << converter * y << " -> " << ring << rrow << rcol << std::endl;
                    mouseToBoard[std::make_tuple(converter * x, converter * y)] = std::make_tuple(ring, rrow, rcol);
                    boardToMouse[std::make_tuple(ring, rrow, rcol)] = std::make_tuple(converter * x, converter * y);
                }
                x = x + (3 - ring);
            }
            x = ring + 1;
            y = y + (3 - ring);
        }
    }

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    if (winner != 0) {

    }

    ofSetColor(255,255,255);
    background.draw(0,0);

    for (int ring = 0; ring < 3; ring++) {
        for (int rrow = 0; rrow < 3; rrow++) {
            for (int rcol = 0; rcol < 3; rcol++) {
                if (field[ring][rrow][rcol] != 0) {
                    if (field[ring][rrow][rcol] == 1){
                        ofSetColor(255,0,0);
                    } else if (field[ring][rrow][rcol] == 2){
                        ofSetColor(0,0,255);
                    }
                    std::tuple<int,int> xy = boardToMouse[std::make_tuple(ring, rrow, rcol)];
                    ofDrawCircle(std::get<0>(xy), std::get<1>(xy), hitbox/2); // TODO: Better Radius
                }
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){    
    // Parse x/y position
    int position [3];

    std::tuple<int, int, int> gridxy = getBoardPosition(x, y);
    position[0] = std::get<0>(gridxy); // Thanks cplup
    position[1] = std::get<1>(gridxy);
    position[2] = std::get<2>(gridxy);

    std::cout << position[0] << position[1] << position[2] << std::endl;


    // Handle logic
    if (winner != 0) {
        std::cout << "Player " << winner << " wins!" << std::endl;

    } else if (turn < 6) {
        if (field[position[0]][position[1]][position[2]] == 0) {
            field[position[0]][position[1]][position[2]] = (turn % 2) + 1;

            winner = getWinner();
            turn++;
        }
    } else {
        // Select Pawn
        if (selectedPawn == 0) {
            if (field[position[0]][position[1]][position[2]] == ((turn % 2) + 1)) {
                selectedPawn = field[position[0]][position[1]][position[2]];
                selectedPawnPosition = new int [3];

                for (int i = 0; i < 3; i++) {
                    selectedPawnPosition[i] = position[i];
                }
            }

        // Move Pawn
        } else {
            if (field[position[0]][position[1]][position[2]] == 0) {
                // Move Pawn
                field[position[0]][position[1]][position[2]] = field[selectedPawnPosition[0]][selectedPawnPosition[1]][selectedPawnPosition[2]];
                field[selectedPawnPosition[0]][selectedPawnPosition[1]][selectedPawnPosition[2]] = 0;

                selectedPawn = 0;
                delete selectedPawnPosition;

                winner = getWinner();
                turn++;
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

// Helper functions
//--------------------------------------------------------------
int ofApp::getWinner(){
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

std::tuple<int, int, int> ofApp::getBoardPosition(const int x, const int y) {
    int gridx = converter * int((round(float(x)/converter)));
    int gridy = converter * int((round(float(y)/converter)));
    if (abs(x - gridx) <= hitbox && abs(y - gridy) <= hitbox) {
        std::tuple<int, int> gridxy = std::make_tuple(gridx, gridy);
        if (mouseToBoard.find(gridxy) != mouseToBoard.end()){
            return mouseToBoard[gridxy];
        }
    }

    return std::make_tuple(-1, -1, -1);
}
