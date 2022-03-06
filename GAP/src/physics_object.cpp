#pragma once
#include "physics_object.h"

PhysicsVector objectGetVelocity(PhysicsVector A, PhysicsVector B){
	return B - A;
}

void AABBInitObject(PhysicsObjectAABB A){
	if(A.Mass == 0)
  		A.InvMass = 0;
	else
  		A.InvMass = 1 / A.Mass;
}
void AABBResolveCollision(PhysicsObjectAABB A, PhysicsObjectAABB B){
	PhysicsVector Normal = PhysicsVector{1,1};
  	PhysicsVector RV = B.Velocity - A.Velocity;
  	float VelAlongNormal = vectorDotProduct(RV, Normal);
  	if(VelAlongNormal > 0)
  	  	return;
  	float E = std::min(A.Restitution, B.Restitution);
  	float J = (-(1 + E)) * VelAlongNormal;
  	J /= 1 / A.Mass + 1 / B.Mass;
  	PhysicsVector Impulse = J * Normal;
  	A.Velocity = A.Velocity - 1 / A.Mass * Impulse;
  	B.Velocity = B.Velocity + 1 / B.Mass * Impulse;
}

/*void AABBPositionalCorrection(PhysicsObjectAABB A, PhysicsObjectAABB B){
  	const float Percent = 0.2; // usually 20% to 80%
  	const float slop = 0.01; // usually 0.01 to 0.1
  	Vec2 correction = max( penetration - k_slop, 0.0f ) / (A.inv_mass + B.inv_mass)) * percent * n;
  	A.position = A.position - A.InvMass * Correction;
  	B.position = B.position + B.InvMass * Correction;
}*/