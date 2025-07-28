#pragma once
#include "cTool.h"

// Inherits from cShape Class
class cRectangle : public cTool {
private:
	sf::Vector2f m_Origin;
	sf::RectangleShape m_Tool;

public:
	cRectangle(sf::RenderWindow* _window, cCanvas* _canvas, float _length, float _width, sf::Color _color = sf::Color::White);
	~cRectangle();

	void SetColor(sf::Color _color) override; // Extended SetColor Function
	void UseToolOnce() override;
	void UseToolRealtime() override;
	void UseToolEnd() override;
	void Draw() override;
};