// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

//This Is A Beast Engine File Which Has The License Apache 2.0

#include "TileMap.h"
#include <string>
#include "TextureManager.h"
#include "ErrorReporter.h"

void TileMap::Init()
{

}

void TileMap::Load()
{

}

int TileMap::AddTileMap(TileMapCore core)
{
	TileMaps.push_back(core);

	TileMapNumber++;

	return TileMapNumber - 1;
}

void TileMap::DeleteTileMap(int TileMapNumber)
{
	TileMaps[TileMapNumber].Level.clear();

	for (int i = 0; i < TileMaps[TileMapNumber].Textures.size();i++)
	{
		SDL_DestroyTexture(TileMaps[TileMapNumber].Textures[i]);
	}

	TileMaps[TileMapNumber].Textures.clear();
}

void TileMap::SelectCurrentTileMap(int tileMapNumber)
{
	if (TileMaps.size() != 0)
	{
		for (int i = 0; i < TileMaps[CurrentTileMap].Textures.size(); i++)
		{
			SDL_DestroyTexture(TileMaps[CurrentTileMap].Textures[i]);
		}
	}

	CurrentTileMap = tileMapNumber;

	for (int i = 0; i < TileMaps[CurrentTileMap].Textures.size(); i++)
	{
		TileMaps[CurrentTileMap].Textures[i] = TextureManager::Load(TileMaps[CurrentTileMap].FileAdress[i]);
	}
}

void TileMap::SelectCurrentTileMap(const char* tileMapName)
{
	for (int i = 0; i < TileMaps.size(); i++)
	{
		if (TileMaps[i].TileMapName == tileMapName)
		{
			CurrentTileMap = i;
			return;

			RefreshTileMap();
		}
	}
}

void TileMap::Update()
{
	RefreshTileMap();
}

void TileMap::RefreshTileMap()
{
	for (int i = 0; i < TileMaps[CurrentTileMap].Textures.size(); i++)
	{
		if (TileMaps[CurrentTileMap].Textures[i] == nullptr)
		{
			std::string LogMessage = TileMaps[CurrentTileMap].FileAdress[i] + std::string(" Is A nullptr. ") + std::string("Trying To Reimport File");

			ErrorReporter::LogMessage("Warning", LogMessage.c_str());

			TileMaps[CurrentTileMap].Textures[i] = TextureManager::Load(TileMaps[CurrentTileMap].FileAdress[i]);

			if (TileMaps[CurrentTileMap].Textures[i] == nullptr)
			{
				LogMessage = "Cant Reimport " + std::string(TileMaps[CurrentTileMap].FileAdress[i]) + ". " + SDL_GetError();

				ErrorReporter::LogMessage("Error", LogMessage.c_str());
			}
		}
	}
}

void TileMap::Draw()
{
	if (TileMaps.size() != 0)
	{
		int DistanceBetweenGrids = TileMaps[CurrentTileMap].scene.DistanceBetweenGrid;
		SDL_Rect SceneRect = TileMaps[CurrentTileMap].scene.SceneRect;

		SDL_Rect DstRect;
		DstRect.w = DistanceBetweenGrids;
		DstRect.h = DistanceBetweenGrids;
		SDL_Rect SrcRect = TileMaps[CurrentTileMap].Rect;

		for (int i = 0; i < TileMaps[CurrentTileMap].Level.size(); i++)
		{
			for (int j = 0; i < TileMaps[CurrentTileMap].Level[i].size(); i++)
			{
				DstRect.x = (DistanceBetweenGrids * j) + SceneRect.x;
				DstRect.y = (DistanceBetweenGrids * i) + SceneRect.y;

				TextureManager::Draw(TileMaps[CurrentTileMap].Textures[TileMaps[CurrentTileMap].Level[i][j]], &SrcRect, &DstRect);
			}
		}
	}
}

void TileMap::Clean()
{
	TileMaps.clear();
}
