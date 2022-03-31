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

}

void MainLevel::Update()
{


}

void MainLevel::LevelChangeStart()
{
	CreateActor<BackGround>(0);
	BackGroundScale_ = CreateActor<MainBackGround>(1, "MainBackGround")->GetScale();
	//CreateActor<MainCursor>(2, "MainCursor");

	MapScale_ = StageData::Inst_->Scale_[0];
	GameWindowPosX_ = GameEngineWindow::GetScale().Half().x - BackGroundScale_.Half().x;
	GameWindowPosY_ = GameEngineWindow::GetScale().Half().y - BackGroundScale_.Half().y;
	CreatMap(StageData::Inst_->StageData_[0]);
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
			else
			{
				Coordinate* Coordi = CreateActor<Coordinate>(1);
				CPos = { GameWindowPosX_ + static_cast<float>(x * DotSizeX), GameWindowPosY_ + static_cast<float>(y * DotSizeY) };
				Coordi->Pos_ = { static_cast<float>(x), static_cast<float>(y) };
				Coordi->CPos_ = CPos;
				Coordi->Object_ = _Stage[y][x];
				Coordi->SetImg(Idx->GetImage());
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