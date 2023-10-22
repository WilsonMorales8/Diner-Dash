#include "LoseState.h"

void LoseState::tick(){
}

void LoseState::render(){
    ofSetBackgroundColor(255,64,64);
    ofSetColor(0,0,0);
    ofDrawBitmapString("Game Over, You Lost", ofGetWidth()/2 - 50, ofGetHeight()/2);    //renders lose screen
}

void LoseState::keyPressed(int key){
}

void LoseState::mousePressed(int x, int y, int button){
}

void LoseState::reset(){
    setFinished(false);
    setNextState("");
}