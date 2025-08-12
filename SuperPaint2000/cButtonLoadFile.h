#pragma once
#include "cFileInterface.h"

class cButtonLoadFile : public cFileInterface {
private:
	cWindowManager* m_Window;

public:
	cButtonLoadFile(cWindowManager* _window, cToolManager* _toolManager, sf::Vector2f _size);
	~cButtonLoadFile();

	// Overridden Functions
	void Select() override; // Removes Select() Functionality
	void Unselect() override; // Removes Unselect() Functionality
	void UseButton() override;
	void DrawButton(cWindowManager* _window, float _posY) override;
};

