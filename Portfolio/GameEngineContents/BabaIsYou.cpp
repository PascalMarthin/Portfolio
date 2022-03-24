#include "BabaIsYou.h"
#include "PlayLevel.h"
#include "TitleLevel.h"
#include "MainLevel.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineBase/GameEngineFile.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngineBase/GameEngineInput.h>


BabaIsYou::BabaIsYou() 
{
}

BabaIsYou::~BabaIsYou() 
{
}

void BabaIsYou::GameInit()
{
	GameEngineWindow::GetInst().SetWindowScaleAndPosition({ 100, 100 }, { 1920, 1080 });

	CreateKeyBaba();

	// 리소스 파일 위치 적용
	GameEngineDirectory ResourcesDir;
	ResourcesDir.MoveParent("Portfolio");
	ResourcesDir.Move("Resources");
	ResourcesDir.Move("Sprites");

	// 배경
	ResourcesDir.Move("BackGround");
	std::vector<GameEngineFile> AllImageFileList = ResourcesDir.GetAllFile("Bmp");
	for (size_t i = 0; i < AllImageFileList.size(); i++)
	{
		GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
	}

	// 타이틀로고
	ResourcesDir.MoveParent("Sprites");
	ResourcesDir.Move("Ui");
	ResourcesDir.Move("TitleLogo");
	AllImageFileList = ResourcesDir.GetAllFile("Bmp");
	for (size_t i = 0; i < AllImageFileList.size(); i++)
	{
		GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
	}
	
	// 타이틀매뉴
	ResourcesDir.MoveParent("Ui");
	ResourcesDir.Move("TitleMenu");
	AllImageFileList = ResourcesDir.GetAllFile("Bmp");
	for (size_t i = 0; i < AllImageFileList.size(); i++)
	{
		GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
	}

	// 메인메뉴
	ResourcesDir.MoveParent("Ui");
	ResourcesDir.Move("MainMenu");
	AllImageFileList = ResourcesDir.GetAllFile("Bmp");
	for (size_t i = 0; i < AllImageFileList.size(); i++)
	{
		GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
	}

	// 게임 UI
	ResourcesDir.MoveParent("Ui");
	ResourcesDir.Move("Game_UI");
	AllImageFileList = ResourcesDir.GetAllFile("Bmp");
	for (size_t i = 0; i < AllImageFileList.size(); i++)
	{
		GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
	}

	// BABA OBJECT
	ResourcesDir.MoveParent("Sprites");
	ResourcesDir.Move("Object");
	ResourcesDir.Move("Object");
	ResourcesDir.Move("it");
	ResourcesDir.Move("baba");
	AllImageFileList = ResourcesDir.GetAllFile("Bmp");
	for (size_t i = 0; i < AllImageFileList.size(); i++)
	{
		GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
	}


	CreateLevel<TitleLevel>("Title");
	CreateLevel<MainLevel>("Main");
	CreateLevel<PlayLevel>("Play");

	//CreateLevel<EndingLevel>("Ending");
	ChangeLevel("Main");
}
void BabaIsYou::GameLoop()
{

}
void BabaIsYou::GameEnd()
{

}

void BabaIsYou::CreateKeyBaba()
{
	if (false == GameEngineInput::GetInst()->IsKey("MoveLeft"))
	{
		// 이때 대문자여야 합니다.
		GameEngineInput::GetInst()->CreateKey("Left", VK_LEFT);
		GameEngineInput::GetInst()->CreateKey("Right", VK_RIGHT);
		GameEngineInput::GetInst()->CreateKey("Up", VK_UP);
		GameEngineInput::GetInst()->CreateKey("Down", VK_DOWN);
		GameEngineInput::GetInst()->CreateKey("Enter", VK_RETURN);
		GameEngineInput::GetInst()->CreateKey("R", 'r');
		GameEngineInput::GetInst()->CreateKey("Space", VK_SPACE);
		// VK_LBUTTON;
	}
}