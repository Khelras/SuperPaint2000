#include "cButtonManager.h"

cButtonManager::cButtonManager(cToolManager* _toolManager, cWindowManager* _window) {
	this->m_Window = _window;
	this->m_ToolManager = _toolManager;

	// Buttons
	this->m_ButtonRectangle = new cButtonRectangle(_toolManager, sf::Vector2f(50, 50));
	this->m_ButtonEllipse = new cButtonEllipse(_toolManager, sf::Vector2f(50, 50));
}

cButtonManager::~cButtonManager() {
	delete(this->m_ButtonRectangle);
	delete(this->m_ButtonEllipse);
}

void cButtonManager::DrawButtons() {
	this->m_ButtonRectangle->DrawButton(this->m_Window, 25.0f);
	this->m_ButtonEllipse->DrawButton(this->m_Window, 75.0f);
}

bool cButtonManager::HasButton(sf::Vector2i _mousePos) {
	// If Mouse Position is over Rectangle Tool Button
	if (this->m_ButtonRectangle->m_Button.getGlobalBounds().contains(sf::Vector2f(_mousePos))) {
		return true;
	}
	// If Mouse Position is over Ellipse Tool Button
	else if (this->m_ButtonEllipse->m_Button.getGlobalBounds().contains(sf::Vector2f(_mousePos))) {
		return true;
	}
	// If Mouse Position is NOT over a Button
	else {
		return false;
	}
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
	// If Mouse Position is NOT over a Button
	else {
		return nullptr;
	}
}

void cButtonManager::RemoveHovers() { // Removes all Hovers
	this->m_ButtonRectangle->RemoveHover();
	this->m_ButtonEllipse->RemoveHover();
}

void cButtonManager::UnselectButtons() { // Unselects all Buttons
	this->m_ButtonRectangle->Unselect();
	this->m_ButtonEllipse->Unselect();
}

void cButtonManager::HoverButton(sf::Vector2i _mousePos) {
	// First Removes any Pre-Existing Hovers
	this->RemoveHovers();

	// Sets new Hover
	this->GetButton(_mousePos)->Hover();
}

void cButtonManager::ClickButton(sf::Vector2i _mousePos) {
	// First Unselects ALL Buttons
	this->UnselectButtons();

	// Selects a new Button
	this->GetButton(_mousePos)->Select();
	this->GetButton(_mousePos)->UseButton();
}
