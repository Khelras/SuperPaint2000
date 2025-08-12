#include "cButtonSaveFile.h"

cButtonSaveFile::cButtonSaveFile(cToolManager* _toolManager, sf::Vector2f _size) : cFileInterface(_toolManager, _size, "Save") {
	this->m_CanSelect = false;
}

cButtonSaveFile::~cButtonSaveFile() {

}

void cButtonSaveFile::UseButton() {
	this->SaveFile(this->m_ToolManager->GetCanvas()->GetCanvasTexture());
}
