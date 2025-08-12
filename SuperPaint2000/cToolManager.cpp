#include "cToolManager.h"

cToolManager::cToolManager(sf::RenderWindow* _window) {
	this->m_Window = _window;
	this->m_Canvas = new cCanvas(*(this->m_Window), sf::Color(255, 255, 255, 250));

	// Default Settings
	this->m_SelectedTool = Tools::TOOL_RECTANGLE;
	this->m_ToolFillColour = sf::Color::Transparent;
	this->m_ToolOutlineColor = sf::Color::Black;
	this->m_ToolOutlineThickness = 1.0f;
	this->m_ToolScaleFactor = 1.0f;

	// Tools
	this->m_ToolRectangle = new cRectangle(this->m_Window, this->m_Canvas);
	this->m_ToolEllipse = new cEllipse(this->m_Window, this->m_Canvas);
	this->m_ToolLine = new cLine(this->m_Window, this->m_Canvas);
	this->m_ToolPolygon = new cPolygon(this->m_Window, this->m_Canvas);
	this->m_ToolStamp = new cStamp(this->m_Window, this->m_Canvas);

	// Applies Default Settings onto Selected Tool
	this->GetSelectedTool()->SetFillColor(this->m_ToolFillColour);
	this->GetSelectedTool()->SetOutlineColor(this->m_ToolOutlineColor);
	this->GetSelectedTool()->SetOutlineThickness(this->m_ToolOutlineThickness);
}

cToolManager::~cToolManager() {
	delete(this->m_Canvas);
	delete(this->m_ToolRectangle);
	delete(this->m_ToolEllipse);
	delete(this->m_ToolLine);
	delete(this->m_ToolPolygon);
	delete(this->m_ToolStamp);
}

cCanvas* cToolManager::GetCanvas() const {
	return this->m_Canvas;
}

cTool* cToolManager::GetSelectedTool() const {
	// Switch Case Statement
	switch (this->m_SelectedTool) {
		// Rectangle Tool
		case (Tools::TOOL_RECTANGLE): {
			return this->m_ToolRectangle;
			break;
		}

		// Circle Tool
		case (Tools::TOOL_ELLIPSE): {
			return this->m_ToolEllipse;
			break;
		}

		 // Line Tool
		case (Tools::TOOL_LINE): {
			return this->m_ToolLine;
			break;
		}

		// Line Tool
		case (Tools::TOOL_POLYGON): {
			return this->m_ToolPolygon;
			break;
		}

		// Line Tool
		case (Tools::TOOL_STAMP): {
			return this->m_ToolStamp;
			break;
		}

		// Default
		default: {
			return nullptr;
			break;
		}
	}
}

Tools cToolManager::GetSelectedToolEnum() const {
	return this->m_SelectedTool;
}

float cToolManager::GetOutlineThickness() const {
	return this->m_ToolOutlineThickness;
}

float cToolManager::GetScaleFactor() const {
	return this->m_ToolScaleFactor;
}


void cToolManager::SelectTool(Tools _newTool) {
	this->m_SelectedTool = _newTool;

	// Applies the current tool settings onto the newly selected tool
	this->GetSelectedTool()->SetFillColor(this->m_ToolFillColour);
	this->GetSelectedTool()->SetOutlineColor(this->m_ToolOutlineColor);
	this->GetSelectedTool()->SetOutlineThickness(this->m_ToolOutlineThickness);
	this->GetSelectedTool()->SetScaleFactor(this->m_ToolScaleFactor);
}

void cToolManager::SetFillColor(sf::Color _color) {
	// Because Line Tool has not Fill Color
	if (this->GetSelectedTool() != this->m_ToolLine) {
		this->m_ToolFillColour = _color;
		this->GetSelectedTool()->SetFillColor(_color);
	}
}

void cToolManager::SetOutlineColor(sf::Color _color) {
	this->m_ToolOutlineColor = _color;
	this->GetSelectedTool()->SetOutlineColor(_color);
}

void cToolManager::SetOutlineThickness(float _thickness) {
	this->m_ToolOutlineThickness = _thickness;
	this->GetSelectedTool()->SetOutlineThickness(_thickness);
}

void cToolManager::SetScaleFactor(float _scale) {
	this->m_ToolScaleFactor = _scale;
	this->GetSelectedTool()->SetScaleFactor(_scale);
}
