#include "cColorBoxBG.h"

cColorBoxBG::cColorBoxBG(cWindowManager* _window, cToolManager* _toolManager, sf::Vector2f _size) 
	: cColorBox(_window, _toolManager, _size) {
	this->m_ButtonShape.setFillColor(sf::Color::Green);
	this->m_Button.setOrigin(this->m_Button.getGlobalBounds().getCenter());
}

cColorBoxBG::~cColorBoxBG() {
}

void cColorBoxBG::OpenColorPicker() {
	// First checks to see if the OTHER Color Picker Window is already open
	if (this->m_Window->m_ColorPickerFGWindow.isOpen() == true) {
		// Close it...
		this->m_Window->m_ColorPickerFGWindow.close();
	}

	// Then checks to see if Color Picker BG Window is already open
	if (this->m_Window->m_ColorPickerFGWindow.isOpen() == false) {
		this->m_Window->OpenWindow(Windows::WINDOW_COLOR_BG);
	}
}

void cColorBoxBG::CloseColorPicker() {
	// First checks to see if the Window is already open
	if (this->m_Window->m_ColorPickerFGWindow.isOpen() == true) {
		this->m_Window->m_ColorPickerFGWindow.close();
	}
}

void cColorBoxBG::UseButton() {
	printf("Colour Picker Background Button Pressed!\n"); // FOR DEBUGGING
	this->OpenColorPicker();
}

void cColorBoxBG::DrawButton(cWindowManager* _window, float _posY)
{
	// Sets Button Shape Positioning
	float fToolWinCenter = _window->m_ToolWindow.getSize().x / 2;
	float fOffset = (this->m_Button.getSize().x / 2) + 2.0f;
	float fPosX = fToolWinCenter - fOffset;
	float fPosY = _posY + ((this->m_Button.getSize().y / 2) - 2.0f);
	this->m_ButtonShape.setPosition(sf::Vector2f(fPosX, fPosY));

	// Sets Button Positioning
	float fX = this->m_ButtonShape.getPosition().x + (this->m_ButtonShape.getSize().x / 2);
	float fY = this->m_ButtonShape.getPosition().y + (this->m_ButtonShape.getSize().y / 2);
	this->m_Button.setPosition(sf::Vector2f(fX, fY));

	// Draws the Buttons
	_window->m_ToolWindow.draw(this->m_Button);
	_window->m_ToolWindow.draw(this->m_ButtonShape);
}