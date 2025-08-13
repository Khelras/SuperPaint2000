#pragma once
#include "cButtonManager.h"
#include "cColorPickerManager.h"

class cEventManager {
private:
	cWindowManager* m_Window;
	sf::Vector2i m_MainWindowPosition;
	sf::Vector2i m_ToolWindowPosition;
	cToolManager* m_ToolManager;
	cButtonManager* m_ButtonManager;
	cColorPickerManager* m_ColorPickerManager;
	sf::RenderWindow* m_ColorPickerWindow;

	void ProcessEventMain(const std::optional<sf::Event> _event);
	void ProcessEventTool(const std::optional<sf::Event> _event);
	void ProcessEventColorPicker(const std::optional<sf::Event> _event);
	void ProcessRealtime();

public:
	cEventManager(cWindowManager* _window);
	~cEventManager();

	void Process();
};

