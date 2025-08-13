#pragma once
#include <string>
#include "cCanvas.h"

enum Windows {
	WINDOW_TOOL,
	WINDOW_COLOR_FG,
	WINDOW_COLOR_BG
};

class cWindowManager : public sf::RenderWindow {
private:
	sf::Vector2u m_ToolWindowSize;
	sf::Vector2u m_ColorPickerWindowSize;

public:
	sf::RenderWindow m_ToolWindow;
	sf::RenderWindow m_ColorPickerFGWindow; // FG = Foreground
	sf::RenderWindow m_ColorPickerBGWindow; // BG = Background
	bool ShouldApplyColor;

	cWindowManager(sf::VideoMode _mode, std::string _name);
	~cWindowManager();

	void Process();
	void OpenWindow(Windows _windowType);
	void AutoMoveToolWindow();
	void ResizeViewToWindow();
	void PreventResizeToolWindow();
	void ImportImage(sf::Texture _importedImageTexture, cCanvas* _canvas);
	bool IsColorPickerOpen() const;
};