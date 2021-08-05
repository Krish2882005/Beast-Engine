// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

//This Is A Beast Engine File Which Has The License Apache 2.0

#include "Editor.h"
#include "Init.h"
#include "InputHandling.h"
#include "BeastGui.h"
#include "ErrorReporter.h"

BeastGui* EditorGui = new BeastGui();

void Editor::Init()
{
	Rects.push_back(MenuBarBase);
	Rects.push_back(HierarchyBase);
	Rects.push_back(InspectorBase);
	Rects.push_back(FileViewerBase);

	OutlineToBeDrawn.push_back(HierarchyBase);
	OutlineToBeDrawn.push_back(InspectorBase);
	OutlineToBeDrawn.push_back(FileViewerBase);
}

void Editor::Load()
{

}

void Editor::Events()
{
	MousePosition = InputHandling::GetMousePosition();
	IsMouseDown = InputHandling::GetMouseDown();
	MouseScroll = InputHandling::GetMouseScroll();
}

void Editor::Update()
{

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

	Colour = { 195, 195, 195, 255 };

	EditorGui->DrawRects(RectsToArr, Rects.size(), Colour);
	EditorGui->FillRects(RectsToArr, Rects.size(), Colour);

	delete[] RectsToArr;

	DrawOutlines();
}

void Editor::DrawOutlines()
{
	OutlineRects.clear();

	for (int i = 0; i < OutlineToBeDrawn.size(); i++)
	{
		OutlineRect.x = OutlineToBeDrawn[i].x;
		OutlineRect.y = OutlineToBeDrawn[i].y;
		OutlineRect.w = 5;
		OutlineRect.h = OutlineToBeDrawn[i].h;

		OutlineRects.push_back(OutlineRect);
	}

	for (int i = 0; i < OutlineToBeDrawn.size(); i++)
	{
		OutlineRect.x = OutlineToBeDrawn[i].x;
		OutlineRect.y = OutlineToBeDrawn[i].y;
		OutlineRect.w = OutlineToBeDrawn[i].w;
		OutlineRect.h = 5;

		OutlineRects.push_back(OutlineRect);
	}

	for (int i = 0; i < OutlineToBeDrawn.size(); i++)
	{
		OutlineRect.w = 5;
		OutlineRect.x = OutlineToBeDrawn[i].x + OutlineToBeDrawn[i].w - OutlineRect.w;
		OutlineRect.y = OutlineToBeDrawn[i].y;
		OutlineRect.h = OutlineToBeDrawn[i].h;

		OutlineRects.push_back(OutlineRect);
	}

	for (int i = 0; i < OutlineToBeDrawn.size(); i++)
	{
		OutlineRect.x = OutlineToBeDrawn[i].x;
		OutlineRect.h = 5;
		OutlineRect.y = OutlineToBeDrawn[i].y + OutlineToBeDrawn[i].h - OutlineRect.h;
		OutlineRect.w = OutlineToBeDrawn[i].w;

		OutlineRects.push_back(OutlineRect);
	}

	SDL_Rect* OutlineRectsToArr = new SDL_Rect[OutlineRects.size()];

	for (int i = 0; i < OutlineRects.size(); i++)
	{
		OutlineRectsToArr[i] = OutlineRects[i];
	}

	EditorGui->DrawRects(OutlineRectsToArr, OutlineRects.size(), OutlineColour);
	EditorGui->FillRects(OutlineRectsToArr, OutlineRects.size(), OutlineColour);

	delete[] OutlineRectsToArr;
}

void Editor::Clean()
{

}
