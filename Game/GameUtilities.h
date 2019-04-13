#pragma once
#include <math.h>

constexpr double PI = 3.1415926;
struct Vector { Vector() { x = 0.0f; y = 0.0f; }; double x = 0.0f, y = 0.0f; };
struct Vector2 : Vector { Vector2() { x = 0.0f; y = 0.0f; } Vector2(double _x, double _y) { x = _x; y = _y; } };
struct Vector3 : Vector { double z = 0.0f; Vector3() { x = 0.0f; y = 0.0f; z = 0.0f; } Vector3(double _x, double _y, double _z) { x = _x; y = _y; z = _z; } };

static double Distance(Vector2 a, Vector2 b) { return sqrt(((a.x - a.y) * (a.x - a.y)) + ((b.x - b.y) * (b.x - b.y))); } // Returns the distance between the two vectors

// static double Direction() { return 0; }

// static Vector2 Dot(Vector2 a, Vector2 b) { Vector2 v = { (a.x * b.x) } return v; }

static double Magnitude(Vector2 a) { return sqrt((a.x*a.x) + (a.y*a.y)); } // Returns the length of the vector

static Vector2 Normalize(Vector2 a) { auto mag = Magnitude(a); Vector2 v = { a.x / mag, a.y / mag }; return v; } // Normalize the vector
