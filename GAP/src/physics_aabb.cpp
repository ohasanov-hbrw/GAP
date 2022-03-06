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
