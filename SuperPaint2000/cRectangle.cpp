#include "cRectangle.h"

// Constructor
cRectangle::cRectangle(sf::RenderWindow* _window, cCanvas* _canvas) : cTool(_window, _canvas) {
	// Tool
	this->SetFillColor(sf::Color::Transparent);
	this->SetOutlineColor(sf::Color::Black);
	this->SetOutlineThickness(1.0f);
}

// Destructor
cRectangle::~cRectangle() {
	
}

void cRectangle::SetFillColor(sf::Color _color) {
	// Call SetColor Function from cTool Parent Class
	cTool::SetFillColor(_color);

	// Extend Functionality
	// Changes the Fill Color of Rectangle Tool
	this->m_Tool.setFillColor(_color);
}

void cRectangle::SetOutlineColor(sf::Color _color) {
	// Call SetColor Function from cTool Parent Class
	cTool::SetOutlineColor(_color);

	// Extend Functionality
	// Changes the Outline Color of Rectangle Tool
	this->m_Tool.setOutlineColor(_color);
}

void cRectangle::SetOutlineThickness(float _thickness) {
	// Call SetColor Function from cTool Parent Class
	cTool::SetOutlineThickness(_thickness);

	// Extend Functionality
	// Changes the Outline Thickness of Rectangle Tool
	this->m_Tool.setOutlineThickness(_thickness);
}

void cRectangle::UseToolOnce() { // Starts the Draw Process
	this->m_Tool.setPosition(sf::Vector2f(sf::Mouse::getPosition(*(this->m_Window))));
	this->m_Origin = this->m_Tool.getPosition();
}

void cRectangle::UseToolRealtime() { // The Draw Process
	sf::Vector2f offset = sf::Vector2f(sf::Mouse::getPosition(*(this->m_Window))) - this->m_Origin;
	this->m_Tool.setSize(offset);
}

void cRectangle::UseToolEnd() { // Completes the Draw Process
	this->m_Canvas->Draw(this->m_Tool);
	this->m_Tool.setSize(sf::Vector2f(0, 0));
}

void cRectangle::Draw() {
	this->m_Window->draw(*(this->m_Canvas->GetCanvasShape()));
	this->m_Window->draw(this->m_Tool);
}
