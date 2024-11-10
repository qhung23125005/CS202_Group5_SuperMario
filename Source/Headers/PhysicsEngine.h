#pragma once
#include "GameObject.h"

class PhysicsEngine 
{
private:
	std::list<GameObject> objects;
	sf::Vector2f gravity;
	sf::Vector2f horizontalUserForce;
	sf::Vector2f verticalUserForce;


public:
	PhysicsEngine();
	void applyGravity(GameObject& obj);
	bool checkCollision(GameObject& obj1, GameObject& obj2);
	void resolveCollision(GameObject& obj1, GameObject& obj2);
	void updatePhysics();

};

