#include "Toolbox.h"

Toolbox::Toolbox() {
	m_ActiveTool = ActiveTool::Tool_Rectangle;
	m_ToolColour = sf::Color::White;
}

Toolbox::~Toolbox() {

}

void Toolbox::Swap() {
	// Needs to be hooked to an input register
	// Call this function (with a paramater) to change the tool
}

void Toolbox::Draw() {

}
