//This Is A Beast Engine File Which Has The License Apache 2.0

#include "InputHandling.h"
#include "Init.h"
#include <iostream>

const Uint8* PressedKey = SDL_GetKeyboardState(0);

void InputHandling::Init()
{

}

bool InputHandling::IsKeyDown(const char* Key)
{
	if (Init::Event.type == SDL_KEYDOWN)
	{
		if (SDL_strcasecmp(Key, "a"))
		{
			if (PressedKey[SDL_SCANCODE_A])
			{
				return true;
			}
		}
		if (SDL_strcasecmp(Key, "b"))
		{
			if (PressedKey[SDL_SCANCODE_B])
			{
				return true;
			}
		}
		if (SDL_strcasecmp(Key, "c"))
		{
			if (PressedKey[SDL_SCANCODE_C])
			{
				return true;
			}
		}
		if (SDL_strcasecmp(Key, "d"))
		{
			if (PressedKey[SDL_SCANCODE_D])
			{
				return true;
			}
		}
		if (SDL_strcasecmp(Key, "e"))
		{
			if (PressedKey[SDL_SCANCODE_E])
			{
				true;
			}
		}
		if (SDL_strcasecmp(Key, "f"))
		{
			if (PressedKey[SDL_SCANCODE_F])
			{
				return true;
			}
		}
		if (SDL_strcasecmp(Key, "g"))
		{
			if (PressedKey[SDL_SCANCODE_G])
			{
				return true;
			}
		}
		if (SDL_strcasecmp(Key, "h"))
		{
			if (PressedKey[SDL_SCANCODE_H])
			{
				return true;
			}
		}
		if (SDL_strcasecmp(Key, "i"))
		{
			if (PressedKey[SDL_SCANCODE_I])
			{
				return true;
			}
		}
		if (SDL_strcasecmp(Key, "j"))
		{
			if (PressedKey[SDL_SCANCODE_J])
			{
				return true;
			}
		}
		if (SDL_strcasecmp(Key, "k"))
		{
			if (PressedKey[SDL_SCANCODE_K])
			{
				return true;
			}
		}
		if (SDL_strcasecmp(Key, "l"))
		{
			if (PressedKey[SDL_SCANCODE_L])
			{
				return true;
			}
		}
		if (SDL_strcasecmp(Key, "m"))
		{
			if (PressedKey[SDL_SCANCODE_M])
			{
				return true;
			}
		}
		if (SDL_strcasecmp(Key, "n"))
		{
			if (PressedKey[SDL_SCANCODE_N])
			{
				return true;
			}
		}
		if (SDL_strcasecmp(Key, "o"))
		{
			if (PressedKey[SDL_SCANCODE_O])
			{
				return true;
			}
		}
		if (SDL_strcasecmp(Key, "p"))
		{
			if (PressedKey[SDL_SCANCODE_A])
			{
				return true;
			}
		}
		if (SDL_strcasecmp(Key, "q"))
		{
			if (PressedKey[SDL_SCANCODE_Q])
			{
				return true;
			}
		}
		if (SDL_strcasecmp(Key, "r"))
		{
			if (PressedKey[SDL_SCANCODE_R])
			{
				return true;
			}
		}
		if (SDL_strcasecmp(Key, "s"))
		{
			if (PressedKey[SDL_SCANCODE_S])
			{
				return true;
			}
		}
		if (SDL_strcasecmp(Key, "t"))
		{
			if (PressedKey[SDL_SCANCODE_T])
			{
				return true;
			}
		}
		if (SDL_strcasecmp(Key, "u"))
		{
			if (PressedKey[SDL_SCANCODE_U])
			{
				return true;
			}
		}
		if (SDL_strcasecmp(Key, "v"))
		{
			if (PressedKey[SDL_SCANCODE_V])
			{
				return true;
			}
		}
		if (SDL_strcasecmp(Key, "w"))
		{
			if (PressedKey[SDL_SCANCODE_X])
			{
				return true;
			}
		}
		if (SDL_strcasecmp(Key, "x"))
		{
			if (PressedKey[SDL_SCANCODE_X])
			{
				return true;
			}
		}
		if (SDL_strcasecmp(Key, "y"))
		{
			if (PressedKey[SDL_SCANCODE_Y])
			{
				return true;
			}
		}
		if (SDL_strcasecmp(Key, "z"))
		{
			if (PressedKey[SDL_SCANCODE_Z])
			{
				return true;
			}
		}
		if (SDL_strcasecmp(Key, "left control"))
		{
			if (PressedKey[SDL_SCANCODE_LCTRL])
			{
				return true;
			}
		}
		if (SDL_strcasecmp(Key, "right control"))
		{
			if (PressedKey[SDL_SCANCODE_RCTRL])
			{
				return true;
			}
		}
	}

	return false;
}

Vector2 InputHandling::GetMousePosition()
{
	Vector2 MousePosition;

	//if (Init::Event.type == SDL_MOUSEMOTION)
	//{
	int MouseXPosition = 0;
	int MouseYPosition = 0;

	SDL_GetMouseState(&MouseXPosition, &MouseYPosition);

	MousePosition.X = MouseXPosition;
	MousePosition.Y = MouseYPosition;

	return MousePosition;
	//}

	return MousePosition;
}

Vector2 InputHandling::GetMouseGlobalPosition()
{
	Vector2 MousePosition;

	//if (Init::Event.type == SDL_MOUSEMOTION)
	//{
	int MouseXPosition = 0;
	int MouseYPosition = 0;

	SDL_GetGlobalMouseState(&MouseXPosition, &MouseYPosition);

	MousePosition.X = MouseXPosition;
	MousePosition.Y = MouseYPosition;

	return MousePosition;
	//}

	return MousePosition;
}

bool M_IsMouse1Down = false;
bool M_IsMouse3Down = false;

int InputHandling::GetMouseDown()
{
	if (Init::Event.type == SDL_MOUSEBUTTONDOWN)
	{
		return Init::Event.button.button;
	}

	return 0;
}

int InputHandling::GetMouseUp()
{
	if (Init::Event.type == SDL_MOUSEBUTTONUP)
	{
		return Init::Event.button.button;
	}

	return 0;
}

char* InputHandling::GetTextInput()
{
	if (Init::Event.type == SDL_TEXTINPUT)
	{
		return Init::Event.text.text;
	}

	return 0;
}

int InputHandling::GetMouseScroll()
{
	//Check The Output

	if (Init::Event.type == SDL_MOUSEWHEEL)
	{
		return Init::Event.wheel.y;
	}
	
	return 0;
}
