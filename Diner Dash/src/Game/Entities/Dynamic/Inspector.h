#pragma once
#include "Client.h"


class Inspector : public Client { //added inspector subclass to client.h
    private:
        bool isLeaving;
    public:
        Inspector(int x, int y, int width, int height, ofImage sprite, Burger* burger) : Client(x, y, width, height, sprite, burger){
            isLeaving = false;
        }
        bool getLeaving(){
            return isLeaving;
        }
        void setLeaving(bool x){
            isLeaving = x;
        }
    
};