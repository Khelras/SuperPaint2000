#pragma once
#include "cButtonManager.h"

class cEventManager {
private:
	cWindowManager* m_Window;
	cToolManager* m_ToolManager;
	cButtonManager* m_ButtonManager;

	void ProcessEventMain(const std::optional<sf::Event> _event);
	void ProcessEventTool(const std::optional<sf::Event> _event);
	void ProcessRealtime();

public:
	cEventManager(cWindowManager* _window);
	~cEventManager();

	void Process();
};

