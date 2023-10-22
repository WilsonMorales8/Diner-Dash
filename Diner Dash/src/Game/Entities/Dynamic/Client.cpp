#include "Client.h"

Client::Client(int x, int y, int width, int height, ofImage sprite, Burger* burger): Entity(x, y, width, height, sprite){
    this->burger = burger;
    patiencelost = 0;
}
Client::~Client(){
    delete burger;
}
void Client::render(){
    ofSetColor (255,255,255);
    burger->render();
    ofSetColor (255,255-patiencelost,255-patiencelost);
    sprite.draw(x, y, width, height);
    if(nextClient != nullptr){
        nextClient->render();
    }
}

void Client::tick(){
    patiencelost += 0.1;
    patience -= 1;
    burger->setY(y);
    if(patience == 0){
        isLeaving = true;
    }
    if(nextClient != nullptr){
        nextClient->tick();
    }
}

int Client::calculateBurgerPrice(Burger* burger) {           //ingredient pricing
    int price = 0;
    for (Item* ing : burger->getIngredients()) {
        if (ing->name == "topBun" || ing->name == "bottomBun") {
            price++;
        } 
        else if (ing->name == "lettuce" || ing->name == "tomato") {
            price += 2;
        } 
        else if (ing->name == "cheese") {
            price += 3;
        } 
        else if (ing->name == "patty") {
            price += 4;
        }
    }
    return price;
}

int Client::serve(Burger* burger) {                        //equals method + serving other clients
    if (this->burger->equals(burger)) {
        isLeaving = true;
        int price = calculateBurgerPrice(burger);
        burger->clear();
        return price;
    } 
    else if (nextClient != nullptr) {
        return nextClient->serve(burger);
    }
    burger->clear();
    return 0;
}