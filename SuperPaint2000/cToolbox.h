#pragma once
#include <SFML/Graphics.hpp>

enum Tools {
	TOOL_RECTANGLE,   // Rectangle Tool
	TOOL_CIRCLE,      // Circle Tool
	TOOL_LINE,        // Line Tool
	TOOL_PENCIL,      // Pencil Tool
	TOOL_ERASER,      // Eraser Tool
	TOOL_EYEDROP      // Eyedrop Tool
};

class cToolbox {
private:
	Tools m_SelectedTool;
	sf::Color m_ToolColour;

public:
	cToolbox();
	~cToolbox();

	void SelectTool(Tools _newTool);
	Tools GetSelectedTool() const;
	void UseTool();
};

