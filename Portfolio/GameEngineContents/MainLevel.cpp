#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngineBase/GameEngineInput.h>
#include "MainLevel.h"
#include "MainBackGround.h"
#include "MainCursor.h"
#include "Coordinate.h"
#include "BackGround.h"
#include "GamePlayGobal.h"
#include "StageData.h"
#include <GameEngine/GameEngine.h>


Stage MainLevel::CurrentStage_ = Stage::MainStage;

MainLevel::MainLevel()
	:GameWindowStartPosX_(0),
	GameWindowStartPosY_(0) ,
	MapScale_({0, 0}) ,
	MainCursorPos_({0, 0}),
	MainCursor_(nullptr)
{
}

MainLevel::~MainLevel()
{
}


void MainLevel::Loading()
{

	MapScale_ = StageData::Inst_->Scale_[Stage::MainStage];

	CreateActor<BackGround>(0);
	BackGroundScale_ = CreateActor<MainBackGround>(1, "MainBackGround")->GetScale();

	{
		GameWindowStartPosX_ = (GameEngineWindow::GetScale().x - BackGroundScale_.x) / 2;
		GameWindowStartPosY_ = (GameEngineWindow::GetScale().y - BackGroundScale_.y) / 2;
	}

	CreatMap(StageData::Inst_->StageData_[Stage::MainStage]);
	{
		MainMap_[14][10]->SetCFrame(3, 5);
		MainMap_[13][10]->SetCFrame(3, 5);
		MainMap_[12][10]->SetCFrame(6, 8);
		MainMap_[11][10]->SetCFrame(15, 17);
		MainMap_[11][11]->SetCFrame(18, 20);
		MainMap_[12][11]->SetCFrame(12, 14);
		MainMap_[13][11]->SetCFrame(9, 11);
		MainMap_[12][12]->SetCFrame(21, 23);
		MainMap_[11][12]->SetCFrame(6, 8);
	}
	MainCursor_ = CreateActor<MainCursor>(2, "MainCursor");
	MainCursor_->SetPosition(MainMap_[15][9]->GetPosition());
	MainCursorPos_ = { 9, 15 };
}

void MainLevel::Update()
{
	if (GameEngineInput::GetInst()->IsDown("Down"))
	{
		if (MainMap_[MainCursorPos_.iy()+1][MainCursorPos_.ix()] != nullptr)
		{
			MainCursor_->SetPosition((MainCursor_->GetPosition()) + (float4{ 0, 48}));
			MainCursorPos_ += {0, 1};
		}
	}
	if (GameEngineInput::GetInst()->IsDown("Up"))
	{
		if (MainMap_[MainCursorPos_.iy()-1][MainCursorPos_.ix()] != nullptr)
		{
			MainCursor_->SetPosition((MainCursor_->GetPosition()) - (float4{ 0, 48 }));
			MainCursorPos_ -= {0, 1};
		}
	}
	if (GameEngineInput::GetInst()->IsDown("Right"))
	{
		if (MainMap_[MainCursorPos_.iy()][MainCursorPos_.ix()+1] != nullptr)
		{
			MainCursor_->SetPosition((MainCursor_->GetPosition()) + (float4{ 48, 0 }));
			MainCursorPos_ += {1, 0};
		}
	}
	if (GameEngineInput::GetInst()->IsDown("Left"))
	{
		if (MainMap_[MainCursorPos_.iy()][MainCursorPos_.ix()-1] != nullptr)
		{
			MainCursor_->SetPosition((MainCursor_->GetPosition()) - (float4{ 48, 0 }));
			MainCursorPos_ -= {1, 0};
		}
	}


	if (GameEngineInput::GetInst()->IsDown("Space"))
	{
		if (MainCursorPos_.ix() == 9 && MainCursorPos_.iy() == 15)
		{
			CurrentStage_ = Stage::Stage0;
			GameEngine::GetInst().ChangeLevel("PlayLevel");
		}

	}
	if (GameEngineInput::GetInst()->IsDown("R"))
	{

	}
	if (GameEngineInput::GetInst()->IsDown("Space"))
	{

	}

}

void MainLevel::LevelChangeStart()
{
}

void MainLevel::CreatMap(std::map<int, std::map<int, ObjectName>>& _Stage)
{
	for (int y = 0; y < MapScale_.iy(); ++y)
	{
		for (int x = 0; x < MapScale_.ix(); ++x)
		{
			GamePlayObject* Idx = (GamePlayGobal::GetInst()->Find(_Stage[y][x]));
			if (Idx == nullptr)
			{
				continue;
			}
			else
			{
				Coordinate* Coordi = CreateActor<Coordinate>(1);
				Coordi->SetPos({ static_cast<float>(x), static_cast<float>(y) }, { GameWindowStartPosX_ + static_cast<float>(x * DotSizeX), GameWindowStartPosY_ + static_cast<float>(y * DotSizeY)});
				Coordi->SetValue(Idx);
				MainMap_[y][x] = Coordi;
			}
		}
	}
}

//if (Idx == nullptr)
//{
//	Coordinate* Coordi = CreateActor<Coordinate>(1);
//	CPos = { GameWindowPosX_ + static_cast<float>(x * DotSizeX), GameWindowPosY_ + static_cast<float>(y * DotSizeY) };
//	Coordi->Pos_ = { static_cast<float>(x), static_cast<float>(y) };
//	Coordi->CPos_ = CPos;
//	Coordi->Object_ = ObjectName::Baba_Unit;
//	Coordi->SetImg(GamePlayGobal::GetInst()->Find(ObjectName::Baba_Unit)->GetImage());
//}
//else {
//	Coordinate* Coordi = CreateActor<Coordinate>(1);
//	CPos = { GameWindowPosX_ + static_cast<float>(x * DotSizeX), GameWindowPosY_ + static_cast<float>(y * DotSizeY) };
//	Coordi->Pos_ = { static_cast<float>(x), static_cast<float>(y) };
//	Coordi->CPos_ = CPos;
//	Coordi->Object_ = _Stage[y][x];
//	Coordi->SetImg(Idx->GetImage());
//	MainMap_[y][x] = Coordi;
//}