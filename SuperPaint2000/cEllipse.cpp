#include <cmath>
#include "cEllipse.h"
#include <iostream>

// Constructor
cEllipse::cEllipse(sf::RenderWindow* _window, cCanvas* _canvas, float _radius) : cTool(_window, _canvas) {
	// Tool
	this->m_Tool.setRadius(_radius);
	this->SetFillColor(sf::Color::Transparent);
	this->SetOutlineColor(sf::Color::Black);
	this->m_Tool.setOutlineThickness(1.0f);
}

// Destructor
cEllipse::~cEllipse() {

}

void cEllipse::SetFillColor(sf::Color _color) {
	// Call SetColor Function from cTool Parent Class
	cTool::SetFillColor(_color);

	// Extend Functionality
	// Changes the Fill Color of Ellipse Tool
	this->m_Tool.setFillColor(_color);
}

void cEllipse::SetOutlineColor(sf::Color _color) {
	// Call SetColor Function from cTool Parent Class
	cTool::SetOutlineColor(_color);

	// Extend Functionality
	// Changes the Outline Color of Ellipse Tool
	this->m_Tool.setOutlineColor(_color);
}

void cEllipse::UseToolOnce() { // Starts the Draw Process
	this->m_Tool.setPosition(sf::Vector2f(sf::Mouse::getPosition(*(this->m_Window))));
	this->m_Origin = this->m_Tool.getPosition();
}

void cEllipse::UseToolRealtime() { // The Draw Process
	sf::Vector2f offset = sf::Vector2f(sf::Mouse::getPosition(*(this->m_Window))) - this->m_Origin; // Rectangle Bounds
	this->m_Tool.setRadius(0.5f); // Initial Radius of 0.5
	this->m_Tool.setScale(offset); // Scales using the offset variable (based on the initial radius of 0.5)

	// Divides thickness by magnitude to keep the outline thickness consistent throughout the scaling process
	float fOutlineThickness = this->m_Thickness / this->m_Tool.getScale().length();
	this->m_Tool.setOutlineThickness(fOutlineThickness);

	/* This was the original code for a "Circle" tool where it uniformly scales from the center of the circle */
	//// Distance Formula
	//sf::Vector2i mousePos = sf::Mouse::getPosition(*(this->m_Window));
	//float fdx = mousePos.x - this->m_Origin.x;
	//float fdy = mousePos.y - this->m_Origin.y;
	//float fRadius = std::sqrt(fdx * fdx + fdy * fdy);

	//// Set new Radius
	//this->m_Tool.setRadius(fRadius);

	//// Position the Circle so that resizing is performed from the Center
	//this->m_Tool.setOrigin(sf::Vector2f(fRadius, fRadius));
	//this->m_Tool.setPosition(m_Origin);
}

void cEllipse::UseToolEnd() { // Completes the Draw Process
	this->m_Canvas->Draw(this->m_Tool);
	this->m_Tool.setRadius(0);
}

void cEllipse::Draw() {
	this->m_Window->draw(this->m_Canvas->GetCanvasShape());
	this->m_Window->draw(this->m_Tool);
}
