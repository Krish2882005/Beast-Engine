// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#pragma once
#include <vector>
#include "SDL.h"
#include "SDL_image.h"
#include "Vector2.h"

struct Text
{
	const char* Text;
	SDL_Colour Colour;
	SDL_Rect TextRect;
};

struct Shapes
{
	std::vector<SDL_Rect> Rects;
	//Colour Should Be Corresponding To The Rects
	//Number Of Rects = Colours
	std::vector<SDL_Colour> Colours;
};

struct Gui
{
	const char* GuiType;
	int GuiTokenNumber;
	int NumberOfElements;
	std::vector<Shapes> GuiShapes;
	std::vector<Text> Texts;
};

struct Texture
{
	const char* GuiType;
	int GuiTokenNumber;
};

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
	void CreateErrorMessage(const char* ErrorSeverityLevel, const char* Error);
	void Events();
	void Update();
	void ClearAllGuis();
	int GetNumberOfGuis();
	void Draw();
	void Clean();

private:
	int CurrentNumberOfToken = 0;

	void DeleteGui();

	//To Be Done When A Gui Is Deleted
	void RefreshGuiTokens();
	int GetGuiToken();

	int WindowWidth = 1080;
	int WindowHeight = 720;
	SDL_Rect GuiPosition = { 0, 0, 0, 0 };

	//Guis Such As The Menu Bar
	std::vector<Gui> EssentialGuis;
	std::vector<Gui> Guis;
	std::vector<Texture> TextureGuis;
};
