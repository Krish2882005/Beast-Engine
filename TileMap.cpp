// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

//This Is A Beast Engine File Which Has The License Apache 2.0

#include "TileMap.h"
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

void TileMap::Update()
{

}

void TileMap::Draw()
{
	for (int i = 0; i < TileMaps.size(); i++)
	{
		for (int j = 0; j < TileMaps[i].Level.size(); j++)
		{
			for (int k = 0; k < TileMaps[i].Level[i].size(); k++)
			{
				TextureManager::Draw(TileMaps[i].Textures[TileMaps[i].Level[j][k]], &TileMaps[i].Rect, &TileMaps[i].Rect);
			}
		}
	}
}

void TileMap::Clean()
{
	TileMaps.clear();
}
