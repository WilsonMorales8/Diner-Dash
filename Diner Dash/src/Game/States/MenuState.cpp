#include "MenuState.h"

MenuState::MenuState() {
	string text = "Start";
	startButton = new Button(ofGetWidth()/2 - text.length()*8, ofGetHeight()/2 - text.length()*11, 64, 50, "Start");
}

void MenuState::tick() {
	startButton->tick();
	if(startButton->wasPressed()){
		setNextState("Game");
		setFinished(true);

	}
}

void MenuState::render() {
	ofSetBackgroundColor(230, 230, 250);
	ofDrawBitmapString("Press e to pick up an ingredient", ofGetWidth()/2-100, ofGetHeight()/2 + 50);         //renders start screen
	ofDrawBitmapString("Press s to serve the client", ofGetWidth()/2-100, ofGetHeight()/2 + 30);
	ofDrawBitmapString("Press u to undo the last added ingredient",ofGetWidth()/2-100, ofGetHeight()/2 + 10);
	startButton->render();
}

void MenuState::keyPressed(int key){
	
}

void MenuState::mousePressed(int x, int y, int button){
	startButton->mousePressed(x, y);
}

void MenuState::reset(){
	setFinished(false);
	setNextState("");
	startButton->reset();
}