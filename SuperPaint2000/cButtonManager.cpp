#include "cButtonManager.h"

cButtonManager::cButtonManager(cWindowManager* _window, cToolManager* _toolManager) {
	this->m_Window = _window;
	this->m_ToolManager = _toolManager;
	
	// Thickness Text
	if (this->m_Font.openFromFile("fonts/arial.ttf") == false) printf("ERR: Unable to Load Font!\n"); // FOR DEBUGGING
	this->m_Text = new sf::Text(this->m_Font);
	int iThickness = this->m_ToolManager->GetOutlineThickness();
	this->m_Text->setString(std::to_string(iThickness) + "px");
	this->m_Text->setOrigin(this->m_Text->getGlobalBounds().getCenter());
	this->m_Text->setPosition(sf::Vector2f(this->m_Window->m_ToolWindow.getSize().x / 2.0f, this->m_Window->m_ToolWindow.getSize().y - 195.0f));
	this->m_Text->setFillColor(sf::Color::Black);

	// Normal Texture
	if (this->m_NormalImage.loadFromFile("images/normal.jpg") == false)
		printf("ERR: Unable to Load Image!\n"); // FOR DEBUGGING
	if (this->m_NormalTexture.loadFromImage(this->m_NormalImage) == false)
		printf("ERR: Unable to Load Image onto Texture!\n"); // FOR DEBUGGING

	// Transparent Texture
	if (this->m_TransparentImage.loadFromFile("images/transparent.jpg") == false)
		printf("ERR: Unable to Load Image!\n"); // FOR DEBUGGING
	if (this->m_TransparentTexture.loadFromImage(this->m_TransparentImage) == false)
		printf("ERR: Unable to Load Image onto Texture!\n"); // FOR DEBUGGING

	// Buttons
	this->m_ButtonRectangle = new cButtonRectangle(_toolManager, sf::Vector2f(50.0f, 50.0f));
	this->m_ButtonEllipse = new cButtonEllipse(_toolManager, sf::Vector2f(50.0f, 50.0f));
	this->m_ButtonLine = new cButtonLine(_toolManager, sf::Vector2f(50.0f, 50.0f));
	this->m_ButtonPolygon = new cButtonPolygon(_toolManager, sf::Vector2f(50.0f, 50.0f));
	this->m_ButtonStamp = new cButtonStamp(_toolManager, sf::Vector2f(50.0f, 50.0f));
	this->m_ButtonSizeUp = new cButtonSizeUp(_toolManager, sf::Vector2f(50.0f, 50.0f));
	this->m_ButtonSizeDown = new cButtonSizeDown(_toolManager, sf::Vector2f(50.0f, 50.0f));
	this->m_ButtonLoadFile = new cButtonLoadFile(_window, _toolManager, sf::Vector2f(75.0f, 50.0f));
	this->m_ButtonSaveFile = new cButtonSaveFile(_toolManager, sf::Vector2f(75.0f, 50.0f));
	this->m_ColorBoxFG = new cColorBoxFG(_window, _toolManager, sf::Vector2f(40.0f, 40.0f));
	this->m_ColorBoxBG = new cColorBoxBG(_window, _toolManager, sf::Vector2f(40.0f, 40.0f));

	// Pre-Selects Rectangle Tool
	this->m_ButtonRectangle->Select();
}

cButtonManager::~cButtonManager() {
	delete(this->m_Text);
	delete(this->m_ButtonRectangle);
	delete(this->m_ButtonEllipse);
	delete(this->m_ButtonLine);
	delete(this->m_ButtonPolygon);
	delete(this->m_ButtonStamp);
	delete(this->m_ButtonSizeUp);
	delete(this->m_ButtonSizeDown);
	delete(this->m_ButtonLoadFile);
	delete(this->m_ButtonSaveFile);
	delete(this->m_ColorBoxFG);
	delete(this->m_ColorBoxBG);
}

