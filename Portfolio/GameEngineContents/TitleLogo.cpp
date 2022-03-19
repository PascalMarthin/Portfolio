#include "TitleLogo.h"
#include <Windows.h>
#include <GameEngineBase/GameEngineWindow.h>

TitleLogo::TitleLogo()
{
}

TitleLogo::~TitleLogo()
{
}



void TitleLogo::Start()
{
	// GameEngineWindow::GetScale().Half() ȭ�� �߾�
	SetPosition(GameEngineWindow::GetScale().Half());
	SetScale({ 200, 500 });
}

void TitleLogo::Render()
{
	DebugRectRender();
}