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
	GameWindowStartPosY_(0),
	MapScale_({ 0, 0 }),
	MainCursorPos_({ 0, 0 }),
	CurrentMovePos_(0),
	MainCursor_(nullptr),
	Fade_(nullptr),
	StageName_(nullptr),
	Menu_(nullptr),
	IsPause_(false),
	IntoStage_(false),
	IntoTitle_(false),
	IntoMain_(false),
	Grid_(nullptr)
{
}

MainLevel::~MainLevel()
{
}


void MainLevel::Loading()
{
	{
		Fade_ = CreateActor<Fade_InAndOut>(10);
		Fade_->Reset();

		StageName_ = CreateActor<StageName>(3);
	}
	{
		Menu_ = CreateActor<PlayAndMainLevelMenu>(8);
	}
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
		MainMap_[12][12]->SetCFrame(18, 20);
		MainMap_[12][11]->SetCFrame(12, 14);
		MainMap_[13][11]->SetCFrame(9, 11);
		MainMap_[11][11]->SetCFrame(21, 23);
		MainMap_[11][12]->SetCFrame(6, 8);
	}
	MainCursor_ = CreateActor<MainCursor>(3, "MainCursor");
	MainCursor_->SetPosition(MainMap_[15][9]->GetPosition());
	MainCursorPos_ = { 9, 15 };
	Grid_ = CreateActor<PlayAndMainGrid>(3);
	Grid_->Reset();
}

bool MainLevel::KeyPush()
{
	if (GameEngineInput::GetInst()->IsDown("Down"))
	{
		if (MainMap_[MainCursorPos_.iy() + 1][MainCursorPos_.ix()] != nullptr)
		{
			MoveQueue_.push(Direction::Down);
			//MainCursor_->SetPosition((MainCursor_->GetPosition()) + (float4{ 0, 48 }));
			MainCursorPos_ += {0, 1};
			GameEngineSound::SoundPlayOneShot("move1.ogg");
		}
		return true;
	}
	if (GameEngineInput::GetInst()->IsDown("Up"))
	{
		if (MainMap_[MainCursorPos_.iy() - 1][MainCursorPos_.ix()] != nullptr)
		{
			MoveQueue_.push(Direction::Up);
			//MainCursor_->SetPosition((MainCursor_->GetPosition()) - (float4{ 0, 48 }));
			MainCursorPos_ -= {0, 1};
			GameEngineSound::SoundPlayOneShot("move3.ogg");
		}
		return true;
	}
	if (GameEngineInput::GetInst()->IsDown("Right"))
	{
		if (MainMap_[MainCursorPos_.iy()][MainCursorPos_.ix() + 1] != nullptr)
		{
			MoveQueue_.push(Direction::Right);
			//MainCursor_->SetPosition((MainCursor_->GetPosition()) + (float4{ 48, 0 }));
			MainCursorPos_ += {1, 0};
			GameEngineSound::SoundPlayOneShot("move2.ogg");
		}
		return true;
	}
	if (GameEngineInput::GetInst()->IsDown("Left"))
	{
		if (MainMap_[MainCursorPos_.iy()][MainCursorPos_.ix() - 1] != nullptr)
		{
			MoveQueue_.push(Direction::Left);
			//MainCursor_->SetPosition((MainCursor_->GetPosition()) - (float4{ 48, 0 }));
			MainCursorPos_ -= {1, 0};
			GameEngineSound::SoundPlayOneShot("move4.ogg");
		}
		return true;
	}


	if (GameEngineInput::GetInst()->IsDown("Space") || GameEngineInput::GetInst()->IsDown("Enter"))
	{
		if (CurrentStage_ != Stage::MainStage)
		{
			IntoStage_ = true;
			IntoLevel();
		}
		return true;
	}

	if (GameEngineInput::GetInst()->IsDown("ESC"))
	{
		if (IsPause_ == false)
		{
			ShowMenuMode();
		}
		return false;
	}
	return false;
}

void MainLevel::ShowMenuMode()
{
	Menu_->SetMenuOn();
	GameEngineTime::GetInst()->SetTimeScale(0, 0.0f);
	IsPause_ = true;
}
void MainLevel::ShowMainMode()
{
	Menu_->SetMenuOff();
	GameEngineTime::GetInst()->SetTimeScale(0, 1.0f);
	IsPause_ = false;
}

