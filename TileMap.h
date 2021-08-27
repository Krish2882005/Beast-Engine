#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include "Scene.h"
#include "Vector2.h"

class TileMap
{
	public:
		void Init();
		void Load();
		void DeleteTileMap();
		void SetScene(Scene* TileMapScene);
		void Events();
		void Update();
		void RefreshTileMap();
		void Draw();
		void Clean();
	private:
		Vector2 MousePosition;
		bool IsMouseDown = false;

		Scene* scene = nullptr;

		std::vector<SDL_Texture*> Textures;

		std::vector<const char*> FileAdress;

		//The Map
		std::vector<std::vector<int> > Level;

		SDL_Rect Rect;

		const char* TileMapName;

		Vector2 ClickedOnTile;

		Vector2 LocalPosition;
};

