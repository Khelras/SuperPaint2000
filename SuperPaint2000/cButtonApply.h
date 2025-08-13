#pragma once
#include "cButton.h"

class cButtonApply : public cButton {
private:
	cWindowManager* m_Window;
	cToolManager* m_ToolManager;
	sf::Font m_Font;
	sf::Text* m_Text;

public:
	cButtonApply(cWindowManager* _window, cToolManager* _toolManager, sf::Vector2f _size);
	~cButtonApply();

	void DrawButton(sf::Vector2f _pos);

	// Overridden Functions
	void UseButton() override;
	void Select() override; // Removes Select() Functionality
	void Unselect() override; // Removes Unselect() Functionality
};

