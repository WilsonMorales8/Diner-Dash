#include "State.h"
#include "Client.h"

class LoseState: public State{

    public:
        void tick();
        void render();
        void keyPressed(int key);
        void mousePressed(int x, int y, int button);
        void reset();
};