// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

//This Is A Beast Engine File Which Has The License Apache 2.0

#include "Editor.h"
#include "Init.h"
#include "InputHandling.h"
#include "BeastGui.h"
#include "ErrorReporter.h"
#include "CollisionDetection.h"
#include "RenderText.h"
#include "TextureManager.h"

BeastGui* EditorGui = new BeastGui();

RenderText* EditorTextRenderer = new RenderText();

void Editor::Init()
{
	Rects.push_back(MenuBarBase);
	Rects.push_back(HierarchyBase);
	Rects.push_back(InspectorBase);
	Rects.push_back(FileViewerBase);

	OutlineToBeDrawn.push_back(HierarchyBase);
	OutlineToBeDrawn.push_back(InspectorBase);
	OutlineToBeDrawn.push_back(FileViewerBase);

	EditorTextRenderer->Init();

	EditorGui->Init();
}

void Editor::Load()
{
	EditorTextRenderer->Load();

	EditorGui->Load();
}

void Editor::Events()
{
	MousePosition = InputHandling::GetMousePosition();
	IsMouseDown = InputHandling::GetMouseDown();
	MouseScroll = InputHandling::GetMouseScroll();
}

void Editor::Update()
{
	if (IsMouseDown)
	{
		if (CollisionDetection::DetectCollision(MousePosition, HierarchyBase))
		{
			CurrentLayer = "Hierarchy";
		}
		else if (CollisionDetection::DetectCollision(MousePosition, InspectorBase))
		{
			CurrentLayer = "InspectorBase";
		}
		else if (CollisionDetection::DetectCollision(MousePosition, FileViewerBase))
		{
			CurrentLayer = "FileViewer";
		}
		else
		{
			CurrentLayer = "";
		}
	}
}

void Editor::Draw()
{
	SDL_Rect* RectsToArr = new SDL_Rect[Rects.size()];

	if (RectsToArr == nullptr)
	{
		ErrorReporter::LogMessage("Error", "Couldn't Allocate Memory");
		delete[] RectsToArr;
		return;
	}

	for (int i = 0; i < Rects.size(); i++)
	{
		RectsToArr[i] = Rects[i];
	}

	EditorGui->FillRects(RectsToArr, Rects.size(), SceneColour);

	delete[] RectsToArr;

	DrawOutlines();

	DrawTextBase();

	DrawText();
}

void Editor::DrawOutlines()
{
	OutlineRects.clear();

	SDL_Rect* OutlineRectsToArr = new SDL_Rect[OutlineToBeDrawn.size() * 4];

	if (OutlineRectsToArr == nullptr)
	{
		ErrorReporter::LogMessage("Error", "Couldn't Allocate Memory");
		delete[] OutlineRectsToArr;
		return;
	}

	for (int i = 0; i < OutlineToBeDrawn.size(); i++)
	{
		SceneOutlineRect.x = OutlineToBeDrawn[i].x;
		SceneOutlineRect.y = OutlineToBeDrawn[i].y;
		SceneOutlineRect.w = 5;
		SceneOutlineRect.h = OutlineToBeDrawn[i].h;

		OutlineRects.push_back(SceneOutlineRect);
	}

	for (int i = 0; i < OutlineToBeDrawn.size(); i++)
	{
		SceneOutlineRect.x = OutlineToBeDrawn[i].x;
		SceneOutlineRect.y = OutlineToBeDrawn[i].y;
		SceneOutlineRect.w = OutlineToBeDrawn[i].w;
		SceneOutlineRect.h = 5;

		OutlineRects.push_back(SceneOutlineRect);
	}

	for (int i = 0; i < OutlineToBeDrawn.size(); i++)
	{
		SceneOutlineRect.w = 5;
		SceneOutlineRect.x = OutlineToBeDrawn[i].x + OutlineToBeDrawn[i].w - SceneOutlineRect.w;
		SceneOutlineRect.y = OutlineToBeDrawn[i].y;
		SceneOutlineRect.h = OutlineToBeDrawn[i].h;

		OutlineRects.push_back(SceneOutlineRect);
	}

	for (int i = 0; i < OutlineToBeDrawn.size(); i++)
	{
		SceneOutlineRect.x = OutlineToBeDrawn[i].x;
		SceneOutlineRect.h = 5;
		SceneOutlineRect.y = OutlineToBeDrawn[i].y + OutlineToBeDrawn[i].h - SceneOutlineRect.h;
		SceneOutlineRect.w = OutlineToBeDrawn[i].w;

		OutlineRects.push_back(SceneOutlineRect);
	}

	for (int i = 0; i < OutlineRects.size(); i++)
	{
		OutlineRectsToArr[i] = OutlineRects[i];
	}

	EditorGui->FillRects(OutlineRectsToArr, OutlineRects.size(), SceneOutlineColour);

	delete[] OutlineRectsToArr;
}

