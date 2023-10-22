//
// Created by joshu on 11/3/2020.
//

#pragma once

#include "Item.h"
#include "Entity.h"

class BaseCounter: public Entity {
    private:
        Item *item;

    public:
        BaseCounter(int x, int y, int width, int height, Item* item, ofImage sprite);
        Item* getItem();
        void showItem();
        int tickstocook = 7;
        int currentticks = 0;
        bool isCooked = false;
        bool isCooking = false;
};
