#ifndef _GRID_HPP_
#define _GRID_HPP_

#include <raylib.h>
#include <vector>

class Grid {
private:
    int rows{};
    int columns{};
    int cellSize{};
    std::vector<std::vector<int>> cells{};

    bool is_within_bounds(int row, int column);

public:
    Grid(int width, int height, int cellSize);

    void Draw();
    void set_value(int row, int column, int value);
    int get_value(int row, int column);
    int get_rows() { return rows; }
    int get_columns() { return columns; }
    void fill_random();
};

#endif
