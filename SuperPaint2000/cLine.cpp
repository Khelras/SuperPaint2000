#include "cLine.h"
#define _USE_MATH_DEFINES // for PI
#include <math.h> // for atan2()

// Constructor
cLine::cLine(sf::RenderWindow* _window, cCanvas* _canvas) : cTool(_window, _canvas) {
	// Tool
	this->SetFillColor(sf::Color::Transparent);
	this->SetOutlineColor(sf::Color::Black);
	this->SetOutlineThickness(1.0f);
}

// Destructor
cLine::~cLine() {

}

void cLine::SetOutlineColor(sf::Color _color) {
	// Call SetColor Function from cTool Parent Class
	cTool::SetOutlineColor(_color);

	// Extend Functionality
	// Changes the Outline Color of Rectangle Tool
	this->m_Tool.setOutlineColor(_color);
}

void cLine::SetOutlineThickness(float _thickness) {
	// Call SetColor Function from cTool Parent Class
	cTool::SetOutlineThickness(_thickness / 2); // Halves it to Normalise Thickness

	// Extend Functionality
	// Changes the Outline Thickness of Rectangle Tool
	this->m_Tool.setOutlineThickness(_thickness / 2); // Halves it to Normalise Thickness
}

void cLine::UseToolOnce() { // Starts the Draw Process
	this->m_Tool.setPosition(sf::Vector2f(sf::Mouse::getPosition(*(this->m_Window))));
	this->m_Origin = this->m_Tool.getPosition();
}

void cLine::UseToolRealtime() { // The Draw Process
	// Mouse Position
	sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(*(this->m_Window)));

	// Length
	sf::Vector2f offset = mousePos - this->m_Origin;
	this->m_Tool.setSize(sf::Vector2f(0.0f, offset.length()));

	// Angle Calculations
	float fX1 = this->m_Origin.x; // x1
	float fY1 = this->m_Origin.y; // y1
	float fX2 = mousePos.x;       // x2
	float fY2 = mousePos.y;       // y2
	float fAngleRad = atan2f(fY2 - fY1, fX2 - fX1);
	this->m_Tool.setRotation(sf::radians(fAngleRad - (M_PI / 2.0f)));
}

void cLine::UseToolEnd() { // Completes the Draw Process
	this->m_Canvas->Draw(this->m_Tool);
	this->m_Tool.setSize(sf::Vector2f(0, 0));
}

void cLine::Draw() {
	this->m_Window->draw(*(this->m_Canvas->GetCanvasShape()));
	this->m_Window->draw(this->m_Tool);
}

