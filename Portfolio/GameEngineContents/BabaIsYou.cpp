#include "BabaIsYou.h"
#include "PlayLevel.h"
#include "TitleLevel.h"
#include "MainLevel.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineBase/GameEngineFile.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngineBase/GameEngineInput.h>
#include "GamePlayGobal.h"


BabaIsYou::BabaIsYou() 
{
}

BabaIsYou::~BabaIsYou() 
{
}

void BabaIsYou::GameInit()
{
	GamePlayGobal::GetInst();
	GameEngineWindow::GetInst().SetWindowScaleAndPosition({ 100, 100 }, { 1700, 880 });
	CreateKeyBaba();

	// ���ҽ� ���� ��ġ ����
	GameEngineDirectory ResourcesDir;
	ResourcesDir.MoveParent("Portfolio");
	ResourcesDir.Move("Resources");
	ResourcesDir.Move("Sprites");

	// ���
	ResourcesDir.Move("BackGround");
	std::vector<GameEngineFile> AllImageFileList = ResourcesDir.GetAllFile("Bmp");
	for (size_t i = 0; i < AllImageFileList.size(); i++)
	{
		GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
	}

	// Ÿ��Ʋ�ΰ�
	ResourcesDir.MoveParent("Sprites");
	ResourcesDir.Move("Ui");
	ResourcesDir.Move("TitleLogo");
	AllImageFileList = ResourcesDir.GetAllFile("Bmp");
	for (size_t i = 0; i < AllImageFileList.size(); i++)
	{
		GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
	}
	
	// Ÿ��Ʋ�Ŵ�
	ResourcesDir.MoveParent("Ui");
	ResourcesDir.Move("TitleMenu");
	AllImageFileList = ResourcesDir.GetAllFile("Bmp");
	for (size_t i = 0; i < AllImageFileList.size(); i++)
	{
		GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
	}

	// ���θ޴�
	ResourcesDir.MoveParent("Ui");
	ResourcesDir.Move("MainMenu");
	AllImageFileList = ResourcesDir.GetAllFile("Bmp");
	for (size_t i = 0; i < AllImageFileList.size(); i++)
	{
		GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
	}

	// ���� UI
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


	CreateLevel<TitleLevel>("TitleLevel");
	CreateLevel<MainLevel>("MainLevel");
	CreateLevel<PlayLevel>("PlayLevel");

	//CreateLevel<EndingLevel>("Ending");
	ChangeLevel("TitleLevel");
}
void BabaIsYou::GameLoop()
{

}
void BabaIsYou::GameEnd()
{
	GamePlayGobal::GetInst()->Destroy();

}

void BabaIsYou::CreateKeyBaba()
{
	if (false == GameEngineInput::GetInst()->IsKey("MoveLeft"))
	{
		// �̶� �빮�ڿ��� �մϴ�.
		GameEngineInput::GetInst()->CreateKey("Left", VK_LEFT);
		GameEngineInput::GetInst()->CreateKey("Right", VK_RIGHT);
		GameEngineInput::GetInst()->CreateKey("Up", VK_UP);
		GameEngineInput::GetInst()->CreateKey("Down", VK_DOWN);
		GameEngineInput::GetInst()->CreateKey("Enter", VK_RETURN);
		GameEngineInput::GetInst()->CreateKey("R", 'r');
		GameEngineInput::GetInst()->CreateKey("Z", 'z');
		GameEngineInput::GetInst()->CreateKey("Space", VK_SPACE);
		// VK_LBUTTON;
	}
}