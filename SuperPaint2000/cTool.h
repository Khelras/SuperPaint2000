#pragma once
#include <SFML/Graphics.hpp>

class cTool {
private:
	sf::Color m_color;

public:
	// Normal Functions
	sf::Color GetColor() const {
		return m_color;
	}

	// Abstract Functions
	virtual void SetColor(sf::Color _color) {
		this->m_color = _color;
	}
};