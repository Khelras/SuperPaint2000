#include "cButtonManager.h"

cButtonManager::cButtonManager(cToolManager* _toolManager, cWindowManager* _window) {
	this->m_Window = _window;
	this->m_ButtonRectangle = new cButtonRectangle(_toolManager, sf::Vector2f(30, 50), sf::Color::Green);
	this->m_ButtonEllipse = new cButtonEllipse(_toolManager, sf::Vector2f(40, 125), sf::Color::Green);
}

cButtonManager::~cButtonManager() {
	delete(this->m_ButtonRectangle);
	delete(this->m_ButtonEllipse);
}

void cButtonManager::DrawButtons() {
	this->m_Window->m_ToolWindow.draw(this->m_ButtonRectangle->m_ButtonShape);
	this->m_Window->m_ToolWindow.draw(this->m_ButtonEllipse->m_ButtonShape);
}

void cButtonManager::ClickButtons(sf::Vector2i _mousePos) {
	if (this->m_ButtonRectangle->m_ButtonShape.getGlobalBounds().contains(sf::Vector2f(_mousePos))) {
		this->m_ButtonRectangle->UseButton();
	}
	else if (this->m_ButtonEllipse->m_ButtonShape.getGlobalBounds().contains(sf::Vector2f(_mousePos))) {
		this->m_ButtonEllipse->UseButton();
	}
}
