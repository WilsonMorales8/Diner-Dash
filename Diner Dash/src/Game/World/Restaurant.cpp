//
// Created by joshu on 11/3/2020.
//

#include "Restaurant.h"

Player *Restaurant::getPlayer() { return player; }
void Restaurant::setPlayer(Player *player) { this->player = player; }

Restaurant::Restaurant() {
    floor.load("images/floor.jpg");
    entityManager = new EntityManager();
    ofImage chefPlayerImage;
    chefPlayerImage.load("images/chef.png");
    this->player = new Player(0, 600, 64, 64, chefPlayerImage, entityManager);    
    ofImage spriteCrop, chairdec, tabledec;
        spriteCrop.load("images/sprite.png");
        chairdec.cropFrom(spriteCrop, 105, 10, 40, 38);//crops chair from sprite.png
        tabledec.cropFrom(spriteCrop, 17, 21, 75, 58);//crops table from sprite.png
        ofImage welcomemat;
        welcomemat.load("images/welcome.png");
        ofImage doordec;
        doordec.load("images/door.png");
        entityManager->addEntity(new Entity(450, 300, 50, 55, chairdec));//adds chair
        entityManager->addEntity(new Entity(350, 280, 75, 78, tabledec));//adds table
        entityManager->addEntity(new Entity(20, 100, 25, 50, welcomemat));//adds welcoming mat
        entityManager->addEntity(new Entity(80, 100, 275, 255, doordec));//adds door
        

    initItems();
    initCounters();
    initClients();
    generateClient();
}

void Restaurant::initItems(){
    ofImage burgerSpriteSheet, cheeseImg, lettuceImg, tomatoImg, burgerImg, botBreadImg, topBreadImg, plateImg;
    burgerSpriteSheet.load("images/burger.png");
    topBreadImg.cropFrom(burgerSpriteSheet, 25, 16, 112, 43); // top bun
    burgerImg.cropFrom(burgerSpriteSheet, 30, 134, 103, 48); // patty
    cheeseImg.cropFrom(burgerSpriteSheet, 169, 213, 102, 39); // cheese
    tomatoImg.cropFrom(burgerSpriteSheet, 169, 158, 110, 41); // tomato
    lettuceImg.cropFrom(burgerSpriteSheet, 161, 62, 117, 34); // lettuce
    botBreadImg.cropFrom(burgerSpriteSheet, 444, 270, 115, 39); // bottom bun
    plateImg.cropFrom(burgerSpriteSheet, 575, 263, 131, 51); // plate

    cheese = new Item(cheeseImg, "cheese");
    lettuce = new Item(lettuceImg, "lettuce");
    tomato = new Item(tomatoImg, "tomato");
    burger = new Item(burgerImg, "patty");
    botBread = new Item(botBreadImg, "bottomBun");
    topBread = new Item(topBreadImg, "topBun");
}

void Restaurant::initCounters(){
    int counterWidth = 96;
    int yOffset = 500;
    ofImage counterSheet, plateCounterImg, cheeseCounterImg, stoveCounterImg, lettuceCounterImg, emptyCounterImg, tomatoCounterImg, breadCounterImg;
    counterSheet.load("images/kitchen_cabinets_by_ayene_chan.png");
    stoveCounterImg.cropFrom(counterSheet, 224,12,32,43);//stoveTop
    lettuceCounterImg.cropFrom(counterSheet,96,76,32,43);//Vegetables
    emptyCounterImg.cropFrom(counterSheet,0,245,30,43);//Empty
    tomatoCounterImg.cropFrom(counterSheet,96,200,32,48);//fruit basket
    cheeseCounterImg.cropFrom(counterSheet,64,73,32,46);//cheese
    plateCounterImg.cropFrom(counterSheet,0,133,32,50);//plates
    breadCounterImg.cropFrom(counterSheet,0,63,34,56);//buns
    entityManager->addEntity(new BaseCounter(0,yOffset-16, counterWidth, 117, nullptr, plateCounterImg));
    entityManager->addEntity( new BaseCounter(counterWidth,yOffset-7, counterWidth,108, cheese, cheeseCounterImg));
    entityManager->addEntity(new StoveCounter(counterWidth*2,yOffset, counterWidth, 102, burger, stoveCounterImg));    //makes stovecounter a StoveCounter class
    entityManager->addEntity(new BaseCounter(counterWidth*3, yOffset, counterWidth, 102, lettuce, lettuceCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*4,yOffset, counterWidth, 102, nullptr, emptyCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*5, yOffset -10, counterWidth, 113, tomato, tomatoCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*6, yOffset-32, counterWidth, 133, botBread, breadCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*7, yOffset-32, counterWidth, 133, topBread, breadCounterImg));
}

void Restaurant::initClients(){
    ofImage temp;
    temp.load("images/People/Car_Designer3Female.png");
    people.push_back(temp);
    temp.load("images/People/Freedom_Fighter2Male.png");
    people.push_back(temp);
    temp.load("images/People/Hipster.png");
    people.push_back(temp);
    temp.load("images/People/Lawyer2Male.png");
    people.push_back(temp);
    temp.load("images/People/Mad_Scientist3Female.png");
    people.push_back(temp);
    temp.load("images/People/Programmer2Male.png");
    people.push_back(temp);
    temp.load("images/People/Songwriter3Male.png");
    people.push_back(temp);
    temp.load("images/People/Weather_Reporter2Female.png");
    people.push_back(temp);
}

void Restaurant::tick() {
    ticks++;
    if(ticks % 400 == 0){
        generateClient();
    }
    player->tick();
    entityManager->tick();
    if(entityManager->inspectorleave){ //if the inspector leaves it takes half of your money
        money -= money/2;
        entityManager->inspectorleave = false;
    }
}

void Restaurant::generateClient(){          //RandomIngredients
    Burger* b = new Burger(72, 100, 50, 25);
    b->addIngredient(botBread);
    for(int i = 0; i < 3; i++){
        int random = rand() % 4 + 1;
        if(random == 1){
            b->addIngredient(burger);
        }
        else if(random == 2){
            b->addIngredient(cheese);
        }
        else if(random == 3){
            b->addIngredient(tomato);
        }
        else if(random == 4){
            b->addIngredient(lettuce);
        }
    }
    b->addIngredient(topBread);
    entityManager->addClient(new Client(0, 50, 64, 72,people[ofRandom(8)], b));
    clientslost += 1;
    if (clientslost==10){
        entityManager->addInspector(new Inspector(0, 50, 64, 72, people[ofRandom(8)], b)); //inspectors are added after 10 clients leave
    }
}

void Restaurant::render() {
    floor.draw(0,0, ofGetWidth(), ofGetHeight());
    player->render();
    entityManager->render();
    ofSetColor(0, 100, 0);
    ofDrawBitmapString("Money: " + to_string(money), ofGetWidth()/2, 10);
    ofSetColor(256, 256, 256);
}

void Restaurant::serveClient(){
    if(entityManager->firstClient != nullptr){
        money += entityManager->firstClient->serve(player->getBurger());
    }
}

void Restaurant::keyPressed(int key) {
    player->keyPressed(key);
    if(key == 's'){
        serveClient();
    }
    if(key == 'e'){    //ingredient cost
        money-=1;
    }
}
