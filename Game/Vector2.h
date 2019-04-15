#pragma once
#include <math.h>

class Vector2
{ 
public:
	Vector2() 
	{ 
		x = 0.0f; y = 0.0f;
	}

	Vector2(double _x, double _y) 
	{
		x = _x; y = _y; 
	}

	// Returns the distance between the two vectors
	static double Distance(Vector2 a, Vector2 b) { return sqrt(((a.x - a.y) * (a.x - a.y)) + ((b.x - b.y) * (b.x - b.y))); } 
	
	// Returns the length of the vector
	static double Magnitude(Vector2 a) { return sqrt((a.x*a.x) + (a.y*a.y)); }

	// Normalize the vector
	static Vector2 Normalize(Vector2 a) { auto mag = Magnitude(a); Vector2 v = { a.x / mag, a.y / mag }; return v; } 
	
	double x, y;
};
