#include "raylib.h"
#include "physics_math.h"
#include "utils.h"
#include "entity.h"
#include <vector>

struct ComponentColor{
    Color color;
};

struct TransformButNotRaylib{
    Vector2 position;
    Vector2 scale;

    void step(){
        if (IsKeyDown(KEY_D))
            position.x += 20 * GetFrameTime();
        DrawRectangleV(position, scale, RED);
    }
};

int main(){
    InitWindow(1280, 720, "GAP");
    //SetTargetFPS(144);
    
    //Entity entities[5000];
    
    /*ECS ecs;
    for (std::size_t i = 0; i < 5000; i++){
        Entity entity = ecs.createEntity();
        ecs.addComponent<TransformButNotRaylib>(entity, {{200,200}, {50.f, 50.f}});
        ecs.addComponent<ComponentColor>(entity, {BLUE});
        entities[i] = entity;
    }*/
    
    while (!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(BLACK);
        /*for (auto& entity : entities){
            TransformButNotRaylib& transform = ecs.getComponent<TransformButNotRaylib>(entity);
            auto const& color = ecs.getComponent<ComponentColor>(entity);
            transform.step();
        }*/
        DrawFPS(20, 20);
        EndDrawing();
    }
}
