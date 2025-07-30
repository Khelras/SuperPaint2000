#include "cRectangle.h"

// Constructor
cRectangle::cRectangle(sf::RenderWindow* _window, cCanvas* _canvas, float _length, float _width, sf::Color _color) : cTool(_window, _canvas) {
	// Tool
	this->m_Tool.setSize({ _length, _width });
	this->SetColor(_color);
}

// Destructor
cRectangle::~cRectangle() {
	
}

void cRectangle::SetColor(sf::Color _color) {
	// Call SetColor Function from cTool Parent Class
	cTool::SetColor(_color);

	// Extend Functionality
	// Changes the Fill Color of Rectangle Tool
	this->m_Tool.setFillColor(_color);
}

void cRectangle::UseToolOnce() {
	this->m_Tool.setPosition(sf::Vector2f(sf::Mouse::getPosition(*(this->m_Window))));
	this->m_Origin = this->m_Tool.getPosition();
}

void cRectangle::UseToolRealtime() {
	sf::Vector2f offset = sf::Vector2f(sf::Mouse::getPosition(*(this->m_Window))) - this->m_Origin;
	this->m_Tool.setSize(offset);
}

void cRectangle::UseToolEnd() {
	this->m_Canvas->Draw(this->m_Tool);
	this->m_Tool.setSize(sf::Vector2f(0, 0));
}

void cRectangle::Draw() {
	this->m_Window->draw(this->m_Canvas->GetCanvasShape());
	this->m_Window->draw(this->m_Tool);
	
}
