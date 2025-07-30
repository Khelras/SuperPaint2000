#pragma once
#include <SFML/Graphics.hpp>

class cButton {
public:
	sf::RectangleShape m_ButtonShape;

	cButton(sf::Vector2f _pos, sf::Color _color);
	~cButton();

	void UseButton();
};

