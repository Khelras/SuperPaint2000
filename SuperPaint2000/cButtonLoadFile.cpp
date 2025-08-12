#include "cButtonLoadFile.h"

cButtonLoadFile::cButtonLoadFile(cWindowManager* _window, cToolManager* _toolManager, sf::Vector2f _size) 
	: cFileInterface(_toolManager, _size, "Load") {
	this->m_CanSelect = false;
	this->m_Window = _window;
}

cButtonLoadFile::~cButtonLoadFile() {

}

void cButtonLoadFile::Select() {} // Removes Select() Functionality

void cButtonLoadFile::Unselect() {} // Removes Unselect() Functionality

void cButtonLoadFile::UseButton() {
	this->LoadFile(this->m_Window, this->m_ToolManager->GetCanvas());
}

void cButtonLoadFile::DrawButton(cWindowManager* _window, float _posY) {
    // Calls DrawFunction Function from cButton Parent Class
    cButton::DrawButton(_window, _posY);

    // Extend Functionality
    // Draws the Contents of the Button
    // Draws Button Contents to the Center Position of Button Bounds
    float fCenterBoundsX = this->m_Button.getPosition().x + (this->m_Button.getSize().x / 2);
    float fCenterBoundsY = this->m_Button.getPosition().y + (this->m_Button.getSize().y / 2);
    this->m_Text->setPosition(sf::Vector2f(fCenterBoundsX, fCenterBoundsY));

    _window->m_ToolWindow.draw(*(this->m_Text));
}