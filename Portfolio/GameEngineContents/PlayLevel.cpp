#include "PlayLevel.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineLevel.h>
#include <GameEngineBase/GameEngineInput.h>

PlayLevel::PlayLevel() 
{
}

PlayLevel::~PlayLevel() 
{
}


void PlayLevel::Loading()
{

}

void PlayLevel::Update()
{

	if (GameEngineInput::GetInst()->IsDown("Down"))
	{
		//Move();
	}
	if (GameEngineInput::GetInst()->IsDown("Up"))
	{
		
	}

	if (GameEngineInput::GetInst()->IsDown("Right"))
	{

	}
	if (GameEngineInput::GetInst()->IsDown("Left"))
	{

	}


	if (GameEngineInput::GetInst()->IsPress("Space"))
	{

	}
	if (GameEngineInput::GetInst()->IsPress("R"))
	{

	}
	if (GameEngineInput::GetInst()->IsPress("Space"))
	{

	}

}

void PlayLevel::LevelChangeStart()
{

}

