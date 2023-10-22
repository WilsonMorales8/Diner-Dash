#include "BaseCounter.h"

StoveCounter::StoveCounter(int x, int y, int width, int height,Item* item, ofImage sprite) : BaseCounter(x, y, width, height, item, sprite){

}
void StoveCounter::counter(){

}
void StoveCounter::tick() {
    if (isCooking && !isCooked){
        while (currentticks < 7 && tickstocook > 0){
            ofDrawBitmapString(to_string(tickstocook)+"ticks to finish cooking", ofGetWidth()/2-32, ofGetHeight()/2-20); //countdown to finish cooking
            tickstocook -= 1;
            currentticks += 1;
        }if (currentticks == 7){
            isCooked = true;
        } 
    }

}
void StoveCounter::keyPressed(int key){
    if (key == 'e' && !isCooking && !isCooked){
        isCooking = true;
        currentticks = 0;

    }

}