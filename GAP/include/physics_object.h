#pragma once
#include "physics_aabb.h"
#include "physics_math.h"

struct PhysicsObjectAABB{
	PhysicsVector Position;
	PhysicsVector Velocity;
	float Mass;
	float InvMass;
	float Restitution;
};

struct PhysicsObjectCircle{
	PhysicsVector Position;
	PhysicsVector Velocity;
	float Mass;
	float InvMass;
	float Restitution;
};

void AABBInitObject(PhysicsObjectAABB A);
PhysicsVector objectGetVelocity(PhysicsVector A, PhysicsVector B);
void AABBResolveCollision(PhysicsObjectAABB A, PhysicsObjectAABB B);