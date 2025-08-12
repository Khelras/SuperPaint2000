#pragma once
#include "cFileInterface.h"

class cButtonSaveFile : public cFileInterface {
public:
	cButtonSaveFile(cToolManager* _toolManager, sf::Vector2f _size);
	~cButtonSaveFile();

	// Overridden Functions
	void UseButton() override;
};

