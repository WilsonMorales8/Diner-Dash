//
// Created by joshu on 11/4/2020.
//
#pragma once

#include "Entity.h"
#include "Item.h"

class Burger {
  private:
    int x, y, width, height;
    vector<Item *> ingredients;

  public:
    Burger(int, int, int, int);
    void addIngredient(Item *item);
    void render();
    void clear();
    void undoLastIngredient();         
    void setY(int y) {
        this->y = y;
    } 
    bool equals(Burger* param);
    const std::vector<Item*>& getIngredients() const;       
};
