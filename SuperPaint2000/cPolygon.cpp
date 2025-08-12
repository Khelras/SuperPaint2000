#include "cPolygon.h"

// Constructor
cPolygon::cPolygon(sf::RenderWindow* _window, cCanvas* _canvas) : cTool(_window, _canvas) {
	// Tool
	this->SetFillColor(sf::Color::Transparent);
	this->SetOutlineColor(sf::Color::Black);
	this->SetOutlineThickness(1.0f);
	this->m_Tool.setPointCount(0);
}

// Destructor
cPolygon::~cPolygon() {

}

void cPolygon::SetFillColor(sf::Color _color) {
	// Call SetColor Function from cTool Parent Class
	cTool::SetFillColor(_color);

	// Extend Functionality
	// Changes the Fill Color of Rectangle Tool
	this->m_Tool.setFillColor(_color);
}

void cPolygon::SetOutlineColor(sf::Color _color) {
	// Call SetColor Function from cTool Parent Class
	cTool::SetOutlineColor(_color);

	// Extend Functionality
	// Changes the Outline Color of Rectangle Tool
	this->m_Tool.setOutlineColor(_color);
}

void cPolygon::SetOutlineThickness(float _thickness) {
	// Call SetColor Function from cTool Parent Class
	cTool::SetOutlineThickness(_thickness);

	// Extend Functionality
	// Changes the Outline Thickness of Rectangle Tool
	this->m_Tool.setOutlineThickness(_thickness);
}

void cPolygon::UseToolOnce() { // Starts the Draw Process
	// First Increase the Point Count by 1 to allow for another point to be made
	this->m_Tool.setPointCount(this->m_Tool.getPointCount() + 1); 

	// Afterwards, we can set a new point
	this->m_Tool.setPoint(this->m_Tool.getPointCount() - 1, sf::Vector2f(sf::Mouse::getPosition(*(this->m_Window))));
}

void cPolygon::UseToolRealtime() { // The Draw Process
	// Does... Nothing? (No Realtime Process is Needed)
}

void cPolygon::UseToolEnd() { // Completes the Draw Process
	this->m_Canvas->Draw(this->m_Tool);
	this->m_Tool.setPointCount(0);
}

void cPolygon::Draw() {
	this->m_Window->draw(*(this->m_Canvas->GetCanvasShape()));
	this->m_Window->draw(this->m_Tool);
}