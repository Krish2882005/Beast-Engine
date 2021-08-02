#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include "Scene.h"

struct TileMapCore
{
	std::vector<SDL_Texture*> Textures;

	//The Map
	std::vector<std::vector<int> > Level;

	SDL_Rect Rect;

	Scene& scene;
};

class TileMap
{
public:
	void Init();
	void Load();
	int AddTileMap(TileMapCore core);
	void DeleteTileMap(int tileMapNumber);
	void Update();
	void Draw();
	void Clean();
private:
	std::vector<TileMapCore> TileMaps;
	
	int TileMapNumber = 0;
};

