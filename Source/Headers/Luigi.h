#pragma once

#include "PlayerManager.h" 
#include "AnimationComponent.h"

class Luigi : public PlayerManager {
private:
    std::string m_name;
    std::string currentAction;
    bool isAnimationInProgress;
    std::unordered_map<std::string, sf::IntRect> spritesSheet;
    bool isMovingLeft;
public:
    Luigi();
    Luigi(sf::Vector2f position, sf::Vector2f size, int health = 3, int speed = 15.0f);
    ~Luigi();

    // Initialization function
    void init();
    void initAnimations();

    //Setters and Getters
    bool getIsBig() const;

    // Functions
    void update(const float& dt) override;
    void render(sf::RenderTarget* target) override;
    void handleInput(const float& dt);
    void updateAnimation(const float& dt) override;

    void updateHitboxSize();

    void setBig(bool big) override;
};