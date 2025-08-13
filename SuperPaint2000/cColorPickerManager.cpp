#include "cColorPickerManager.h"
#include <iostream>

cColorPickerManager::cColorPickerManager(cWindowManager* _window, cToolManager* _toolManager) {
	this->m_Window = _window;
	this->m_ToolManager = _toolManager;
	this->m_ColorPickerWindow = nullptr;

	// Color Picker Image
	if (this->m_ColorPickerImage.loadFromFile("images/colordialog.jpg") == false) 
		printf("ERR: Unable to Load Image!\n"); // FOR DEBUGGING
	if (this->m_ColorPickerTexture.loadFromImage(this->m_ColorPickerImage) == false) 
		printf("ERR: Unable to Load Image onto Texture!\n"); // FOR DEBUGGING
	this->m_ColorPickerSprite = new sf::Sprite(this->m_ColorPickerTexture);
	this->m_ColorPickerSprite->setPosition(sf::Vector2f(25.0f, 25.0f));

	// Colors (Default Selected)
	this->m_SelectedFillColor = sf::Color::Transparent;
	this->m_FillColor = sf::Color::Transparent;
	this->m_SelectedOutlineColor = sf::Color::Black;
	this->m_OutlineColor = sf::Color::Black;

	// Buttons
	this->m_ButtonApply = new cButtonApply(_window, _toolManager, sf::Vector2f(100.0f, 50.0f));
	this->m_ButtonCancel = new cButtonCancel(_window, sf::Vector2f(100.0f, 50.0f));
	this->m_ButtonTransparent = new cButtonColor(_window, 30.0f);
	this->m_ButtonWhite = new cButtonColor(_window, 30.0f);
	this->m_ButtonBlack = new cButtonColor(_window, 30.0f);

	// Transparent Texture
	if (this->m_TransparentImage.loadFromFile("images/transparent.jpg") == false)
		printf("ERR: Unable to Load Image!\n"); // FOR DEBUGGING
	if (this->m_TransparentTexture.loadFromImage(this->m_TransparentImage) == false)
		printf("ERR: Unable to Load Image onto Texture!\n"); // FOR DEBUGGING

	// Color Buttons Fill Textures/Colors
	this->m_ButtonTransparent->m_ButtonShape.setTexture(&(this->m_TransparentTexture));
	this->m_ButtonBlack->m_ButtonShape.setFillColor(sf::Color::Black);
}

cColorPickerManager::~cColorPickerManager() {
	delete(this->m_ColorPickerSprite);
	delete(this->m_ButtonApply);
	delete(this->m_ButtonCancel);
}

void cColorPickerManager::DrawButtons(sf::RenderWindow* _colorPickerWindow) {
	this->m_ColorPickerWindow = _colorPickerWindow;

	// Draws Color Picker Image
	this->m_ColorPickerWindow->draw(*(this->m_ColorPickerSprite));

	this->m_ButtonApply->DrawButton(sf::Vector2f(this->m_ColorPickerWindow->getSize().x / 4, this->m_ColorPickerWindow->getSize().y - 50.0f));
	this->m_ButtonCancel->DrawButton(sf::Vector2f((this->m_ColorPickerWindow->getSize().x / 4) * 3, this->m_ColorPickerWindow->getSize().y - 50.0f));
	this->m_ButtonTransparent->DrawButton(sf::Vector2f(this->m_ColorPickerWindow->getSize().x / 4, this->m_ColorPickerWindow->getSize().y - 150.0f));
	this->m_ButtonWhite->DrawButton(sf::Vector2f(this->m_ColorPickerWindow->getSize().x / 2, this->m_ColorPickerWindow->getSize().y - 150.0f));
	this->m_ButtonBlack->DrawButton(sf::Vector2f((this->m_ColorPickerWindow->getSize().x / 4) * 3, this->m_ColorPickerWindow->getSize().y - 150.0f));
}

cButton* cColorPickerManager::GetButton(sf::Vector2i _mousePos) {
	// If Mouse Position is over the Apply Button
	if (this->m_ButtonApply->m_Button.getGlobalBounds().contains(sf::Vector2f(_mousePos))) {
		return this->m_ButtonApply;
	}
	// If Mouse Position is over the Cancel Button
	else if (this->m_ButtonCancel->m_Button.getGlobalBounds().contains(sf::Vector2f(_mousePos))) {
		return this->m_ButtonCancel;
	}
	// If Mouse Position is NOT over a Button
	else {
		return nullptr;
	}
}

cButtonColor* cColorPickerManager::GetButtonColor(sf::Vector2i _mousePos) {
	// If Mouse Position is over the Transparent Button
	if (this->m_ButtonTransparent->m_Button.getGlobalBounds().contains(sf::Vector2f(_mousePos))) {
		return this->m_ButtonTransparent;
	}
	// If Mouse Position is over the White Button
	else if (this->m_ButtonWhite->m_Button.getGlobalBounds().contains(sf::Vector2f(_mousePos))) {
		return this->m_ButtonWhite;
	}
	// If Mouse Position is over the Black Button
	else if (this->m_ButtonBlack->m_Button.getGlobalBounds().contains(sf::Vector2f(_mousePos))) {
		return this->m_ButtonBlack;
	}
	else {
		return nullptr;
	}
}

