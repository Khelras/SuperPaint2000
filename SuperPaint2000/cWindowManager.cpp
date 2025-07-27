#include "cWindowManager.h"

cWindowManager::cWindowManager(std::string _name) {
	this->create(sf::VideoMode({ 1200, 900 }), _name);
}

cWindowManager::~cWindowManager() {

}

void cWindowManager::Process() {
    sf::Vector2f ShapeOrigin;

    cCanvas Canvas(*this);

    // Rectangle Tool
    cRectangle cRectangle(0, 0);

    while (this->isOpen()) {
        while (const std::optional event = this->pollEvent()) {
            // Close Event
            if (event->is<sf::Event::Closed>()) {
                this->close();
            }

            // Mouse Button Pressed Event
            if (const auto* mousePressed = event->getIf<sf::Event::MouseButtonPressed>()) {
                if (mousePressed->button == sf::Mouse::Button::Left) {
                    cRectangle.m_Tool.setPosition(sf::Vector2f(sf::Mouse::getPosition(*this)));
                    ShapeOrigin = cRectangle.m_Tool.getPosition();
                }
            }

            // Mouse Button Released Event
            if (const auto* mouseReleased = event->getIf<sf::Event::MouseButtonReleased>()) {
                if (mouseReleased->button == sf::Mouse::Button::Left) {
                    Canvas.Draw(cRectangle.m_Tool);
                    cRectangle.m_Tool.setSize(sf::Vector2f(0, 0));
                }
            }
        }

        // -- WARNING REALTIME INPUT ZONE -- //
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            sf::Vector2f offset = sf::Vector2f(sf::Mouse::getPosition(*this)) - ShapeOrigin;

            cRectangle.m_Tool.setSize(offset);
        }

        this->clear();
        this->draw(Canvas.GetCanvasShape());
        this->draw(cRectangle.m_Tool);
        this->display();
    }
}