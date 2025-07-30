#include "cWindowManager.h"
#include "cEventManager.h"

cWindowManager::cWindowManager(sf::VideoMode _mode, std::string _name) {
	this->create(_mode, _name);
    this->m_ToolWindow.create(sf::VideoMode({ 100, 700 }), "Super Tools 2000!");
    this->m_ToolWindow.setPosition(sf::Vector2i(this->getPosition().x + this->getSize().x, this->getPosition().y));
}

cWindowManager::~cWindowManager() {
    
}

void cWindowManager::Process() {
    cEventManager* EventManager = new cEventManager(this);

    while (this->isOpen()) {
        EventManager->Process();
    }

    delete(EventManager);
}