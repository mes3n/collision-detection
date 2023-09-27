#ifndef VEC2_HPP
#define VEC2_HPP

#include <utility>

typedef std::pair<int, int> int_pair;

class Vec2 {
  private:

  public:
    float x, y;

    Vec2();
    Vec2(const Vec2 &v);
    Vec2(const float x, const float y);

    float getX(void) const { return x; }
    float getY(void) const { return y; }

    float length(void) const;
    Vec2 normal(void) const;

    float distanceTo(const Vec2 &pos) const;

    Vec2 operator+(const Vec2 &v) const;
    Vec2 operator-(const Vec2 &v) const;
    Vec2 operator*(const float s) const;

    int_pair getIntPair(const int_pair &shape) const;
};

#endif  // VEC2_HPP
