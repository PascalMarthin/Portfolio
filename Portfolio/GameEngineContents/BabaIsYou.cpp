#include "BabaIsYou.h"
#include "PlayLevel.h"
#include "TitleLevel.h"
#include "MainLevel.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineBase/GameEngineFile.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineBase/GameEngineSound.h>
#include "GamePlayGobal.h"
#include "StageData.h"


BabaIsYou::BabaIsYou() 
{
}

BabaIsYou::~BabaIsYou() 
{
}

void BabaIsYou::GameInit()
{
	//GameEngineTime::GetInst()->SetTimeScale(0, 1.0f);
	GameEngineWindow::GetInst().SetWindowScaleAndPosition({ 100, 100 }, { 1700, 880 });
	CreateKeyBaba();

	// 리소스 파일 위치 적용

	{
		GameEngineDirectory ResourcesDir;
		ResourcesDir.MoveParent("Portfolio");
		ResourcesDir.Move("Resources");
		ResourcesDir.Move("Sound");
		ResourcesDir.Move("Music");
		std::vector<GameEngineFile> AllImageFileList = ResourcesDir.GetAllFile();
		for (size_t i = 0; i < AllImageFileList.size(); i++)
		{
			GameEngineSound::LoadRes(AllImageFileList[i].GetFullPath());
		}
	}
	{
		GameEngineDirectory ResourcesDir;
		ResourcesDir.MoveParent("Portfolio");
		ResourcesDir.Move("Resources");
		ResourcesDir.Move("Sound"); 
		ResourcesDir.Move("Soundeffect");
		std::vector<GameEngineFile> AllImageFileList = ResourcesDir.GetAllFile();
		for (size_t i = 0; i < AllImageFileList.size(); i++)
		{
			GameEngineSound::LoadRes(AllImageFileList[i].GetFullPath());
		}
	}

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

	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("island_decor_sheet.bmp");
		Image->Cut({ 1584 , 864});
		Image = GameEngineImageManager::GetInst()->Find("island_sheet.bmp");
		Image->Cut({ 1584 , 864 });
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

	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("TitleLogo_sheet.bmp");
		Image->Cut({ 900 , 350 });
	}

	// 타이틀매뉴
	ResourcesDir.MoveParent("Ui");
	ResourcesDir.Move("TitleMenu");
	AllImageFileList = ResourcesDir.GetAllFile("Bmp");
	for (size_t i = 0; i < AllImageFileList.size(); i++)
	{
		GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
	}

	// stage
	ResourcesDir.MoveParent("Ui");
	ResourcesDir.Move("Stage");
	AllImageFileList = ResourcesDir.GetAllFile("Bmp");
	for (size_t i = 0; i < AllImageFileList.size(); i++)
	{
		GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
	}
	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("Main_stage_sheet.bmp");
		Image->Cut({ DotSizeX , DotSizeY });
	}

	// Clear
	ResourcesDir.MoveParent("Ui");
	ResourcesDir.Move("Clear");
	AllImageFileList = ResourcesDir.GetAllFile("Bmp");
	for (size_t i = 0; i < AllImageFileList.size(); i++)
	{
		GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
	}
	{
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("Clear_make_sheet.bmp");
		Image->Cut({ 820 , 270 });
		Image = GameEngineImageManager::GetInst()->Find("Clear_Stay_sheet.bmp");
		Image->Cut({ 820 , 270 });
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
		GameEngineImage* Image = GameEngineImageManager::GetInst()->Find("button_move_sheet.bmp");
		Image->Cut({ 96 , 48 });
		Image = GameEngineImageManager::GetInst()->Find("button_restart_sheet.bmp");
		Image->Cut({ 96 , 48 });
		Image = GameEngineImageManager::GetInst()->Find("button_undo_sheet.bmp");
		Image->Cut({ 96 , 48 });
		Image = GameEngineImageManager::GetInst()->Find("cursor_sheet.bmp");
		Image->Cut({ 64 , 64 });
		Image = GameEngineImageManager::GetInst()->Find("default_sheet.bmp");
		Image->Cut({ 48 , 48 });
	}
	// Fade
	ResourcesDir.MoveParent("Ui");
	ResourcesDir.Move("Fade");
	GameEngineImageManager::GetInst()->FolderImageLoad(ResourcesDir.GetFullPath());
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
				(GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath()))->Cut({ DotSizeX , DotSizeY });
			}

		}
		//brick
		{
			GameEngineDirectory ResourcesDir;
			ResourcesDir.MoveParent("Portfolio");
			ResourcesDir.Move("Resources");
			ResourcesDir.Move("Sprites");
			ResourcesDir.Move("Object");
			ResourcesDir.Move("Object");
			ResourcesDir.Move("it");
			ResourcesDir.Move("brick");
			AllImageFileList = ResourcesDir.GetAllFile("Bmp");
			for (size_t i = 0; i < AllImageFileList.size(); i++)
			{
				(GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath()))->Cut({ DotSizeX , DotSizeY });
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
				(GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath()))->Cut({ DotSizeX , DotSizeY });
			}
		}

		//flower
		
		{
			GameEngineDirectory ResourcesDir;
			ResourcesDir.MoveParent("Portfolio");
			ResourcesDir.Move("Resources");
			ResourcesDir.Move("Sprites");
			ResourcesDir.Move("Object");
			ResourcesDir.Move("Object");
			ResourcesDir.Move("it");
			ResourcesDir.Move("flower");
			AllImageFileList = ResourcesDir.GetAllFile("Bmp");
			for (size_t i = 0; i < AllImageFileList.size(); i++)
			{
				(GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath()))->Cut({ DotSizeX , DotSizeY });
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
				(GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath()))->Cut({ DotSizeX , DotSizeY });
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
				(GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath()))->Cut({ DotSizeX , DotSizeY });
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
				GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath())->Cut({ DotSizeX , DotSizeY });
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
				GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath())->Cut({ DotSizeX , DotSizeY });
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
				GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath())->Cut({ DotSizeX , DotSizeY });
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
				GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath())->Cut({ DotSizeX , DotSizeY });
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
				GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath())->Cut({ DotSizeX , DotSizeY });
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
				GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath())->Cut({ DotSizeX , DotSizeY });
			}
		}
		//brick
		{
			GameEngineDirectory ResourcesDir;
			ResourcesDir.MoveParent("Portfolio");
			ResourcesDir.Move("Resources");
			ResourcesDir.Move("Sprites");
			ResourcesDir.Move("Object");
			ResourcesDir.Move("Object");
			ResourcesDir.Move("Text");
			ResourcesDir.Move("brick");
			AllImageFileList = ResourcesDir.GetAllFile("Bmp");
			for (size_t i = 0; i < AllImageFileList.size(); i++)
			{
				GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath())->Cut({ DotSizeX , DotSizeY });
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
				GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath())->Cut({ DotSizeX , DotSizeY });
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
				GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath())->Cut({ DotSizeX , DotSizeY });
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
			ResourcesDir.Move("Text");
			ResourcesDir.Move("grass");
			AllImageFileList = ResourcesDir.GetAllFile("Bmp");
			for (size_t i = 0; i < AllImageFileList.size(); i++)
			{
				GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath())->Cut({ DotSizeX , DotSizeY });
			}
		}

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
				GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath())->Cut({ DotSizeX , DotSizeY });
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
				GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath())->Cut({ DotSizeX , DotSizeY });
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
				GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath())->Cut({ DotSizeX , DotSizeY });
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
				GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath())->Cut({ DotSizeX , DotSizeY });
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
				GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath())->Cut({ DotSizeX , DotSizeY });
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
				GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath())->Cut({ DotSizeX , DotSizeY });
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
				GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath())->Cut({ DotSizeX , DotSizeY });
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
				GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath())->Cut({ DotSizeX , DotSizeY });
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
				GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath())->Cut({ DotSizeX , DotSizeY });
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
				GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath())->Cut({ DotSizeX , DotSizeY });
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
				GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath())->Cut({ DotSizeX , DotSizeY });
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
				GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath())->Cut({ DotSizeX , DotSizeY });
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
				GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath())->Cut({ DotSizeX , DotSizeY });
			}
		}

		// line
		{
			GameEngineDirectory ResourcesDir;
			ResourcesDir.MoveParent("Portfolio");
			ResourcesDir.Move("Resources");
			ResourcesDir.Move("Sprites");
			ResourcesDir.Move("Object");
			ResourcesDir.Move("Object");
			ResourcesDir.Move("it");
			ResourcesDir.Move("line");
			AllImageFileList = ResourcesDir.GetAllFile("Bmp");
			for (size_t i = 0; i < AllImageFileList.size(); i++)
			{
				GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath())->Cut({ DotSizeX , DotSizeY });
			}
		}
		// effect
		{
			GameEngineDirectory ResourcesDir;
			ResourcesDir.MoveParent("Portfolio");
			ResourcesDir.Move("Resources");
			ResourcesDir.Move("Sprites");
			ResourcesDir.Move("Object");
			ResourcesDir.Move("Effect");
			AllImageFileList = ResourcesDir.GetAllFile("Bmp");
			for (size_t i = 0; i < AllImageFileList.size(); i++)
			{
				GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath())->CutCount({ 4 , 1 });
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
	StageData::Destroy();

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