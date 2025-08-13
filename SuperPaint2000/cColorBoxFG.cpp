#include "cColorBoxFG.h"

cColorBoxFG::cColorBoxFG(cWindowManager* _window, cToolManager* _toolManager, sf::Vector2f _size) 
	: cColorBox(_window, _toolManager, _size) {
	this->m_Button.setOrigin(this->m_Button.getGlobalBounds().getCenter());
}

cColorBoxFG::~cColorBoxFG() {
}

void cColorBoxFG::OpenColorPicker() {
	// First checks to see if the OTHER Color Picker Window is Open
	if (this->m_Window->m_ColorPickerBGWindow.isOpen() == true) {
		// Close it...
		this->m_Window->m_ColorPickerBGWindow.close();
	}

	// Then checks to see if Color Picker FG Window is already open
	if (this->m_Window->m_ColorPickerFGWindow.isOpen() == false) {
		this->m_Window->OpenWindow(Windows::WINDOW_COLOR_FG);
	}
}

void cColorBoxFG::CloseColorPicker() {
	// First checks to see if the Window is already open
	if (this->m_Window->m_ColorPickerFGWindow.isOpen() == true) {
		this->m_Window->m_ColorPickerFGWindow.close();
	}
}

void cColorBoxFG::UseButton() {
	printf("Colour Picker Foreground Button Pressed!\n"); // FOR DEBUGGING
	this->OpenColorPicker();
}

void cColorBoxFG::DrawButton(cWindowManager* _window, float _posY)
{
	// Sets Button Shape Position
	float fToolWinCenter = _window->m_ToolWindow.getSize().x / 2;
	float fPosX = fToolWinCenter - this->m_Button.getSize().x;
	this->m_ButtonShape.setPosition(sf::Vector2f(fPosX, _posY));

	// Sets Button Positioning
	float fX = this->m_ButtonShape.getPosition().x + (this->m_ButtonShape.getSize().x / 2);
	float fY = this->m_ButtonShape.getPosition().y + (this->m_ButtonShape.getSize().y / 2);
	this->m_Button.setPosition(sf::Vector2f(fX, fY));

	// Draws the Buttons
	_window->m_ToolWindow.draw(this->m_Button);
	_window->m_ToolWindow.draw(this->m_ButtonShape);
}