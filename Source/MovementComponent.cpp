#include "Headers/MovementComponent.h"

MovementComponent::MovementComponent() {
    acceleration = 15.0f;
    maxVelocity = 5.0f;
    isMoveLeft = false;
    isMoveRight = false;
    isJump = false;
    onGround = true;       
    hitCeiling = false;
    velocity = sf::Vector2f(0.0f, 0.0f);
    jumpsRemaining = MAX_JUMPS;  // Initialize jumps
}

MovementComponent::MovementComponent(int a, int maxV) {
    acceleration = static_cast<float>(a) * PIXELS_PER_METER;
    maxVelocity = static_cast<float>(maxV);
    isMoveLeft = false;
    isMoveRight = false;
    isJump = false;
    onGround = true;
    hitCeiling = false;
    velocity = sf::Vector2f(0.0f, 0.0f);
    jumpsRemaining = MAX_JUMPS;  // Initialize jumps
}

MovementComponent::~MovementComponent() {}

void MovementComponent::resetJumps() {
    jumpsRemaining = MAX_JUMPS;
}

int MovementComponent::getJumpsRemaining() const {
    return jumpsRemaining;
}

void MovementComponent::moveLeft(const float& dt) {
    if (!isMoveLeft) return;

    velocity.x -= acceleration * dt;
    if (velocity.x < -maxVelocity) {
        velocity.x = -maxVelocity;
    }
}

void MovementComponent::moveRight(const float& dt) {
    if (!isMoveRight) return;

    velocity.x += acceleration * dt;
    if (velocity.x > maxVelocity) {
        velocity.x = maxVelocity;
    }
}

void MovementComponent::jump(const float& dt) {
    if (onGround && isJump) {
        velocity.y = -0.6f * PIXELS_PER_METER;
        onGround = false;
        isJump = false;
        jumpsRemaining = MAX_JUMPS - 1; 
    }
    else if (!onGround && isJump && jumpsRemaining > 0) {
        velocity.y = -0.6f * PIXELS_PER_METER;  
        isJump = false;
        jumpsRemaining--;
    }
}
