#pragma once
#include "cWindowManager.h"
#include "cToolManager.h"

class cButton {
private:
	bool m_IsSelected;

public:
	bool m_CanSelect; // Allows for Selection Visuals when Button is Pressed
	sf::RectangleShape m_Button;

	cButton(sf::Vector2f _size);
	~cButton();
	
	virtual void UseButton() = 0;
	virtual void Hover();
	virtual void RemoveHover();
	virtual void Select();
	virtual void Unselect();
	virtual void DrawButton(cWindowManager* _window, float _posY);
};

