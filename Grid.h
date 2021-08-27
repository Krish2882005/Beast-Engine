#pragma once
#include <SDL.h>
#include "Scene.h"

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
		float Sensitivity = 1;
		Scene* scene = nullptr;
};
