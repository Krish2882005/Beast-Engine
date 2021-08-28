// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#pragma once
#include <vector>
#include "SDL.h"
#include "SDL_image.h"
#include "Vector2.h"
#include "BeastGuiDropDownMenu.h"
#include "BeastGuiDropDown.h"
#include "BeastGuiFileImporter.h"

class BeastGui
{
public:
	BeastGui(BeastGui& gui) = delete;
	void operator= (const BeastGui&) = delete;
	static BeastGui*& GetInstance()
	{
		static BeastGui* beastgui = new BeastGui();
		return beastgui;
	}
	int Init();
	void Load();
	static void DrawRect(SDL_Rect* Rect, SDL_Colour Colour);
	static void DrawRects(const SDL_Rect* Rects, int Count, SDL_Colour Colour);
	static void DrawLine(float XPos1, float XPos2, float YPos1, float YPos2, SDL_Colour Colour);
	static void DrawLines(SDL_Point* Points, int Count, SDL_Colour Colour);
	static void FillRect(SDL_Rect* Rect, SDL_Colour Colour);
	static void FillRects(const SDL_Rect* Rects, int Count, SDL_Colour Colour);
	void Events();
	void Update();
	void Draw();
	void Clean();

	BeastGuiDropDownMenu* CreateDropDownMenu()
	{
		Guis.push_back(new BeastGuiDropDownMenu);

		return (BeastGuiDropDownMenu*)Guis.back();
	}
	BeastGuiDropDown* CreateDropDown()
	{
		Guis.push_back(new BeastGuiDropDown);

		return (BeastGuiDropDown*)Guis.back();
	}
	BeastGuiFileImporter* CreateFileImporter()
	{
		Guis.push_back(new BeastGuiFileImporter);

		return (BeastGuiFileImporter*)Guis.back();
	}
private:
	BeastGui() = default;
	std::vector<void*> Guis;
};