// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#pragma once
#include "Init.h"

class TextureManager
{
public:
	static int Init();
	static SDL_Texture* Load(const char* File);
	static void Draw(SDL_Texture* Texture, SDL_Rect* SrcRect, SDL_Rect* DstRect, int Angle = 0, SDL_RendererFlip Flip = SDL_FLIP_NONE);
};