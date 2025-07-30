#pragma once
#include "cRectangle.h"
#include "cCircle.h"

enum Tools {
	TOOL_RECTANGLE,   // Rectangle Tool
	TOOL_CIRCLE,      // Circle Tool
	TOOL_LINE,        // Line Tool
	TOOL_PENCIL,      // Pencil Tool
	TOOL_ERASER,      // Eraser Tool
	TOOL_EYEDROP      // Eyedrop Tool
};

class cToolManager {
private:
	sf::RenderWindow* m_Window;
	cCanvas* m_Canvas;
	Tools m_SelectedTool;
	sf::Color m_ToolColour;

	// Tools
	cRectangle* m_ToolRectangle;
	cCircle* m_ToolCircle;

public:
	cToolManager(sf::RenderWindow* _window);
	~cToolManager();

	void SelectTool(Tools _newTool);
	Tools GetSelectedTool() const;
	void UseTool(bool _isRealtime = false, bool _isEnd = false);
	void Draw();
};

