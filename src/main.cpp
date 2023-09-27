#include <iostream>

#include "graphics/window.hpp"
#include "grid/grid.hpp"
#include "objects/ball.hpp"

int main(void) {
    const auto dims = std::make_pair(800, 800);
    Window window(dims, "Collision");

    const auto gridShape = std::make_pair(40, 40);
    Grid<Ball> grid(gridShape);
    Balls balls(100, grid);

    while (window.isOpen()) {
        window.pollEvents();

        balls.updatePosition();
        
        window.update(balls);
    }

    return 0;
}