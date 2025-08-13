#pragma once
#include "cColorBox.h"

class cColorBoxFG : public cColorBox {
public:
	cColorBoxFG(cWindowManager* _window, cToolManager* _toolManager, sf::Vector2f _size);
	~cColorBoxFG();

	// Overridden Functions
	void OpenColorPicker() override;
	void CloseColorPicker() override;
	void UseButton() override;
	void DrawButton(cWindowManager* _window, float _posY) override;
};

