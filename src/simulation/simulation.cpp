#include "simulation.hpp"
#include <cstdio>

Simulation::Simulation(int width, int height, int cellSize)
    : grid(width, height, cellSize), tempGrid(width, height, cellSize) {
        // grid.fill_random();
    }

void Simulation::Draw() {
    grid.Draw();
}

void Simulation::set_cell_value(int row, int column, int value) {
    grid.set_value(row, column, value);
}

int Simulation::count_live_neighbors(int row, int column) {
    int liveNeighbors{0};
    std::vector<std::pair<int, int>> neighborOffsets = {
        {-1 , 0},
        { 1 , 0},
        { 0 ,-1},
        { 0 , 1},
        {-1 ,-1},
        {-1 , 1},
        { 1 ,-1},
        { 1 , 1},
    };

    for(const auto& offset : neighborOffsets) {
        int neighborRow = row + offset.first;
        int neighborColumn = column + offset.second;
        liveNeighbors += grid.get_value(neighborRow, neighborColumn);
    }

    return liveNeighbors;
}

void Simulation::Update() {
    for(int row{}; row < grid.get_rows(); row++) {
        for(int column{}; column < grid.get_columns(); column++) {
            int liveNeighbors = count_live_neighbors(row, column);
            int cellValue = grid.get_value(row, column);

            if(cellValue == 1)
                if (liveNeighbors > 3 || liveNeighbors < 2)
                    tempGrid.set_value(row, column, 0);
                else
                    tempGrid.set_value(row, column, 1);
            else
                if(liveNeighbors == 3)
                    tempGrid.set_value(row, column, 1);
                else
                    tempGrid.set_value(row, column, 0);
        }
    }
    grid = tempGrid;
}

Grid Simulation::get_grid() {
    return grid;
}
