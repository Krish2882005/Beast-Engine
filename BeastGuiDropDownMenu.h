#pragma once
#include <SDL.h>
#include <vector>
#include "Vector2.h"

struct Button
{
	const char* ButtonName = "";
	bool IsEnabled = true;
};

class BeastGuiDropDownMenu
{
	public:
		void Update();
		void Draw();
		void Clean();
		
		const char* IsButtonClicked();
		inline void AddButton(const char* ButtonName, bool IsEnabled = true)
		{
			if (DoesButtonExist(ButtonName) == false)
			{
				Buttons.push_back({ ButtonName, IsEnabled });
			}
		}
		bool EnableButton(const char* ButtonName)
		{
			for (int i = 0; i < Buttons.size(); i++)
			{
				if (Buttons[i].ButtonName == ButtonName)
				{
					Buttons[i].IsEnabled = true;
					return true;
				}
			}

			return false;
		}
		bool DisableButton(const char* ButtonName)
		{
			for (int i = 0; i < Buttons.size(); i++)
			{
				if (Buttons[i].ButtonName == ButtonName)
				{
					Buttons[i].IsEnabled = false;
					return true;
				}
			}

			return false;
		}
		bool DoesButtonExist(const char* ButtonName)
		{
			for (int i = 0; i < Buttons.size(); i++)
			{
				if (Buttons[i].ButtonName == ButtonName)
				{
					return true;
				}
			}
			return false;
		}
	private:
		std::vector<Button> Buttons;

		SDL_Rect GuiRect;

		int ButtonDistance = 5;
};
