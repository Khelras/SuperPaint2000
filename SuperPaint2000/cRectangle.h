#pragma once
#include "cTool.h"

// Inherits from cTool Class
class cRectangle : public cTool {
private:
	sf::Vector2f m_Origin;
	sf::RectangleShape m_Tool;

public:
	cRectangle(sf::RenderWindow* _window, cCanvas* _canvas);
	~cRectangle();

	void SetFillColor(sf::Color _color) override; // Extended SetFillColor Function
	void SetOutlineColor(sf::Color _color) override; // Extended SetOutlineColor Function
	void SetOutlineThickness(float _thickness) override;  // Extended SetOutlineThickness Function
	void UseToolOnce() override; // Starts the Draw Process
	void UseToolRealtime() override; // The Draw Process
	void UseToolEnd() override; // Completes the Draw Process
	void Draw() override;
};