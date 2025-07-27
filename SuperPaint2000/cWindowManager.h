#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "cRectangle.h"

class cWindowManager : public sf::RenderWindow {
public:
	cWindowManager(std::string _name = "Super Paint 2000!");
	~cWindowManager();

	bool Process();
};