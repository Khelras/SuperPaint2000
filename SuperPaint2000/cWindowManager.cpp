#include "cWindowManager.h"
#include "cEventManager.h"

cWindowManager::cWindowManager(sf::VideoMode _mode, std::string _name) {
	this->create(_mode, _name);
    this->setFramerateLimit(60);

    // Tool Window + Auto Moves to the Right of Main Window
    this->m_ToolWindowSize = sf::Vector2u(100, 700);
    this->m_ToolWindow.create(sf::VideoMode(this->m_ToolWindowSize), "Super Tools 2000!");
    this->AutoMoveToolWindow();
    this->m_ToolWindow.setFramerateLimit(60);
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
