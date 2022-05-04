#include <GameEngineBase/GameEngineWindow.h>
#include "GamePlayEnum.h"
#include "GameHelpMoveUI.h"

GameHelpMoveUI::GameHelpMoveUI() 
{
}

GameHelpMoveUI::~GameHelpMoveUI() 
{
}


void GameHelpMoveUI::Start()
{
	SetPosition(GameEngineWindow::GetScale().Half());

	CreateRendererToScale("Arrow.bmp", { 144, 96 }, 1, RenderPivot::CENTER, { 0,-330 });
	CreateRenderer("move.bmp", 1, RenderPivot::CENTER, { 0,-250 });

}
void GameHelpMoveUI::Update()
{

}

void GameHelpMoveUI::Render()
{
}