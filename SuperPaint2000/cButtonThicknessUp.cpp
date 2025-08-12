#include "cButtonThicknessUp.h"

cButtonThicknessUp::cButtonThicknessUp(cToolManager* _toolManager, sf::Vector2f _size) : cButton(_size) {
	this->m_ToolManager = _toolManager;
	this->m_ButtonShape.setRadius(15.0f);
	this->m_ButtonShape.setFillColor(sf::Color::Black);
	this->m_ButtonShape.setPointCount(3);
	this->m_ButtonShape.setOrigin(this->m_ButtonShape.getGlobalBounds().getCenter());
}

cButtonThicknessUp::~cButtonThicknessUp() {

}

void cButtonThicknessUp::UseButton() {
	// Increases Thickness by 1px
	this->m_ToolManager->SetOutlineThickness(this->m_ToolManager->GetOutlineThickness() + 1.0f);
}

void cButtonThicknessUp::Select() {} // Removes Select() Functionality

void cButtonThicknessUp::Unselect() {} // Removes Unselect() Functionality

void cButtonThicknessUp::DrawButton(cWindowManager* _window, float _posY) {
	// Calls DrawFunction Function from cButton Parent Class
	cButton::DrawButton(_window, _posY);

	// Extend Functionality
	// Draws the Contents of the Button
	// Draws Button Contents to the Center Position of Button Bounds
	float fCenterBoundsX = this->m_Button.getPosition().x + (this->m_Button.getSize().x / 2);
	float fCenterBoundsY = this->m_Button.getPosition().y + (this->m_Button.getSize().y / 2);
	this->m_ButtonShape.setPosition(sf::Vector2f(fCenterBoundsX, fCenterBoundsY));

	_window->m_ToolWindow.draw(this->m_ButtonShape);
}
