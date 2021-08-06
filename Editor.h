//This Is A Beast Engine File Which Has The License Apache 2.0

#pragma once
#include <SDL.h>
#include "Vector2.h"
#include <vector>

//struct Gui
//{
//	SDL_Rect Rect;
//	const char* GuiName;
//};

class Editor
{
	public:
		void Init();
		void Load();
		void Events();
		void Update();
		void Draw();
		void DrawOutlines();
		void DrawTextBase();
		void DrawText();
		void Clean();

		//Menu Bar
		SDL_Rect MenuBarBase = { 0, 0, 1080, 20 };

		//Hierarchy
		SDL_Rect HierarchyBase = { 0, 20, 200, 550 };

		//Inspector
		SDL_Rect InspectorBase = { 880, 20, 200, 550 };

		//File Viewer
		SDL_Rect FileViewerBase = { 0, 570, 1080, 220 };
	private:
		std::vector<SDL_Rect> Rects;
		std::vector<SDL_Rect> OutlineToBeDrawn;
		std::vector<SDL_Rect> OutlineRects;
		std::vector<SDL_Rect> TextBase;

		Vector2 MousePosition;

		float MouseScroll = 0.0f;

		bool IsMouseDown = false;

		//Scene Colour
		SDL_Colour Colour = { 195, 195, 195, 255 };

		SDL_Colour OutlineColour = { 127, 127, 127, 255 };

		SDL_Rect OutlineRect;

		const char* CurrentLayer = "";

		//Text Base

		SDL_Colour TextBaseColour = { 127, 127, 127, 255 };

		SDL_Rect HierarchyTextBase;

		SDL_Rect InspectorTextBase;

		//Text

		SDL_Colour TextColour = { 255, 255, 255, 255 };

		SDL_Rect HierarchyText;

		SDL_Rect InspectorText;
};

