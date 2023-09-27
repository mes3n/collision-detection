#ifndef BALL_HPP
#define BALL_HPP

#include <memory>

#include "../graphics/entity.hpp"
#include "../grid/grid.hpp"
#include "vec2.hpp"

typedef unsigned long size_t;

class Ball : public CircleEntity {
  private:
    std::shared_ptr<Grid<Ball>> m_grid_ptr;
    int_pair m_grid_pos;

    float m_radius;

    Vec2 m_position;
    Vec2 m_velocity;

  public:
    const size_t id;

    Ball();
    Ball(const std::shared_ptr<Grid<Ball>> &grid_ptr, const size_t i);
    // Ball(const Ball &ball);

    bool operator==(const Ball &ball) const;

    float getRadius(void) const { return m_radius; }
    Vec2 getPosition(void) const { return m_position; }
    void setPosition(const Vec2 &v) { m_position = v; }

    void checkCollision(const std::vector<Ball> balls_vec);
    void fall(void);

    void update(void);
};

class Balls {
  private:
    std::vector<Ball> m_balls;

  public:
    Balls(const size_t count, const Grid<Ball> &grid);

    std::vector<Ball> getBalls(void) const { return m_balls; }

    void updatePosition(void);
};

#endif  // BALL_HPP
