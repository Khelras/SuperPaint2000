#include "cButtonRectangle.h"

cButtonRectangle::cButtonRectangle(cToolManager* _toolManager, sf::Vector2f _pos, sf::Color _color) {
	this->m_ToolManager = _toolManager;
	this->m_ButtonShape.setPosition(_pos);
	this->m_ButtonShape.setSize(sf::Vector2f(60, 40));
	this->m_ButtonShape.setFillColor(_color);
}

cButtonRectangle::~cButtonRectangle() {
	delete(this->m_ToolManager);
}

void cButtonRectangle::UseButton() {
	printf("Rectangle Button Pressed!\n");
	this->m_ToolManager->SelectTool(Tools::TOOL_RECTANGLE);
}
