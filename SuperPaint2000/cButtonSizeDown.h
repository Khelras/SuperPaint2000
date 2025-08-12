#pragma once
#include "cButton.h"

class cButtonSizeDown : public cButton {
private:
	cToolManager* m_ToolManager;
	sf::CircleShape m_ButtonShape;

public:
	cButtonSizeDown(cToolManager* _toolManager, sf::Vector2f _size);
	~cButtonSizeDown();

	// Overridden Functions
	void UseButton() override;
	void Select() override; // Removes Select() Functionality
	void Unselect() override; // Removes Unselect() Functionality
	void DrawButton(cWindowManager* _window, float _posY) override;
};


