#ifndef GRID_HPP
#define GRID_HPP

#include <memory>
#include <unordered_map>
#include <vector>

#include "tile.hpp"

typedef std::pair<int, int> int_pair;

struct PairHash {
    size_t operator()(const int_pair &p) const {
        size_t s = std::hash<int>{}(p.first);
        return s ^ (std::hash<int>{}(p.second) + 0x9e3779b9 + (s << 6) + (s >> 2));
    }
};

template <typename TileChild>
class Grid {
  private:
    std::unordered_map<int_pair, std::shared_ptr<Tile<TileChild>>, PairHash> m_tiles;
    int_pair m_shape;

  public:
    Grid(const int_pair &shape);

    int_pair getShape(void) const;

    std::vector<int_pair> get3x3Square(const int_pair &pos) const;
    std::shared_ptr<Tile<TileChild>> getTile(const int_pair &pos);

    std::unordered_map<int_pair, std::shared_ptr<Tile<TileChild>>, PairHash> getTiles(void) const { return m_tiles; };
};

#endif  // GRID_HPP