void cColorPickerManager::RemoveHovers() {
	this->m_ButtonApply->RemoveHover();
	this->m_ButtonCancel->RemoveHover();
	this->m_ButtonTransparent->RemoveHover();
	this->m_ButtonWhite->RemoveHover();
	this->m_ButtonBlack->RemoveHover();
}

void cColorPickerManager::UnselectButtons() {
	this->m_ButtonApply->Unselect();
	this->m_ButtonCancel->Unselect();
}

void cColorPickerManager::HoverButton(sf::Vector2i _mousePos) {
	// First Removes any Pre-Existing Hovers
	this->RemoveHovers();

	// Sets new Hover
	this->GetButton(_mousePos)->Hover();
}

void cColorPickerManager::HoverButtonColor(sf::Vector2i _mousePos) {
	// First Removes any Pre-Existing Hovers
	this->RemoveHovers();

	// Sets new Hover
	this->GetButtonColor(_mousePos)->Hover();
}

void cColorPickerManager::ClickButton(sf::Vector2i _mousePos) {
	// First Unselects ALL Buttons (If Button Pressed is a Tool)
	if (this->GetButton(_mousePos)->m_CanSelect == true) {
		this->UnselectButtons();

		// Selects a new Button
		this->GetButton(_mousePos)->Select();
		this->GetButton(_mousePos)->UseButton();
	}
	// Else Button is a Outline Thickness or Scale Change
	else {
		// First use Button
		this->GetButton(_mousePos)->UseButton();
	}
}

void cColorPickerManager::ClickButtonColor(sf::Vector2i _mousePos) {
	if (this->GetButtonColor(_mousePos) == this->m_ButtonTransparent) { // Transparent
		// Sets the Color based on the opened Color Picker Window
		if (this->m_Window->m_ColorPickerFGWindow.isOpen() == true) { // Foreground Window
			printf("foreground transparent picked\n"); // FOR DEBUGGING
			this->m_FillColor = sf::Color::Transparent;
		}
		else if (this->m_Window->m_ColorPickerBGWindow.isOpen() == true) { // Background Window
			printf("background transparent picked\n"); // FOR DEBUGGING
			this->m_OutlineColor = sf::Color::Transparent;
		}
	}
	else if (this->GetButtonColor(_mousePos) == this->m_ButtonWhite) { // White
		// Sets the Color based on the opened Color Picker Window
		if (this->m_Window->m_ColorPickerFGWindow.isOpen() == true) { // Foreground Window
			printf("foreground white picked\n"); // FOR DEBUGGING
			this->m_FillColor = sf::Color::White;
		}
		else if (this->m_Window->m_ColorPickerBGWindow.isOpen() == true) { // Background Window
			printf("background white picked\n"); // FOR DEBUGGING
			this->m_OutlineColor = sf::Color::White;
		}
	}
	else if (this->GetButtonColor(_mousePos) == this->m_ButtonBlack) { // Black
		// Sets the Color based on the opened Color Picker Window
		if (this->m_Window->m_ColorPickerFGWindow.isOpen() == true) { // Foreground Window
			printf("foreground black picked\n"); // FOR DEBUGGING
			this->m_FillColor = sf::Color::Black;
		}
		else if (this->m_Window->m_ColorPickerBGWindow.isOpen() == true) { // Background Window
			printf("background black picked\n"); // FOR DEBUGGING
			this->m_OutlineColor = sf::Color::Black;
		}
	}
}

void cColorPickerManager::PickColor() {
	if (this->m_ColorPickerSprite->getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*(this->m_ColorPickerWindow))))) {
		// Color Pixel Selection
		int iColorPosX = sf::Mouse::getPosition(*(this->m_ColorPickerWindow)).x - this->m_ColorPickerSprite->getPosition().x;
		int iColorPosY = sf::Mouse::getPosition(*(this->m_ColorPickerWindow)).y - this->m_ColorPickerSprite->getPosition().y;

		// Sets the Color based on the opened Color Picker Window
		if (this->m_Window->m_ColorPickerFGWindow.isOpen() == true) { // Foreground Window
			printf("foreground picked\n"); // FOR DEBUGGING
			this->m_FillColor = this->m_ColorPickerImage.getPixel(sf::Vector2u(iColorPosX, iColorPosY));
		}
		else if (this->m_Window->m_ColorPickerBGWindow.isOpen() == true) { // Background Window
			printf("background picked\n"); // FOR DEBUGGING
			this->m_OutlineColor = this->m_ColorPickerImage.getPixel(sf::Vector2u(iColorPosX, iColorPosY));
		}
	}
}

sf::Color cColorPickerManager::GetSelectedFillColor() const {
	return this->m_SelectedFillColor;
}

sf::Color cColorPickerManager::GetSelectedOutlineColor() const {
	return this->m_SelectedOutlineColor;
}

void cColorPickerManager::ConfirmNewColors() {
	this->m_SelectedFillColor = this->m_FillColor;
	this->m_SelectedOutlineColor = this->m_OutlineColor;
}

void cColorPickerManager::CancelNewColors() {
	this->m_FillColor = this->m_SelectedFillColor;
	this->m_OutlineColor = this->m_SelectedOutlineColor;
}
