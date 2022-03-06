#pragma once
#include "physics_math.h"

struct AABB{
  PhysicsVector Min;
  PhysicsVector Max;
};

struct Circle{
  float Radius;
  PhysicsVector Position;
};

bool AABBCollision(AABB A, AABB B);
bool CircleCollisionUnoptimized(Circle A, Circle B);
bool CircleCollision(Circle A, Circle B);