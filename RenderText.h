#pragma once
#include <SDL.h>
#include <SDL_ttf.h>

class RenderText
{
	public:
		static int Init();
		static void Load();
		static SDL_Texture* CreateNewTexture(const char* Text, SDL_Rect TextRect, const char* Font, SDL_Colour textColour);
		static void Clean();
	private:
		
};
