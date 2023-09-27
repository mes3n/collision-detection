#include "grid.hpp"

#include "../objects/ball.hpp"

#include <iostream>

template <>
Grid<Ball>::Grid(const int_pair &shape) {
    for (int y = 0; y < shape.second; y++) {
        for (int x = 0; x < shape.first; x++) {
            m_tiles[std::make_pair(x, y)] = std::make_shared<Tile<Ball>>(Tile<Ball>());
        }
    }
    m_shape = shape;
}

template <>
std::vector<int_pair> Grid<Ball>::get3x3Square(const int_pair &pos) const {
    const std::array<int_pair, 9> pairs = {
        std::make_pair(pos.first - 1, pos.second + 1),
        std::make_pair(pos.first, pos.second + 1),
        std::make_pair(pos.first + 1, pos.second + 1),
        std::make_pair(pos.first - 1, pos.second),
        std::make_pair(pos.first, pos.second),
        std::make_pair(pos.first + 1, pos.second),
        std::make_pair(pos.first - 1, pos.second - 1),
        std::make_pair(pos.first, pos.second - 1),
        std::make_pair(pos.first + 1, pos.second - 1),
    };
    std::vector<int_pair> result;
    for (const auto &pair : pairs) {
        if ((0 <= pair.first) && (pair.first < m_shape.first) && (0 <= pair.second) && (pair.second < m_shape.second))
            result.push_back(pair);
    }
    return result;
}

template <>
std::shared_ptr<Tile<Ball>> Grid<Ball>::getTile(const int_pair &pos) {
    try {
        return m_tiles.at(pos);
    } catch (std::out_of_range &err) {
        std::cout << pos.first << ", " << pos.second << std::endl;
        throw err;
    }
}

template <>
int_pair Grid<Ball>::getShape(void) const {
    return m_shape;
}
