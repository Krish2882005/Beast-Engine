#pragma once
#include <SDL.h>
#include "Scene.h"
#include "BeastGui.h"

class Grid
{
	public:
		void Init(Scene* GridScene);
		void Load();
		void Events();
		void Update();
		void Draw();
		void Clean();
		float DistanceBetweenGrid = 16;
	private:
		Scene* scene = nullptr;

		BeastGui* GridGui = nullptr;

		float Sensitivity = 1;

		float XOffset = 0;
		float YOffset = 0;
};
