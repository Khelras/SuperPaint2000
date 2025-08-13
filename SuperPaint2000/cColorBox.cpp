#include "cColorBox.h"

cColorBox::cColorBox(cWindowManager* _window, cToolManager* _toolManager, sf::Vector2f _size) : cButton(_size) {
	this->m_CanSelect = false;
	this->m_Window = _window;
	this->m_ToolManager = _toolManager;
	this->m_ButtonShape.setSize(sf::Vector2f(35.0f, 35.0f));
	this->m_ButtonShape.setFillColor(sf::Color::White);
	this->m_ButtonShape.setOutlineColor(sf::Color::Black);
	this->m_ButtonShape.setOutlineThickness(1.0f);
}

cColorBox::~cColorBox() {

}

void cColorBox::Select() {} // Removes Select() Functionality

void cColorBox::Unselect() {} // Removes Unselect() Functionality
