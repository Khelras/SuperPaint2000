#pragma once
#include "cFileInterface.h"

class cButtonStamp : public cFileInterface {
private:
	sf::RectangleShape m_ButtonShape;

public:
	cButtonStamp(cToolManager* _toolManager, sf::Vector2f _size);
	~cButtonStamp();

	// Overridden Functions
	void UseButton() override;
	void DrawButton(cWindowManager* _window, float _posY) override;
};

