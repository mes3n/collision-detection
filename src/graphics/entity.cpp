#include "entity.hpp"

#include <SFML/System/Vector2.hpp>

#include "window.hpp"

CircleEntity::CircleEntity() {}

CircleEntity::CircleEntity(const sf::Color &color) {
    m_shape.setFillColor(color);
}

// CircleEntity::CircleEntity(const CircleEntity &circleEntity) {
//     m_shape = circleEntity.m_shape;
// }

void CircleEntity::setEntRadius(const float radius) {
    m_shape.setRadius((radius / 100.0f) * 800);
}

void CircleEntity::updateEntPosition(const Vec2 &pos) {
    m_shape.setPosition(sf::Vector2f((pos.getX() / 100.0f) * 800, (pos.getY() / 100.0f) * 800));
}

void CircleEntity::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(m_shape, states);
}
