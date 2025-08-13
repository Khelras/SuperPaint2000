#pragma once
#include "cRectangle.h"
#include "cEllipse.h"
#include "cLine.h"
#include "cPolygon.h"
#include "cStamp.h"

enum Tools {
	TOOL_RECTANGLE,   // Rectangle Tool
	TOOL_ELLIPSE,     // Ellipse Tool
	TOOL_LINE,        // Line Tool
	TOOL_POLYGON,     // Polygon Tool
	TOOL_STAMP        // Stamp Tool
};

class cToolManager {
private:
	sf::RenderWindow* m_Window;
	cCanvas* m_Canvas;
	Tools m_SelectedTool;
	sf::Color m_ToolFillColour;
	sf::Color m_ToolOutlineColor;
	float m_ToolOutlineThickness;
	float m_ToolScaleFactor; // Only for Supported Tools (Such as Stamp and Brush... Except theres no Brush Tool)

	// Tools
	cRectangle* m_ToolRectangle;
	cEllipse* m_ToolEllipse;
	cLine* m_ToolLine;
	cPolygon* m_ToolPolygon;
	cStamp* m_ToolStamp;

public:
	cToolManager(sf::RenderWindow* _window);
	~cToolManager();
	
	// Getters
	cCanvas* GetCanvas() const;
	cTool* GetSelectedTool() const;
	Tools GetSelectedToolEnum() const;
	sf::Color GetFillColor() const;
	sf::Color GetOutlineColor() const;
	float GetOutlineThickness() const;
	float GetScaleFactor() const;

	// Setters
	void SelectTool(Tools _newTool);
	void SetFillColor(sf::Color _color);
	void SetOutlineColor(sf::Color _color);
	void SetOutlineThickness(float _thickness);
	void SetScaleFactor(float _scale);
};

