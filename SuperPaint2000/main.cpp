#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow Window(sf::VideoMode({ 1200, 900 }), "Super Paint 2000!");

    sf::RectangleShape RectangleTool({ 0, 0 });
    RectangleTool.setFillColor(sf::Color::Red);
    sf::Vector2f ShapeOrigin;

    sf::RectangleShape m_CanvasShape;
    sf::RenderTexture m_CanvasTexture;

    m_CanvasShape.setSize(sf::Vector2f(Window.getSize()));
    if (m_CanvasTexture.resize(Window.getSize()));
    m_CanvasShape.setTexture(&m_CanvasTexture.getTexture());

    while (Window.isOpen()) {
        while (const std::optional event = Window.pollEvent()) {
            // Close Event
            if (event->is<sf::Event::Closed>()) {
                Window.close();
            }

            // Mouse Button Pressed Event
            if (const auto* mousePressed = event->getIf<sf::Event::MouseButtonPressed>()) {
                if (mousePressed->button == sf::Mouse::Button::Left) {
                    RectangleTool.setPosition(sf::Vector2f(sf::Mouse::getPosition(Window)));
                    ShapeOrigin = RectangleTool.getPosition();
                }
            }

            // Mouse Button Released Event
            if (const auto* mouseReleased = event->getIf<sf::Event::MouseButtonReleased>()) {
                if (mouseReleased->button == sf::Mouse::Button::Left) {
                    m_CanvasTexture.draw(RectangleTool);
                    RectangleTool.setSize(sf::Vector2f(0, 0));
                    m_CanvasTexture.display();
                }
            }
        }
        
        // -- WARNING REALTIME INPUT ZONE -- //
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            sf::Vector2f offset = sf::Vector2f(sf::Mouse::getPosition(Window)) - ShapeOrigin;

            RectangleTool.setSize(offset);
        }

        Window.clear();
        Window.draw(m_CanvasShape);
        Window.draw(RectangleTool);
        Window.display();
    }
}