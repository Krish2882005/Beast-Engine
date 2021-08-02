// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

//This Is A Beast Engine File Which Has The License Apache 2.0

#include <iostream>
#include "Scene.h"
#include "Init.h"
#include "InputHandling.h"
#include "Vector2.h"
#include "CollisionDetection.h"
#include "ErrorReporter.h"
#include "TextureManager.h"
#include <string>

Vector2 MousePosition;

void Scene::Init()
{
	//entt::entity entity = Registry.create();
	//TransformComponent& transform = Registry.emplace<TransformComponent>(entity);
}

void Scene::Load()
{
	//Check If All The Gameobjects And Textures Are Loaded In The Folder

}

void Scene::Events()
{
	MousePosition = InputHandling::GetMousePosition();
}

void Scene::Update()
{
	if (InputHandling::GetMouseDown() == 1)
	{
		Vector2 MousePosition;

		MousePosition.X = InputHandling::GetMousePosition().X;
		MousePosition.Y = InputHandling::GetMousePosition().Y;

		if (CollisionDetection::DetectCollision(MousePosition, SceneRect))
		{
			Layer = "Scene";
		}
		else
		{
			Layer = "";
		}
	}

	RefreshScene();
}

void Scene::RefreshScene()
{
	for (int i = 0; i < Entities.size(); i++)
	{
		//Check If The Component Has A Sprite Renderer
		SpriteRenderer* spriterenderer = Registry.try_get<SpriteRenderer>(Entities[i]);

		if (spriterenderer != nullptr)
		{
			//Is Texture Is Not Found Then Log Warning And Try To Reimport
			//If The Texture Is Stil A nullptr Then Log Error
			if (spriterenderer->Sprite == nullptr)
			{
				std::string LogMessage = spriterenderer->FileAdress + std::string(" Is A nullptr. ") + std::string("Trying To Reimport File");

				ErrorReporter::LogMessage("Warning", LogMessage.c_str());

				spriterenderer->Sprite = TextureManager::Load(spriterenderer->FileAdress);

				if (spriterenderer->Sprite == nullptr)
				{
					std::string LogMessage = "Cant Reimport " + std::string(spriterenderer->FileAdress) + ". " + SDL_GetError();

					ErrorReporter::LogMessage("Error", LogMessage.c_str());

					Registry.remove_if_exists<SpriteRenderer>(Entities[i]);
				}
			}
		}
	}
}

void Scene::Draw()
{
	//Drawing The Background Bases

	SDL_SetRenderDrawColor(Init::Renderer, 128, 128, 128, 255);

	SceneRect.x = 200;
	SceneRect.y = 100;
	SceneRect.w = 800;
	SceneRect.h = 500;

	SDL_RenderDrawRect(Init::Renderer, &SceneRect);
	SDL_RenderFillRect(Init::Renderer, &SceneRect);

	SDL_SetRenderDrawColor(Init::Renderer, 0, 0, 0, 255);

	//Drawing The Scene Grid

	int GridXCoordinate = SceneRect.x;
	int GridYCoordinate = SceneRect.y;

	int NumberOfRows = 0;
	int NumberOfColumns = 0;

	if (Layer == "Scene" && InputHandling::GetMouseDown() == 3)
	{
		DistanceBetweenGrid += InputHandling::GetMouseScroll();
	}

	//if (DistanceBetweenGrid <= 0)
	//{
		//DistanceBetweenGrid = 1;
	//}

	if (DistanceBetweenGrid <= 10)
	{
		DistanceBetweenGrid = 10;
	}
	else if (DistanceBetweenGrid >= 500)
	{
		DistanceBetweenGrid = 500;
	}

	NumberOfRows = SceneRect.w / DistanceBetweenGrid;

	NumberOfRows += 1;

	NumberOfColumns = SceneRect.h / DistanceBetweenGrid;

	NumberOfColumns += 1;

	SDL_SetRenderDrawBlendMode(Init::Renderer, SDL_BLENDMODE_BLEND);

	SDL_SetRenderDrawColor(Init::Renderer, 255, 255, 255, 30);

	for (int i = 0; i < NumberOfRows; i++)
	{
		SDL_RenderDrawLine(Init::Renderer, GridXCoordinate, GridYCoordinate, GridXCoordinate, GridYCoordinate + SceneRect.h - 1);

		GridXCoordinate += DistanceBetweenGrid;
	}

	GridXCoordinate = SceneRect.x;
	GridYCoordinate = SceneRect.y;

	for (int i = 0; i < NumberOfColumns; i++)
	{
		SDL_RenderDrawLine(Init::Renderer, GridXCoordinate, GridYCoordinate, GridXCoordinate + SceneRect.w - 1, GridYCoordinate);

		GridYCoordinate += DistanceBetweenGrid;
	}

	SDL_SetRenderDrawColor(Init::Renderer, 0, 0, 0, 255);

	//SDL_SetRenderDrawBlendMode(Init::Renderer, SDL_BLENDMODE_ADD);
	SDL_SetRenderDrawBlendMode(Init::Renderer, SDL_BLENDMODE_NONE);
}

void Scene::Clean()
{

}
