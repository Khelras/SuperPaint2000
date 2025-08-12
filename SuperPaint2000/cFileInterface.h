#pragma once
#include <Windows.h>
#include <ShObjIdl.h>
#include "cButton.h"

class cFileInterface : public cButton {
protected:
	cToolManager* m_ToolManager;
	sf::Font m_Font;
	sf::Text* m_Text;

	cFileInterface(cToolManager* _toolManager, sf::Vector2f _size, std::string _text);
	~cFileInterface();

	void LoadFile(cWindowManager* _window, cCanvas* _canvas);
	void SaveFile(sf::RenderTexture* _canvasTexture);
	
public:
	// Overridden Functions
	void Select() override; // Removes Select() Functionality
	void Unselect() override; // Removes Unselect() Functionality
	void DrawButton(cWindowManager* _window, float _posY) override;
};

