#include "State.h"
#include "Restaurant.h"
#include "Client.h"
#include "EntityManager.h"

class GameState: public State{
    public: 
        GameState();
		void reset();
		void tick();
		void render();
		void keyPressed(int key);
		void mousePressed(int x, int y, int button);
		void keyReleased(int key);
		Client* client;
	
	private:
		Restaurant *restaurant;
		int patience = 2000;
		int clientslost;
};