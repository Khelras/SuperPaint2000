#include "cButtonRectangle.h"

cButtonRectangle::cButtonRectangle(cToolManager* _toolManager, sf::Vector2f _size) : cButton(_size) {
	this->m_ToolManager = _toolManager;
	this->m_ButtonShape.setSize(sf::Vector2f(30, 20));
	this->m_ButtonShape.setFillColor(sf::Color::Transparent);
	this->m_ButtonShape.setOutlineColor(sf::Color::Black);
	this->m_ButtonShape.setOutlineThickness(2.0f);
}

cButtonRectangle::~cButtonRectangle() {
	delete(this->m_ToolManager);
}

void cButtonRectangle::UseButton() {
	printf("Rectangle Button Pressed!\n"); // FOR DEBUGGING
	this->m_ToolManager->SelectTool(Tools::TOOL_RECTANGLE);
}

void cButtonRectangle::DrawButton(cWindowManager* _window, float _posY)
{
	// Calls DrawFunction Function from cButton Parent Class
	cButton::DrawButton(_window, _posY);

	// Extend Functionality
	// Draws the Contents of the Button
	// Draws Button Contents to the Center Position of Button Bounds
	float fCenterBoundsX = this->m_Button.getPosition().x + (this->m_Button.getSize().x / 2);
	float fCenterBoundsY = this->m_Button.getPosition().y + (this->m_Button.getSize().y / 2);
	float fOffsetX = this->m_ButtonShape.getSize().x / 2;
	float fOffsetY = this->m_ButtonShape.getSize().y / 2;
	this->m_ButtonShape.setPosition(sf::Vector2f(fCenterBoundsX - fOffsetX, fCenterBoundsY - fOffsetY));

	_window->m_ToolWindow.draw(this->m_ButtonShape);
}
