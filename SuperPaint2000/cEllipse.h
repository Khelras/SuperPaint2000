#pragma once
#include "cTool.h"

// Inherits from cTool Class
class cEllipse : public cTool {
private:
	sf::Vector2f m_Origin;
	sf::CircleShape m_Tool;

public:
	cEllipse(sf::RenderWindow* _window, cCanvas* _canvas);
	~cEllipse();

	void SetFillColor(sf::Color _color) override; // Extended SetFillColor Function
	void SetOutlineColor(sf::Color _color) override; // Extended SetOutlineColor Function
	void SetOutlineThickness(float _thickness) override;  // Extended SetOutlineThickness Function
	void UseToolOnce() override; // Starts the Draw Process
	void UseToolRealtime() override; // The Draw Process
	void UseToolEnd() override; // Completes the Draw Process
	void Draw() override;
};