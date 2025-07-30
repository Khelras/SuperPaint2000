#pragma once
#include <string>
#include "SFML/Graphics.hpp"

class cWindowManager : public sf::RenderWindow {
public:
	sf::RenderWindow m_ToolWindow;

	cWindowManager(sf::VideoMode _mode, std::string _name);
	~cWindowManager();

	void Process();
};