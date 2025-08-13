#pragma once
#include "cButton.h"

class cButtonCancel : public cButton {
private:
	cWindowManager* m_Window;
	sf::Font m_Font;
	sf::Text* m_Text;

public:
	cButtonCancel(cWindowManager* _window, sf::Vector2f _size);
	~cButtonCancel();

	void DrawButton(sf::Vector2f _pos);

	// Overridden Functions
	void UseButton() override;
	void Select() override; // Removes Select() Functionality
	void Unselect() override; // Removes Unselect() Functionality
};

