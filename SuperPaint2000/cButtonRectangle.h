#pragma once
#include "cToolManager.h"
#include "cButton.h"

class cButtonRectangle : public cButton {
private:
	cToolManager* m_ToolManager;
	sf::RectangleShape m_ButtonShape;

public:
	cButtonRectangle(cToolManager* _toolManager, sf::Vector2f _size);
	~cButtonRectangle();

	// Overridden Functions
	void UseButton() override;
	void DrawButton(cWindowManager* _window, float _posY) override;
};

