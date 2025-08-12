#include "cButtonSaveFile.h"

cButtonSaveFile::cButtonSaveFile(cToolManager* _toolManager, sf::Vector2f _size) : cFileInterface(_toolManager, _size, "Save") {
	this->m_CanSelect = false;
}

cButtonSaveFile::~cButtonSaveFile() {

}

void cButtonSaveFile::Select() {} // Removes Select() Functionality

void cButtonSaveFile::Unselect() {} // Removes Unselect() Functionality

void cButtonSaveFile::UseButton() {
	this->SaveFile(this->m_ToolManager->GetCanvas()->GetCanvasTexture());
}

void cButtonSaveFile::DrawButton(cWindowManager* _window, float _posY) {
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