#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Entt.h"
#include "Editor.h"

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
		void Init(Editor* editor);
		void Load();
		void Events();
		void Update();
		void RefreshScene();
		void AddTileMap();
		void DeleteTileMap();
		void Draw();
		void Clean();

		SDL_Rect SceneRect = { 200, 20, 680, 550 };

		const char* Layer = "";

	private:
		Vector2 MousePosition;
		bool IsMouseDown = false;

		Editor* M_Editor = nullptr;

		entt::registry Registry;

		std::vector<entt::entity> Entities;
};

