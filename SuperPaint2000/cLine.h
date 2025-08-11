#pragma once
#include "cTool.h"

// Inherits from cTool Class
class cLine : public cTool {
private:
	sf::Vector2f m_Origin;
	sf::RectangleShape m_Tool;

public:
	cLine(sf::RenderWindow* _window, cCanvas* _canvas);
	~cLine();
	
	void SetOutlineColor(sf::Color _color) override; // Extended SetOutlineColor Function
	void SetOutlineThickness(float _thickness) override;  // Extended SetOutlineThickness Function
	void UseToolOnce() override; // Starts the Draw Process
	void UseToolRealtime() override; // The Draw Process
	void UseToolEnd() override; // Completes the Draw Process
	void Draw() override;
};

