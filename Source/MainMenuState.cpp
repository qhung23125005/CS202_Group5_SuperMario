#include "Headers/MainMenuState.h"

void MainMenuState::initVariables()
{
	nButtons = 4;
	btn_Width = 400;
	btn_Height = 75;
	btn_CharSize = 20;
}

void MainMenuState::initBackground()
{
	backgroundTexture.loadFromFile("Source/Resources/texture/menu_background.png");
	background.setTexture(backgroundTexture);
	background.setScale(window->getSize().x / background.getGlobalBounds().width, 
		window->getSize().y / background.getGlobalBounds().height);
}

void MainMenuState::initFonts()
{
	if (!font.loadFromFile("Source/Resources/font/Super-Mario-Bros--3.ttf")) {
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}
}

void MainMenuState::initButtons()
{
	buttons.resize(nButtons);

	float x = window->getSize().x / 2 - btn_Width / 2;
	float y = window->getSize().y / 2.2;

	buttons[BTN_CONTINUE] = new GUI::TextureButton(
		x, y, btn_Width, btn_Height,
		&font, "coninue", btn_CharSize,
		sf::Color::Black, sf::Color::White, sf::Color::White,
		"Source/Resources/texture/menu_button.png", 
		"Source/Resources/texture/menu_button.png", 
		"Source/Resources/texture/menu_button.png"
	);
	
	y += btn_Height * 1.5;
	buttons[BTN_NEWGAME] = new GUI::TextureButton(
		x, y, btn_Width, btn_Height,
		&font, "new game", btn_CharSize,
		sf::Color::Black, sf::Color::White, sf::Color::White,
		"Source/Resources/texture/menu_button.png", 
		"Source/Resources/texture/menu_button.png", 
		"Source/Resources/texture/menu_button.png"
	);

	y += btn_Height * 1.5;
	buttons[BTN_LEADER] = new GUI::TextureButton(
		x, y, btn_Width, btn_Height,
		&font, "leader board", btn_CharSize,
		sf::Color::Black, sf::Color::White, sf::Color::White,
		"Source/Resources/texture/menu_button.png", 
		"Source/Resources/texture/menu_button.png", 
		"Source/Resources/texture/menu_button.png"
	);

	y += btn_Height * 1.5;
	buttons[BTN_EXIT] = new GUI::TextureButton(
		x, y, btn_Width, btn_Height,
		&font, "exit", btn_CharSize,
		sf::Color::Black, sf::Color::White, sf::Color::White,
		"Source/Resources/texture/menu_button.png", 
		"Source/Resources/texture/menu_button.png", 
		"Source/Resources/texture/menu_button.png"
	);

}

MainMenuState::MainMenuState(StateData* stateData)
	: State(stateData)
{
	this->initVariables();
	this->initBackground();
	this->initFonts();
	this->initButtons();
}

MainMenuState::~MainMenuState()
{
	for (auto it = buttons.begin(); it != buttons.end(); ++it)
	{
		delete* it;
	}
}

void MainMenuState::updateGUI()
{
	for (auto& it : buttons)
	{
		it->update(mousePosWindow);
	}

	if (buttons[BTN_CONTINUE]->isPressed())
	{
		//this->states.push(new GameState(this->window));
	}

	if (buttons[BTN_NEWGAME]->isPressed())
	{
		//this->states.push(new GameState(this->window));
	}

	if (buttons[BTN_LEADER]->isPressed())
	{
		//this->states.push(new GameState(this->window));
	}

	if (buttons[BTN_EXIT]->isPressed())
	{
		endState();
	}

}

void MainMenuState::update(const float& dt)
{
	updateMousePosition();
	updateGUI();
}

void MainMenuState::resetGUI()
{

}

void MainMenuState::renderGUI()
{
	for (auto& it : buttons)
	{
		it->render(window);
	}
}

void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);
	renderGUI();
}