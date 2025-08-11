#pragma once
#include "cToolManager.h"
#include "cButton.h"

class cButtonThicknessUp : public cButton {
private:
	cToolManager* m_ToolManager;
	sf::CircleShape m_ButtonShape;

public:
	cButtonThicknessUp(cToolManager* _toolManager, sf::Vector2f _size);
	~cButtonThicknessUp();

	// Overridden Functions
	void UseButton() override;
	void Select() override; // Removes Select() Functionality
	void Unselect() override; // Removes Unselect() Functionality
	void DrawButton(cWindowManager* _window, float _posY) override;
};

