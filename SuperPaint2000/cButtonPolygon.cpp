#include "cButtonPolygon.h"

cButtonPolygon::cButtonPolygon(cToolManager* _toolManager, sf::Vector2f _size) : cButton(_size) {
	this->m_CanSelect = true;
	this->m_ToolManager = _toolManager;
	this->m_ButtonShape.setRadius(15.0f);
	this->m_ButtonShape.setPointCount(5);
	this->m_ButtonShape.setFillColor(sf::Color::Transparent);
	this->m_ButtonShape.setOutlineColor(sf::Color::Black);
	this->m_ButtonShape.setOutlineThickness(2.0f);
	this->m_ButtonShape.setOrigin(this->m_ButtonShape.getGlobalBounds().getCenter());
}

cButtonPolygon::~cButtonPolygon() {
	
}

void cButtonPolygon::UseButton() {
	printf("Polygon Button Pressed!\n"); // FOR DEBUGGING
	this->m_ToolManager->SelectTool(Tools::TOOL_POLYGON);
}

void cButtonPolygon::DrawButton(cWindowManager* _window, float _posY)
{
	// Calls DrawFunction Function from cButton Parent Class
	cButton::DrawButton(_window, _posY);

	// Extend Functionality
	// Draws the Contents of the Button
	float fCenterBoundsX = this->m_Button.getPosition().x + (this->m_Button.getSize().x / 2);
	float fCenterBoundsY = this->m_Button.getPosition().y + (this->m_Button.getSize().y / 2);
	this->m_ButtonShape.setPosition(sf::Vector2f(fCenterBoundsX, fCenterBoundsY));

	_window->m_ToolWindow.draw(this->m_ButtonShape);
}
