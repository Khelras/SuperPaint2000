#pragma once
#include "cToolManager.h"

class cButtonEllipse {
private:
	cToolManager* m_ToolManager;

public:
	sf::CircleShape m_ButtonShape;

	cButtonEllipse(cToolManager* _toolManager, sf::Vector2f _pos, sf::Color _color);
	~cButtonEllipse();

	void UseButton();
};
