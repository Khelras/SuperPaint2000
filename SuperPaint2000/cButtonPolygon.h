#pragma once
#include "cButton.h"

class cButtonPolygon : public cButton {
private:
	cToolManager* m_ToolManager;
	sf::CircleShape m_ButtonShape;

public:
	cButtonPolygon(cToolManager* _toolManager, sf::Vector2f _size);
	~cButtonPolygon();

	// Overridden Functions
	void UseButton() override;
	void DrawButton(cWindowManager* _window, float _posY) override;
};

