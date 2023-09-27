#ifndef TILE_HPP
#define TILE_HPP

#include <memory>
#include <unordered_set>

typedef unsigned long size_t;

// template <typename Child>
// struct Hash {
//     size_t operator()(const  &child) const;
// };

template <typename Child>
class Tile {
  private:
    std::unordered_set<size_t> m_children;

  public:
    Tile();

    std::unordered_set<size_t> getChildren() const;
    void removeChild(size_t child);
    void addChild(size_t child);
};

#endif  // TILE_HPP
