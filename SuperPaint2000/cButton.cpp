#include "cButton.h"

cButton::cButton(sf::Vector2f _size) {
	this->m_IsSelected = false;
	this->m_CanSelect = true;

	// Button
	this->m_Button.setSize(_size);
	this->m_Button.setFillColor(sf::Color::Transparent);
	this->m_Button.setOutlineColor(sf::Color::Transparent);
	this->m_Button.setOutlineThickness(-2.0f);
}

cButton::~cButton() {
	
}

void cButton::Hover() {
	// Don't Change Button Properties on Selected Button
	if (m_IsSelected == false) {
		// Sets box fill color to White when mouse is hovering
		this->m_Button.setFillColor(sf::Color(255, 255, 255, 150)); // Slightly Opaque White
	}
}

void cButton::RemoveHover() {
	// Don't Change Button Properties on Selected Button
	if (m_IsSelected == false) {
		// Sets box fill color to Transparent when mouse leaves
		this->m_Button.setFillColor(sf::Color::Transparent);
	}
}

void cButton::Select() {
	this->m_IsSelected = true;

	// Highlights the Selected Button
	this->m_Button.setFillColor(sf::Color(255, 255, 255, 150)); // Slightly Opaque White
	this->m_Button.setOutlineColor(sf::Color(255, 95, 5, 255)); // Orange
}

void cButton::Unselect() {
	this->m_IsSelected = false;

	// Removes highlights from Button
	this->m_Button.setFillColor(sf::Color::Transparent);
	this->m_Button.setOutlineColor(sf::Color::Transparent);
}

void cButton::DrawButton(cWindowManager* _window, float _posY) {
	// Gets Center of Tool Window + Center Offset and Sets Button Positioning
	float fToolWinCenter = _window->m_ToolWindow.getSize().x / 2;
	float fOffset = this->m_Button.getSize().x / 2;
	float fPosX = fToolWinCenter - fOffset;
	this->m_Button.setPosition(sf::Vector2f(fPosX, _posY));

	// Draws the Button
	_window->m_ToolWindow.draw(this->m_Button);
}
