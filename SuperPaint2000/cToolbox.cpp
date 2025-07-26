#include "cToolbox.h"

cToolbox::cToolbox() {
	this->m_SelectedTool = Tools::TOOL_RECTANGLE;
	this->m_ToolColour = sf::Color::White;
}

cToolbox::~cToolbox() {

}

void cToolbox::SelectTool(Tools _newTool) {
	// Needs to be hooked to an input register
	// Call this function (with a paramater) to change the tool
}

Tools cToolbox::GetSelectedTool() const {
	return this->m_SelectedTool;
}

void cToolbox::UseTool() {
	// Switch Case Statement
	switch (this->m_SelectedTool) {
		// Rectangle Tool
		case (Tools::TOOL_RECTANGLE): {

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
