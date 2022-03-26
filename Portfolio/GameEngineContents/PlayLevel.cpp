#include "PlayLevel.h"
#include "Coordinate.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineLevel.h>
#include <GameEngineBase/GameEngineInput.h>

#include "Baba.h"

PlayLevel::PlayLevel() 
	: WindowHalfScale(GameEngineWindow::GetInst().GetScale().Half()),
	GameWindowPosX_( 0 ),
	GameWindowPosY_( 0 ),
	MapScale_({0, 0}),
	CurrentMap_(nullptr)
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

	// ¸Ê ½ºÄµÇÑ´Ù
	// ScanMap();
	// fucn();

}

void PlayLevel::LevelChangeStart()
{
	MapScale_ = { 33, 18 };
	GameWindowPosX_ = WindowHalfScale.x + 24 - MapScale_.x * 24;
	GameWindowPosY_ = WindowHalfScale.y + 24 - MapScale_.y * 24;
	CreatMap();

	EndGame();
}

void PlayLevel::CreatMap()
{
	float4 CPos;
	std::map<int, std::map<int, Coordinate*>>* Makemap = new std::map<int, std::map<int, Coordinate*>>;
	for (int y = 0; y < MapScale_.iy(); ++y)
	{
		for (int x = 0; x < MapScale_.ix(); ++x)
		{
			Coordinate* Coordi = new Coordinate();
			CPos = { GameWindowPosX_ + static_cast<float>(x * 48), GameWindowPosY_ + static_cast<float>(y * 48) };
			Coordi->Pos_ = { static_cast<float>(x), static_cast<float>(y) };
			Coordi->CPos_ = CPos;
			Coordi->Object_[ObjectName::Baba_Object] = CreateActor<Baba_Unit>(2);
			(Coordi->Object_[ObjectName::Baba_Object])->SetObjectCPos(CPos);
			(*Makemap)[y][x] = Coordi;
		}
	}
	CurrentMap_ = Makemap;

	
}

void PlayLevel::MoveMap()
{

}

void PlayLevel::ScanMap()
{

}

void PlayLevel::EndGame()
{
	if (CurrentMap_ == nullptr)
	{
		MsgBoxAssert("PlayLevel CurrentMap_ is nullptr");
	}

	std::map<int, std::map<int, Coordinate*>>::iterator StartIter = CurrentMap_->begin();
	std::map<int, std::map<int, Coordinate*>>::iterator EndIter = CurrentMap_->end();

	
	std::map<int, Coordinate*>::iterator StartIt;
	std::map<int, Coordinate*>::iterator EndIt;

	for (; StartIter != EndIter; ++StartIter)
	{
		StartIt = (StartIter->second).begin();
		EndIt = (StartIter->second).end();

		for (;StartIt != EndIt; ++StartIt)
		{
			if (StartIt->second != nullptr)
			{
				delete StartIt->second;
				(StartIt->second) = nullptr;
			}
		}
	}
	delete CurrentMap_;
	CurrentMap_ = nullptr;

}