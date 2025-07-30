#pragma once
#include "cTool.h"

// Inherits from cShape Class
class cCircle : public cTool {
private:
	sf::Vector2f m_Origin;
	sf::CircleShape m_Tool;

public:
	cCircle(sf::RenderWindow* _window, cCanvas* _canvas, float _radius, sf::Color _color = sf::Color::White);
	~cCircle();

	void SetColor(sf::Color _color) override; // Extended SetColor Function
	void UseToolOnce() override;
	void UseToolRealtime() override;
	void UseToolEnd() override;
	void Draw() override;
};