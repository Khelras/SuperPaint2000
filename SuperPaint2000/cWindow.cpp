#include "cWindow.h"

cWindow::cWindow(std::string _name) {
	this->create(sf::VideoMode({ 1200, 900 }), _name);
    this->m_EventManager = new cEventManager(this);
}

cWindow::~cWindow() {
    delete(m_EventManager);
}

void cWindow::Process() {
    sf::Vector2f ShapeOrigin;

    while (this->isOpen()) {
        this->m_EventManager->Process();
    }
}