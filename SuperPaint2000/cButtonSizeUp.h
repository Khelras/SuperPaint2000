#pragma once
#include "cButton.h"

class cButtonSizeUp : public cButton {
private:
	cToolManager* m_ToolManager;
	sf::CircleShape m_ButtonShape;

public:
	cButtonSizeUp(cToolManager* _toolManager, sf::Vector2f _size);
	~cButtonSizeUp();

	// Overridden Functions
	void UseButton() override;
	void Select() override; // Removes Select() Functionality
	void Unselect() override; // Removes Unselect() Functionality
	void DrawButton(cWindowManager* _window, float _posY) override;
};

