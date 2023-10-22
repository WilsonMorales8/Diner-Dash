#include "WinState.h"

void WinState::tick(){
}

void WinState::render(){
    ofSetBackgroundColor(0,255,100);
    ofSetColor(0,0,0);
    ofDrawBitmapString("Congratulations, You Win!", ofGetWidth()/2 - 50, ofGetHeight()/2); //renders win screen
}

void WinState::keyPressed(int key){
}

void WinState::mousePressed(int x, int y, int button){
}

void WinState::reset(){
    setFinished(false);
    setNextState("");
}