#include "PlayLevel.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineLevel.h>
#include <GameEngineBase/GameEngineInput.h>
#include "Coordinate.h"
#include "BackGround.h"

PlayLevel::PlayLevel() 
	:GameWindowPosX_(0),
	GameWindowPosY_(0)
{
}

PlayLevel::~PlayLevel() 
{
	StageData::Destroy();
}


void PlayLevel::Loading()
{

}

void PlayLevel::Update()
{

	//if (GameEngineInput::GetInst()->IsDown("Down"))
	//{
	//	//Move();
	//}
	//if (GameEngineInput::GetInst()->IsDown("Up"))
	//{
	//	
	//}

	//if (GameEngineInput::GetInst()->IsDown("Right"))
	//{

	//}
	//if (GameEngineInput::GetInst()->IsDown("Left"))
	//{

	//}


	//if (GameEngineInput::GetInst()->IsPress("Space"))
	//{

	//}
	//if (GameEngineInput::GetInst()->IsPress("R"))
	//{

	//}
	//if (GameEngineInput::GetInst()->IsPress("Space"))
	//{

	//}

}

void PlayLevel::LevelChangeStart()
{
	CreateActor<BackGround>(0);
	MapScale_ = StageData::Inst_->Scale_[0];
	GameWindowPosX_ = GameEngineWindow::GetScale().Half().x + 24 - MapScale_.x * 24;
	GameWindowPosY_ = GameEngineWindow::GetScale().Half().y + 24 - MapScale_.y * 24;
	CreatMap(StageData::Inst_->StageData_[0]);

}


void PlayLevel::CreatMap(std::map<int, std::map<int, ObjectName>>& _Stage)
{

	float4 CPos;
	for (int y = 0; y < MapScale_.iy(); ++y)
	{
		for (int x = 0; x < MapScale_.ix(); ++x)
		{
			GamePlayObject* Idx = (GamePlayGobal::GetInst()->Find(_Stage[y][x]));
			if (Idx == nullptr)
			{
				continue;
			}
			Coordinate* Coordi = CreateActor<Coordinate>(1);
			CPos = { GameWindowPosX_ + static_cast<float>(x * DotSizeX), GameWindowPosY_ + static_cast<float>(y * DotSizeY) };
			Coordi->Pos_ = { static_cast<float>(x), static_cast<float>(y) };
			Coordi->CPos_ = CPos;
			Coordi->Object_ = _Stage[y][x];
			Coordi->SetImg(Idx->GetImage());
			CurrentMap_[y][x] = Coordi;
		}
	}
}
//void PlayLevel::MoveMap()
//{
//
//}
//
//void PlayLevel::ScanMap()
//{
//
//}