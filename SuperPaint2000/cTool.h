#pragma once
#include "cCanvas.h"

class cTool {
protected:
	sf::Color m_FillColor;
	sf::Color m_OutlineColor;
	float m_Thickness;

public:
	sf::RenderWindow* m_Window;
	cCanvas* m_Canvas;

	cTool(sf::RenderWindow* _window, cCanvas* _canvas);
	~cTool();

	// Abstract Functions
	virtual void SetFillColor(sf::Color _color);
	virtual void SetOutlineColor(sf::Color _color);
	virtual void SetOutlineThickness(float _thickness);
	virtual void UseToolOnce() = 0; // Starts the Draw Process
	virtual void UseToolRealtime() = 0; // The Draw Process (in Realtime)
	virtual void UseToolEnd() = 0; // Completes the Draw Process
	virtual void Draw() = 0;
};