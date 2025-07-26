#include "cRectangle.h"

// Constructor
cRectangle::cRectangle(float _length, float _width, sf::Color _color) {
	this->m_Tool.setSize({ _length, _width });


	this->SetColor(_color);
}

// Destructor
cRectangle::~cRectangle() {

}

void cRectangle::SetColor(sf::Color _color) {
	// Call SetColor Function from cShape Class
	cTool::SetColor(_color);

	// Extend Functionality
	// Changes the Fill Color of Rectangle Tool
	this->m_Tool.setFillColor(_color);
}
