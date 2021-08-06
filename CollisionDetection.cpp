#include "CollisionDetection.h"

bool CollisionDetection::DetectCollision(SDL_Rect Rect, SDL_Rect Rect2)
{
	if (Rect.x < Rect2.x + Rect2.w &&
		Rect.x + Rect.w > Rect2.x &&
		Rect.y < Rect2.y + Rect2.h &&
		Rect.y + Rect.h > Rect2.y)
	{
		return true;
	}

	return false;
}

bool CollisionDetection::DetectCollision(Vector2 Position, SDL_Rect Rect2)
{
	if (Position.X < Rect2.x + Rect2.w &&
		Position.X > Rect2.x &&
		Position.Y < Rect2.y + Rect2.h &&
		Position.Y > Rect2.y)
	{
		return true;
	}

	return false;
}

bool CollisionDetection::DetectCollision(Vector2 Position1, Vector2 Position2)
{
	if(Position1.X == Position2.X && Position1.X && Position2.Y)
	{
		return true;
	}

	return false;
}
