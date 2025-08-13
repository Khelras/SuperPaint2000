#include "cEventManager.h"

cEventManager::cEventManager(cWindowManager* _window) {
    this->m_Window = _window;
    this->m_MainWindowPosition = _window->getPosition();
    this->m_ToolWindowPosition = _window->m_ToolWindow.getPosition();
    this->m_ToolManager = new cToolManager(this->m_Window);
    this->m_ButtonManager = new cButtonManager(this->m_Window, this->m_ToolManager);
    this->m_ColorPickerManager = new cColorPickerManager(this->m_Window, this->m_ToolManager);
    this->m_ColorPickerWindow = nullptr;
}

cEventManager::~cEventManager() {
    delete(this->m_ToolManager);
    delete(this->m_ButtonManager);
    delete(this->m_ColorPickerManager);
}

// Event Processing
void cEventManager::Process() {
    // If a Color Picker Window is NOT open
    if (this->m_Window->IsColorPickerOpen() == false) {
        this->m_ColorPickerWindow = nullptr; // Meaning no Color Picker Window is Open

        // Applies NEW Color If True
        if (this->m_Window->ShouldApplyColor == true) {
            this->m_ColorPickerManager->ConfirmNewColors();
            this->m_ToolManager->SetFillColor(this->m_ColorPickerManager->GetSelectedFillColor());
            this->m_ToolManager->SetOutlineColor(this->m_ColorPickerManager->GetSelectedOutlineColor());
        }
        // Cancels NEW Color If True
        else {
            this->m_ColorPickerManager->CancelNewColors();
        }
        

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
    }
    // Else a Color Picker Window IS open
    else {
        // Sets Color Picker Window Variable
        if (this->m_Window->m_ColorPickerFGWindow.isOpen() == true) { // Foreground Window
            this->m_ColorPickerWindow = &(this->m_Window->m_ColorPickerFGWindow);
        }
        else if (this->m_Window->m_ColorPickerBGWindow.isOpen() == true) { // Background Window
            this->m_ColorPickerWindow = &(this->m_Window->m_ColorPickerBGWindow);
        }

        // Color Picker Window Events
        while (const std::optional eventColorPicker = this->m_ColorPickerWindow->pollEvent()) {
            this->ProcessEventColorPicker(eventColorPicker);
        }
    }

    // Realtime Processing Section
    this->ProcessRealtime();
}

// Main Window Events
void cEventManager::ProcessEventMain(const std::optional<sf::Event> _event) {
    // Close Event
    if (_event->is<sf::Event::Closed>()) {
        this->m_Window->close();
    }

    // Resize Main Window Event
    if (_event->is<sf::Event::Resized>()) {
        this->m_Window->ResizeViewToWindow();
    }

    // Mouse Button Pressed Event
    if (const auto* mousePressed = _event->getIf<sf::Event::MouseButtonPressed>()) {
        // Left Mouse Button
        if (mousePressed->button == sf::Mouse::Button::Left) {
            this->m_ToolManager->GetSelectedTool()->UseToolOnce();
        }

        // Right Mouse Button
        if (mousePressed->button == sf::Mouse::Button::Right) {
            if (this->m_ToolManager->GetSelectedToolEnum() == Tools::TOOL_POLYGON) {
                this->m_ToolManager->GetSelectedTool()->UseToolEnd();
            }
        }
    }

    // Mouse Button Released Event
    if (const auto* mouseReleased = _event->getIf<sf::Event::MouseButtonReleased>()) {
        // Left Mouse Button
        if (mouseReleased->button == sf::Mouse::Button::Left) {
            if (this->m_ToolManager->GetSelectedToolEnum() != Tools::TOOL_POLYGON) {
                this->m_ToolManager->GetSelectedTool()->UseToolEnd();
            }
        }
    }
}

