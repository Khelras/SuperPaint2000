#include "cButtonColor.h"

cButtonColor::cButtonColor(cWindowManager* _window, float _radius) {
    this->m_Window = _window;

	// Button
	this->m_Button.setRadius(_radius);
    this->m_Button.setFillColor(sf::Color::Transparent);
    this->m_Button.setOutlineColor(sf::Color::Transparent);
    this->m_Button.setOutlineThickness(-2.0f);
    this->m_Button.setOrigin(this->m_Button.getGlobalBounds().getCenter());
    
    // Button Shape 
    this->m_ButtonShape.setRadius(_radius - 5.0f);
    this->m_ButtonShape.setFillColor(sf::Color::White);
    this->m_ButtonShape.setOutlineColor(sf::Color::Black);
    this->m_ButtonShape.setOutlineThickness(-2.0f);
    this->m_ButtonShape.setOrigin(this->m_ButtonShape.getGlobalBounds().getCenter());
}

cButtonColor::~cButtonColor() {
}

void cButtonColor::Hover() {
	// Sets box fill color to White when mouse is hovering
	this->m_Button.setFillColor(sf::Color(255, 255, 255, 150)); // Slightly Opaque White
}

void cButtonColor::RemoveHover() {
	// Sets box fill color to Transparent when mouse leaves
	this->m_Button.setFillColor(sf::Color::Transparent);
}

void cButtonColor::DrawButton(sf::Vector2f _pos) {
    // Sets Position
    this->m_Button.setPosition(_pos);
    this->m_ButtonShape.setPosition(this->m_Button.getGlobalBounds().getCenter());

    // If Color Picker FG WIndow is Open
    if (this->m_Window->m_ColorPickerFGWindow.isOpen() == true) {
        // Draws Button
        this->m_Window->m_ColorPickerFGWindow.draw(this->m_Button);
        this->m_Window->m_ColorPickerFGWindow.draw(this->m_ButtonShape);
    }
    // If Color Picker BG WIndow is Open
    else if (this->m_Window->m_ColorPickerBGWindow.isOpen() == true) {
        // Draws Button
        this->m_Window->m_ColorPickerBGWindow.draw(this->m_Button);
        this->m_Window->m_ColorPickerBGWindow.draw(this->m_ButtonShape);
    }
}
