#pragma once
#include <SFML/Graphics.hpp>

enum ActiveTool {
	Tool_Rectangle
};

class Toolbox {
public:
	ActiveTool m_ActiveTool;
	sf::Color m_ToolColour;

	Toolbox();
	~Toolbox();

	void Swap();
	void Draw();
};

