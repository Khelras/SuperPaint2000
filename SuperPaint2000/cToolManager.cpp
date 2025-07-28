#include "cToolManager.h"

cToolManager::cToolManager(sf::RenderWindow* _window) {
	this->m_Window = _window;
	this->m_Canvas = new cCanvas(*(this->m_Window));
	this->m_SelectedTool = Tools::TOOL_RECTANGLE;
	this->m_ToolColour = sf::Color::White;

	// Tools
	this->m_ToolRectangle = new cRectangle(this->m_Window, this->m_Canvas, 0, 0);
}

cToolManager::~cToolManager() {
	delete(this->m_Canvas);
	delete(this->m_ToolRectangle);
}

void cToolManager::SelectTool(Tools _newTool) {
	// Needs to be hooked to an input register
	// Call this function (with a paramater) to change the tool
}

Tools cToolManager::GetSelectedTool() const {
	return this->m_SelectedTool;
}

void cToolManager::UseTool(bool _isRealtime, bool _isEnd) {
	// Switch Case Statement
	switch (this->m_SelectedTool) {
		// Rectangle Tool
		case (Tools::TOOL_RECTANGLE): {
			this->m_ToolRectangle->UseTool(_isRealtime, _isEnd);
		break;
		}
		
		// Circle Tool
		case (Tools::TOOL_CIRCLE): {
			
		break;
		}

		// Line Tool
		case (Tools::TOOL_LINE): {
			
		break;
		}

		// Pencil Tool
		case (Tools::TOOL_PENCIL): {
			
		break;
		}

		// Eraser Tool
		case (Tools::TOOL_ERASER): {
			
		break;
		}

		// Eyedrop Tool
		case (Tools::TOOL_EYEDROP): {
			
		break;
		}
	}
}

void cToolManager::Draw() {
	// Switch Case Statement
	switch (this->m_SelectedTool) {
		// Rectangle Tool
		case (Tools::TOOL_RECTANGLE): {
			this->m_ToolRectangle->Draw();
		break;
		}

		// Circle Tool
		case (Tools::TOOL_CIRCLE): {

		break;
		}

		// Line Tool
		case (Tools::TOOL_LINE): {

		break;
		}

		// Pencil Tool
		case (Tools::TOOL_PENCIL): {

		break;
		}

		// Eraser Tool
		case (Tools::TOOL_ERASER): {

		break;
		}

		// Eyedrop Tool
		case (Tools::TOOL_EYEDROP): {

		break;
		}
	}
}
