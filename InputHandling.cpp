//This Is A Beast Engine File Which Has The License Apache 2.0

#include "InputHandling.h"
#include "Init.h"

const Uint8* PressedKey = SDL_GetKeyboardState(0);

void InputHandling::Init()
{

}

bool InputHandling::IsKeyDown(Keycode keycode)
{	
	//if (Init::Event.type == SDL_KEYDOWN)
	//{
	if (PressedKey[(int)keycode])
	{
		return true;
		}
	//}

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
	//if (Init::Event.type == SDL_MOUSEBUTTONDOWN)
	//{
		return Init::Event.button.button;
	//}

	return 0;
}

int InputHandling::GetMouseUp()
{
	//if (Init::Event.type == SDL_MOUSEBUTTONUP)
	//{
		return Init::Event.button.button;
	//}

	return 0;
}

char* InputHandling::GetTextInput()
{
	//if (Init::Event.type == SDL_TEXTINPUT)
	//{
		return Init::Event.text.text;
	//}
}

int InputHandling::GetMouseScroll()
{
	//Check The Output

	//if (Init::Event.type == SDL_MOUSEWHEEL)
	//{
		return Init::Event.wheel.y;
	//}
}
