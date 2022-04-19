#include "PlayAndMainLevelMenu.h"
#include <GameEngineBase/GameEngineWindow.h>
#include "GamePlayEnum.h"
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngine/GameEngine.h>

PlayAndMainLevelMenu::PlayAndMainLevelMenu() 
	: Resume_ON_(nullptr)
	, Resume_OFF_(nullptr)
	, ReStart_ON_(nullptr)
	, ReStart_OFF_(nullptr)
	, ReturnToMap_ON_(nullptr)
	, ReturnToMap_OFF_(nullptr)
	, ReturnToMap_Disabled_(nullptr)
	, Setting_ON_(nullptr)
	, Setting_OFF_(nullptr)
	, ReturnToTitle_ON_(nullptr)
	, ReturnToTitle_OFF_(nullptr)
	, CurrentMenu_(MainMenu::Resume)

{
}

PlayAndMainLevelMenu::~PlayAndMainLevelMenu() 
{
}



void PlayAndMainLevelMenu::Start()
{
	SetPosition(GameEngineWindow::GetScale().Half());

	{
		Resume_ON_ = GameEngineImageManager::GetInst()->Find("Main_Resume2.bmp");
		Resume_OFF_ = GameEngineImageManager::GetInst()->Find("Main_Resume1.bmp");
		ReStart_ON_ = GameEngineImageManager::GetInst()->Find("Main_Restart2.bmp");
		ReStart_OFF_ = GameEngineImageManager::GetInst()->Find("Main_Restart1.bmp");
		ReturnToMap_ON_ = GameEngineImageManager::GetInst()->Find("Main_Return_To_Map2.bmp");
		ReturnToMap_OFF_ = GameEngineImageManager::GetInst()->Find("Main_Return_To_Map1.bmp");
		ReturnToMap_Disabled_ = GameEngineImageManager::GetInst()->Find("Main_Return_To_Map3.bmp");
		Setting_ON_ = GameEngineImageManager::GetInst()->Find("Main_Settings2.bmp");
		Setting_OFF_ = GameEngineImageManager::GetInst()->Find("Main_Settings1.bmp");
		ReturnToTitle_ON_ = GameEngineImageManager::GetInst()->Find("Main_Return_To_Menu2.bmp");
		ReturnToTitle_OFF_ = GameEngineImageManager::GetInst()->Find("Main_Return_To_Menu1.bmp");
	}

	{
		ResumePos_ = {0 , -280};
		ReStartPos_ = { 0 , -220 };
		ReturnToMapPos_ = { 0 , -160 };
		SettingPos_ = { 0 , -100 };
		ReturnToTitlePos_ = { 0 , 120 };
	}
	CurrentMenu_ = MainMenu::Resume;
	SetOrder(8);
	Off();

}

void PlayAndMainLevelMenu::Update()
{

}

void PlayAndMainLevelMenu::KeyPush()
{
	if (GameEngineInput::GetInst()->IsDown("Up"))
	{
		switch (CurrentMenu_)
		{
		case MainMenu::Resume:
			CurrentMenu_ = MainMenu::ReturnToMenu;
			break;
		case MainMenu::ReStart:
			CurrentMenu_ = MainMenu::Resume;
			break;
		case MainMenu::ReturnToMap:
			CurrentMenu_ = MainMenu::ReStart;
			break;
		case MainMenu::Setting:
			if (GetLevel()->GetNameConstRef() == "MainLevel")
			{
				CurrentMenu_ = MainMenu::ReStart;
				break;
			}
			else
			{
				CurrentMenu_ = MainMenu::ReturnToMap;
			}
			break;
		case MainMenu::ReturnToMenu:
			CurrentMenu_ = MainMenu::Setting;
			break;
		default:
			break;
		}
	}
	if (GameEngineInput::GetInst()->IsDown("Down"))
	{
		switch (CurrentMenu_)
		{
		case MainMenu::Resume:
			CurrentMenu_ = MainMenu::ReStart;
			break;
		case MainMenu::ReStart:
			if (GetLevel()->GetNameConstRef() == "MainLevel")
			{
				CurrentMenu_ = MainMenu::Setting;
				break;
			}
			else
			{
				CurrentMenu_ = MainMenu::ReturnToMap;
			}
			break;
		case MainMenu::ReturnToMap:
			CurrentMenu_ = MainMenu::Setting;
			break;
		case MainMenu::Setting:
			CurrentMenu_ = MainMenu::ReturnToMenu;
			break;
		case MainMenu::ReturnToMenu:
			CurrentMenu_ = MainMenu::Resume;
			break;
		default:
			break;
		}
	}
}

