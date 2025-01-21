#ifndef _SIMULATION_HPP_
#define _SIMULATION_HPP_

#include "../grid/grid.hpp"

#include <vector>
#include <utility>

class Simulation {
private:
    Grid grid;
    Grid tempGrid;

public:
    Simulation(int width, int height, int cellSize);

    void Draw();
    void set_cell_value(int row, int column, int value);
    int count_live_neighbors(int row, int column);
    Grid get_grid();
    void Update();
};

#endif
