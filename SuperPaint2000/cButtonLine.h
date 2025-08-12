#pragma once
#include "cButton.h"

class cButtonLine : public cButton {
private:
	cToolManager* m_ToolManager;
	sf::RectangleShape m_ButtonShape;

public:
	cButtonLine(cToolManager* _toolManager, sf::Vector2f _size);
	~cButtonLine();

	// Overridden Functions
	void UseButton() override;
	void DrawButton(cWindowManager* _window, float _posY) override;
};

