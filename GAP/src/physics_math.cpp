#pragma once
#include "physics_math.h"

float vectorLength(PhysicsVector Vec){
    return sqrt(Vec.X * Vec.X + Vec.Y * Vec.Y);
}

float vectorDistance(PhysicsVector A, PhysicsVector B){
  	return sqrt((A.X - B.X) * (A.X - B.X) + (A.Y - B.Y) * (A.Y - B.Y));
}

float vectorSqrLength(PhysicsVector Vec){
    return Vec.X * Vec.X + Vec.Y * Vec.Y;
}

PhysicsVector vectorNormalized(PhysicsVector Vec){
    return Vec * (1.0f / vectorLength(Vec));
}

PhysicsVector vectorScalarMultiplication(PhysicsVector Vec, float Scalar){
    return Vec * Scalar;
}

float vectorDotProduct(PhysicsVector Vec1, PhysicsVector Vec2){
    return Vec1.X * Vec2.X + Vec1.Y * Vec2.Y;
}

float vectorCross(PhysicsVector Vec1, PhysicsVector Vec2){
    return Vec1.X * Vec2.Y - Vec1.Y * Vec2.X;
}

PhysicsVector vectorCross(PhysicsVector Vec, float S){
    return PhysicsVector{S * Vec.Y, (- S) * Vec.X};
}

PhysicsVector vectorCross(float S, PhysicsVector Vec){
    return PhysicsVector{(- S) * Vec.Y, S * Vec.X};
}