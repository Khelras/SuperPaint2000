#pragma once
#include "cFileInterface.h"

class cButtonLoadFile : public cFileInterface {
private:
	cWindowManager* m_Window;

public:
	cButtonLoadFile(cWindowManager* _window, cToolManager* _toolManager, sf::Vector2f _size);
	~cButtonLoadFile();

	// Overridden Functions
	void UseButton() override;
};

