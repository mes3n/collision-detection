#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SFML/Graphics/RenderWindow.hpp>

#include "../objects/ball.hpp"

class Window : sf::RenderWindow {
  private:
    std::pair<int, int> m_dimensions;
  public:
    Window(const std::pair<int, int> &dims, const std::string &title);

    using sf::RenderWindow::isOpen;

    void pollEvents(void);
    void update(const Balls &balls);
};

#endif  // WINDOW_HPP
