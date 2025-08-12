#pragma once
#include <SFML/Graphics.hpp>

class cCanvas {
private:
	sf::RectangleShape* m_CanvasShape;
	sf::RenderTexture* m_CanvasTexture;
	sf::Color m_CanvasColor;

public:
	cCanvas(sf::RenderWindow& _window, sf::Color _colorBG = sf::Color::White);
	~cCanvas();

	void Draw(sf::Drawable& _shape);
	void Clear();

	// Getters
	sf::RectangleShape* GetCanvasShape() const;
	sf::RenderTexture* GetCanvasTexture() const;
};

