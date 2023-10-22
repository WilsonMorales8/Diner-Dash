#include "State.h"

class WinState: public State{

    public:
        void tick();
        void render();
        void keyPressed(int key);
        void mousePressed(int x, int y, int button);
        void reset();
};