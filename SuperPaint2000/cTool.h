#pragma once
#include "cCanvas.h"

class cTool {
private:
	sf::Color m_color;

public:
	sf::RenderWindow* m_Window;
	cCanvas* m_Canvas;

	cTool(sf::RenderWindow* _window, cCanvas* _canvas);
	~cTool();

	// Normal Functions
	sf::Color GetColor() const;

	// Abstract Functions
	virtual void SetColor(sf::Color _color);
	virtual void UseTool(bool _isRealtime, bool _isEnd);
	virtual void UseToolOnce() = 0;
	virtual void UseToolRealtime() = 0;
	virtual void UseToolEnd() = 0;
	virtual void Draw() = 0;
};