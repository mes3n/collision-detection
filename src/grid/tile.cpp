#include "tile.hpp"

#include "../objects/ball.hpp"


// template <>
// size_t Hash<Ball>::operator()(const Ball* ball) const {
//     return std::hash<int>{}(ball->id);
// }

template <>
Tile<Ball>::Tile() {
}

template <>
std::unordered_set<size_t> Tile<Ball>::getChildren() const {
    return m_children;
}

template <>
void Tile<Ball>::removeChild(size_t child) {
    m_children.erase(child);
}

template <>
void Tile<Ball>::addChild(size_t child) {
    m_children.insert(child);
}