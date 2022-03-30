#include "TitleMenu.h"
#include <Windows.h>
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>
#include <map>


BabaLocation TitleMenu::BabaTitleLocate = BabaLocation::Baba;

TitleMenu::TitleMenu()
	: StartPos_(0, 0)
	, SettingPos_(0, 0)
	, ExitPos_(0, 0)
	, BabaPos_(0, 0)
	, BabaPosFF_(-330, 0)
{
}

TitleMenu::~TitleMenu()
{
}



void TitleMenu::Start()
{
	//// GameEngineWindow::GetScale().Half() È­¸é Áß¾Ó
	//SetPosition(GameEngineWindow::GetScale().Half());
	////SetScale({ 10, 100 });
	//StartPos_ = GetPosition() + float4{0, 100};
	//SettingPos_ = GetPosition() + float4{ 0, 190 };
	//ExitPos_ = GetPosition() + float4{ 0, 280 };
	//

	//TilteMenuImage[BabaLocation::Baba].push_back(GameEngineImageManager::GetInst()->Find("unit_baba_right_Sheet.bmp"));
	////TilteMenuImage[BabaLocation::Null].push_back(CreateRenderer("baba_0_2.bmp", RenderPivot::CENTER, { -320 , 100 }));
	////TilteMenuImage[BabaLocation::Null].push_back(CreateRenderer("baba_0_3.bmp", RenderPivot::CENTER, { -320 , 100 }));
	//BabaTitleLocate = BabaLocation::Start_the_Game;

	//TilteMenuImage[BabaLocation::Start_the_Game].push_back(GameEngineImageManager::GetInst()->Find("Start_the_Game1.bmp"));
	//TilteMenuImage[BabaLocation::Start_the_Game].push_back(GameEngineImageManager::GetInst()->Find("Start_the_Game2.bmp"));
	//TilteMenuImage[BabaLocation::Settings].push_back(GameEngineImageManager::GetInst()->Find("Settings1.bmp"));
	//TilteMenuImage[BabaLocation::Settings].push_back(GameEngineImageManager::GetInst()->Find("Settings2.bmp"));
	//TilteMenuImage[BabaLocation::Exit_The_Game].push_back(GameEngineImageManager::GetInst()->Find("Exit_The_Game1.bmp"));
	//TilteMenuImage[BabaLocation::Exit_The_Game].push_back(GameEngineImageManager::GetInst()->Find("Exit_The_Game2.bmp"));

}

void TitleMenu::Update()
{

}
//RGB(255, 0, 255)
void TitleMenu::Render()
{

	//GameEngine::BackBufferImage()->TransCopy(TilteMenuImage[BabaLocation::Start_the_Game][0], StartPos_, RGB(255, 0, 255));
	//GameEngine::BackBufferImage()->TransCopy(TilteMenuImage[BabaLocation::Settings][0], SettingPos_, RGB(255, 0, 255));
	//GameEngine::BackBufferImage()->TransCopy(TilteMenuImage[BabaLocation::Exit_The_Game][0], ExitPos_, RGB(255, 0, 255));
	//switch (BabaTitleLocate)
	//{
	//case BabaLocation::Start_the_Game:
	//	GameEngine::BackBufferImage()->TransCopy(TilteMenuImage[BabaLocation::Start_the_Game][1], StartPos_, RGB(255, 0, 255));
	//	BabaPos_ = StartPos_ + BabaPosFF_;
	//	break;
	//case BabaLocation::Settings:
	//	GameEngine::BackBufferImage()->TransCopy(TilteMenuImage[BabaLocation::Settings][1], SettingPos_, RGB(255, 0, 255));
	//	BabaPos_ = SettingPos_ + BabaPosFF_;
	//	break;
	//case BabaLocation::Exit_The_Game:
	//	GameEngine::BackBufferImage()->TransCopy(TilteMenuImage[BabaLocation::Exit_The_Game][1], ExitPos_, RGB(255, 0, 255));
	//	BabaPos_ = ExitPos_ + BabaPosFF_;
	//	break;
	//default:
	//	MsgBoxAssert("BabaTitleLocate_Swicth Error");
	//	break;
	//}
	//GameEngine::BackBufferImage()->TransCopy(TilteMenuImage[BabaLocation::Baba][0], BabaPos_, RGB(255, 0, 255));

}