#pragma once
#include "cToolManager.h"
#include "cButton.h"

class cEventManager {
private:
	sf::RenderWindow* m_Window;
	cToolManager* m_ToolManager;
	cButton* m_Button;

	void ProcessEvent(const std::optional<sf::Event> _event);
	void ProcessRealtime();

public:
	cEventManager(sf::RenderWindow* _window);
	~cEventManager();

	void Process();
};

