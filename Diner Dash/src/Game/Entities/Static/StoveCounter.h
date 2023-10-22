#include "BaseCounter.h"
#include "EntityManager.h"

class StoveCounter : public BaseCounter {
    public:
        StoveCounter(int x, int y, int width, int height, Item* item, ofImage sprite); //added stovecounter subclass
        void tick();
        void keyPressed(int key);
        void counter();
    private:
        EntityManager* entityManager;

};
