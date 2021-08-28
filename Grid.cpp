#include "Grid.h"
#include "Init.h"
#include "InputHandling.h"
#include <iostream>

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

	if (InputHandling::GetMouseDown() == 3 && scene->Layer == "Scene")
	{
		DistanceBetweenGrid += InputHandling::GetMouseScroll();
	}

	if (scene->Layer == "Scene")
	{
		if (InputHandling::IsKeyDown(Keycode::Up))
		{
			if (InputHandling::IsKeyDown(Keycode::LCtrl) || InputHandling::IsKeyDown(Keycode::RCtrl))
			{
				DistanceBetweenGrid += Sensitivity;
			}
			else
			{
				YOffset += Sensitivity;
			}
		}
		if (InputHandling::IsKeyDown(Keycode::Down))
		{
			if (InputHandling::IsKeyDown(Keycode::LCtrl) || InputHandling::IsKeyDown(Keycode::RCtrl))
			{
				DistanceBetweenGrid -= Sensitivity;
			}
			else
			{
				YOffset -= Sensitivity;
			}
		}
		if (InputHandling::IsKeyDown(Keycode::Right))
		{
			XOffset -= Sensitivity;
		}
		if (InputHandling::IsKeyDown(Keycode::Left))
		{
			XOffset += Sensitivity;
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
}

void Grid::Draw()
{
	//Drawing The Background Bases

	SDL_Rect SceneRect = scene->SceneRect;

	GridGui.DrawRect(&SceneRect, { 0, 0, 0, 255 });
	GridGui.FillRect(&SceneRect, { 0, 0, 0, 255 });

	//Drawing The Scene Grid
	int NumberOfRows = (SceneRect.w / DistanceBetweenGrid) + 1;

	int NumberOfColumns = (SceneRect.h / DistanceBetweenGrid) + 1;

	int GridXCoordinate = SceneRect.x;
	int GridYCoordinate = SceneRect.y;

	SDL_SetRenderDrawBlendMode(Init::Renderer, SDL_BLENDMODE_BLEND);

	int AvailableRowsInLeft = 0;
	int AvailableRowsInRight = 0;

	int FirstPosition = 0;
	int LastPosition = 0;

	FirstPosition = GridXCoordinate;

	SDL_Rect Rect;

	Rect.x = FirstPosition + XOffset;
	Rect.y = GridYCoordinate + YOffset;
	Rect.w = DistanceBetweenGrid;
	Rect.h = DistanceBetweenGrid;

	GridGui.DrawRect(&Rect, { 255, 255, 255, 255 });

	for (int i = 0; i < NumberOfRows; i++)
	{
		if (NumberOfRows - i == 1)
		{
			LastPosition = GridXCoordinate;
		}

		if (GridXCoordinate + XOffset >= SceneRect.x && GridXCoordinate + XOffset <= SceneRect.x + SceneRect.w)
		{
			GridGui.DrawLine(GridXCoordinate + XOffset, GridXCoordinate + XOffset, GridYCoordinate, GridYCoordinate + SceneRect.h - 1, { 255, 255, 255, 20 });
		}

		AvailableRowsInLeft = XOffset / DistanceBetweenGrid;
		AvailableRowsInRight = XOffset / DistanceBetweenGrid;

		AvailableRowsInRight *= -1;

		GridXCoordinate += DistanceBetweenGrid;
	}

	for (int i = 1; i <= AvailableRowsInLeft + 1; i++)
	{
		int Distance = 0;

		Distance = FirstPosition;

		Distance -= DistanceBetweenGrid * i;

		int NewGridXCoordinate = Distance;

		if (NewGridXCoordinate + XOffset >= SceneRect.x && NewGridXCoordinate + XOffset <= SceneRect.x + SceneRect.w)
		{
			GridGui.DrawLine(NewGridXCoordinate + XOffset, NewGridXCoordinate + XOffset, GridYCoordinate, GridYCoordinate + SceneRect.h - 1, { 255, 255, 255, 20 });
		}

		GridXCoordinate += DistanceBetweenGrid;
	}

	for (int i = 1; i <= AvailableRowsInRight + 1; i++)
	{
		int Distance = 0;

		Distance = LastPosition;

		Distance += DistanceBetweenGrid * i;

		int NewGridXCoordinate = Distance;

		if (NewGridXCoordinate + XOffset >= SceneRect.x && NewGridXCoordinate + XOffset <= SceneRect.x + SceneRect.w)
		{
			GridGui.DrawLine(NewGridXCoordinate + XOffset, NewGridXCoordinate + XOffset, GridYCoordinate, GridYCoordinate + SceneRect.h - 1, { 255, 255, 255, 20 });
		}

		GridXCoordinate += DistanceBetweenGrid;
	}

	int AvailableColumnsInTop = 0;
	int AvailableColumnsDown = 0;

	FirstPosition = 0;
	LastPosition = 0;

	GridXCoordinate = SceneRect.x;
	GridYCoordinate = SceneRect.y;

	FirstPosition = GridYCoordinate;

	for (int i = 0; i < NumberOfColumns; i++)
	{
		if (NumberOfColumns - i == 1)
		{
			LastPosition = GridYCoordinate;
		}

		if (GridYCoordinate + YOffset >= SceneRect.y && GridYCoordinate + YOffset <= SceneRect.y + SceneRect.h)
		{
			GridGui.DrawLine(GridXCoordinate, GridXCoordinate + SceneRect.w - 1, GridYCoordinate + YOffset, GridYCoordinate + YOffset, { 255, 255, 255, 20 });
		}

		AvailableColumnsDown = YOffset / DistanceBetweenGrid;
		AvailableColumnsInTop = YOffset / DistanceBetweenGrid;

		AvailableColumnsDown *= -1;

		GridYCoordinate += DistanceBetweenGrid;
	}

	for (int i = 1; i <= AvailableColumnsInTop + 1; i++)
	{
		int Distance = 0;

		Distance = FirstPosition;

		Distance -= DistanceBetweenGrid * i;

		int NewGridYCoordinate = Distance;

		if (NewGridYCoordinate + YOffset >= SceneRect.y && NewGridYCoordinate + YOffset <= SceneRect.y + SceneRect.h)
		{
			GridGui.DrawLine(GridXCoordinate, GridXCoordinate + SceneRect.w - 1, NewGridYCoordinate + YOffset, NewGridYCoordinate + YOffset, { 255, 255, 255, 20 });
		}

		GridYCoordinate += DistanceBetweenGrid;
	}

	for (int i = 1; i <= AvailableColumnsDown + 1; i++)
	{
		int Distance = 0;

		Distance = LastPosition;

		Distance += DistanceBetweenGrid * i;

		int NewGridYCoordinate = Distance;

		if (NewGridYCoordinate + YOffset >= SceneRect.y && NewGridYCoordinate + YOffset <= SceneRect.y + SceneRect.h)
		{
			GridGui.DrawLine(GridXCoordinate, GridXCoordinate + SceneRect.w - 1, NewGridYCoordinate + YOffset, NewGridYCoordinate + YOffset, { 255, 255, 255, 20 });
		}

		GridYCoordinate += DistanceBetweenGrid;
	}

	//SDL_SetRenderDrawBlendMode(Init::Renderer, SDL_BLENDMODE_ADD);
	SDL_SetRenderDrawBlendMode(Init::Renderer, SDL_BLENDMODE_NONE);
}

void Grid::Clean()
{
	GridGui.Clean();
}