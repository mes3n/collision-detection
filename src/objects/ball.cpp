#include "ball.hpp"

#include <time.h>

#include <iostream>
#include <random>

Ball::Ball(const std::shared_ptr<Grid<Ball>> &grid_ptr, const size_t i)
    : CircleEntity(sf::Color::Green), id(i) {
    m_grid_ptr = grid_ptr;

    m_radius = 2.5f;
    m_position = Vec2(
        100.0f * (static_cast<float>(rand()) / static_cast<float>(RAND_MAX)),
        100.0f * (static_cast<float>(rand()) / static_cast<float>(RAND_MAX)));
    // m_velocity = Vec2(30.0f, 1.5f);
    m_velocity = Vec2(-0.05f + 0.1f * (static_cast<float>(rand()) / static_cast<float>(RAND_MAX)), 0.0f);

    m_grid_pos = m_position.getIntPair(grid_ptr->getShape());
    grid_ptr->getTile(m_grid_pos)->addChild(id);

    setEntRadius(m_radius);
    updateEntPosition(m_position);
}

Ball::Ball() : id(-1){};

// Ball::Ball(const Ball &ball)
//     : CircleEntity(ball), id(ball.id) {
//     m_grid_ptr = ball.m_grid_ptr;
//     m_radius = ball.m_radius;
//     m_position = ball.m_position;
//     m_velocity = ball.m_velocity;
// }

// Ball::Ball(const Ball *ball)
//     : CircleEntity(*ball), id(ball->id) {
//     m_grid_ptr = ball->m_grid_ptr;
//     m_radius = ball->m_radius;
//     m_position = ball->m_position;
//     m_velocity = ball->m_velocity;
// }

bool Ball::operator==(const Ball &ball) const {
    return id == ball.id;
}

void Ball::checkCollision(const std::vector<Ball> balls_vec) {
    const auto surrounding = m_grid_ptr->get3x3Square(m_position.getIntPair(m_grid_ptr->getShape()));
    for (const auto &pos : surrounding) {
        auto children = m_grid_ptr->getTile(pos)->getChildren();
        for (size_t ball_id : children) {
            if (ball_id == id)
                continue;

            try {
                Ball ball = balls_vec.at(ball_id);

                // std::cout << "---- ---- ----" << std::endl;
                // std::cout << id << ": " << m_position.x << ", " << m_position.y << std::endl;
                // std::cout << ball_id << ": " << ball.getPosition().x << ", " << ball.getPosition().y << std::endl;
                // std::cout << m_position.distanceTo(ball.getPosition()) << std::endl;

                Vec2 delta = m_position - ball.getPosition();
                if (delta.length() < m_radius + ball.getRadius()) {
                    Vec2 delta = m_position - ball.getPosition();
                    delta = delta.normal() * (-delta.length() + (m_radius + ball.getRadius()));

                    m_position = m_position + (delta * 0.5f);
                    ball.setPosition(ball.getPosition() - (delta * 0.5f));

                    // std::cout << id << ", " << ball.id << std::endl;

                    setColor(sf::Color::Red);
                } else {
                    // setColor(sf::Color::Green);
                }

            } catch (std::out_of_range &err) {
                std::cout << "Could not find ball with id " << ball_id << std::endl;
                continue;
            };
        }
    }
}

void Ball::fall(void) {
    m_position = m_position + m_velocity;
    // m_velocity = m_velocity + Vec2(0.0f, 0.001f);
    m_velocity = (Vec2(50.0f, 50.0f) - m_position) * 0.01f;

    if (m_position.x < 0.0f) {
        m_velocity.x = fabsf(m_velocity.x) * 0.5f;
        // m_position.x = 0.0f;
    }
    if (100.0f < m_position.x + 2 * m_radius) {
        m_velocity.x = -fabsf(m_velocity.x) * 0.5f;
        // m_position.x = 100.0f;
    }
    if (m_position.y < 0.0f) {
        m_velocity.y = fabsf(m_velocity.y) * 0.5f;
        // m_position.y = 0.0f;
    }
    if (100.0f < m_position.y + 2 * m_radius) {
        m_velocity.y = -fabsf(m_velocity.y) * 0.9f;
        // m_position.y = 100.0f;
    }
}

void Ball::update(void) {
    updateEntPosition(m_position);

    int_pair new_pos = m_position.getIntPair(m_grid_ptr->getShape());
    if (new_pos.first != m_grid_pos.first ||
        new_pos.second != m_grid_pos.second) {
        m_grid_ptr->getTile(m_grid_pos)->removeChild(id);
        m_grid_ptr->getTile(new_pos)->addChild(id);

        m_grid_pos = new_pos;
    }
}

Balls::Balls(const size_t count, const Grid<Ball> &grid) {
    std::shared_ptr<Grid<Ball>> grid_ptr = std::make_shared<Grid<Ball>>(grid);

    srand(time(0));
    for (size_t i = 0; i < count; i++) {
        m_balls.push_back(Ball(grid_ptr, i));
    }
}

void Balls::updatePosition(void) {
    for (auto &ball : m_balls) {
        ball.fall();
        ball.update();
    }
    for (auto &ball : m_balls) {
        ball.checkCollision(m_balls);
    }
}
