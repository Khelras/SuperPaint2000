#include "cEventManager.h"

cEventManager::cEventManager(sf::RenderWindow* _window) {
    this->m_Window = _window;
    this->m_ToolManager = new cToolManager(this->m_Window);
    this->m_Button = new cButton(sf::Vector2f(50, 50), sf::Color::Green);
}

cEventManager::~cEventManager() {
	delete(this->m_Window);
    delete(this->m_ToolManager);
    delete(this->m_Button);
}

void cEventManager::Process() {
	while (const std::optional event = this->m_Window->pollEvent()) {
        this->ProcessEvent(event);
	}

    this->ProcessRealtime();
}

void cEventManager::ProcessEvent(const std::optional<sf::Event> _event) {
    // Close Event
    if (_event->is<sf::Event::Closed>()) {
        this->m_Window->close();
    }

    // Mouse Button Pressed Event
    if (const auto* mousePressed = _event->getIf<sf::Event::MouseButtonPressed>()) {
        if (mousePressed->button == sf::Mouse::Button::Left) {
            this->m_ToolManager->UseTool(false, false);
        }
    }

    // Mouse Button Released Event
    if (const auto* mouseReleased = _event->getIf<sf::Event::MouseButtonReleased>()) {
        if (mouseReleased->button == sf::Mouse::Button::Left) {
            this->m_ToolManager->UseTool(false, true);
        }
    }
}

void cEventManager::ProcessRealtime() {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        this->m_ToolManager->UseTool(true, false);
    }

    this->m_Window->clear();
    this->m_ToolManager->Draw();
    this->m_Window->draw(this->m_Button->m_ButtonShape);
    this->m_Window->display();
}
