#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Super Paint 2000!");

    // Shape Creation
    float fRadius = 50.0f;
    sf::CircleShape shape(fRadius);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        sf::Vector2 localMousePosition = sf::Mouse::getPosition(window);
        shape.setPosition(sf::Vector2f(localMousePosition.x - fRadius, localMousePosition.y - fRadius));

        window.clear();
        window.draw(shape);
        window.display();
    }
}