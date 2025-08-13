#include "cWindowManager.h"
#include "cEventManager.h"

cWindowManager::cWindowManager(sf::VideoMode _mode, std::string _name) {
	this->create(_mode, _name);
    this->setFramerateLimit(60);
    this->ShouldApplyColor = false;

    // Tool Window + Auto Moves to the Right of Main Window
    this->m_ToolWindowSize = sf::Vector2u(100, 700);
    this->OpenWindow(Windows::WINDOW_TOOL);
    this->m_ToolWindow.setFramerateLimit(60);

    // Colour Picker Windows
    this->m_ColorPickerWindowSize = sf::Vector2u(306, 512);
}

cWindowManager::~cWindowManager() {
    
}

void cWindowManager::Process() {
    cEventManager* EventManager = new cEventManager(this);

    // Starts the Event Managing Process
    while (this->isOpen()) {
        EventManager->Process();
    }

    delete(EventManager);
}

void cWindowManager::OpenWindow(Windows _windowType) {
    if (_windowType == Windows::WINDOW_TOOL) {
        this->m_ToolWindow.create(sf::VideoMode(this->m_ToolWindowSize), "Super Tools 2000!", sf::Style::Titlebar);
        this->AutoMoveToolWindow();
    }
    else if (_windowType == Windows::WINDOW_COLOR_FG) {
        this->m_ColorPickerFGWindow.create(sf::VideoMode(this->m_ColorPickerWindowSize), "Super Color Picker (Foreground) 2000!", sf::Style::Titlebar);
    }
    else if (_windowType == Windows::WINDOW_COLOR_BG) {
        this->m_ColorPickerBGWindow.create(sf::VideoMode(this->m_ColorPickerWindowSize), "Super Color Picker (Background) 2000!", sf::Style::Titlebar);
    }
}

void cWindowManager::AutoMoveToolWindow() {
    this->m_ToolWindow.setPosition(sf::Vector2i(this->getPosition().x + this->getSize().x, this->getPosition().y));
}

void cWindowManager::ResizeViewToWindow() {
    sf::View newView(sf::FloatRect({ 0, 0 }, sf::Vector2f(this->getSize())));
    this->setView(newView);
    this->AutoMoveToolWindow(); // Auto Moves the Tool Window
}

void cWindowManager::PreventResizeToolWindow() {
    this->m_ToolWindow.setSize(this->m_ToolWindowSize); // Sets back to the Default Size
    sf::View newView(sf::FloatRect({ 0, 0 }, sf::Vector2f(this->m_ToolWindow.getSize())));
    this->m_ToolWindow.setView(newView);
    this->AutoMoveToolWindow(); // Auto Moves the Tool Window
    
}

void cWindowManager::ImportImage(sf::Texture _importedImageTexture, cCanvas* _canvas) {
    sf::Sprite newSprite(_importedImageTexture); // Creates a Sprite with Image Texture
    if (_canvas->GetCanvasTexture()->resize(_importedImageTexture.getSize())); // Resizes Canvas to the Image Size

    // Drawing Imported Image onto the Canvas Texture
    _canvas->Clear(); // Custom Clear Function to Include the BG Color
    _canvas->GetCanvasTexture()->draw(newSprite);

    // Drawing the new Canvas Texture WITH Imported Image onto the Canvas Shape
    _canvas->GetCanvasShape()->setSize(sf::Vector2f(_importedImageTexture.getSize()));
    _canvas->GetCanvasShape()->setTexture(&(_canvas->GetCanvasTexture()->getTexture()), true);

    // Resizes the Window to Fit the Canvas
    this->setSize(_importedImageTexture.getSize());

    // Finally Displays the Canvas Image
    _canvas->GetCanvasTexture()->display();
}

bool cWindowManager::IsColorPickerOpen() const {
    // If EITHER Color Picker is Open
    if (this->m_ColorPickerFGWindow.isOpen() || this->m_ColorPickerBGWindow.isOpen()) {
        return true; // A Color Picker Window is Open
    }
    else {
        return false;
    }
}
