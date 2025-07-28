#pragma once
#include "cToolManager.h"

class cEventManager {
private:
	sf::RenderWindow* m_Window;
	cToolManager* m_ToolManager;

	void ProcessEvent(const std::optional<sf::Event> _event);
	void ProcessRealtime();

public:
	cEventManager(sf::RenderWindow* _window);
	~cEventManager();

	void Process();
};

