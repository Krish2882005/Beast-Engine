#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include "Scene.h"

struct TileMapCore
{
	std::vector<SDL_Texture*> Textures;

	std::vector<const char*> FileAdress;

	//The Map
	std::vector<std::vector<int> > Level;

	SDL_Rect Rect;

	Scene& scene;

	const char* TileMapName;
};

class TileMap
{
public:
	void Init();
	void Load();
	int AddTileMap(TileMapCore core);
	void DeleteTileMap(int tileMapNumber);
	void SelectCurrentTileMap(int tileMapNumber);
	void SelectCurrentTileMap(const char* tileMapName);
	void Update();
	void RefreshTileMap();
	void Draw();
	void Clean();
private:
	std::vector<TileMapCore> TileMaps;
	
	int TileMapNumber = 0;

	int CurrentTileMap = 0;
};

