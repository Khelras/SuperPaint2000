#include "cButton.h"

cButton::cButton(sf::Vector2f _pos, sf::Color _color) {
	this->m_ButtonShape.setPosition(_pos);
	this->m_ButtonShape.setSize(sf::Vector2f(75, 50));
	this->m_ButtonShape.setFillColor(_color);
}

cButton::~cButton() {

}

void cButton::UseButton() {

}
