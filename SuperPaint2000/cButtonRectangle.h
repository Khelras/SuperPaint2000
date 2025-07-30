#pragma once
#include "cToolManager.h"

class cButtonRectangle {
private:
	cToolManager* m_ToolManager;

public:
	sf::RectangleShape m_ButtonShape;

	cButtonRectangle(cToolManager* _toolManager, sf::Vector2f _pos, sf::Color _color);
	~cButtonRectangle();

	void UseButton();
};

