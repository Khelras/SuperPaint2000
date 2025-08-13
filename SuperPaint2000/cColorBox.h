#pragma once
#include "cButton.h"

class cColorBox : public cButton {
protected:
	cWindowManager* m_Window;
	cToolManager* m_ToolManager;

	cColorBox(cWindowManager* _window, cToolManager* _toolManager, sf::Vector2f _size);
	~cColorBox();

	// Abstract Functions
	virtual void OpenColorPicker() = 0; // Opens Color Picker Window
	virtual void CloseColorPicker() = 0; // Closes Color Picker Window

public:
	sf::RectangleShape m_ButtonShape;

	// Overridden Functions
	void Select() override; // Removes Select() Functionality
	void Unselect() override; // Removes Unselect() Functionality
};

