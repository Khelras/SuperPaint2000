#include "cStamp.h"

// Constructor
cStamp::cStamp(sf::RenderWindow* _window, cCanvas* _canvas) : cTool(_window, _canvas) {
	this->m_ImageTexture = nullptr;

	// Tool
	this->SetFillColor(sf::Color::Transparent);
	this->SetOutlineColor(sf::Color::Transparent);
	this->SetOutlineThickness(0.0f);
}

// Destructor
cStamp::~cStamp() {

}

void cStamp::ImportImage(sf::Texture* _imageTexture) {
	// If user Imported an Image Texture, else do nothing...
	if (_imageTexture != nullptr) {
		this->m_ImageTexture = _imageTexture;
		this->m_Tool.setTexture(this->m_ImageTexture, true);
	}
}

void cStamp::SetFillColor(sf::Color _color) {} // Removes SetFillColor() Functionality

void cStamp::SetOutlineColor(sf::Color _color) {} // Removes SetOutlineColor() Functionality

void cStamp::SetOutlineThickness(float _thickness) {} // Removes SetOutlineThickness() Functionality

void cStamp::UseToolOnce() { // Starts the Draw Process
	// If Imported Image Texture Exist, else do nothing...
	if (this->m_ImageTexture != nullptr) {
		// Scales Size Uniformly to Maintain the Aspect Ratio
		sf::Vector2f ScaledSize(this->m_ImageTexture->getSize().x * this->m_ScaleFactor, this->m_ImageTexture->getSize().y * this->m_ScaleFactor);
		this->m_Tool.setSize(ScaledSize);
		this->m_Tool.setOrigin(this->m_Tool.getGlobalBounds().getCenter());
		this->m_Tool.setPosition(sf::Vector2f(sf::Mouse::getPosition(*(this->m_Window))));
	}
}

void cStamp::UseToolRealtime() { // The Draw Process
	// Does... Nothing? (No Realtime Process is Needed)
}

void cStamp::UseToolEnd() { // Completes the Draw Process
	// If Imported Image Texture Exist, else do nothing...
	if (this->m_ImageTexture != nullptr) {
		this->m_Canvas->Draw(this->m_Tool);
	}

	// Resets Size, Origin and Position
	this->m_Tool.setSize(sf::Vector2f(0.0f, 0.0f));
	this->m_Tool.setOrigin(sf::Vector2f(0.0f, 0.0f));
	this->m_Tool.setPosition(sf::Vector2f(0.0f, 0.0f));
}

void cStamp::Draw() {
	this->m_Window->draw(*(this->m_Canvas->GetCanvasShape()));
	this->m_Window->draw(this->m_Tool);
}
