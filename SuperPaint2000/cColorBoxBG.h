#pragma once
#include "cColorBox.h"

class cColorBoxBG : public cColorBox {
public:
	cColorBoxBG(cWindowManager* _window, cToolManager* _toolManager, sf::Vector2f _size);
	~cColorBoxBG();

	// Overridden Functions
	void OpenColorPicker() override;
	void CloseColorPicker() override;
	void UseButton() override;
	void DrawButton(cWindowManager* _window, float _posY) override;
};

