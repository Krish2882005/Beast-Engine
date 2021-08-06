// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

//This Is A Beast Engine File Which Has The License Apache 2.0

#include "Init.h"
#include <iostream>
#include "TextureManager.h"
#include "RenderText.h"
#include "Logger.h"
#include "Scene.h"
#include "BeastGui.h"
#include "ErrorReporter.h"
#include "BeastGui.h"
#include "Editor.h"

constexpr int ScreenWidth = 1080;
constexpr int ScreenHeight = 720;

SDL_Renderer* Init::Renderer = nullptr;

SDL_Event Init::Event;

Editor* editor = new Editor();

Scene* scene = new Scene();

BeastGui* beastgui = new BeastGui();

void Init::Init_SDL2()
{
	ErrorReporter::Init();

	ErrorReporter::LogMessage("Info", "Starting Beast Engine");
	ErrorReporter::LogMessage("Info", "Initializing Subsystems And Other Tasks");

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		if (TextureManager::Init() != 0)
		{
			m_IsRunning = false;
			ErrorReporter::LogMessage("Error", SDL_GetError());
			return;
		}

		Window = SDL_CreateWindow("Beast Engine", SDL_WINDOWPOS_CENTERED_MASK, SDL_WINDOWPOS_CENTERED_MASK, ScreenWidth, ScreenHeight, SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);

		if (Window == nullptr)
		{
			m_IsRunning = false;
			ErrorReporter::LogMessage("Error", SDL_GetError());
			return;
		}

		Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

		if (Renderer == nullptr)
		{
			ErrorReporter::LogMessage("Error", SDL_GetError());
			m_IsRunning = false;
			return;
		}

		ErrorReporter::LogMessage("Info", "Initializing GUI");

		if (beastgui->Init() != 0)
		{
			ErrorReporter::LogMessage("Error", SDL_GetError());
			m_IsRunning = false;
			return;
		}

		ErrorReporter::LogMessage("Info", "Initialized GUI");

		m_IsRunning = true;
	}
	else
	{
		m_IsRunning = false;
		ErrorReporter::LogMessage("Error", SDL_GetError());
		return;
	}

	editor->Init();

	scene->Init(editor);

	ErrorReporter::LogMessage("Info", "Beast Engine Has Successfully Initialized And Other Tasks Are Completed");
}

void Init::Load()
{
	ErrorReporter::LogMessage("Info", "Loading Files And Other Tasks");

	editor->Load();

	ErrorReporter::LogMessage("Info", "Loading GUI");
	
	beastgui->Load();

	ErrorReporter::LogMessage("Info", "Successfully Loaded GUI");

	ErrorReporter::LogMessage("Info", "Loading Scene");

	scene->Load();

	ErrorReporter::LogMessage("Info", "Loaded Scene");

	ErrorReporter::LogMessage("Info", "Beast Engine Has Loaded Files And Other Tasks Are Succesfully Completed");

	ErrorReporter::LogMessage("Info", "Beast Engine Has Started");
}

void Init::Events()
{
	SDL_PollEvent(&Event);

	if (Event.type == SDL_QUIT)
	{
		m_IsRunning = false;
	}

	editor->Events();
	scene->Events();
}

void Init::Update()
{
	editor->Update();

	scene->Update();
}

void Init::Draw()
{
	SDL_RenderClear(Renderer);

	scene->Draw();

	editor->Draw();

	SDL_RenderPresent(Renderer);
}

void Init::Clean()
{
	scene->Clean();

	editor->Clean();

	beastgui->Clean();

	SDL_DestroyWindow(Window);
	SDL_DestroyRenderer(Renderer);

	ErrorReporter::LogMessage("Info", "Beast Engine Is Clean");
	ErrorReporter::Clean();
}
