#include "GameEngineActor.h"
#include <GameEngineBase/GameEngineWindow.h>

GameEngineActor::GameEngineActor() 
	: Level_(nullptr)
{
}

GameEngineActor::~GameEngineActor() 
{
}


void GameEngineActor::DebugRectRender()
{
	// 선생님은 기본적으로 중앙을 기준으로하는걸 좋아합니다.

	GameEngineRect DebugRect(Position_, Scale_);

	for (int i = 0; i < 100; i++)
	{
		SetPixel(GameEngineWindow::GetHDC(), 100 + i, 100, RGB(255, 0, 0));
	}



	Rectangle(
		GameEngineWindow::GetHDC(), 
		DebugRect.CenterLeft(),
		DebugRect.CenterTop(),
		DebugRect.CenterRight(),
		DebugRect.CenterBot()
	);
}