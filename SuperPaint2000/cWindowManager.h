#pragma once
#include <string>
#include "cCanvas.h"

class cWindowManager : public sf::RenderWindow {
private:
	sf::Vector2u m_ToolWindowSize;

public:
	sf::RenderWindow m_ToolWindow;

	cWindowManager(sf::VideoMode _mode, std::string _name);
	~cWindowManager();

	void Process();
	void AutoMoveToolWindow();
	void ResizeViewToWindow();
	void PreventResizeToolWindow();
	void ImportImage(sf::Texture _importedImageTexture, cCanvas* _canvas);
};