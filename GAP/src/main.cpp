#include "raylib.h"


int main(){
    InitWindow(1080, 720, "GAP");
    SetTargetFPS(120);

    while (!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawFPS(20, 20);
        EndDrawing();
    }
}