void PlayAndMainLevelMenu::Render()
{
	if (GetLevel()->GetNameConstRef() == "MainLevel")
	{
		switch (CurrentMenu_)
		{
		case MainMenu::Resume:
			GameEngine::BackBufferImage()->TransCopy(Resume_ON_, GetPosition() - Resume_ON_->GetScale().Half() + ResumePos_, Resume_ON_->GetScale(), float4::ZERO , Resume_ON_->GetScale(), RGB(255, 0, 255));
			GameEngine::BackBufferImage()->TransCopy(ReStart_OFF_, GetPosition() - ReStart_OFF_->GetScale().Half() + ReStartPos_, ReStart_OFF_->GetScale(), float4::ZERO, ReStart_OFF_->GetScale(), RGB(255, 0, 255));
			GameEngine::BackBufferImage()->TransCopy(ReturnToMap_Disabled_, GetPosition() - ReturnToMap_Disabled_->GetScale().Half() + ReturnToMapPos_, ReturnToMap_Disabled_->GetScale(), float4::ZERO, ReturnToMap_Disabled_->GetScale(), RGB(255, 0, 255));
			GameEngine::BackBufferImage()->TransCopy(Setting_OFF_, GetPosition() - Setting_OFF_->GetScale().Half() + SettingPos_, Setting_OFF_->GetScale(), float4::ZERO, Setting_OFF_->GetScale(), RGB(255, 0, 255));
			GameEngine::BackBufferImage()->TransCopy(ReturnToTitle_OFF_, GetPosition() - ReturnToTitle_OFF_->GetScale().Half() + ReturnToTitlePos_, ReturnToTitle_OFF_->GetScale(), float4::ZERO, ReturnToTitle_OFF_->GetScale(), RGB(255, 0, 255));
		
			break;
		case MainMenu::ReStart:
			GameEngine::BackBufferImage()->TransCopy(Resume_OFF_, GetPosition() - Resume_OFF_->GetScale().Half() + ResumePos_, Resume_OFF_->GetScale(), float4::ZERO, Resume_OFF_->GetScale(), RGB(255, 0, 255));
			GameEngine::BackBufferImage()->TransCopy(ReStart_ON_, GetPosition() - ReStart_ON_->GetScale().Half() + ReStartPos_, ReStart_ON_->GetScale(), float4::ZERO, ReStart_ON_->GetScale(), RGB(255, 0, 255));
			GameEngine::BackBufferImage()->TransCopy(ReturnToMap_Disabled_, GetPosition() - ReturnToMap_Disabled_->GetScale().Half() + ReturnToMapPos_, ReturnToMap_Disabled_->GetScale(), float4::ZERO, ReturnToMap_Disabled_->GetScale(), RGB(255, 0, 255));
			GameEngine::BackBufferImage()->TransCopy(Setting_OFF_, GetPosition() - Setting_OFF_->GetScale().Half() + SettingPos_, Setting_OFF_->GetScale(), float4::ZERO, Setting_OFF_->GetScale(), RGB(255, 0, 255));
			GameEngine::BackBufferImage()->TransCopy(ReturnToTitle_OFF_, GetPosition() - ReturnToTitle_OFF_->GetScale().Half() + ReturnToTitlePos_, ReturnToTitle_OFF_->GetScale(), float4::ZERO, ReturnToTitle_OFF_->GetScale(), RGB(255, 0, 255));

			break;
		case MainMenu::Setting:
			GameEngine::BackBufferImage()->TransCopy(Resume_OFF_, GetPosition() - Resume_OFF_->GetScale().Half() + ResumePos_, Resume_OFF_->GetScale(), float4::ZERO, Resume_OFF_->GetScale(), RGB(255, 0, 255));
			GameEngine::BackBufferImage()->TransCopy(ReStart_OFF_, GetPosition() - ReStart_OFF_->GetScale().Half() + ReStartPos_, ReStart_OFF_->GetScale(), float4::ZERO, ReStart_OFF_->GetScale(), RGB(255, 0, 255));
			GameEngine::BackBufferImage()->TransCopy(ReturnToMap_Disabled_, GetPosition() - ReturnToMap_Disabled_->GetScale().Half() + ReturnToMapPos_, ReturnToMap_Disabled_->GetScale(), float4::ZERO, ReturnToMap_Disabled_->GetScale(), RGB(255, 0, 255));
			GameEngine::BackBufferImage()->TransCopy(Setting_ON_, GetPosition() - Setting_ON_->GetScale().Half() + SettingPos_, Setting_ON_->GetScale(), float4::ZERO, Setting_ON_->GetScale(), RGB(255, 0, 255));
			GameEngine::BackBufferImage()->TransCopy(ReturnToTitle_OFF_, GetPosition() - ReturnToTitle_OFF_->GetScale().Half() + ReturnToTitlePos_, ReturnToTitle_OFF_->GetScale(), float4::ZERO, ReturnToTitle_OFF_->GetScale(), RGB(255, 0, 255));

			break;
		case MainMenu::ReturnToMenu:
			GameEngine::BackBufferImage()->TransCopy(Resume_OFF_, GetPosition() - Resume_OFF_->GetScale().Half() + ResumePos_, Resume_OFF_->GetScale(), float4::ZERO, Resume_OFF_->GetScale(), RGB(255, 0, 255));
			GameEngine::BackBufferImage()->TransCopy(ReStart_OFF_, GetPosition() - ReStart_OFF_->GetScale().Half() + ReStartPos_, ReStart_OFF_->GetScale(), float4::ZERO, ReStart_OFF_->GetScale(), RGB(255, 0, 255));
			GameEngine::BackBufferImage()->TransCopy(ReturnToMap_Disabled_, GetPosition() - ReturnToMap_Disabled_->GetScale().Half() + ReturnToMapPos_, ReturnToMap_Disabled_->GetScale(), float4::ZERO, ReturnToMap_Disabled_->GetScale(), RGB(255, 0, 255));
			GameEngine::BackBufferImage()->TransCopy(Setting_OFF_, GetPosition() - Setting_OFF_->GetScale().Half() + SettingPos_, Setting_OFF_->GetScale(), float4::ZERO, Setting_OFF_->GetScale(), RGB(255, 0, 255));
			GameEngine::BackBufferImage()->TransCopy(ReturnToTitle_ON_, GetPosition() - ReturnToTitle_ON_->GetScale().Half() + ReturnToTitlePos_, ReturnToTitle_ON_->GetScale(), float4::ZERO, ReturnToTitle_ON_->GetScale(), RGB(255, 0, 255));

			break;
		default:
			break;
		}

	}

	if (GetLevel()->GetNameConstRef() == "PlayLevel")
	{
		switch (CurrentMenu_)
		{
		case MainMenu::Resume:
			GameEngine::BackBufferImage()->TransCopy(Resume_ON_, GetPosition() - Resume_ON_->GetScale().Half() + ResumePos_, Resume_ON_->GetScale(), float4::ZERO, Resume_ON_->GetScale(), RGB(255, 0, 255));
			GameEngine::BackBufferImage()->TransCopy(ReStart_OFF_, GetPosition() - ReStart_OFF_->GetScale().Half() + ReStartPos_, ReStart_OFF_->GetScale(), float4::ZERO, ReStart_OFF_->GetScale(), RGB(255, 0, 255));
			GameEngine::BackBufferImage()->TransCopy(ReturnToMap_OFF_, GetPosition() - ReturnToMap_OFF_->GetScale().Half() + ReturnToMapPos_, ReturnToMap_OFF_->GetScale(), float4::ZERO, ReturnToMap_OFF_->GetScale(), RGB(255, 0, 255));
			GameEngine::BackBufferImage()->TransCopy(Setting_OFF_, GetPosition() - Setting_OFF_->GetScale().Half() + SettingPos_, Setting_OFF_->GetScale(), float4::ZERO, Setting_OFF_->GetScale(), RGB(255, 0, 255));
			GameEngine::BackBufferImage()->TransCopy(ReturnToTitle_OFF_, GetPosition() - ReturnToTitle_OFF_->GetScale().Half() + ReturnToTitlePos_, ReturnToTitle_OFF_->GetScale(), float4::ZERO, ReturnToTitle_OFF_->GetScale(), RGB(255, 0, 255));

			break;
		case MainMenu::ReStart:
			GameEngine::BackBufferImage()->TransCopy(Resume_OFF_, GetPosition() - Resume_OFF_->GetScale().Half() + ResumePos_, Resume_OFF_->GetScale(), float4::ZERO, Resume_OFF_->GetScale(), RGB(255, 0, 255));
			GameEngine::BackBufferImage()->TransCopy(ReStart_ON_, GetPosition() - ReStart_ON_->GetScale().Half() + ReStartPos_, ReStart_ON_->GetScale(), float4::ZERO, ReStart_ON_->GetScale(), RGB(255, 0, 255));
			GameEngine::BackBufferImage()->TransCopy(ReturnToMap_OFF_, GetPosition() - ReturnToMap_OFF_->GetScale().Half() + ReturnToMapPos_, ReturnToMap_OFF_->GetScale(), float4::ZERO, ReturnToMap_OFF_->GetScale(), RGB(255, 0, 255));
			GameEngine::BackBufferImage()->TransCopy(Setting_OFF_, GetPosition() - Setting_OFF_->GetScale().Half() + SettingPos_, Setting_OFF_->GetScale(), float4::ZERO, Setting_OFF_->GetScale(), RGB(255, 0, 255));
			GameEngine::BackBufferImage()->TransCopy(ReturnToTitle_OFF_, GetPosition() - ReturnToTitle_OFF_->GetScale().Half() + ReturnToTitlePos_, ReturnToTitle_OFF_->GetScale(), float4::ZERO, ReturnToTitle_OFF_->GetScale(), RGB(255, 0, 255));

			break;
		case MainMenu::ReturnToMap:
			GameEngine::BackBufferImage()->TransCopy(Resume_OFF_, GetPosition() - Resume_OFF_->GetScale().Half() + ResumePos_, Resume_OFF_->GetScale(), float4::ZERO, Resume_OFF_->GetScale(), RGB(255, 0, 255));
			GameEngine::BackBufferImage()->TransCopy(ReStart_OFF_, GetPosition() - ReStart_OFF_->GetScale().Half() + ReStartPos_, ReStart_OFF_->GetScale(), float4::ZERO, ReStart_OFF_->GetScale(), RGB(255, 0, 255));
			GameEngine::BackBufferImage()->TransCopy(ReturnToMap_ON_, GetPosition() - ReturnToMap_ON_->GetScale().Half() + ReturnToMapPos_, ReturnToMap_ON_->GetScale(), float4::ZERO, ReturnToMap_ON_->GetScale(), RGB(255, 0, 255));
			GameEngine::BackBufferImage()->TransCopy(Setting_OFF_, GetPosition() - Setting_OFF_->GetScale().Half() + SettingPos_, Setting_OFF_->GetScale(), float4::ZERO, Setting_OFF_->GetScale(), RGB(255, 0, 255));
			GameEngine::BackBufferImage()->TransCopy(ReturnToTitle_OFF_, GetPosition() - ReturnToTitle_OFF_->GetScale().Half() + ReturnToTitlePos_, ReturnToTitle_OFF_->GetScale(), float4::ZERO, ReturnToTitle_OFF_->GetScale(), RGB(255, 0, 255));

			break;
		case MainMenu::Setting:
			GameEngine::BackBufferImage()->TransCopy(Resume_OFF_, GetPosition() - Resume_OFF_->GetScale().Half() + ResumePos_, Resume_OFF_->GetScale(), float4::ZERO, Resume_OFF_->GetScale(), RGB(255, 0, 255));
			GameEngine::BackBufferImage()->TransCopy(ReStart_OFF_, GetPosition() - ReStart_OFF_->GetScale().Half() + ReStartPos_, ReStart_OFF_->GetScale(), float4::ZERO, ReStart_OFF_->GetScale(), RGB(255, 0, 255));
			GameEngine::BackBufferImage()->TransCopy(ReturnToMap_OFF_, GetPosition() - ReturnToMap_OFF_->GetScale().Half() + ReturnToMapPos_, ReturnToMap_OFF_->GetScale(), float4::ZERO, ReturnToMap_OFF_->GetScale(), RGB(255, 0, 255));
			GameEngine::BackBufferImage()->TransCopy(Setting_ON_, GetPosition() - Setting_ON_->GetScale().Half() + SettingPos_, Setting_ON_->GetScale(), float4::ZERO, Setting_ON_->GetScale(), RGB(255, 0, 255));
			GameEngine::BackBufferImage()->TransCopy(ReturnToTitle_OFF_, GetPosition() - ReturnToTitle_OFF_->GetScale().Half() + ReturnToTitlePos_, ReturnToTitle_OFF_->GetScale(), float4::ZERO, ReturnToTitle_OFF_->GetScale(), RGB(255, 0, 255));

			break;
		case MainMenu::ReturnToMenu:
			GameEngine::BackBufferImage()->TransCopy(Resume_OFF_, GetPosition() - Resume_OFF_->GetScale().Half() + ResumePos_, Resume_OFF_->GetScale(), float4::ZERO, Resume_OFF_->GetScale(), RGB(255, 0, 255));
			GameEngine::BackBufferImage()->TransCopy(ReStart_OFF_, GetPosition() - ReStart_OFF_->GetScale().Half() + ReStartPos_, ReStart_OFF_->GetScale(), float4::ZERO, ReStart_OFF_->GetScale(), RGB(255, 0, 255));
			GameEngine::BackBufferImage()->TransCopy(ReturnToMap_OFF_, GetPosition() - ReturnToMap_OFF_->GetScale().Half() + ReturnToMapPos_, ReturnToMap_OFF_->GetScale(), float4::ZERO, ReturnToMap_OFF_->GetScale(), RGB(255, 0, 255));
			GameEngine::BackBufferImage()->TransCopy(Setting_OFF_, GetPosition() - Setting_OFF_->GetScale().Half() + SettingPos_, Setting_OFF_->GetScale(), float4::ZERO, Setting_OFF_->GetScale(), RGB(255, 0, 255));
			GameEngine::BackBufferImage()->TransCopy(ReturnToTitle_ON_, GetPosition() - ReturnToTitle_ON_->GetScale().Half() + ReturnToTitlePos_, ReturnToTitle_ON_->GetScale(), float4::ZERO, ReturnToTitle_ON_->GetScale(), RGB(255, 0, 255));

			break;
		default:
			break;
		}

	}
}

void PlayAndMainLevelMenu::SetMenuOn()
{
	CurrentMenu_ = MainMenu::Resume;
	On();
}

void PlayAndMainLevelMenu::SetMenuOff()
{

	Off();
}