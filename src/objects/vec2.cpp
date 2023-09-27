#include "vec2.hpp"

#include <cmath>

Vec2::Vec2() {
    this->x = 0.0f;
    this->y = 0.0f;
}

Vec2::Vec2(const Vec2 &v) {
    x = v.x;
    y = v.y;
}

Vec2::Vec2(const float x, const float y) {
    this->x = x;
    this->y = y;
}

float Vec2::distanceTo(const Vec2 &pos) const {
    return sqrtf(
        (x - pos.x) * (x - pos.x) + (y - pos.y) * (y - pos.y));
}

float Vec2::length(void) const {
    return sqrtf(
        x * x + y * y);
}

Vec2 Vec2::normal(void) const {
    const float l = length();
    return Vec2(
        x / l,
        y / l);
}

Vec2 Vec2::operator+(const Vec2 &v) const {
    return Vec2(
        x + v.x,
        y + v.y);
}

Vec2 Vec2::operator-(const Vec2 &v) const {
    return Vec2(
        x - v.x,
        y - v.y);
}

Vec2 Vec2::operator*(const float s) const {
    return Vec2(
        x * s,
        y * s);
}

int_pair Vec2::getIntPair(const int_pair &shape) const {
    const auto bounds = std::make_pair(100.0f, 100.0f);
    auto result = std::make_pair(
        static_cast<int>((x / bounds.first) * shape.first),
        static_cast<int>((y / bounds.second) * shape.second));
    result.first = result.first < 0 ? 0 : (result.first > shape.first - 1 ? shape.first - 1 : result.first);
    result.second = result.second < 0 ? 0 : (result.second > shape.second - 1 ? shape.second - 1 : result.second);

    return result;
}