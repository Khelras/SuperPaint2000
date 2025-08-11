#pragma once
#include "cButtonRectangle.h"
#include "cButtonEllipse.h"

class cButtonManager {
private:
	cWindowManager* m_Window;
	cToolManager* m_ToolManager;
	cButtonRectangle* m_ButtonRectangle;
	cButtonEllipse* m_ButtonEllipse;

public:
	cButtonManager(cToolManager* _toolManager, cWindowManager* _window);
	~cButtonManager();

	void DrawButtons();
	bool HasButton(sf::Vector2i _mousePos);
	cButton* GetButton(sf::Vector2i _mousePos);
	void RemoveHovers();
	void UnselectButtons();
	void HoverButton(sf::Vector2i _mousePos);
	void ClickButton(sf::Vector2i _mousePos);
	
};

