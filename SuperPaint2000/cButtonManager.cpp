#include "cButtonManager.h"
#include <string>

cButtonManager::cButtonManager(cWindowManager* _window, cToolManager* _toolManager) {
	this->m_Window = _window;
	this->m_ToolManager = _toolManager;
	
	// Thickness Text
	if (this->m_Font.openFromFile("fonts/arial.ttf") == false) printf("ERR: Unable to Load Font!\n"); // FOR DEBUGGING
	this->m_TextThickness = new sf::Text(this->m_Font);
	int iThickness = this->m_ToolManager->GetOutlineThickness();
	this->m_TextThickness->setString(std::to_string(iThickness) + "px");
	this->m_TextThickness->setOrigin(this->m_TextThickness->getGlobalBounds().getCenter());
	this->m_TextThickness->setPosition(sf::Vector2f(this->m_Window->m_ToolWindow.getSize().x / 2.0f, this->m_Window->m_ToolWindow.getSize().y - 195.0f));
	this->m_TextThickness->setFillColor(sf::Color::Black);

	// Buttons
	this->m_ButtonRectangle = new cButtonRectangle(_toolManager, sf::Vector2f(50.0f, 50.0f));
	this->m_ButtonEllipse = new cButtonEllipse(_toolManager, sf::Vector2f(50.0f, 50.0f));
	this->m_ButtonLine = new cButtonLine(_toolManager, sf::Vector2f(50.0f, 50.0f));
	this->m_ButtonPolygon = new cButtonPolygon(_toolManager, sf::Vector2f(50.0f, 50.0f));
	this->m_ButtonThicknessUp = new cButtonThicknessUp(_toolManager, sf::Vector2f(50.0f, 50.0f));
	this->m_ButtonThicknessDown = new cButtonThicknessDown(_toolManager, sf::Vector2f(50.0f, 50.0f));
	this->m_ButtonLoadFile = new cButtonLoadFile(_window, _toolManager, sf::Vector2f(75.0f, 50.0f));
	this->m_ButtonSaveFile = new cButtonSaveFile(_toolManager, sf::Vector2f(75.0f, 50.0f));

	// Pre-Selects Rectangle Tool
	this->m_ButtonRectangle->Select();
}

cButtonManager::~cButtonManager() {
	delete(this->m_TextThickness);
	delete(this->m_ButtonRectangle);
	delete(this->m_ButtonEllipse);
	delete(this->m_ButtonLine);
	delete(this->m_ButtonPolygon);
	delete(this->m_ButtonThicknessUp);
	delete(this->m_ButtonThicknessDown);
	delete(this->m_ButtonLoadFile);
	delete(this->m_ButtonSaveFile);
}

void cButtonManager::DrawButtons() {
	// Thickness Text
	this->m_Window->m_ToolWindow.draw(*(this->m_TextThickness));

	// Buttons
	this->m_ButtonRectangle->DrawButton(this->m_Window, 25.0f);
	this->m_ButtonEllipse->DrawButton(this->m_Window, 75.0f);
	this->m_ButtonLine->DrawButton(this->m_Window, 125.0f);
	this->m_ButtonPolygon->DrawButton(this->m_Window, 175.0f);
	this->m_ButtonThicknessUp->DrawButton(this->m_Window, this->m_Window->m_ToolWindow.getSize().y - 275.0f);
	this->m_ButtonThicknessDown->DrawButton(this->m_Window, this->m_Window->m_ToolWindow.getSize().y - 175.0f);
	this->m_ButtonLoadFile->DrawButton(this->m_Window, this->m_Window->m_ToolWindow.getSize().y - 125.0f);
	this->m_ButtonSaveFile->DrawButton(this->m_Window, this->m_Window->m_ToolWindow.getSize().y - 75.0f);
}