void Editor::DrawTextBase()
{
	TextBase.clear();

	SDL_Rect* TextBaseRectsToArr = new SDL_Rect[Rects.size()];

	if (TextBaseRectsToArr == nullptr)
	{
		ErrorReporter::LogMessage("Error", "Couldn't Allocate Memory");
		delete[] TextBaseRectsToArr;
		return;
	}

	HierarchyTextBase.x = HierarchyBase.x;
	HierarchyTextBase.y = HierarchyBase.y;
	HierarchyTextBase.w = HierarchyBase.w;
	HierarchyTextBase.h = HierarchyBase.h / 16;

	InspectorTextBase.x = InspectorBase.x;
	InspectorTextBase.y = InspectorBase.y;
	InspectorTextBase.w = InspectorBase.w;
	InspectorTextBase.h = InspectorBase.h / 16;

	TextBase.push_back(HierarchyTextBase);
	TextBase.push_back(InspectorTextBase);

	for (int i = 0; i < TextBase.size(); i++)
	{
		TextBaseRectsToArr[i] = TextBase[i];
	}

	EditorGui->FillRects(TextBaseRectsToArr, TextBase.size(), TextBaseColour);

	delete[] TextBaseRectsToArr;
}

void Editor::DrawText()
{
	SDL_SetRenderDrawBlendMode(Init::Renderer, SDL_BLENDMODE_BLEND);

	if (OldHierarchyTextBase.x != HierarchyTextBase.x || OldHierarchyTextBase.y != HierarchyTextBase.y || OldHierarchyTextBase.w != HierarchyTextBase.w || OldHierarchyTextBase.h != HierarchyTextBase.h)
	{
		OldHierarchyTextBase = HierarchyTextBase;

		HierarchyText.x = HierarchyTextBase.x + HierarchyTextBase.w / 6;
		HierarchyText.y = HierarchyTextBase.y + HierarchyTextBase.h / 4;
		//Use 2
		HierarchyText.w = HierarchyTextBase.w / 1.5;
		HierarchyText.h = HierarchyTextBase.h - (HierarchyTextBase.h / 4);

		SDL_DestroyTexture(HierarchyTextTexture);

		HierarchyTextTexture = EditorTextRenderer->CreateNewTextureCustom("Hierarchy", HierarchyText, Raleway, TextColour);
	}

	TextureManager::Draw(HierarchyTextTexture, 0, &HierarchyText);

	if (OldInspectorTextBase.x != InspectorTextBase.x || OldInspectorTextBase.y != InspectorTextBase.y || OldInspectorTextBase.w != InspectorTextBase.w || OldInspectorTextBase.h != InspectorTextBase.h)
	{
		OldInspectorTextBase = InspectorTextBase;

		InspectorText.x = InspectorTextBase.x + InspectorTextBase.w / 6;
		InspectorText.y = InspectorTextBase.y + InspectorTextBase.h / 4;
		InspectorText.w = InspectorTextBase.w / 1.5;
		InspectorText.h = InspectorTextBase.h - (HierarchyTextBase.h / 4);

		SDL_DestroyTexture(InspectorTextTexture);

		InspectorTextTexture = EditorTextRenderer->CreateNewTextureCustom("Inspector", InspectorText, Raleway, TextColour);
	}


	TextureManager::Draw(InspectorTextTexture, 0, &InspectorText);

	SDL_SetRenderDrawBlendMode(Init::Renderer, SDL_BLENDMODE_NONE);
}

void Editor::Clean()
{
	EditorTextRenderer->Clean();
}
