#pragma once
#include "cToolManager.h"

class cButtonCircle {
private:
	cToolManager* m_ToolManager;

public:
	sf::CircleShape m_ButtonShape;

	cButtonCircle(cToolManager* _toolManager, sf::Vector2f _pos, sf::Color _color);
	~cButtonCircle();

	void UseButton();
};
