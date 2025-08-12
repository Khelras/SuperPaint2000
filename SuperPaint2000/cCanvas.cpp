#include "cCanvas.h"

cCanvas::cCanvas(sf::RenderWindow& _window, sf::Color _colorBG) {
    this->m_CanvasShape = new sf::RectangleShape();
    this->m_CanvasTexture = new sf::RenderTexture();
    this->m_CanvasColor = _colorBG;

    // Making of Canvas
    this->m_CanvasShape->setSize(sf::Vector2f(_window.getSize()));
    if (this->m_CanvasTexture->resize(_window.getSize()));
    this->Clear(); // Custom Clear Function to Include the BG Color
    this->m_CanvasShape->setTexture(&(this->m_CanvasTexture->getTexture()));
}

cCanvas::~cCanvas() {
    delete(this->m_CanvasShape);
    delete(this->m_CanvasTexture);
}

void cCanvas::Draw(sf::Drawable& _shape) {
    this->m_CanvasTexture->draw(_shape);
    this->m_CanvasTexture->display();
}

void cCanvas::Clear() {
    this->m_CanvasTexture->clear(this->m_CanvasColor);
}

sf::RectangleShape* cCanvas::GetCanvasShape() const {
    return this->m_CanvasShape;
}

sf::RenderTexture* cCanvas::GetCanvasTexture() const {
    return this->m_CanvasTexture;
}
