#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include "../objects/vec2.hpp"

class CircleEntity : public sf::Drawable {
  private:
    sf::CircleShape m_shape;

  public:
    CircleEntity();
    CircleEntity(const sf::Color &color);
    // CircleEntity(const CircleEntity &circleEntity);

    void setEntRadius(const float radius);
    void updateEntPosition(const Vec2 &pos);

    void setColor (const sf::Color color) { m_shape.setFillColor(color); }

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};

#endif  // ENTITY_HPP
