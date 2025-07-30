#include "cTool.h"

cTool::cTool(sf::RenderWindow* _window, cCanvas* _canvas) {
	this->m_Window = _window;
	this->m_Canvas = _canvas;
}

cTool::~cTool() {

}

sf::Color cTool::GetColor() const {
	return this->m_color;
}

void cTool::SetColor(sf::Color _color) {
	this->m_color = _color;
}

void cTool::UseTool(bool _isRealtime, bool _isEnd) {
	if (_isRealtime == true) {
		this->UseToolRealtime();
	}
	else {
		if (_isEnd == true) {
			this->UseToolEnd();
		}
		else {
			this->UseToolOnce();
		}
	}
}
