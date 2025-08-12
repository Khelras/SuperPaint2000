#pragma once
#include "cTool.h"

// Inherits from cTool Class
class cPolygon : public cTool {
private:
	sf::ConvexShape m_Tool;

public:
	cPolygon(sf::RenderWindow* _window, cCanvas* _canvas);
	~cPolygon();

	void SetFillColor(sf::Color _color) override; // Extended SetFillColor Function
	void SetOutlineColor(sf::Color _color) override; // Extended SetOutlineColor Function
	void SetOutlineThickness(float _thickness) override;  // Extended SetOutlineThickness Function
	void UseToolOnce() override; // Starts the Draw Process
	void UseToolRealtime() override; // The Draw Process
	void UseToolEnd() override; // Completes the Draw Process
	void Draw() override;
};