void MainLevel::Update()
{
	if (Fade_->IsFadeOut() == true && Fade_->IsChangeScreen() == false && (IntoStage_ == true || IntoTitle_ == true || IntoMain_ == true))
	{
		if (IntoStage_ == true)
		{
			GameEngine::GetInst().ChangeLevel("PlayLevel");
		}
		else if (IntoTitle_ == true)
		{
			GameEngine::GetInst().ChangeLevel("TitleLevel");
		}
		else if (IntoMain_ == true)
		{
			GameEngine::GetInst().ChangeLevel("MainLevel");
		}
		return;
	}
	if (Fade_->IsChangeScreen() == true)
	{
		return;
	}
	if (IsPause_ == true)
	{
		KeyPushInMenu();
		return;
	}
	CursorPosCheck();
	KeyPush();
	if (MoveQueue_.empty() == false)
	{
		CurrentMovePos_ += 2.0f;
		if (CurrentMovePos_ > static_cast<float>(DotSizeX))
		{
			CurrentMovePos_ = 0;
			MoveQueue_.pop();
		}
		else
		{
			switch (MoveQueue_.front())
			{
			case Direction::Right:
				MainCursor_->SetPosition((MainCursor_->GetPosition()) + (float4{ 2, 0 }));
				break;
			case Direction::Up:
				MainCursor_->SetPosition((MainCursor_->GetPosition()) + (float4{ 0, -2 }));
				break;
			case Direction::Left:
				MainCursor_->SetPosition((MainCursor_->GetPosition()) + (float4{ -2, 0 }));
				break;
			case Direction::Down:
				MainCursor_->SetPosition((MainCursor_->GetPosition()) + (float4{ 0, 2 }));
				break;
			default:
				break;
			}
		}

	}

}
void MainLevel::CursorPosCheck()
{
	if (MainCursorPos_.ix() == 9 && MainCursorPos_.iy() == 15)
	{
		CurrentStage_ = Stage::Stage0;

	}
	else if (MainCursorPos_.ix() == 10 && MainCursorPos_.iy() == 13)
	{
		CurrentStage_ = Stage::Stage1;
	}
	else if (MainCursorPos_.ix() == 10 && MainCursorPos_.iy() == 12)
	{
		CurrentStage_ = Stage::Stage2;
	}
	else if (MainCursorPos_.ix() == 11 && MainCursorPos_.iy() == 13)
	{
		CurrentStage_ = Stage::Stage3;
	}
	else if (MainCursorPos_.ix() == 11 && MainCursorPos_.iy() == 12)
	{
		CurrentStage_ = Stage::Stage4;
	}
	else if (MainCursorPos_.ix() == 10 && MainCursorPos_.iy() == 11)
	{
		CurrentStage_ = Stage::Stage5;
	}
	else if (MainCursorPos_.ix() == 12 && MainCursorPos_.iy() == 12)
	{
		CurrentStage_ = Stage::Stage6;
	}
	else if (MainCursorPos_.ix() == 11 && MainCursorPos_.iy() == 11)
	{
		CurrentStage_ = Stage::Stage7;
	}
	else
	{
		CurrentStage_ = Stage::MainStage;
	}
}

void MainLevel::KeyPushInMenu()
{
	if (GameEngineInput::GetInst()->IsDown("Esc"))
	{
		if (IsPause_ == true)
		{
			ShowMainMode();
			return;
		}
	}
	if (GameEngineInput::GetInst()->IsDown("Space"))
	{
		if (Menu_->IsInOption() == true)
		{
			MainOption GetCurrentOption = Menu_->GetCurrentMenuOption();
			switch (GetCurrentOption)
			{
			case MainOption::EnableGrid:
				if (GamePlayGobal::EnableGrid_ == true)
				{
					GamePlayGobal::EnableGrid_ = false;
				}
				else
				{
					GamePlayGobal::EnableGrid_ = true;
				}
				break;
			case MainOption::DisableParticleEffects:
				if (GamePlayGobal::DisableParticleEffects_ == true)
				{
					GamePlayGobal::DisableParticleEffects_ = false;
				}
				else
				{
					GamePlayGobal::DisableParticleEffects_ = true;
				}
				break;
			case MainOption::DisableScreenshake:
				if (GamePlayGobal::DisableScreenshake_ == true)
				{
					GamePlayGobal::DisableScreenshake_ = false;
				}
				else
				{
					GamePlayGobal::DisableScreenshake_ = true;
				}
				break;
			case MainOption::ReturnOption:
				Menu_->OuttotheOption();
				GameEngineSound::Update();
				GameEngineSound::SoundPlayOneShot("select.ogg");
				return;
				break;
			}
			GameEngineSound::Update();
			GameEngineSound::SoundPlayOneShot("select.ogg");
		}
		else
		{
			MainMenu GetCurrentMenu = Menu_->GetCurrentMenu();
			switch (GetCurrentMenu)
			{
			case MainMenu::Resume:
				ShowMainMode();
				GameEngineSound::Update();
				GameEngineSound::SoundPlayOneShot("select.ogg");
				return;
				break;
			case MainMenu::ReStart:
				IntoMain_ = true;
				IntoLevel();
				return;
				break;
			case MainMenu::ReturnToMap:
				return;
				break;
			case MainMenu::Setting:
				Menu_->IntotheOption();
				GameEngineSound::Update();
				GameEngineSound::SoundPlayOneShot("select.ogg");
				break;
			case MainMenu::ReturnToMenu:
				IntoTitle_ = true;
				IntoLevel();
				return;
				break;
			default:
				break;
			}
			return;
		}
	}
	Menu_->KeyPush();
}

void MainLevel::IntoLevel()
{

	Fade_->ShowFadeOut();
	if (IntoMain_ == true)
	{
		GameEngineSound::SoundPlayOneShot("Retrun.ogg");
	}
	else if(IntoTitle_ == true)
	{
		GameEngineSound::SoundPlayOneShot("input.ogg");
	}
	else if (IntoStage_ == true)
	{
		GameEngineSound::SoundPlayOneShot("IntotheMap.ogg");
	}
	GameEngineSound::Update();
	BackGroundMusicControl_.Stop();
}

void MainLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	IntoTitle_ = false;
	IntoStage_ = false;
	IntoMain_ = false;
	GameEngineSound::Update();
	Fade_->ShowFadeIn();
	BackGroundMusicControl_ = GameEngineSound::SoundPlayControl("map.ogg");
	CurrentMovePos_ = 0;
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

void MainLevel::LevelChangeEnd(GameEngineLevel* _NextLevel)
{
	ShowMainMode();
	Fade_->Reset();
}