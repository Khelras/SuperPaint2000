#include "cButtonSizeDown.h"

cButtonSizeDown::cButtonSizeDown(cToolManager* _toolManager, sf::Vector2f _size) : cButton(_size) {
	this->m_CanSelect = false;
	this->m_ToolManager = _toolManager;
	this->m_ButtonShape.setRadius(15.0f);
	this->m_ButtonShape.setFillColor(sf::Color::Black);
	this->m_ButtonShape.setPointCount(3);
	this->m_ButtonShape.setOrigin(this->m_ButtonShape.getGlobalBounds().getCenter());
	this->m_ButtonShape.setRotation(sf::degrees(180));
}

cButtonSizeDown::~cButtonSizeDown() {

}

void cButtonSizeDown::UseButton() {// If Tool Selected is NOT Stamp Tool
	if (this->m_ToolManager->GetSelectedToolEnum() != Tools::TOOL_STAMP) {
		// Decreases Thickness by 1pxc (Never going below 0)
		float fDecrease = this->m_ToolManager->GetOutlineThickness() - 1.0f;
		if (fDecrease >= 0) {
			this->m_ToolManager->SetOutlineThickness(fDecrease);
		}
	}
	// If Tool Selected IS Stamp Tool
	else {
		float fDecrease = this->m_ToolManager->GetScaleFactor();
		if (fDecrease > 1.0f) {
			// Decreases Scale Factor by 1
			this->m_ToolManager->SetScaleFactor(this->m_ToolManager->GetScaleFactor() - 1.0f);
		}
		else if (fDecrease <= 1.0f) {
			// Halves Scale Factor
			this->m_ToolManager->SetScaleFactor(this->m_ToolManager->GetScaleFactor() / 2.0f);
		}
	}
}

void cButtonSizeDown::Select() {} // Removes Select() Functionality

void cButtonSizeDown::Unselect() {} // Removes Unselect() Functionality

void cButtonSizeDown::DrawButton(cWindowManager* _window, float _posY) {
	// Calls DrawFunction Function from cButton Parent Class
	cButton::DrawButton(_window, _posY);

	// Extend Functionality
	// Draws the Contents of the Button
	float fCenterBoundsX = this->m_Button.getPosition().x + (this->m_Button.getSize().x / 2);
	float fCenterBoundsY = this->m_Button.getPosition().y + (this->m_Button.getSize().y / 2);
	this->m_ButtonShape.setPosition(sf::Vector2f(fCenterBoundsX, fCenterBoundsY));

	_window->m_ToolWindow.draw(this->m_ButtonShape);
}