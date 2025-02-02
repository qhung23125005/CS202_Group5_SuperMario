#pragma once
#include "MainMenuState.h"
#include "PlayerManager.h"

namespace LevelMenu {
	enum level_options { BTN_LEVEL1 = 0, BTN_LEVEL2, BTN_LEVEL3, BTN_SETTING, BTN_BACK };
}

class MenuLevelState : public MainMenuState
{
private:
    // Continue
	bool Continue;

    int world;
    int level;
    sf::Text worldText;

	// Transition effects
	bool transitioningOut;
	float transitionAlpha;

    void initButtons() override;
    PlayerManager* player;
public:
    MenuLevelState(StateData* stateData, int world);
	MenuLevelState(StateData* stateData, int world, bool Continue);
    virtual ~MenuLevelState();


    void updateGUI() override;
    void update(const float& dt, const sf::Event& event) override;
    void render(sf::RenderTarget* target) override;
    void updateTransitionEffect(const float& dt);
};