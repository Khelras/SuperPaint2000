#pragma once
#include "cTool.h"

// Inherits from cTool Class
class cStamp : public cTool {
private:
	sf::Texture* m_ImageTexture;
	sf::RectangleShape m_Tool;

public:
	cStamp(sf::RenderWindow* _window, cCanvas* _canvas);
	~cStamp();

	// Overridden Functions
	void ImportImage(sf::Texture* _imageTexture) override;
	void SetFillColor(sf::Color _color) override; // Removes SetFillColor() Functionality
	void SetOutlineColor(sf::Color _color) override; // Removes SetOutlineColor() Functionality
	void SetOutlineThickness(float _thickness) override;  // Removes SetOutlineThickness() Functionality
	void UseToolOnce() override; // Starts the Draw Process
	void UseToolRealtime() override; // The Draw Process
	void UseToolEnd() override; // Completes the Draw Process
	void Draw() override;
};

