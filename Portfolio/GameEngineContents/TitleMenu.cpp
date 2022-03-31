#include "TitleMenu.h"
#include "TitleBaba.h"
#include <Windows.h>
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineRenderer.h>
#include <map>

TitleMenu::TitleMenu()
	: StartPos_(0, 0)
	, SettingPos_(0, 0)
	, ExitPos_(0, 0)

{
}

TitleMenu::~TitleMenu()
{
}



void TitleMenu::Start()
{
	SetPosition(GameEngineWindow::GetScale().Half());

	StartPos_ = GetPosition() + float4{0, 100};
	SettingPos_ = GetPosition() + float4{ 0, 190 };
	ExitPos_ = GetPosition() + float4{ 0, 280 };

	TilteMenuImage[BabaLocation::Start_The_Game].push_back(GameEngineImageManager::GetInst()->Find("Start_the_Game1.bmp"));
	TilteMenuImage[BabaLocation::Start_The_Game].push_back(GameEngineImageManager::GetInst()->Find("Start_the_Game2.bmp"));
	TilteMenuImage[BabaLocation::Settings].push_back(GameEngineImageManager::GetInst()->Find("Settings1.bmp"));
	TilteMenuImage[BabaLocation::Settings].push_back(GameEngineImageManager::GetInst()->Find("Settings2.bmp"));
	TilteMenuImage[BabaLocation::Exit_The_Game].push_back(GameEngineImageManager::GetInst()->Find("Exit_The_Game1.bmp"));
	TilteMenuImage[BabaLocation::Exit_The_Game].push_back(GameEngineImageManager::GetInst()->Find("Exit_The_Game2.bmp"));

}

void TitleMenu::Update()
{
	

}

void TitleMenu::Render()
{

	switch (TitleBaba::BabaTitleLocate_)
	{
	case BabaLocation::Start_The_Game:
		GameEngine::BackBufferImage()->TransCopy(TilteMenuImage[BabaLocation::Start_The_Game][1], StartPos_, RGB(255, 0, 255));
		GameEngine::BackBufferImage()->TransCopy(TilteMenuImage[BabaLocation::Settings][0], SettingPos_, RGB(255, 0, 255));
		GameEngine::BackBufferImage()->TransCopy(TilteMenuImage[BabaLocation::Exit_The_Game][0], ExitPos_, RGB(255, 0, 255));
		break;
	case BabaLocation::Settings:
		GameEngine::BackBufferImage()->TransCopy(TilteMenuImage[BabaLocation::Settings][1], SettingPos_, RGB(255, 0, 255));
		GameEngine::BackBufferImage()->TransCopy(TilteMenuImage[BabaLocation::Start_The_Game][0], StartPos_, RGB(255, 0, 255));
		GameEngine::BackBufferImage()->TransCopy(TilteMenuImage[BabaLocation::Exit_The_Game][0], ExitPos_, RGB(255, 0, 255));
		break;
	case BabaLocation::Exit_The_Game:
		GameEngine::BackBufferImage()->TransCopy(TilteMenuImage[BabaLocation::Exit_The_Game][1], ExitPos_, RGB(255, 0, 255));
		GameEngine::BackBufferImage()->TransCopy(TilteMenuImage[BabaLocation::Start_The_Game][0], StartPos_, RGB(255, 0, 255));
		GameEngine::BackBufferImage()->TransCopy(TilteMenuImage[BabaLocation::Settings][0], SettingPos_, RGB(255, 0, 255));
		break;
	default:
		break;
	}

}