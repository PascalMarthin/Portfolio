#include "MainLevel.h"
#include "MainBackGround.h"
#include "MainCursor.h"
#include "Coordinate.h"
#include "BackGround.h"
#include <GameEngineBase/GameEngineWindow.h>
#include "GamePlayGobal.h"
#include "StageData.h"

MainLevel::MainLevel()
	:GameWindowPosX_(0),
	GameWindowPosY_(0) ,
	MapScale_({0, 0})
{
}

MainLevel::~MainLevel()
{
}


void MainLevel::Loading()
{
	MapScale_ = StageData::Inst_->Scale_[0];
	GameWindowPosX_ = GameEngineWindow::GetScale().Half().x + 24 - MapScale_.x * 24;
	GameWindowPosY_ = GameEngineWindow::GetScale().Half().y + 24 - MapScale_.y * 24;
	CreatMap(StageData::Inst_->StageData_[0]);

}

void MainLevel::Update()
{


}

void MainLevel::LevelChangeStart()
{
	CreateActor<BackGround>(0);
	CreateActor<MainBackGround>(1, "MainBackGround");
	//CreateActor<MainStage>("MainStage", 2);
	//CreateActor<MainCursor>(2, "MainCursor");
}

void MainLevel::CreatMap(std::map<int, std::map<int, ObjectName>>& _Stage)
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
			MainMap_[y][x].push_back(Coordi);
		}
	}
}