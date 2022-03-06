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