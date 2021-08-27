// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

//This Is A Beast Engine File Which Has The License Apache 2.0

#include <string>
#include "Scene.h"
#include "Init.h"
#include "InputHandling.h"
#include "Vector2.h"
#include "CollisionDetection.h"
#include "ErrorReporter.h"
#include "TextureManager.h"
#include "TileMap.h"

TileMap tilemap;

void Scene::Init(Editor* editor)
{
	//entt::entity entity = Registry.create();
	//TransformComponent& transform = Registry.emplace<TransformComponent>(entity);

	M_Editor = editor;

	tilemap.Init();
}

void Scene::Load()
{
	//Check If All The Gameobjects And Textures Are Loaded In The Folder

	tilemap.Load();

	AddTileMap();
}

void Scene::Events()
{
	MousePosition = InputHandling::GetMousePosition();
	IsMouseDown = InputHandling::GetMouseDown();

	tilemap.Events();
}

void Scene::Update()
{
	RefreshScene();

	tilemap.Update();

	SceneRect.x = M_Editor->HierarchyBase.x + M_Editor->HierarchyBase.w;

	SceneRect.w = M_Editor->InspectorBase.x - (M_Editor->HierarchyBase.x + M_Editor->HierarchyBase.w);

	SceneRect.h = M_Editor->FileViewerBase.y - 20;

	if (IsMouseDown == 1)
	{
		if (CollisionDetection::DetectCollision(MousePosition, SceneRect))
		{
			Layer = "Scene";
		}
		else
		{
			Layer = "";
		}
	}
}

void Scene::RefreshScene()
{
	for (int i = 0; i < Entities.size(); i++)
	{
		//Check If The Component Has A Sprite Renderer
		SpriteRenderer* spriterenderer = Registry.try_get<SpriteRenderer>(Entities[i]);

		if (spriterenderer != nullptr)
		{
			//If Texture Is Not Found Then Log Warning And Try To Reimport
			//If The Texture Is Stil A nullptr Then Log Error
			if (spriterenderer->Sprite == nullptr)
			{
				std::string LogMessage = spriterenderer->FileAdress + std::string(" Is A nullptr. ") + std::string("Trying To Reimport File");

				ErrorReporter::LogMessage("Warning", LogMessage.c_str());

				spriterenderer->Sprite = TextureManager::Load(spriterenderer->FileAdress);

				if (spriterenderer->Sprite == nullptr)
				{
					LogMessage = "Cant Reimport " + std::string(spriterenderer->FileAdress) + ". " + SDL_GetError();

					ErrorReporter::LogMessage("Error", LogMessage.c_str());

					Registry.remove_if_exists<SpriteRenderer>(Entities[i]);
				}
			}
		}
	}
}

void Scene::AddTileMap()
{
	tilemap.SetScene(this);
}

void Scene::DeleteTileMap()
{

}

void Scene::Draw()
{
	tilemap.Draw();
}

void Scene::Clean()
{
	tilemap.Clean();
}
