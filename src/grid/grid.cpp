#include "grid.hpp"
#include <raylib.h>

Grid::Grid(int width, int height, int cellSize)
    : rows(height/cellSize), columns(width/cellSize), cellSize(cellSize), cells(rows, std::vector<int>(columns, 0)) { }

void Grid::Draw() {
    for(int row{0}; row < rows; row++) {
        for (int collum{0}; collum < columns; collum++) {
            Color color = cells[row][collum] ? Color{200, 171, 255, 255} : Color{55, 55, 55, 255};
            // DrawRectangle(collum * cellSize + 1, row * cellSize + 1, cellSize-2, cellSize-2, color);
            DrawRectangle(collum * cellSize, row * cellSize, cellSize-1, cellSize-1, color);
        }
    }
}

void Grid::set_value(int row, int column, int value) {
    if(is_within_bounds(row, column)) {
        cells[row][column] = value;
    }
}

int Grid::get_value(int row, int column) {
    if(is_within_bounds(row, column))
        return cells[row][column];
    return 0;
}

bool Grid::is_within_bounds(int row, int column) {
    if(row >= 0 && row < rows && column >= 0 && column < columns)
        return true;
    return false;
}

void Grid::fill_random() {
    for(int row{}; row < rows; row++) {
        for(int column{}; column < columns; column++) {
            int randomValue = GetRandomValue(0, 4);
            cells[row][column] = (randomValue == 4) ? 1 : 0;
        }
    }
}
