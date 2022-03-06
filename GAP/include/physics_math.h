#pragma once
#include <algorithm>
#include <math.h>

struct PhysicsVector{
	float X;
	float Y;
};

inline PhysicsVector operator * (PhysicsVector Vec1, PhysicsVector Vec2){
	return PhysicsVector{Vec1.X * Vec2.X, Vec1.Y * Vec2.Y};
}

inline PhysicsVector operator * (PhysicsVector Vec1, float Multiplier){
	return PhysicsVector{Vec1.X * Multiplier, Vec1.Y * Multiplier};
}

inline PhysicsVector operator * (float Multiplier, PhysicsVector Vec1){
	return PhysicsVector{Vec1.X * Multiplier, Vec1.Y * Multiplier};
}

inline PhysicsVector operator * (PhysicsVector Vec1, int Multiplier){
	return PhysicsVector{Vec1.X * Multiplier, Vec1.Y * Multiplier};
}

inline PhysicsVector operator * (int Multiplier, PhysicsVector Vec1){
	return PhysicsVector{Vec1.X * Multiplier, Vec1.Y * Multiplier};
}

inline PhysicsVector operator / (PhysicsVector Vec1, PhysicsVector Vec2){
	return PhysicsVector{Vec1.X / Vec2.X, Vec1.Y / Vec2.Y};
}

inline PhysicsVector operator / (PhysicsVector Vec1, float Divider){
	return PhysicsVector{Vec1.X / Divider, Vec1.Y / Divider};
}

inline PhysicsVector operator / (float Divider, PhysicsVector Vec1){
	return PhysicsVector{Divider / Vec1.X, Divider / Vec1.Y};
}

inline PhysicsVector operator / (PhysicsVector Vec1, int Divider){
	return PhysicsVector{Vec1.X / Divider, Vec1.Y / Divider};
}

inline PhysicsVector operator / (int Divider, PhysicsVector Vec1){
	return PhysicsVector{Divider / Vec1.X,  Divider / Vec1.Y};
}

inline PhysicsVector operator + (PhysicsVector Vec1, PhysicsVector Vec2){
	return PhysicsVector{Vec1.X + Vec2.X, Vec1.Y + Vec2.Y};
}

inline PhysicsVector operator + (PhysicsVector Vec1, float Addition){
	return PhysicsVector{Vec1.X + Addition, Vec1.Y + Addition};
}

inline PhysicsVector operator + (float Addition, PhysicsVector Vec1){
	return PhysicsVector{Vec1.X + Addition, Vec1.Y + Addition};
}

inline PhysicsVector operator + (PhysicsVector Vec1, int Addition){
	return PhysicsVector{Vec1.X + Addition, Vec1.Y + Addition};
}

inline PhysicsVector operator + (int Addition, PhysicsVector Vec1){
	return PhysicsVector{Vec1.X + Addition, Vec1.Y + Addition};
}

inline PhysicsVector operator - (PhysicsVector Vec1, PhysicsVector Vec2){
	return PhysicsVector{Vec1.X - Vec2.X, Vec1.Y - Vec2.Y};
}

inline PhysicsVector operator - (PhysicsVector Vec1, float Subtractor){
	return PhysicsVector{Vec1.X - Subtractor, Vec1.Y - Subtractor};
}

inline PhysicsVector operator - (float Subtractor, PhysicsVector Vec1){
	return PhysicsVector{Subtractor - Vec1.X, Subtractor - Vec1.Y};
}

inline PhysicsVector operator - (PhysicsVector Vec1, int Subtractor){
	return PhysicsVector{Vec1.X - Subtractor, Vec1.Y - Subtractor};
}

inline PhysicsVector operator - (int Subtractor, PhysicsVector Vec1){
	return PhysicsVector{Subtractor - Vec1.X, Subtractor - Vec1.Y};
}

float vectorLength(PhysicsVector Vec);
float vectorDistance(PhysicsVector A, PhysicsVector B);
float vectorSqrLength(PhysicsVector Vec);
PhysicsVector vectorNormalized(PhysicsVector Vec);
PhysicsVector vectorScalarMultiplication(PhysicsVector Vec, float Scalar);
float vectorDotProduct(PhysicsVector Vec1, PhysicsVector Vec2);
float vectorCross(PhysicsVector Vec1, PhysicsVector Vec2);
PhysicsVector vectorCross(PhysicsVector Vec, float S);
PhysicsVector vectorCross(float S, PhysicsVector Vec);