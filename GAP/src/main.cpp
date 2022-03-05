#include "raylib.h"


int main(){
    InitWindow(1280, 720, "GAP");
    SetTargetFPS(144);

    while (!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawFPS(20, 20);
        EndDrawing();
    }
}
