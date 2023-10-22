#include "GameState.h"
#include "EntityManager.h"

GameState::GameState() {
    this->restaurant = new Restaurant();
}

void GameState::tick() {
	restaurant->tick();
}

void GameState::render() {
	restaurant->render();
	if (restaurant->clientslost>14){                 //lose if you lose 10 clients
		setNextState("Lose");
		setFinished(true);
	}else if (restaurant->getMoney()>=100){           //win if money is 100 or more
		setNextState("Win");
		setFinished(true);
	}
}

void GameState::keyPressed(int key){
	restaurant->keyPressed(key);
}

void GameState::mousePressed(int x, int y, int button){
}

void GameState::keyReleased(int key){
}

void GameState::reset(){
	setFinished(false);
	setNextState("");
}