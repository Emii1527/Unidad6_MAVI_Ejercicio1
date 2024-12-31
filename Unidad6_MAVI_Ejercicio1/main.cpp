#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Unidad6_MAVI_Ejercicio1");
    sf::CircleShape circle(30.f);
    circle.setFillColor(sf::Color::Green);

    // Vectores para posición y velocidad inicial
    sf::Vector2f position(0.f, window.getSize().y / 2.f - circle.getRadius());
    sf::Vector2f velocity(100.f, 0.f); // Velocidad inicial (x, y)

    // Incremento de velocidad al salir de pantalla
    const sf::Vector2f increment(50.f, 0.f);
    const float deltaTime = 0.01f;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Actualizar posición
        position += velocity * deltaTime;

        // Verificar si el círculo sale por el lado derecho
        if (position.x > window.getSize().x) {
            position.x = -circle.getRadius() * 2.f;
            velocity += increment; // Incrementa la velocidad
        }

        // Dibujar
        circle.setPosition(position);
        window.clear(sf::Color::Black);
        window.draw(circle);
        window.display();
    }

    return 0;
}