#pragma once
#include "cRectangle.h"
#include "cEllipse.h"
#include "cLine.h"

enum Tools {
	TOOL_RECTANGLE,   // Rectangle Tool
	TOOL_ELLIPSE,     // Ellipse Tool
	TOOL_LINE         // Line Tool
};

class cToolManager {
private:
	sf::RenderWindow* m_Window;
	cCanvas* m_Canvas;
	Tools m_SelectedTool;
	sf::Color m_ToolFillColour;
	sf::Color m_ToolOutlineColor;
	float m_ToolOutlineThickness;

	// Tools
	cRectangle* m_ToolRectangle;
	cEllipse* m_ToolEllipse;
	cLine* m_ToolLine;

public:
	cToolManager(sf::RenderWindow* _window);
	~cToolManager();

	void SelectTool(Tools _newTool);
	cTool* GetSelectedTool() const;
	void SetFillColor(sf::Color _color);
	void SetOutlineColor(sf::Color _color);
	void SetOutlineThickness(float _thickness);
	float GetOutlineThickness() const;
};

