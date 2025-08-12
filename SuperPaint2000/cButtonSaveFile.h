#pragma once
#include "cFileInterface.h"

class cButtonSaveFile : public cFileInterface {
public:
	cButtonSaveFile(cToolManager* _toolManager, sf::Vector2f _size);
	~cButtonSaveFile();

	// Overridden Functions
	void Select() override; // Removes Select() Functionality
	void Unselect() override; // Removes Unselect() Functionality
	void UseButton() override;
	void DrawButton(cWindowManager* _window, float _posY) override;
};

