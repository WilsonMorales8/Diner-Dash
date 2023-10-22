//
// Created by joshu on 11/3/2020.
//
#pragma once

#include "EntityManager.h"
#include "Player.h"
#include "ofMain.h"
#include "Inspector.h"

class Restaurant {
    private:
        Player* player;
        int ticks=0;
        std::vector<ofImage> people;
        EntityManager* entityManager;
        int money = 0;

    public:
        void setMoney(int x){ this->money = x;}
        int clientslost = 0;
        Client *client;
        Restaurant();
        Player* getPlayer();
        void setPlayer(Player *player);
        Item* cheese;
        Item* lettuce;
        Item* tomato;
        Item* burger;
        Item* botBread;
        Item* topBread;
        ofImage floor;
        void initItems();
        void initCounters();
        void initClients();
        void generateClient();
        void serveClient();
        void tick();
        void render();
        void keyPressed(int key);
        int getMoney(){
            return money;
        }
};
