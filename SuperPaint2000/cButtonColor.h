#pragma once
#include "cButton.h"

class cButtonColor {
private:
	cWindowManager* m_Window;

public:
	sf::CircleShape m_Button;
	sf::CircleShape m_ButtonShape;

	cButtonColor(cWindowManager* _window, float _radius);
	~cButtonColor();

	void Hover();
	void RemoveHover();
	void DrawButton(sf::Vector2f _pos);
};

