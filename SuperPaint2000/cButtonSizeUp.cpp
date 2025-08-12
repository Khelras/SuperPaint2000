#include "cButtonSizeUp.h"

cButtonSizeUp::cButtonSizeUp(cToolManager* _toolManager, sf::Vector2f _size) : cButton(_size) {
	this->m_CanSelect = false;
	this->m_ToolManager = _toolManager;
	this->m_ButtonShape.setRadius(15.0f);
	this->m_ButtonShape.setFillColor(sf::Color::Black);
	this->m_ButtonShape.setPointCount(3);
	this->m_ButtonShape.setOrigin(this->m_ButtonShape.getGlobalBounds().getCenter());
}

cButtonSizeUp::~cButtonSizeUp() {

}

void cButtonSizeUp::UseButton() {
	// If Tool Selected is NOT Stamp Tool
	if (this->m_ToolManager->GetSelectedToolEnum() != Tools::TOOL_STAMP) {
		// Increases Thickness by 1px
		this->m_ToolManager->SetOutlineThickness(this->m_ToolManager->GetOutlineThickness() + 1.0f);
	}
	// If Tool Selected IS Stamp Tool
	else {
		float fIncrease = this->m_ToolManager->GetScaleFactor();
		if (fIncrease >= 1.0f) {
			// Increases Scale Factor by 1
			this->m_ToolManager->SetScaleFactor(this->m_ToolManager->GetScaleFactor() + 1.0f);
		}
		else if (fIncrease < 1.0f) {
			// Doubles Scale Factor
			this->m_ToolManager->SetScaleFactor(this->m_ToolManager->GetScaleFactor() * 2.0f);
		}
	}
}

void cButtonSizeUp::Select() {} // Removes Select() Functionality

void cButtonSizeUp::Unselect() {} // Removes Unselect() Functionality

void cButtonSizeUp::DrawButton(cWindowManager* _window, float _posY) {
	// Calls DrawFunction Function from cButton Parent Class
	cButton::DrawButton(_window, _posY);

	// Extend Functionality
	// Draws the Contents of the Button
	// Draws Button Contents to the Center Position of Button Bounds
	float fCenterBoundsX = this->m_Button.getPosition().x + (this->m_Button.getSize().x / 2);
	float fCenterBoundsY = this->m_Button.getPosition().y + (this->m_Button.getSize().y / 2);
	this->m_ButtonShape.setPosition(sf::Vector2f(fCenterBoundsX, fCenterBoundsY));

	_window->m_ToolWindow.draw(this->m_ButtonShape);
}
