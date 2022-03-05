#include <algorithm.h>
#include <math.h>

struct PhysicsVector{
	float x;
	float y;
}

float vectorLength(PhysicsVector vec){
    return sqrt(vec.x * vec.x + vec.y * vec.y)
}

float vectorSqrLength(PhysicsVector vec){
    return vec.x * vec.x + vec.y * vec.y
}
