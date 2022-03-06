#pragma once
#include "physics_aabb.h"

bool AABBCollision(AABB A, AABB B){
  	if(A.Max.X < B.Min.X or A.Min.X > B.Max.X)
  		return false;
  	if(A.Max.Y < B.Min.Y or A.Min.Y > B.Max.Y)
  		return false;
  	return true;
}

bool CircleCollisionUnoptimized(Circle A, Circle B){
  	float r = A.Radius + B.Radius;
  	return r < vectorDistance(A.Position, B.Position);
}
 
bool CircleCollision(Circle A, Circle B){
  	float r = A.Radius + B.Radius;
  	r *= r;
  	return r < ((A.Position.X + B.Position.X) * (A.Position.X + B.Position.X) + (A.Position.Y + B.Position.Y) * (A.Position.Y + B.Position.Y));
}

/*void ResolveCollision( Object A, Object B )
{
  // Calculate relative velocity
  Vec2 rv = B.velocity - A.velocity
 
  // Calculate relative velocity in terms of the normal direction
  float velAlongNormal = DotProduct( rv, normal )
 
  // Do not resolve if velocities are separating
  if(velAlongNormal > 0)
    return;
 
  // Calculate restitution
  float e = min( A.restitution, B.restitution)
 
  // Calculate impulse scalar
  float j = -(1 + e) * velAlongNormal
  j /= 1 / A.mass + 1 / B.mass
 
  // Apply impulse
  Vec2 impulse = j * normal
  A.velocity -= 1 / A.mass * impulse
  B.velocity += 1 / B.mass * impulse
}*/