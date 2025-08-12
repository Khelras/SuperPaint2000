#include "cButtonStamp.h"

cButtonStamp::cButtonStamp(cToolManager* _toolManager, sf::Vector2f _size) : cFileInterface(_toolManager, _size) {
	this->m_CanSelect = true;
	this->m_ButtonShape.setSize(sf::Vector2f(30.0f, 20.0f));
	this->m_ButtonShape.setFillColor(sf::Color::Black);
	this->m_ButtonShape.setOutlineColor(sf::Color::Black);
	this->m_ButtonShape.setOutlineThickness(2.0f);
	this->m_ButtonShape.setOrigin(this->m_ButtonShape.getGlobalBounds().getCenter());
}

cButtonStamp::~cButtonStamp() {

}

void cButtonStamp::UseButton() {
    printf("Stamp Button Pressed!\n"); // FOR DEBUGGING
    this->m_ToolManager->SelectTool(Tools::TOOL_STAMP);
    this->m_ToolManager->GetSelectedTool()->ImportImage(this->LoadFile());
}

void cButtonStamp::DrawButton(cWindowManager* _window, float _posY) {
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