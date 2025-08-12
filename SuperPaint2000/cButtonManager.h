#pragma once
#include "cButtonRectangle.h"
#include "cButtonEllipse.h"
#include "cButtonLine.h"
#include "cButtonThicknessUp.h"
#include "cButtonThicknessDown.h"
#include "cButtonLoadFile.h"
#include "cButtonSaveFile.h"

class cButtonManager {
private:
	cWindowManager* m_Window;
	cToolManager* m_ToolManager;

	// Thickness Text
	sf::Font m_Font;
	sf::Text* m_TextThickness;

	// Button Classes
	cButtonRectangle* m_ButtonRectangle;
	cButtonEllipse* m_ButtonEllipse;
	cButtonLine* m_ButtonLine;
	cButtonThicknessUp* m_ButtonThicknessUp;
	cButtonThicknessDown* m_ButtonThicknessDown;
	cButtonLoadFile* m_ButtonLoadFile;
	cButtonSaveFile* m_ButtonSaveFile;

public:
	cButtonManager(cWindowManager* _window, cToolManager* _toolManager);
	~cButtonManager();

	void DrawButtons();
	bool HasButton(sf::Vector2i _mousePos);
	cButton* GetButton(sf::Vector2i _mousePos);
	void RemoveHovers();
	void UnselectButtons();
	void HoverButton(sf::Vector2i _mousePos);
	void ClickButton(sf::Vector2i _mousePos);
	
};

