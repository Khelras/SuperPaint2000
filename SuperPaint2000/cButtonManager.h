#pragma once
#include "cButtonRectangle.h"
#include "cButtonEllipse.h"
#include "cButtonLine.h"
#include "cButtonPolygon.h"
#include "cButtonStamp.h"
#include "cButtonSizeUp.h"
#include "cButtonSizeDown.h"
#include "cButtonLoadFile.h"
#include "cButtonSaveFile.h"
#include "cColorBoxFG.h"
#include "cColorBoxBG.h"

class cButtonManager {
private:
	cWindowManager* m_Window;
	cToolManager* m_ToolManager;

	// Text
	sf::Font m_Font;
	sf::Text* m_Text;

	// Textures
	sf::Image m_NormalImage;
	sf::Texture m_NormalTexture;
	sf::Image m_TransparentImage;
	sf::Texture m_TransparentTexture;

	// Button Classes
	cButtonRectangle* m_ButtonRectangle;
	cButtonEllipse* m_ButtonEllipse;
	cButtonLine* m_ButtonLine;
	cButtonPolygon* m_ButtonPolygon;
	cButtonStamp* m_ButtonStamp;
	cButtonSizeUp* m_ButtonSizeUp;
	cButtonSizeDown* m_ButtonSizeDown;
	cButtonLoadFile* m_ButtonLoadFile;
	cButtonSaveFile* m_ButtonSaveFile;
	cColorBoxFG* m_ColorBoxFG;
	cColorBoxBG* m_ColorBoxBG;

public:
	cButtonManager(cWindowManager* _window, cToolManager* _toolManager);
	~cButtonManager();

	void DrawButtons();
	cButton* GetButton(sf::Vector2i _mousePos);
	void RemoveHovers();
	void UnselectButtons();
	void HoverButton(sf::Vector2i _mousePos);
	void ClickButton(sf::Vector2i _mousePos);
};