// Tool Window Events
void cEventManager::ProcessEventTool(const std::optional<sf::Event> _event) {
    // Mouse Button Pressed Event
    if (const auto* mousePressed = _event->getIf<sf::Event::MouseButtonPressed>()) {
        if (mousePressed->button == sf::Mouse::Button::Left) {
            // If a Button Exists at Mouse Position
            if (this->m_ButtonManager->GetButton(sf::Mouse::getPosition(this->m_Window->m_ToolWindow)) != nullptr) {
                this->m_ButtonManager->ClickButton(sf::Mouse::getPosition(this->m_Window->m_ToolWindow));
            }
        }
    }
}

void cEventManager::ProcessEventColorPicker(const std::optional<sf::Event> _event) {
    // Ensures a Color Picker Window has been selected
    if (this->m_ColorPickerWindow != nullptr) {
        // Mouse Button Pressed Event
        if (const auto* mousePressed = _event->getIf<sf::Event::MouseButtonPressed>()) {
            // Left Mouse Button
            if (mousePressed->button == sf::Mouse::Button::Left) {
                // If a Button Exists at Mouse Position
                if (this->m_ColorPickerManager->GetButton(sf::Mouse::getPosition(*(this->m_ColorPickerWindow))) != nullptr) {
                    this->m_ColorPickerManager->ClickButton(sf::Mouse::getPosition(*(this->m_ColorPickerWindow)));
                }
                // Else attempt to Pick Color
                else {
                    // Color Buttons
                    if (this->m_ColorPickerManager->GetButtonColor(sf::Mouse::getPosition(*(this->m_ColorPickerWindow))) != nullptr) {
                        this->m_ColorPickerManager->ClickButtonColor(sf::Mouse::getPosition(*(this->m_ColorPickerWindow)));
                    }
                    this->m_ColorPickerManager->PickColor();
                }
            }
        }
    }
}

// Realtime Processing
void cEventManager::ProcessRealtime() {
    // When Main Window is Moved
    if (this->m_Window->getPosition() != this->m_MainWindowPosition) {
        this->m_MainWindowPosition = this->m_Window->getPosition(); // Sets new Position
        this->m_Window->AutoMoveToolWindow(); // Auto Moves the Tool Window
    }

    // When Tool Window is Moved
    if (this->m_Window->m_ToolWindow.getPosition() != this->m_ToolWindowPosition) {
        this->m_ToolWindowPosition = this->m_Window->m_ToolWindow.getPosition(); // Sets new Position
        this->m_Window->AutoMoveToolWindow(); // Auto Moves the Tool Window
    }

    // If a Color Picker Window is Open
    if (this->m_ColorPickerWindow != nullptr) {
        // Button Hovering
        if (this->m_ColorPickerManager->GetButton(sf::Mouse::getPosition(*(this->m_ColorPickerWindow))) != nullptr) {
            this->m_ColorPickerManager->HoverButton(sf::Mouse::getPosition(*(this->m_ColorPickerWindow)));
        } 
        else if (this->m_ColorPickerManager->GetButtonColor(sf::Mouse::getPosition(*(this->m_ColorPickerWindow))) != nullptr) {
            this->m_ColorPickerManager->HoverButtonColor(sf::Mouse::getPosition(*(this->m_ColorPickerWindow)));
        }
        else { // Remove Hovers
            this->m_ColorPickerManager->RemoveHovers();
        }

        // Color Picker Window Drawing
        this->m_ColorPickerWindow->clear(sf::Color(120, 120, 120, 200));
        this->m_ColorPickerManager->DrawButtons(this->m_ColorPickerWindow);
        this->m_ColorPickerWindow->display();
    }
    // If NO Color Picker Window is Open
    else {
        // Button Hovering
        if (this->m_ButtonManager->GetButton(sf::Mouse::getPosition(this->m_Window->m_ToolWindow)) != nullptr) {
            this->m_ButtonManager->HoverButton(sf::Mouse::getPosition(this->m_Window->m_ToolWindow));
        }
        else { // Remove Hovers
            this->m_ButtonManager->RemoveHovers();
        }

        // Drawing (Tool)
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
        this->m_Window->m_ToolWindow.clear(sf::Color(90, 90, 90, 200));
        this->m_ButtonManager->DrawButtons();
        this->m_Window->m_ToolWindow.display();
    }
}
