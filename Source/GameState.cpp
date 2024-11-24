#include "Headers/GameState.h"
#include <algorithm>
using namespace std;

GameState::GameState(StateData* stateData) : State(stateData), mapManager(nullptr) {
    player = new Mario(
        sf::Vector2f(400.f, 300.f),  // Starting position
        sf::Vector2f(64.f, 64.f),    // Size
        100,                         // Health
        150.0f,                       // Speed
        &physicsEngine              // Pointer to physics engine
    );
    Enemies.clear();
	Blocks.clear();

    physicsEngine.addPlayer(player);
    // Add Mario to game objects
  //  gameObjects.push_back(player);
}


GameState::~GameState() {
    // Clean up all game objects
    for (auto& object : gameObjects) {
        delete object;
    }
    gameObjects.clear();

    delete mapManager;
}

void GameState::loadLevel(int level) {
    if (mapManager) {
        delete mapManager;
    }

    mapManager = new MapManager();
    if (level == 1) {
        mapManager->loadMap("Level1_Map", player, Enemies, Blocks, window);
        for (int i = 0; i < Blocks.size(); i++) {
			physicsEngine.addBlock(Blocks[i]);
		}
    }
    else if (level == 2) {
        //mapManager->loadMap("Level2_Map");
    }
    else if (level == 3) {
        //mapManager->loadMap("Level3_Map");
    }

    // Add level objects to physics engine
    // mapManager->getPhysicsObjects() might return vector of GameObjects
    /*for (auto& obj : mapManager->getPhysicsObjects()) {
        physicsEngine.addObject(obj);
    }*/
}

void sleepOneSecond() {
    std::this_thread::sleep_for(std::chrono::seconds(1/3));
}

void GameState::update(const float& dt) {
    if (mapManager) {
		mapManager->update(dt, player);
    }
    player->update(dt);
       
    // Update physics first
    // physicsEngine.playerUpdatePhysics(dt);
    // physicsEngine.objectUpdatePhysics(dt);

    // Then update all game objects
    for (auto& object : gameObjects) {
        object->update(dt);
    }
    cerr << player->getOnGround() << " " << player->getVelocity().x << " " << player->getVelocity().y << endl;
}
  

void GameState::render(sf::RenderTarget* target) {
    if (!target) {
        target = window;
    }

    if (mapManager) {
        //mapManager->render();
    }

    player->render(target);
	

    for (auto& Block : Blocks) {
        Block->render(target);
    }
	//cerr << Blocks.size() << endl;
}

