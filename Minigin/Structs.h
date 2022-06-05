#pragma once
struct Vec2 {
	float x, y;
};

struct Rect
{
	float x, y, width, height;
};

struct Bounds
{
	Vec2 topLeft,
		bottomRight;
};