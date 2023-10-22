//
// Created by joshu on 11/4/2020.
//

#include "Burger.h"

Burger::Burger(int x, int y, int width, int height){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

void Burger::addIngredient(Item *item) {
    ingredients.push_back(item);
}

void Burger::undoLastIngredient() {    //UndoIngredient method
    if (!ingredients.empty()) {
        ingredients.pop_back();
    }
}

void Burger::render(){
    int counter = 1;
    for (Item* ingredient:ingredients){
        ingredient->sprite.draw(x-5,y-(counter * 10)+55,width*0.70,height*0.70);
        counter++;
    }
}

void Burger::clear(){
    ingredients.clear();
}

bool Burger::equals(Burger *param){                                 //equals
    return (this->ingredients == param -> getIngredients());
}

const std::vector<Item*>& Burger::getIngredients() const {         //getIngredients
    return ingredients;
}