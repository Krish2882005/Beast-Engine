#pragma once
#include "SDL_rect.h"
#include "Vector2.h"

class CollisionDetection
{
	public:
		static bool DetectCollision(SDL_Rect Rect, SDL_Rect Rect2);
		static bool DetectCollision(Vector2 Position, SDL_Rect Rect2);
		static bool DetectCollision(Vector2 Position1, Vector2 Position2);
	private:

};

