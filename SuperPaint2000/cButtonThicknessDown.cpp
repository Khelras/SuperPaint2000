#include "cButtonThicknessDown.h"

cButtonThicknessDown::cButtonThicknessDown(cToolManager* _toolManager, sf::Vector2f _size) : cButton(_size) {
	this->m_ToolManager = _toolManager;
	this->m_ButtonShape.setRadius(15.0f);
	this->m_ButtonShape.setFillColor(sf::Color::Black);
	this->m_ButtonShape.setPointCount(3);
	this->m_ButtonShape.setOrigin(this->m_ButtonShape.getGlobalBounds().getCenter());
	this->m_ButtonShape.setRotation(sf::degrees(180));
}

cButtonThicknessDown::~cButtonThicknessDown() {

}

void cButtonThicknessDown::UseButton() {
	// Decreases Thickness by 1pxc (Never going below 0)
	float fDecrease = this->m_ToolManager->GetOutlineThickness() - 1.0f;
	if (fDecrease >= 0) {
		this->m_ToolManager->SetOutlineThickness(fDecrease);
	}
}

void cButtonThicknessDown::Select() {} // Removes Select() Functionality

void cButtonThicknessDown::Unselect() {} // Removes Unselect() Functionality

void cButtonThicknessDown::DrawButton(cWindowManager* _window, float _posY) {
	// Calls DrawFunction Function from cButton Parent Class
	cButton::DrawButton(_window, _posY);

	// Extend Functionality
	// Draws the Contents of the Button
	float fCenterBoundsX = this->m_Button.getPosition().x + (this->m_Button.getSize().x / 2);
	float fCenterBoundsY = this->m_Button.getPosition().y + (this->m_Button.getSize().y / 2);
	this->m_ButtonShape.setPosition(sf::Vector2f(fCenterBoundsX, fCenterBoundsY));

	_window->m_ToolWindow.draw(this->m_ButtonShape);
}