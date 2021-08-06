// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

//This Is A Beast Engine File Which Has The License Apache 2.0

#include "TileMap.h"
#include <string>
#include "TextureManager.h"
#include "ErrorReporter.h"
#include "InputHandling.h"
#include <iostream>

void TileMap::Init()
{
	std::vector<int> EmptyRect;

	for (int i = 0; i < 100; i++)
	{
		EmptyRect.push_back(0);
	}

	for (int i = 0; i < EmptyRect.size(); i++)
	{
		Level.push_back(EmptyRect);
	}
}

void TileMap::Load()
{

}

void TileMap::DeleteTileMap()
{
	Level.clear();

	for (int i = 0; i < Textures.size(); i++)
	{
		SDL_DestroyTexture(Textures[i]);
	}

	Textures.clear();
}

void TileMap::Events()
{
	MousePosition = InputHandling::GetMousePosition();
	IsMouseDown = InputHandling::GetMouseDown();
}

void TileMap::Update()
{
	RefreshTileMap();

	ClickedOnTile.X = 0;
	ClickedOnTile.Y = 0;

	LocalPosition.X = MousePosition.X - scene->SceneRect.x;
	LocalPosition.Y = MousePosition.Y - scene->SceneRect.y;

	//Check Division By 0

	if (IsMouseDown)
	{
		if (LocalPosition.X == 0)
		{
			ClickedOnTile.X = 0;
		}
		else
		{
			ClickedOnTile.X = LocalPosition.X / scene->DistanceBetweenGrid;
		}

		if (LocalPosition.Y == 0)
		{
			ClickedOnTile.Y = 0;
		}
		else
		{
			ClickedOnTile.Y = LocalPosition.Y / scene->DistanceBetweenGrid;
		}
	}
}

void TileMap::RefreshTileMap()
{
	for (int i = 0; i < Textures.size(); i++)
	{
		if (Textures[i] == nullptr)
		{
			std::string LogMessage = FileAdress[i] + std::string(" Is A nullptr. ") + std::string("Trying To Reimport File");

			ErrorReporter::LogMessage("Warning", LogMessage.c_str());

			Textures[i] = TextureManager::Load(FileAdress[i]);

			if (Textures[i] == nullptr)
			{
				LogMessage = "Cant Reimport " + std::string(FileAdress[i]) + ". " + SDL_GetError();

				ErrorReporter::LogMessage("Error", LogMessage.c_str());
			}
		}
	}
}

void TileMap::Draw()
{
	int DistanceBetweenGrids = scene->DistanceBetweenGrid;

	SDL_Rect SceneRect = scene->SceneRect;

	SDL_Rect DstRect = { 0, 0, DistanceBetweenGrids, DistanceBetweenGrids };
	SDL_Rect SrcRect = Rect;

	/*
	for (int i = 0; i < Level.size(); i++)
	{
		for (int j = 0; i < Level[i].size(); i++)
		{
			DstRect.x = (DistanceBetweenGrids * j) + SceneRect.x;
			DstRect.y = (DistanceBetweenGrids * i) + SceneRect.y;

			TextureManager::Draw(Textures[Level[i][j]], &SrcRect, &DstRect);
		}
	}
	*/
}


void TileMap::Clean()
{
	//Save The TileMap



	DeleteTileMap();
}
