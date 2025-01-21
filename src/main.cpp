#include <raylib.h>

#include "simulation/simulation.hpp"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------

int main() {
    // Initialization
    //--------------------------------------------------------------------------------------
    const int width{750}, height{750};
    InitWindow(width, height, "Conway's");
    SetTargetFPS(12);
    //--------------------------------------------------------------------------------------

    Color GREY = {29, 29, 29, 255};
    const int CELL_SIZE = 25;

    Simulation simulation(width, height, CELL_SIZE);

    bool simulate = true;

    // Main game loop
    while (!WindowShouldClose()) {    // Detect window close button or ESC key
        // Event handler
        //----------------------------------------------------------------------------------
        if(IsKeyPressed(KEY_SPACE)) {
            simulate = !simulate;
        }

        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            int row = GetMouseY()/CELL_SIZE;
            int column = GetMouseX()/CELL_SIZE;
            if (simulation.get_grid().get_value(row, column) == 1) {
                simulation.set_cell_value(row, column, 0);
            }
            else {
                simulation.set_cell_value(row, column, 1);
            }
        }

        //----------------------------------------------------------------------------------

        // Update
        //----------------------------------------------------------------------------------
        if (simulate)
            simulation.Update();
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(GREY);
            if (!simulate)
                ClearBackground(DARKGRAY);
            simulation.Draw();

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
