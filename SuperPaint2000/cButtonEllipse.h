#pragma once
#include "cToolManager.h"
#include "cButton.h"

class cButtonEllipse : public cButton {
private:
	cToolManager* m_ToolManager;
	sf::CircleShape m_ButtonShape;

public:
	cButtonEllipse(cToolManager* _toolManager, sf::Vector2f _size);
	~cButtonEllipse();

	// Overridden Functions
	void UseButton() override;
	void DrawButton(cWindowManager* _window, float _posY) override;
};
