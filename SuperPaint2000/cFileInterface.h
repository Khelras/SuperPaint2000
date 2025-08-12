#pragma once
#include <Windows.h>
#include <ShObjIdl.h>
#include "cButton.h"

class cFileInterface : public cButton {
protected:
	cToolManager* m_ToolManager;
	sf::Font m_Font;
	sf::Text* m_Text;
	sf::Texture* m_ImportedImageTexture;

	cFileInterface(cToolManager* _toolManager, sf::Vector2f _size);
	cFileInterface(cToolManager* _toolManager, sf::Vector2f _size, std::string _text);
	~cFileInterface();

	sf::Texture* LoadFile(); // ONLY Loads File
	void LoadFile(cWindowManager* _window, cCanvas* _canvas); // Loads File AND Display it onto Canvas
	void SaveFile(sf::RenderTexture* _canvasTexture);
};

