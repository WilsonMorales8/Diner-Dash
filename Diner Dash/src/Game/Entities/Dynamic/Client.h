#ifndef CLIENT_H
#define CLIENT_H

#include "Entity.h"
#include "Burger.h"
#include "Restaurant.h"

class Client: public Entity{
    private:
        Burger* burger;
        int originalPatience;
        float patiencelost = 0;
        int patience = 2000;

    public:
        Client(int, int, int, int, ofImage, Burger*);
        virtual ~Client();
        void tick();
        void render();
        int serve(Burger*);
        Client* nextClient=nullptr;
        bool isLeaving=false;
        int getPatience() const{
            return patience;
        }
        Burger* getBurger(){
            return burger;
        }
        int calculateBurgerPrice(Burger* burger);
        bool getLeaving(){
            return nextClient->isLeaving;
        }
};
#endif
