#include "window.hpp"

#include <SFML/Window/ContextSettings.hpp>
#include <SFML/Window/Event.hpp>

Window::Window(const std::pair<int, int> &dims, const std::string &title)
    : sf::RenderWindow(sf::VideoMode(dims.first, dims.second), title, sf::Style::Default, sf::ContextSettings(0, 0, 8, 3, 3)) {
    m_dimensions = dims;
    setFramerateLimit(60);
}

void Window::pollEvents(void) {
    sf::Event event;

    while (this->pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                this->close();
                break;
            case sf::Event::KeyPressed:
                switch (event.key.code) {
                    case sf::Keyboard::Escape:
                    case sf::Keyboard::Q:
                        this->close();
                        break;

                    default:
                        break;
                }
            default:
                break;
        }
    }
}

void Window::update(const Balls &balls) {
    this->clear(sf::Color(64, 64, 96));

    for (const auto &ball : balls.getBalls()) {
        this->draw(ball);
    }

    this->display();
}