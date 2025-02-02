#include "Headers/WinMenuState.h"
#include "Headers/GameState.h"


WinMenuState::WinMenuState(StateData* stateData, GameState* gameState)
	: State(stateData), gameState(gameState) {
	initVariables();
	initBackground();
	initTexts();
}

WinMenuState::~WinMenuState() {}

void WinMenuState::initVariables() {
}

void WinMenuState::initBackground() {
	background.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
	background.setFillColor(sf::Color(0, 0, 0, 150));
	background.setPosition(0.f, 0.f);
}

void WinMenuState::initTexts() {
	if (!font.loadFromFile("Source/Resources/font/Super-Mario-Bros--3.ttf")) {
		throw("ERROR::DEATHMENUSTATE::COULD NOT LOAD FONT");
	}


	titleText.setFont(font);
	titleText.setString("You win!");
	titleText.setCharacterSize(75);
	titleText.setFillColor(sf::Color::White);
	centerText(titleText, window->getView().getCenter().y - 250);


	questionText.setFont(font);
	questionText.setString("Press enter to continue");
	questionText.setCharacterSize(30);
	questionText.setFillColor(sf::Color::White);
	centerText(questionText, window->getView().getCenter().y - 100);

}

void WinMenuState::centerText(sf::Text& text, float y) {
	text.setPosition(
		window->getView().getCenter().x - text.getGlobalBounds().width / 2,
		y
	);
}

void WinMenuState::updateBackground() {
	sf::Vector2f viewCenter = window->getView().getCenter();
	sf::Vector2f viewSize = window->getView().getSize();

	background.setPosition(viewCenter.x - viewSize.x / 2.f, viewCenter.y - viewSize.y / 2.f);
}

void WinMenuState::updateButtonHover(sf::Text& text, sf::Vector2f mousePos) {
	if (text.getGlobalBounds().contains(mousePos))
		text.setFillColor(sf::Color(200, 200, 200));
	else
		text.setFillColor(sf::Color::White);
}

void WinMenuState::updateGUI() {
	sf::Vector2f mousePosView = window->mapPixelToCoords(sf::Mouse::getPosition(*window));

	updateBackground();
	updateButtonHover(questionText, mousePosView);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
		this->gameState->endState();
		this->endState();
	}
}

void WinMenuState::update(const float& dt, const sf::Event& event) {
	updateMousePosition();
	updateGUI();
}

void WinMenuState::render(sf::RenderTarget* target) {
	if (!target) {
		target = window;
	}
	if (gameState)
		gameState->render(target);

	target->draw(background);
	target->draw(titleText);
	target->draw(questionText);
}
