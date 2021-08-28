#include "BeastGuiDropDownMenu.h"
#include "InputHandling.h"
#include "CollisionDetection.h"

void BeastGuiDropDownMenu::Update()
{
	
}

void BeastGuiDropDownMenu::Draw()
{

}

void BeastGuiDropDownMenu::Clean()
{
	delete this;
}

const char* BeastGuiDropDownMenu::IsButtonClicked()
{
	if (InputHandling::GetMouseDown())
	{

	}

	return "";
}
