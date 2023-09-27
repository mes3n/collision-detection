# "Optimized" Collision Detection Engine in C++
A small attempt at optimizing c++ collision detection with more c++ type code in order to use for other projects dependent on collision detection. 

## Purpose
The main purpose is to be used within other projects such as my ant simulation. Apart from that this project has also served as practice on how to work with more c++ type code and more optimal solutions.

## How It Works
The optimization is based in a standard world grid layout where all entities are placed into tiles in order to only check the tiles surrounding the objects root tile and as such reduce the time complexity of the typical $O(n^2)$. The engine also utilizes more optimal containers such as hash maps.
