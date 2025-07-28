#pragma once
#include <string>
#include "cEventManager.h"

class cWindow : public sf::RenderWindow {
private:
	cEventManager* m_EventManager;

public:
	cWindow(std::string _name = "Super Paint 2000!");
	~cWindow();

	void Process();
};