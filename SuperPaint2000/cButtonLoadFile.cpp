#include "cButtonLoadFile.h"

cButtonLoadFile::cButtonLoadFile(cWindowManager* _window, cToolManager* _toolManager, sf::Vector2f _size) 
	: cFileInterface(_toolManager, _size, "Load") {
	this->m_CanSelect = false;
	this->m_Window = _window;
}

cButtonLoadFile::~cButtonLoadFile() {

}

void cButtonLoadFile::UseButton() {
	this->LoadFile(this->m_Window, this->m_ToolManager->GetCanvas());
}
