// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#pragma once
#include <vector>
#include "SDL.h"
#include "SDL_image.h"
#include "Vector2.h"

class BeastGui
{
public:
	int Init();
	void Load();
	void DrawRect(SDL_Rect* Rect, SDL_Colour Colour);
	void DrawRects(const SDL_Rect* Rects, int Count, SDL_Colour Colour);
	void DrawLine(float XPos1, float XPos2, float YPos1, float YPos2, SDL_Colour Colour);
	void DrawLines(SDL_Point* Points, int Count, SDL_Colour Colour);
	void FillRect(SDL_Rect* Rect, SDL_Colour Colour);
	void FillRects(const SDL_Rect* Rects, int Count, SDL_Colour Colour);
	void Events();
	void Update();
	void Draw();
	void Clean();

private:
	int WindowWidth = 1080;
	int WindowHeight = 720;
	SDL_Rect GuiPosition = { 0, 0, 0, 0 };
};
