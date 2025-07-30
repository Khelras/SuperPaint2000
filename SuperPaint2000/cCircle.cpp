#include <cmath>
#include "cCircle.h"

// Constructor
cCircle::cCircle(sf::RenderWindow * _window, cCanvas * _canvas, float _radius, sf::Color _color) : cTool(_window, _canvas) {
	// Tool
	this->m_Tool.setRadius(_radius);
	this->SetColor(_color);
}

// Destructor
cCircle::~cCircle() {

}

void cCircle::SetColor(sf::Color _color) {
	// Call SetColor Function from cTool Parent Class
	cTool::SetColor(_color);

	// Extend Functionality
	// Changes the Fill Color of Rectangle Tool
	this->m_Tool.setFillColor(_color);
}

void cCircle::UseToolOnce() {
	this->m_Tool.setPosition(sf::Vector2f(sf::Mouse::getPosition(*(this->m_Window))));
	this->m_Origin = this->m_Tool.getPosition();
}

void cCircle::UseToolRealtime() {
	// Distance Formula
	sf::Vector2i mousePos = sf::Mouse::getPosition(*(this->m_Window));
	float fdx = mousePos.x - this->m_Origin.x;
	float fdy = mousePos.y - this->m_Origin.y;
	float fRadius = std::sqrt(fdx * fdx + fdy * fdy);

	// Set new Radius
	this->m_Tool.setRadius(fRadius);

	// Position the Circle so that resizing is performed from the Center
	this->m_Tool.setOrigin(sf::Vector2f(fRadius, fRadius));
	this->m_Tool.setPosition(m_Origin);
}

void cCircle::UseToolEnd() {
	this->m_Canvas->Draw(this->m_Tool);
	this->m_Tool.setRadius(0);
}

void cCircle::Draw() {
	this->m_Window->draw(this->m_Canvas->GetCanvasShape());
	this->m_Window->draw(this->m_Tool);
}
