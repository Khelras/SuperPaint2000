#include "cTool.h"

cTool::cTool(sf::RenderWindow* _window, cCanvas* _canvas) {
	this->m_Window = _window;
	this->m_Canvas = _canvas;
	this->m_Thickness = 1.0f;
	this->m_ScaleFactor = 1.0f;
}

cTool::~cTool() {

}

void cTool::SetFillColor(sf::Color _color) {
	this->m_FillColor = _color;
}

void cTool::SetOutlineColor(sf::Color _color) {
	this->m_OutlineColor = _color;
}

void cTool::SetOutlineThickness(float _thickness) {
	this->m_Thickness = _thickness;
}

void cTool::SetScaleFactor(float _scale) {
	this->m_ScaleFactor = _scale;
}
