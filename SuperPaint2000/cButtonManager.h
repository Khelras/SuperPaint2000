#pragma once
#include "cWindowManager.h"
#include "cButtonRectangle.h"
#include "cButtonCircle.h"

class cButtonManager {
private:
	cWindowManager* m_Window;
	cButtonRectangle* m_ButtonRectangle;
	cButtonCircle* m_ButtonCircle;

public:
	cButtonManager(cToolManager* _toolManager, cWindowManager* _window);
	~cButtonManager();

	void DrawButtons();
	void ClickButtons(sf::Vector2i _mousePos);
};

