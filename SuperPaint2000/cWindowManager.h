#pragma once
#include <string>
#include "cCanvas.h"
#include "cRectangle.h"

class cWindowManager : public sf::RenderWindow {
private:

public:
	cWindowManager(std::string _name = "Super Paint 2000!");
	~cWindowManager();

	void Process();
};