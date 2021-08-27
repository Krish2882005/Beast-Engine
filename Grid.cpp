#include "Grid.h"
#include "Init.h"
#include "InputHandling.h"
#include "BeastGui.h"

BeastGui GridGui;

void Grid::Init(Scene* GridScene)
{
	scene = GridScene;

	GridGui.Init();
}

void Grid::Load()
{
	GridGui.Load();
}

void Grid::Events()
{

}

void Grid::Update()
{
	GridGui.Update();
}

void Grid::Draw()
{
	//Drawing The Background Bases

	GridGui.DrawRect(&scene->SceneRect, { 0, 0, 0, 255 });
	GridGui.FillRect(&scene->SceneRect, { 0, 0, 0, 255 });

	//Drawing The Scene Grid

	int GridXCoordinate = scene->SceneRect.x;
	int GridYCoordinate = scene->SceneRect.y;

	if (InputHandling::GetMouseDown() == 3 && scene->Layer == "Scene")
	{
		DistanceBetweenGrid += InputHandling::GetMouseScroll();
	}

	if (scene->Layer == "Scene")
	{
		if (InputHandling::IsKeyDown(Keycode::Up))
		{
			DistanceBetweenGrid += 1;
		}
		if (InputHandling::IsKeyDown(Keycode::Down))
		{
			DistanceBetweenGrid -= 1;
		}
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

	int NumberOfRows = (scene->SceneRect.w / DistanceBetweenGrid) + 1;

	int NumberOfColumns = (scene->SceneRect.h / DistanceBetweenGrid) + 1;

	SDL_SetRenderDrawBlendMode(Init::Renderer, SDL_BLENDMODE_BLEND);

	for (int i = 0; i < NumberOfRows; i++)
	{
		GridGui.DrawLine(GridXCoordinate, GridXCoordinate, GridYCoordinate, GridYCoordinate + scene->SceneRect.h - 1, { 255, 255, 255, 20 });

		GridXCoordinate += DistanceBetweenGrid;
	}

	GridXCoordinate = scene->SceneRect.x;
	GridYCoordinate = scene->SceneRect.y;

	for (int i = 0; i < NumberOfColumns; i++)
	{
		GridGui.DrawLine(GridXCoordinate, GridXCoordinate + scene->SceneRect.w - 1, GridYCoordinate, GridYCoordinate, { 255, 255, 255, 20 });

		GridYCoordinate += DistanceBetweenGrid;
	}

	//SDL_SetRenderDrawBlendMode(Init::Renderer, SDL_BLENDMODE_ADD);
	SDL_SetRenderDrawBlendMode(Init::Renderer, SDL_BLENDMODE_NONE);
}

void Grid::Clean()
{
	GridGui.Clean();
}
