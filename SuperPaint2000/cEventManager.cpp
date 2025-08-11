#include "cEventManager.h"

cEventManager::cEventManager(cWindowManager* _window) {
    this->m_Window = _window;
    this->m_ToolManager = new cToolManager(this->m_Window);
    this->m_ButtonManager = new cButtonManager(this->m_ToolManager, this->m_Window);
}

cEventManager::~cEventManager() {
	delete(this->m_Window);
    delete(this->m_ToolManager);
    delete(this->m_ButtonManager);
}

void cEventManager::Process() {
    // Main Window Events
	while (const std::optional eventMain = this->m_Window->pollEvent()) {
        if (this->m_Window->hasFocus()) {
            this->ProcessEventMain(eventMain);
        }
	}

    // Tool Window Events
    while (const std::optional eventTool = this->m_Window->m_ToolWindow.pollEvent()) {
        this->ProcessEventTool(eventTool);
    }

    this->ProcessRealtime();
}

void cEventManager::ProcessEventMain(const std::optional<sf::Event> _event) {
    // Close Event
    if (_event->is<sf::Event::Closed>()) {
        this->m_Window->close();
    }

    // Mouse Button Pressed Event
    if (const auto* mousePressed = _event->getIf<sf::Event::MouseButtonPressed>()) {
        if (mousePressed->button == sf::Mouse::Button::Left) {
            this->m_ToolManager->GetSelectedTool()->UseToolOnce();
        }
    }

    // Mouse Button Released Event
    if (const auto* mouseReleased = _event->getIf<sf::Event::MouseButtonReleased>()) {
        if (mouseReleased->button == sf::Mouse::Button::Left) {
            this->m_ToolManager->GetSelectedTool()->UseToolEnd();
        }
    }
}

void cEventManager::ProcessEventTool(const std::optional<sf::Event> _event) {
    // Mouse Button Pressed Event
    if (const auto* mousePressed = _event->getIf<sf::Event::MouseButtonPressed>()) {
        if (mousePressed->button == sf::Mouse::Button::Left) {
            this->m_ButtonManager->ClickButton(sf::Mouse::getPosition(this->m_Window->m_ToolWindow));
        }
    }
}

void cEventManager::ProcessRealtime() {
    // Button Hovering
    if (this->m_ButtonManager->HasButton(sf::Mouse::getPosition(this->m_Window->m_ToolWindow))) {
        this->m_ButtonManager->HoverButton(sf::Mouse::getPosition(this->m_Window->m_ToolWindow));
    }
    else { // Remove Hovers
        this->m_ButtonManager->RemoveHovers();
    }

    // Drawing
    if (this->m_Window->hasFocus()) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            this->m_ToolManager->GetSelectedTool()->UseToolRealtime();
        }
    }

    // Main Window Drawing
    this->m_Window->clear();
    this->m_ToolManager->GetSelectedTool()->Draw();
    this->m_Window->display();

    // Tool Window Drawing
    this->m_Window->m_ToolWindow.clear(sf::Color(60, 60, 60, 200));
    this->m_ButtonManager->DrawButtons();
    this->m_Window->m_ToolWindow.display();
}
