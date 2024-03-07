/*
Name: Syeda Rija Ali
id:23k-0057
desc:  a game engine showing associaton
*/

#include <iostream>
#include <string>

using namespace std;


class GraphicRenderEngine {
public:
    void render() {
        cout<<"The engine is rendering graphics." << endl;
    }
};

class InputHandler {
public:
    void handleInput() {
        cout << "Input is being handled." << endl;
    }
};

class PhysicsEngine {
public:
    void simulatePhysics() {
        cout << "Physics is being simulated in the engine!" << endl;
    }
};

class GameEngine {
//association being used
private:
    GraphicRenderEngine graphicsEngine;
    InputHandler inputHandler;
    PhysicsEngine physicsEngine;

public:
    void start() {
        cout << "The Graphics engine is starting." << endl;
        graphicsEngine.render();
        inputHandler.handleInput();
        physicsEngine.simulatePhysics();
        cout << "Game engine has started!!!" << endl;
    }
};

int main() {
    GameEngine gameEngine;
    gameEngine.start();
    return 0;
}
