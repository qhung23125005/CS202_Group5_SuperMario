#include "Headers/Bowser.h"

Bowser::Bowser()
{
    walkSpeed = 20.f;   

    isAlive = true;
    setHealth(50);

    currentAction = "WALK-";
    isAnimationInProgress = false;

    if (!entityTexture.loadFromFile("Source/Resources/texture/Enemies.png")) {
        throw std::runtime_error("Failed to load Koopa texture!");
    }

    entitySprite.setTexture(entityTexture);
    entitySprite.setScale(4.0f, 4.0f);


    this->animationComponent = new AnimationComponent(this->entitySprite);
    initAnimations();

    movementComponent = new MovementComponent(walkSpeed, 3.0f);

    hitbox.setSize(sf::Vector2f(128.f, 140.f));
    hitbox.setPosition(position);
    hitbox.setFillColor(sf::Color::Transparent);
    hitbox.setOutlineColor(sf::Color::Green);
    hitbox.setOutlineThickness(-1.f);
}

Bowser::Bowser(sf::Vector2f position, sf::Vector2f size, float x_min, float x_max): Bowser()
{
    this->position = position;
    this->size = size;
    this->x_min = x_min;
    this->x_max = x_max;
    setMoveRight(true);
}

Bowser::~Bowser()
{
}

void Bowser::initAnimations() {
    spritesSheet = {
        { "WALK-1", sf::IntRect(1, 186, 32, 35) },  
        { "WALK-2", sf::IntRect(34, 186, 32, 35) },
        { "WALK-3", sf::IntRect(67, 186, 32, 35) },

		{ "WALKR-1", sf::IntRect(795, 186, 32, 35) },
		{ "WALKR-2", sf::IntRect(762, 186, 32, 35) },
		{ "WALKR-3", sf::IntRect(729, 186, 32, 35) }
    };
}

void Bowser::update(const float& dt) {
    updateAnimation(dt);
    updateVelocity(dt);
    eventMediator->applyExternalForce(this, dt);
	move(dt);
}

void Bowser::updateAnimation(const float& dt) {
    if (this->isMoveLeft()) {
        animationComponent->setAnimationEnemies("WALKR-", spritesSheet, 0.2f);
    }
    else if (this->isMoveRight()) {
        animationComponent->setAnimationEnemies("WALK-", spritesSheet, 0.2f);
    }

    animationComponent->update(dt);
}

void Bowser::getDamaged() {
}

void Bowser::move(const float& dt) {
    this->position += this->movementComponent->velocity * dt;

    if (this->position.x <= x_min) {
        this->position.x = std::max<float>(this->position.x, x_min);

        setMoveLeft(false);
        setMoveRight(true);
    }

    if (this->position.x >= x_max) {
        this->position.x = std::min<float>(this->position.x, x_max);

        setMoveRight(false);
        setMoveLeft(true);
    }

    this->entitySprite.setPosition(this->position);
    this->hitbox.setPosition(this->position);
}

bool Bowser::getIsAlive() const {
    return isAlive;
}

void Bowser::setIsAlive(bool alive) {
    isAlive = alive;
}

void Bowser::reactToPlayerCollision(int collidedSide) {
}

void Bowser::reactToBlockCollision(int collidedSide) {
}
