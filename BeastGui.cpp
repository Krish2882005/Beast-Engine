// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "BeastGui.h"
#include "RenderText.h"
#include "TextureManager.h"
#include <iostream>

RenderText* rendertext = new RenderText();

int BeastGui::Init()
{
	return rendertext->Init();
}

void BeastGui::Load()
{
	rendertext->Load();
}

void BeastGui::DrawRect(SDL_Rect* Rect, SDL_Colour Colour)
{
	SDL_SetRenderDrawColor(Init::Renderer, Colour.r, Colour.g, Colour.b, Colour.a);

	SDL_RenderDrawRect(Init::Renderer, Rect);

	SDL_SetRenderDrawColor(Init::Renderer, 0, 0, 0, 255);
}

void BeastGui::DrawRects(const SDL_Rect* Rects, int Count, SDL_Colour Colour)
{
	SDL_SetRenderDrawColor(Init::Renderer, Colour.r, Colour.g, Colour.b, Colour.a);

	SDL_RenderDrawRects(Init::Renderer, Rects, Count);

	SDL_SetRenderDrawColor(Init::Renderer, 0, 0, 0, 255);
}

void BeastGui::DrawLine(float XPos1, float XPos2, float YPos1, float YPos2, SDL_Colour Colour)
{
	SDL_SetRenderDrawColor(Init::Renderer, Colour.r, Colour.g, Colour.b, Colour.a);

	SDL_RenderDrawLine(Init::Renderer, XPos1, YPos1, XPos2, YPos2);

	SDL_SetRenderDrawColor(Init::Renderer, 0, 0, 0, 255);
}

void BeastGui::FillRect(SDL_Rect* Rect, SDL_Colour Colour)
{
	SDL_SetRenderDrawColor(Init::Renderer, Colour.r, Colour.g, Colour.b, Colour.a);

	SDL_RenderFillRect(Init::Renderer, Rect);

	SDL_SetRenderDrawColor(Init::Renderer, 0, 0, 0, 255);
}

void BeastGui::FillRects(const SDL_Rect* Rects, int Count, SDL_Colour Colour)
{
	SDL_SetRenderDrawColor(Init::Renderer, Colour.r, Colour.g, Colour.b, Colour.a);

	SDL_RenderFillRects(Init::Renderer, Rects, Count);

	SDL_SetRenderDrawColor(Init::Renderer, 0, 0, 0, 255);
}

void BeastGui::CreateErrorMessage(const char* ErrorSeverityLevel, const char* Error)
{
	//Position Should Be In The Center Of The Screen

	if (strcmp(ErrorSeverityLevel, "Fatal"))
	{
		//Dont Allow Program To Resume
	}
	else
	{
		SDL_Texture* ErrorMessageResumeable = nullptr;

		//Allow Program To Resume
		ErrorMessageResumeable = TextureManager::Load("GuiImages\\ErrorMessage.png");
		//TextureGuis.emplace_back("Error", GetGuiToken());

		//Push Back To The Gui Vector
	}
}

void BeastGui::RefreshGuiTokens()
{

}

int BeastGui::GetGuiToken()
{
	return CurrentNumberOfToken++;
}

int BeastGui::GetNumberOfGuis()
{
	return 0;
}

void BeastGui::ClearAllGuis()
{
	Guis.clear();
}

void BeastGui::Update()
{
	RefreshGuiTokens();
}

void BeastGui::Draw()
{

}

void BeastGui::Clean()
{
	rendertext->Clean();
	EssentialGuis.clear();
	Guis.clear();
}