cButton* cButtonManager::GetButton(sf::Vector2i _mousePos) {
	// If Mouse Position is over Rectangle Tool Button
	if (this->m_ButtonRectangle->m_Button.getGlobalBounds().contains(sf::Vector2f(_mousePos))) {
		return this->m_ButtonRectangle;
	}
	// If Mouse Position is over Ellipse Tool Button
	else if (this->m_ButtonEllipse->m_Button.getGlobalBounds().contains(sf::Vector2f(_mousePos))) {
		return this->m_ButtonEllipse;
	}
	// If Mouse Position is over Line Tool Button
	else if (this->m_ButtonLine->m_Button.getGlobalBounds().contains(sf::Vector2f(_mousePos))) {
		return this->m_ButtonLine;
	}
	// If Mouse Position is over Polygon Tool Button
	else if (this->m_ButtonPolygon->m_Button.getGlobalBounds().contains(sf::Vector2f(_mousePos))) {
		return this->m_ButtonPolygon;
	}
	// If Mouse Position is over the Thickness Up Button
	else if (this->m_ButtonThicknessUp->m_Button.getGlobalBounds().contains(sf::Vector2f(_mousePos))) {
		return this->m_ButtonThicknessUp;
	}
	// If Mouse Position is over the Thickness Down Button
	else if (this->m_ButtonThicknessDown->m_Button.getGlobalBounds().contains(sf::Vector2f(_mousePos))) {
		return this->m_ButtonThicknessDown;
	}
	// If Mouse Position is over the Thickness Up Button
	else if (this->m_ButtonLoadFile->m_Button.getGlobalBounds().contains(sf::Vector2f(_mousePos))) {
		return this->m_ButtonLoadFile;
	}
	// If Mouse Position is over the Thickness Down Button
	else if (this->m_ButtonSaveFile->m_Button.getGlobalBounds().contains(sf::Vector2f(_mousePos))) {
		return this->m_ButtonSaveFile;
	}
	// If Mouse Position is NOT over a Button
	else {
		return nullptr;
	}
}

void cButtonManager::RemoveHovers() { // Removes all Hovers
	this->m_ButtonRectangle->RemoveHover();
	this->m_ButtonEllipse->RemoveHover();
	this->m_ButtonLine->RemoveHover();
	this->m_ButtonPolygon->RemoveHover();
	this->m_ButtonThicknessUp->RemoveHover();
	this->m_ButtonThicknessDown->RemoveHover();
	this->m_ButtonLoadFile->RemoveHover();
	this->m_ButtonSaveFile->RemoveHover();
}

void cButtonManager::UnselectButtons() { // Unselects all Buttons
	this->m_ButtonRectangle->Unselect();
	this->m_ButtonEllipse->Unselect();
	this->m_ButtonLine->Unselect();
	this->m_ButtonPolygon->Unselect();
	this->m_ButtonThicknessUp->Unselect();
	this->m_ButtonThicknessDown->Unselect();
	this->m_ButtonLoadFile->Unselect();
	this->m_ButtonSaveFile->Unselect();
}

void cButtonManager::HoverButton(sf::Vector2i _mousePos) {
	// First Removes any Pre-Existing Hovers
	this->RemoveHovers();

	// Sets new Hover
	this->GetButton(_mousePos)->Hover();
}

void cButtonManager::ClickButton(sf::Vector2i _mousePos) {
	// First Unselects ALL Buttons (If Button Pressed is a Tool)
	if (this->GetButton(_mousePos)->m_CanSelect == true) {
		this->UnselectButtons();

		// Selects a new Button
		this->GetButton(_mousePos)->Select();
		this->GetButton(_mousePos)->UseButton();
	}
	// Else Button is a Outline Thickness Change
	else {
		// First use Button
		this->GetButton(_mousePos)->UseButton();

		// Then Update Thickness Text
		int iThickness = this->m_ToolManager->GetOutlineThickness();
		this->m_TextThickness->setString(std::to_string(iThickness) + "px");
	}
}
