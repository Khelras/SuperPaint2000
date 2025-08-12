#pragma once
#include "cWindowManager.h"
#include "cToolManager.h"

class cButton {
private:
	bool m_IsSelected;

public:
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

