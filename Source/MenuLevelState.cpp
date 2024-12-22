#include "Headers/MenuLevelState.h"
#include "Headers/GameState.h"
#include "Headers/FireBuff.h"

MenuLevelState::MenuLevelState(StateData* stateData, int world) : MainMenuState(stateData),level(0)
{
    // Reinitialize buttons with level-specific content
    this->world = world;
    this->initButtons();
}

MenuLevelState::~MenuLevelState()
{
}

void MenuLevelState::initButtons()
{
    buttons.resize(4); // 3 levels + 1 back button

    float x = window->getSize().x / 2 - btn_Width / 2;
    float y = window->getSize().y / 2.2;

    // Init World text
    worldText.setFont(font);
    worldText.setString("WORLD " + std::to_string(world));

    // Adjust the font size and color for better visibility
    worldText.setCharacterSize(60); // Increase size for emphasis
    worldText.setFillColor(sf::Color::Yellow); // Use a bright contrasting color
    worldText.setOutlineThickness(5); // Add outline for better readability
    worldText.setOutlineColor(sf::Color::Red); // Red outline for contrast

    // Position the text in the center of the screen
    worldText.setPosition(SCREEN_WIDTH / 2 - worldText.getGlobalBounds().width / 2,
        y - worldText.getGlobalBounds().height * 2);

    //y += btn_Height * 1.5;


    buttons[BTN_LEVEL1] = new GUI::TextureButton( false,
        x, y, btn_Width, btn_Height,
        &font,  "Level 1", btn_CharSize,
        sf::Color::Black, sf::Color::White, sf::Color::White,
        "Source/Resources/texture/menu_button.png",
        "Source/Resources/texture/menu_button.png",
        "Source/Resources/texture/menu_button.png"
    );

    y += btn_Height * 1.5;
    buttons[BTN_LEVEL2] = new GUI::TextureButton(false,
        x, y, btn_Width, btn_Height,
        &font, "Level 2", btn_CharSize,
        sf::Color::Black, sf::Color::White, sf::Color::White,
        "Source/Resources/texture/menu_button.png",
        "Source/Resources/texture/menu_button.png",
        "Source/Resources/texture/menu_button.png"
    );

    y += btn_Height * 1.5;
    buttons[BTN_LEVEL3] = new GUI::TextureButton(false,
        x, y, btn_Width, btn_Height,
        &font, "Level 3", btn_CharSize,
        sf::Color::Black, sf::Color::White, sf::Color::White,
        "Source/Resources/texture/menu_button.png",
        "Source/Resources/texture/menu_button.png",
        "Source/Resources/texture/menu_button.png"
    );

    y += btn_Height * 1.5;
    buttons[BTN_BACK] = new GUI::TextureButton(false,
        x, y, btn_Width, btn_Height,
        &font, "Back", btn_CharSize,
        sf::Color::Black, sf::Color::White, sf::Color::White,
        "Source/Resources/texture/menu_button.png",
        "Source/Resources/texture/menu_button.png",
        "Source/Resources/texture/menu_button.png"
    );
}

void MenuLevelState::updateGUI()
{
    for (auto& it : buttons)
    {
        it->update(mousePosWindow);
    }
    //If user hasn't completed the previous level, disable these buttons
  //  buttons[BTN_LEVEL2]->setDisable(!this->stateData->userData->getCompleted(world, 1));
   // buttons[BTN_LEVEL3]->setDisable(!this->stateData->userData->getCompleted(world, 2));
    

    // Existing mouse press handlers
    if (buttons[BTN_LEVEL1]->isPressed())
    {
        GameState* gameState = new GameState(this->stateData, world, 1);
        gameState->reloadLevel();
        this->states->push(gameState);
    }
    else if (buttons[BTN_LEVEL2]->isPressed())
    {
        GameState* gameState = new GameState(this->stateData, world, 2);
        gameState->reloadLevel();
        this->states->push(gameState);
    }
    else if (buttons[BTN_LEVEL3]->isPressed()) {
        GameState* gameState = new GameState(this->stateData, world, 3);
        gameState->reloadLevel();
        this->states->push(gameState);
    }
    else if (buttons[BTN_BACK]->isPressed())
    {
        endState();
    }
}

void MenuLevelState::update(const float& dt)
{
    //Defaut view
    window->setView(window->getDefaultView());
    updateMousePosition();
    updateGUI();
}

void MenuLevelState::render(sf::RenderTarget* target)
{
    if (!target)
	{
		target = window;
	}
    target->draw(background[world]);
	target->draw(worldText);
	for (auto& it : buttons)
	{
		it->render(target);
	}
}
