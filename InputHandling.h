#pragma once
#include <SDL.h>
#include "Vector2.h"

class InputHandling
{
	public:
		static void Init();
		static bool IsKeyDown(const char* Key);
		static Vector2 GetMousePosition();
		static Vector2 GetMouseGlobalPosition();
		static int GetMouseDown();
		static int GetMouseUp();
		static char* GetTextInput();
		static int GetMouseScroll();
	private:
		
};
