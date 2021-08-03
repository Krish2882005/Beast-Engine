#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Entt.h"

struct TransformComponent
{
	SDL_Rect Rect;
	int Angle;
};

struct SpriteRenderer
{
	SDL_Texture* Sprite;
	SDL_Rect SpriteRect;
	const char* FileAdress;
	bool FlipX = false;
	bool FlipY = false;
};

class Scene
{
	public:
		void Init();
		void Load();
		void Events();
		void Update();
		void RefreshScene();
		void AddTileMap();
		void DeleteTileMap();
		void Draw();
		void Clean();

		SDL_Rect SceneRect;
		int DistanceBetweenGrid = 20;
	private:
		entt::registry Registry;

		const char* Layer;

		std::vector<entt::entity> Entities;
};

