#pragma once
#include "cTool.h"

// Inherits from cShape Class
class cRectangle : public cTool {
public:
	// Member Variables
	sf::RectangleShape m_Tool;

	// Constructor and Destructor
	cRectangle(float _length, float _width, sf::Color _color = sf::Color::White);
	~cRectangle();

	void SetColor(sf::Color _color) override; // Extended SetColor Function
};