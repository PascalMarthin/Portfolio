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

	{
	// BABA OBJECT
		{
			GameEngineDirectory ResourcesDir;
			ResourcesDir.MoveParent("Portfolio");
			ResourcesDir.Move("Resources");
			ResourcesDir.Move("Sprites");
			ResourcesDir.Move("Object");
			ResourcesDir.Move("Object");
			ResourcesDir.Move("it");
			ResourcesDir.Move("baba");
			AllImageFileList = ResourcesDir.GetAllFile("Bmp");
			for (size_t i = 0; i < AllImageFileList.size(); i++)
			{
				GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
			}
		}
		// flag
		{
			GameEngineDirectory ResourcesDir;
			ResourcesDir.MoveParent("Portfolio");
			ResourcesDir.Move("Resources");
			ResourcesDir.Move("Sprites");
			ResourcesDir.Move("Object");
			ResourcesDir.Move("Object");
			ResourcesDir.Move("it");
			ResourcesDir.Move("flag");
			AllImageFileList = ResourcesDir.GetAllFile("Bmp");
			for (size_t i = 0; i < AllImageFileList.size(); i++)
			{
				GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
			}
		}

		// grass
		{
			GameEngineDirectory ResourcesDir;
			ResourcesDir.MoveParent("Portfolio");
			ResourcesDir.Move("Resources");
			ResourcesDir.Move("Sprites");
			ResourcesDir.Move("Object");
			ResourcesDir.Move("Object");
			ResourcesDir.Move("it");
			ResourcesDir.Move("grass");
			AllImageFileList = ResourcesDir.GetAllFile("Bmp");
			for (size_t i = 0; i < AllImageFileList.size(); i++)
			{
				GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
			}
		}

		// lava
		{
			GameEngineDirectory ResourcesDir;
ResourcesDir.MoveParent("Portfolio");
ResourcesDir.Move("Resources");
ResourcesDir.Move("Sprites");
ResourcesDir.Move("Object");
ResourcesDir.Move("Object");
ResourcesDir.Move("it");
ResourcesDir.Move("lava");
AllImageFileList = ResourcesDir.GetAllFile("Bmp");
for (size_t i = 0; i < AllImageFileList.size(); i++)
{
	GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
}
		}

		// rock
		{
		GameEngineDirectory ResourcesDir;
		ResourcesDir.MoveParent("Portfolio");
		ResourcesDir.Move("Resources");
		ResourcesDir.Move("Sprites");
		ResourcesDir.Move("Object");
		ResourcesDir.Move("Object");
		ResourcesDir.Move("it");
		ResourcesDir.Move("rock");
		AllImageFileList = ResourcesDir.GetAllFile("Bmp");
		for (size_t i = 0; i < AllImageFileList.size(); i++)
		{
			GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
		}
		}

		// skull
		{
			GameEngineDirectory ResourcesDir;
			ResourcesDir.MoveParent("Portfolio");
			ResourcesDir.Move("Resources");
			ResourcesDir.Move("Sprites");
			ResourcesDir.Move("Object");
			ResourcesDir.Move("Object");
			ResourcesDir.Move("it");
			ResourcesDir.Move("skull");
			AllImageFileList = ResourcesDir.GetAllFile("Bmp");
			for (size_t i = 0; i < AllImageFileList.size(); i++)
			{
				GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
			}
		}

		// tile
		{
			GameEngineDirectory ResourcesDir;
			ResourcesDir.MoveParent("Portfolio");
			ResourcesDir.Move("Resources");
			ResourcesDir.Move("Sprites");
			ResourcesDir.Move("Object");
			ResourcesDir.Move("Object");
			ResourcesDir.Move("it");
			ResourcesDir.Move("tile");
			AllImageFileList = ResourcesDir.GetAllFile("Bmp");
			for (size_t i = 0; i < AllImageFileList.size(); i++)
			{
				GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
			}
		}

		// wall
		{
			GameEngineDirectory ResourcesDir;
			ResourcesDir.MoveParent("Portfolio");
			ResourcesDir.Move("Resources");
			ResourcesDir.Move("Sprites");
			ResourcesDir.Move("Object");
			ResourcesDir.Move("Object");
			ResourcesDir.Move("it");
			ResourcesDir.Move("wall");
			AllImageFileList = ResourcesDir.GetAllFile("Bmp");
			for (size_t i = 0; i < AllImageFileList.size(); i++)
			{
				GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
			}
		}

		// water
		{
			GameEngineDirectory ResourcesDir;
			ResourcesDir.MoveParent("Portfolio");
			ResourcesDir.Move("Resources");
			ResourcesDir.Move("Sprites");
			ResourcesDir.Move("Object");
			ResourcesDir.Move("Object");
			ResourcesDir.Move("it");
			ResourcesDir.Move("water");
			AllImageFileList = ResourcesDir.GetAllFile("Bmp");
			for (size_t i = 0; i < AllImageFileList.size(); i++)
			{
				GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
			}
		}
	}

	{
	// baba
		{
			GameEngineDirectory ResourcesDir;
			ResourcesDir.MoveParent("Portfolio");
			ResourcesDir.Move("Resources");
			ResourcesDir.Move("Sprites");
			ResourcesDir.Move("Object");
			ResourcesDir.Move("Object");
			ResourcesDir.Move("Text");
			ResourcesDir.Move("baba");
			AllImageFileList = ResourcesDir.GetAllFile("Bmp");
			for (size_t i = 0; i < AllImageFileList.size(); i++)
			{
				GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
			}
		}

		// defeat
		{
			GameEngineDirectory ResourcesDir;
			ResourcesDir.MoveParent("Portfolio");
			ResourcesDir.Move("Resources");
			ResourcesDir.Move("Sprites");
			ResourcesDir.Move("Object");
			ResourcesDir.Move("Object");
			ResourcesDir.Move("Text");
			ResourcesDir.Move("defeat");
			AllImageFileList = ResourcesDir.GetAllFile("Bmp");
			for (size_t i = 0; i < AllImageFileList.size(); i++)
			{
				GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
			}
		}

		// flag
		{
			GameEngineDirectory ResourcesDir;
			ResourcesDir.MoveParent("Portfolio");
			ResourcesDir.Move("Resources");
			ResourcesDir.Move("Sprites");
			ResourcesDir.Move("Object");
			ResourcesDir.Move("Object");
			ResourcesDir.Move("Text");
			ResourcesDir.Move("flag");
			AllImageFileList = ResourcesDir.GetAllFile("Bmp");
			for (size_t i = 0; i < AllImageFileList.size(); i++)
			{
				GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
			}
		}

		// grass

		// hot
		{
			GameEngineDirectory ResourcesDir;
			ResourcesDir.MoveParent("Portfolio");
			ResourcesDir.Move("Resources");
			ResourcesDir.Move("Sprites");
			ResourcesDir.Move("Object");
			ResourcesDir.Move("Object");
			ResourcesDir.Move("Text");
			ResourcesDir.Move("hot");
			AllImageFileList = ResourcesDir.GetAllFile("Bmp");
			for (size_t i = 0; i < AllImageFileList.size(); i++)
			{
				GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
			}
		}
		//is
		{
			GameEngineDirectory ResourcesDir;
			ResourcesDir.MoveParent("Portfolio");
			ResourcesDir.Move("Resources");
			ResourcesDir.Move("Sprites");
			ResourcesDir.Move("Object");
			ResourcesDir.Move("Object");
			ResourcesDir.Move("Text");
			ResourcesDir.Move("is");
			AllImageFileList = ResourcesDir.GetAllFile("Bmp");
			for (size_t i = 0; i < AllImageFileList.size(); i++)
			{
				GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
			}
		}
		// lava
		{
			GameEngineDirectory ResourcesDir;
			ResourcesDir.MoveParent("Portfolio");
			ResourcesDir.Move("Resources");
			ResourcesDir.Move("Sprites");
			ResourcesDir.Move("Object");
			ResourcesDir.Move("Object");
			ResourcesDir.Move("Text");
			ResourcesDir.Move("lava");
			AllImageFileList = ResourcesDir.GetAllFile("Bmp");
			for (size_t i = 0; i < AllImageFileList.size(); i++)
			{
				GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
			}
		}
		// melt
		{
			GameEngineDirectory ResourcesDir;
			ResourcesDir.MoveParent("Portfolio");
			ResourcesDir.Move("Resources");
			ResourcesDir.Move("Sprites");
			ResourcesDir.Move("Object");
			ResourcesDir.Move("Object");
			ResourcesDir.Move("Text");
			ResourcesDir.Move("melt");
			AllImageFileList = ResourcesDir.GetAllFile("Bmp");
			for (size_t i = 0; i < AllImageFileList.size(); i++)
			{
				GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
			}
		}
		// push
		{
			GameEngineDirectory ResourcesDir;
			ResourcesDir.MoveParent("Portfolio");
			ResourcesDir.Move("Resources");
			ResourcesDir.Move("Sprites");
			ResourcesDir.Move("Object");
			ResourcesDir.Move("Object");
			ResourcesDir.Move("Text");
			ResourcesDir.Move("push");
			AllImageFileList = ResourcesDir.GetAllFile("Bmp");
			for (size_t i = 0; i < AllImageFileList.size(); i++)
			{
				GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
			}
		}
		// rock
		{
			GameEngineDirectory ResourcesDir;
			ResourcesDir.MoveParent("Portfolio");
			ResourcesDir.Move("Resources");
			ResourcesDir.Move("Sprites");
			ResourcesDir.Move("Object");
			ResourcesDir.Move("Object");
			ResourcesDir.Move("Text");
			ResourcesDir.Move("rock");
			AllImageFileList = ResourcesDir.GetAllFile("Bmp");
			for (size_t i = 0; i < AllImageFileList.size(); i++)
			{
				GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
			}
		}
		// sink
		{
			GameEngineDirectory ResourcesDir;
			ResourcesDir.MoveParent("Portfolio");
			ResourcesDir.Move("Resources");
			ResourcesDir.Move("Sprites");
			ResourcesDir.Move("Object");
			ResourcesDir.Move("Object");
			ResourcesDir.Move("Text");
			ResourcesDir.Move("sink");
			AllImageFileList = ResourcesDir.GetAllFile("Bmp");
			for (size_t i = 0; i < AllImageFileList.size(); i++)
			{
				GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
			}
		}
		// skull
		{
			GameEngineDirectory ResourcesDir;
			ResourcesDir.MoveParent("Portfolio");
			ResourcesDir.Move("Resources");
			ResourcesDir.Move("Sprites");
			ResourcesDir.Move("Object");
			ResourcesDir.Move("Object");
			ResourcesDir.Move("Text");
			ResourcesDir.Move("skull");
			AllImageFileList = ResourcesDir.GetAllFile("Bmp");
			for (size_t i = 0; i < AllImageFileList.size(); i++)
			{
				GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
			}
		}
		// stop
		{
			GameEngineDirectory ResourcesDir;
			ResourcesDir.MoveParent("Portfolio");
			ResourcesDir.Move("Resources");
			ResourcesDir.Move("Sprites");
			ResourcesDir.Move("Object");
			ResourcesDir.Move("Object");
			ResourcesDir.Move("Text");
			ResourcesDir.Move("stop");
			AllImageFileList = ResourcesDir.GetAllFile("Bmp");
			for (size_t i = 0; i < AllImageFileList.size(); i++)
			{
				GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
			}
		}
		// wall
		{
			GameEngineDirectory ResourcesDir;
			ResourcesDir.MoveParent("Portfolio");
			ResourcesDir.Move("Resources");
			ResourcesDir.Move("Sprites");
			ResourcesDir.Move("Object");
			ResourcesDir.Move("Object");
			ResourcesDir.Move("Text");
			ResourcesDir.Move("wall");
			AllImageFileList = ResourcesDir.GetAllFile("Bmp");
			for (size_t i = 0; i < AllImageFileList.size(); i++)
			{
				GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
			}
		}
		//water
		{
			GameEngineDirectory ResourcesDir;
			ResourcesDir.MoveParent("Portfolio");
			ResourcesDir.Move("Resources");
			ResourcesDir.Move("Sprites");
			ResourcesDir.Move("Object");
			ResourcesDir.Move("Object");
			ResourcesDir.Move("Text");
			ResourcesDir.Move("water");
			AllImageFileList = ResourcesDir.GetAllFile("Bmp");
			for (size_t i = 0; i < AllImageFileList.size(); i++)
			{
				GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
			}
		}
		// win
		{
			GameEngineDirectory ResourcesDir;
			ResourcesDir.MoveParent("Portfolio");
			ResourcesDir.Move("Resources");
			ResourcesDir.Move("Sprites");
			ResourcesDir.Move("Object");
			ResourcesDir.Move("Object");
			ResourcesDir.Move("Text");
			ResourcesDir.Move("win");
			AllImageFileList = ResourcesDir.GetAllFile("Bmp");
			for (size_t i = 0; i < AllImageFileList.size(); i++)
			{
				GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
			}
		}
		// you
		{
			GameEngineDirectory ResourcesDir;
			ResourcesDir.MoveParent("Portfolio");
			ResourcesDir.Move("Resources");
			ResourcesDir.Move("Sprites");
			ResourcesDir.Move("Object");
			ResourcesDir.Move("Object");
			ResourcesDir.Move("Text");
			ResourcesDir.Move("you");
			AllImageFileList = ResourcesDir.GetAllFile("Bmp");
			for (size_t i = 0; i < AllImageFileList.size(); i++)
			{
				GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
			}
		}
	}

	GamePlayGobal::GetInst()->SetName();



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
		// 이때 대문자여야 합니다.
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