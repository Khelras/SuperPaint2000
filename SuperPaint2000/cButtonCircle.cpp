#include "cButtonCircle.h"

cButtonCircle::cButtonCircle(cToolManager* _toolManager, sf::Vector2f _pos, sf::Color _color) {
	this->m_ToolManager = _toolManager;
	this->m_ButtonShape.setPosition(_pos);
	this->m_ButtonShape.setRadius(20);
	this->m_ButtonShape.setFillColor(_color);
}

cButtonCircle::~cButtonCircle() {
	delete(this->m_ToolManager);
}

void cButtonCircle::UseButton() {
	printf("Circle Button Pressed!\n");
	this->m_ToolManager->SelectTool(Tools::TOOL_CIRCLE);
}
