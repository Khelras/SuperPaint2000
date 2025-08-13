#include "cButtonApply.h"

cButtonApply::cButtonApply(cWindowManager* _window, cToolManager* _toolManager, sf::Vector2f _size) : cButton(_size) {
    this->m_Window = _window;
    this->m_ToolManager = _toolManager;

    // Sets Button Origin to Center
    this->m_Button.setOrigin(this->m_Button.getGlobalBounds().getCenter());

    // Text
    if (this->m_Font.openFromFile("fonts/arial.ttf") == false) printf("ERR: Unable to Load Font!\n"); // FOR DEBUGGING
    this->m_Text = new sf::Text(this->m_Font);
    this->m_Text->setString("Apply");
    this->m_Text->setFillColor(sf::Color::Black);
    this->m_Text->setOrigin(this->m_Text->getGlobalBounds().getCenter());
}

cButtonApply::~cButtonApply() {

}

void cButtonApply::DrawButton(sf::Vector2f _pos) {
    // Sets Position
    this->m_Button.setPosition(_pos);
    this->m_Text->setPosition(this->m_Button.getGlobalBounds().getCenter());

    // If Color Picker FG WIndow is Open
    if (this->m_Window->m_ColorPickerFGWindow.isOpen() == true) {
        // Draws Button
        this->m_Window->m_ColorPickerFGWindow.draw(this->m_Button);
        this->m_Window->m_ColorPickerFGWindow.draw(*(this->m_Text));
    }
    // If Color Picker BG WIndow is Open
    else if (this->m_Window->m_ColorPickerBGWindow.isOpen() == true) {
        // Draws Button
        this->m_Window->m_ColorPickerBGWindow.draw(this->m_Button);
        this->m_Window->m_ColorPickerBGWindow.draw(*(this->m_Text));
    }
}

void cButtonApply::UseButton() {
    // Applies Color
    this->m_Window->ShouldApplyColor = true;

    // If Color Picker FG WIndow is Open
    if (this->m_Window->m_ColorPickerFGWindow.isOpen() == true) {
        // Closes it and saves Color
        this->m_Window->m_ColorPickerFGWindow.close();
    }
    // If Color Picker BG WIndow is Open
    else if (this->m_Window->m_ColorPickerBGWindow.isOpen() == true) {
        // Closes it and saves Color
        this->m_Window->m_ColorPickerBGWindow.close();
    }
}

void cButtonApply::Select() {} // Removes Select() Functionality

void cButtonApply::Unselect() {} // Removes Unselect() Functionality