void cButtonManager::DrawButtons() {
	// First Resets Text Origin and Position
	this->m_Text->setOrigin(sf::Vector2f(0.0f, 0.0f));
	this->m_Text->setPosition(sf::Vector2f(0.0f, 0.0f));

	// Updates to either Outline Thickness or Scale
	if (this->m_ToolManager->GetSelectedToolEnum() != Tools::TOOL_STAMP) { // Outline Thickness
		int iThickness = this->m_ToolManager->GetOutlineThickness();
		this->m_Text->setString(std::to_string(iThickness) + "px");
	}
	else { // Scale Factor
		if (this->m_ToolManager->GetScaleFactor() < 1.0f) {
			// Converts to Fraction
			int iDenominator = 1 / this->m_ToolManager->GetScaleFactor();
			this->m_Text->setString("1/" + std::to_string(iDenominator) + "x");
		}
		else if (this->m_ToolManager->GetScaleFactor() >= 1.0f) {
			int iScale = this->m_ToolManager->GetScaleFactor();
			this->m_Text->setString(std::to_string(iScale) + "x");
		}
	}

	// Auto Center Text + Draws Text
	this->m_Text->setOrigin(this->m_Text->getGlobalBounds().getCenter());
	this->m_Text->setPosition(sf::Vector2f(this->m_Window->m_ToolWindow.getSize().x / 2.0f, this->m_Window->m_ToolWindow.getSize().y - 195.0f));
	this->m_Text->setFillColor(sf::Color::Black);
	this->m_Window->m_ToolWindow.draw(*(this->m_Text)); // Draws Text

	// Update Color FG Box
	if (this->m_ToolManager->GetFillColor() == sf::Color::Transparent) { // Fill Color Transparent
		this->m_ColorBoxFG->m_ButtonShape.setTexture(&(this->m_TransparentTexture));
		this->m_ColorBoxFG->m_ButtonShape.setFillColor(sf::Color::White);
	}
	else { // Fill Color NOT Transparent
		this->m_ColorBoxFG->m_ButtonShape.setTexture(&(this->m_NormalTexture));
		this->m_ColorBoxFG->m_ButtonShape.setFillColor(this->m_ToolManager->GetFillColor());
	}

	// Update Color BG Box
	if (this->m_ToolManager->GetOutlineColor() == sf::Color::Transparent) { // Outline Color Transparent
		this->m_ColorBoxBG->m_ButtonShape.setTexture(&(this->m_TransparentTexture));
		this->m_ColorBoxBG->m_ButtonShape.setFillColor(sf::Color::White);
	}
	else { // Outline Color NOT Transparent
		this->m_ColorBoxBG->m_ButtonShape.setTexture(&(this->m_NormalTexture));
		this->m_ColorBoxBG->m_ButtonShape.setFillColor(this->m_ToolManager->GetOutlineColor());
	}
		

	// Buttons
	this->m_ButtonRectangle->DrawButton(this->m_Window, 25.0f);
	this->m_ButtonEllipse->DrawButton(this->m_Window, 75.0f);
	this->m_ButtonLine->DrawButton(this->m_Window, 125.0f);
	this->m_ButtonPolygon->DrawButton(this->m_Window, 175.0f);
	this->m_ButtonStamp->DrawButton(this->m_Window, 225.0f);
	this->m_ColorBoxBG->DrawButton(this->m_Window, this->m_Window->m_ToolWindow.getSize().y - 340.0f);
	this->m_ColorBoxFG->DrawButton(this->m_Window, this->m_Window->m_ToolWindow.getSize().y - 340.0f);
	this->m_ButtonSizeUp->DrawButton(this->m_Window, this->m_Window->m_ToolWindow.getSize().y - 275.0f);
	this->m_ButtonSizeDown->DrawButton(this->m_Window, this->m_Window->m_ToolWindow.getSize().y - 175.0f);
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
	// If Mouse Position is over Polygon Tool Button
	else if (this->m_ButtonStamp->m_Button.getGlobalBounds().contains(sf::Vector2f(_mousePos))) {
		return this->m_ButtonStamp;
	}
	// If Mouse Position is over the Size Up Button
	else if (this->m_ButtonSizeUp->m_Button.getGlobalBounds().contains(sf::Vector2f(_mousePos))) {
		return this->m_ButtonSizeUp;
	}
	// If Mouse Position is over the Size Down Button
	else if (this->m_ButtonSizeDown->m_Button.getGlobalBounds().contains(sf::Vector2f(_mousePos))) {
		return this->m_ButtonSizeDown;
	}
	// If Mouse Position is over the Load File Button
	else if (this->m_ButtonLoadFile->m_Button.getGlobalBounds().contains(sf::Vector2f(_mousePos))) {
		return this->m_ButtonLoadFile;
	}
	// If Mouse Position is over the Save File Button
	else if (this->m_ButtonSaveFile->m_Button.getGlobalBounds().contains(sf::Vector2f(_mousePos))) {
		return this->m_ButtonSaveFile;
	}
	// If Mouse Position is over the Color Picker Foreground Button
	else if (this->m_ColorBoxFG->m_Button.getGlobalBounds().contains(sf::Vector2f(_mousePos))) {
		return this->m_ColorBoxFG;
	}
	// If Mouse Position is over the Color Picker Background Button
	else if (this->m_ColorBoxBG->m_Button.getGlobalBounds().contains(sf::Vector2f(_mousePos))) {
		return this->m_ColorBoxBG;
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
	this->m_ButtonStamp->RemoveHover();
	this->m_ButtonSizeUp->RemoveHover();
	this->m_ButtonSizeDown->RemoveHover();
	this->m_ButtonLoadFile->RemoveHover();
	this->m_ButtonSaveFile->RemoveHover();
	this->m_ColorBoxFG->RemoveHover();
	this->m_ColorBoxBG->RemoveHover();
}

void cButtonManager::UnselectButtons() { // Unselects all Buttons
	this->m_ButtonRectangle->Unselect();
	this->m_ButtonEllipse->Unselect();
	this->m_ButtonLine->Unselect();
	this->m_ButtonPolygon->Unselect();
	this->m_ButtonStamp->Unselect();
	this->m_ButtonSizeUp->Unselect();
	this->m_ButtonSizeDown->Unselect();
	this->m_ButtonLoadFile->Unselect();
	this->m_ButtonSaveFile->Unselect();
	this->m_ColorBoxFG->Unselect();
	this->m_ColorBoxBG->Unselect();
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
		
		// Updates to either Outline Thickness or Scale
		this->m_Text->setOrigin(sf::Vector2f(0.0f, 0.0f)); // First Resets Origin
		this->m_Text->setPosition({ 0, 0 });
		if (this->GetButton(_mousePos) != this->m_ButtonStamp) { // Outline Thickness
			int iThickness = this->m_ToolManager->GetOutlineThickness();
			this->m_Text->setString(std::to_string(iThickness) + "px");
		}
		else { // Scale Factor
			int iScale = this->m_ToolManager->GetScaleFactor();
			this->m_Text->setString(std::to_string(iScale) + "x");
		}
		
		// Auto Center Text
		this->m_Text->setOrigin(this->m_Text->getGlobalBounds().getCenter());
		this->m_Text->setPosition(sf::Vector2f(this->m_Window->m_ToolWindow.getSize().x / 2.0f, this->m_Window->m_ToolWindow.getSize().y - 195.0f));
		this->m_Text->setFillColor(sf::Color::Black);

	}
	// Else Button is a Outline Thickness or Scale Change
	else {
		// First use Button
		this->GetButton(_mousePos)->UseButton();
	}
}
