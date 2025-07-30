#include "cCanvas.h"

cCanvas::cCanvas(sf::RenderWindow& _window, sf::Color _colorBG) {
    // Making of Canvas
    this->m_CanvasShape.setSize(sf::Vector2f(_window.getSize()));
    if (this->m_CanvasTexture.resize(_window.getSize()));
    this->m_CanvasShape.setTexture(&(this->m_CanvasTexture).getTexture());
}

cCanvas::~cCanvas() {

}

void cCanvas::Draw(sf::Drawable& _shape) {
    this->m_CanvasTexture.draw(_shape);
    this->m_CanvasTexture.display();
}

sf::RectangleShape cCanvas::GetCanvasShape() const {
    return this->m_CanvasShape;
}