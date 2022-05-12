#include "PlayBackGround.h"
#include <GameEngineBase/GameEngineWindow.h>
#include "GamePlayEnum.h"

PlayBackGround::PlayBackGround()
{
}

PlayBackGround::~PlayBackGround()
{
}


void PlayBackGround::Start()
{
	SetPosition(GameEngineWindow::GetScale().Half());
}

void PlayBackGround::Update()
{
}

void PlayBackGround::Render()
{

}