#include "PlayAndMainLevelMenu.h"
#include <GameEngineBase/GameEngineWindow.h>
#include "GamePlayEnum.h"
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngine/GameEngine.h>
#include "PlayLevel.h"

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
	, Baba_(nullptr)
	, CurrentMenu_(MainMenu::Resume)
	, CurrentInterTime_(ImageSpeed)
	, CurrentFrame_(0)
	, CurrentImgScale_(float4(DotSizeX, DotSizeY))
	, CurrentImgPivot_(float4::ZERO)
	, BabaLocate_(float4::ZERO)
	, AlphaBackGround_(nullptr)
	, StageNameImage_(nullptr)
	, CurrentStage_(Stage::MainStage)
	, InOption_(false)
	, SettingWordPos_(float4::ZERO)
	, DisableParticleEffectsPos_(float4::ZERO)
	, DisableScreenshakePos_(float4::ZERO)
	, EnableGridPos_(float4::ZERO)
	, ReturnOptionPos_(float4::ZERO)
	, Setting_Word_(nullptr)
	, Disable_Particle_Effects_ON_(nullptr)
	, Disable_Particle_Effects_OFF_(nullptr)
	, Disable_Particle_Effects_Able_ON_(nullptr)
	, Disable_Particle_Effects_Able_OFF_(nullptr)
	, Disable_Screenshake_ON_(nullptr)
	, Disable_Screenshake_OFF_(nullptr)
	, Disable_Screenshake_Able_ON_(nullptr)
	, Disable_Screenshake_Able_OFF_(nullptr)
	, Enable_Grid_ON_(nullptr)
	, Enable_Grid_OFF_(nullptr)
	, Enable_Grid_Able_ON_(nullptr)
	, Enable_Grid_Able_OFF_(nullptr)
	, Return_Option_ON_(nullptr)
	, Return_Option_OFF_(nullptr)
	, CurrentOption_(MainOption::EnableGrid)

{
}

PlayAndMainLevelMenu::~PlayAndMainLevelMenu() 
{
}



void PlayAndMainLevelMenu::Start()
{
	SetPosition(GameEngineWindow::GetScale().Half());
	GameEngineTime::GetInst()->SetTimeScale(1, 1.0f);
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
		Baba_ = GameEngineImageManager::GetInst()->Find("unit_baba_Sheet.bmp");
		AlphaBackGround_ = GameEngineImageManager::GetInst()->Find("BackGround.bmp");
	}
	{
		Setting_Word_ = GameEngineImageManager::GetInst()->Find("Setting.bmp");
		Disable_Particle_Effects_ON_ = GameEngineImageManager::GetInst()->Find("Disable_Particle_Effects2.bmp");
		Disable_Particle_Effects_OFF_ = GameEngineImageManager::GetInst()->Find("Disable_Particle_Effects1.bmp");
		Disable_Particle_Effects_Able_ON_ = GameEngineImageManager::GetInst()->Find("Disable_Particle_Effects4.bmp");
		Disable_Particle_Effects_Able_OFF_ = GameEngineImageManager::GetInst()->Find("Disable_Particle_Effects3.bmp");
		Disable_Screenshake_ON_ = GameEngineImageManager::GetInst()->Find("Disable_Screenshake2.bmp");
		Disable_Screenshake_OFF_ = GameEngineImageManager::GetInst()->Find("Disable_Screenshake1.bmp");
		Disable_Screenshake_Able_ON_ = GameEngineImageManager::GetInst()->Find("Disable_Screenshake4.bmp");
		Disable_Screenshake_Able_OFF_ = GameEngineImageManager::GetInst()->Find("Disable_Screenshake3.bmp");
		Enable_Grid_ON_ = GameEngineImageManager::GetInst()->Find("Enable_Grid2.bmp");
		Enable_Grid_OFF_ = GameEngineImageManager::GetInst()->Find("Enable_Grid1.bmp");
		Enable_Grid_Able_ON_ = GameEngineImageManager::GetInst()->Find("Enable_Grid4.bmp");
		Enable_Grid_Able_OFF_ = GameEngineImageManager::GetInst()->Find("Enable_Grid3.bmp");
		Return_Option_ON_ = GameEngineImageManager::GetInst()->Find("Return_Option2.bmp");
		Return_Option_OFF_ = GameEngineImageManager::GetInst()->Find("Return_Option1.bmp");
	}
	{
		CurrentStage_ = static_cast<PlayLevel*>(GetLevel())->GetCurrentStage();

		switch (CurrentStage_)
		{
		case Stage::MainStage:
			StageNameImage_ = GameEngineImageManager::GetInst()->Find("MainMap_Map.bmp");
			break;
		case Stage::Stage0:
			StageNameImage_ = GameEngineImageManager::GetInst()->Find("Baba_Is_You.bmp");
			break;
		case Stage::Stage1:
			StageNameImage_ = GameEngineImageManager::GetInst()->Find("Where_Do_I_Go.bmp");
			break;
		case Stage::Stage2:
			StageNameImage_ = GameEngineImageManager::GetInst()->Find("Now_What_Is_This.bmp");
			break;
		case Stage::Stage3:
			StageNameImage_ = GameEngineImageManager::GetInst()->Find("Out_Of_Reach.bmp");
			break;
		case Stage::Stage4:
			StageNameImage_ = GameEngineImageManager::GetInst()->Find("Still_Out_Of_Reach.bmp");
			break;
		case Stage::Stage5:
			StageNameImage_ = GameEngineImageManager::GetInst()->Find("VOLCANO.bmp");
			break;
		case Stage::Stage6:
			StageNameImage_ = GameEngineImageManager::GetInst()->Find("OFF_LIMITS.bmp");
			break;
		case Stage::Stage7:
			StageNameImage_ = GameEngineImageManager::GetInst()->Find("Grass_Yard.bmp");
			break;
		default:
			break;
		}
	}

	{
		ResumePos_ = {0 , -280};
		ReturnToMapPos_ = { 0 , -220 };
		ReStartPos_ = { 0 , -160 };
		SettingPos_ = { 0 , -100 };
		ReturnToTitlePos_ = { 0 , 50 };
		BabaLocate_ = { -60, 0 };
	}
	{
		SettingWordPos_;
		DisableParticleEffectsPos_;
		DisableScreenshakePos_;
		EnableGridPos_;
		ReturnOptionPos_;
	}

	CurrentMenu_ = MainMenu::Resume;
	CurrentStage_ = static_cast<PlayLevel*>(GetLevel())->GetCurrentStage();
	SetOrder(8);
	Off();

}

void PlayAndMainLevelMenu::BabaAnimation()
{
	CurrentInterTime_ -= GameEngineTime::GetInst()->GetDeltaTime(1);
	if (0 >= CurrentInterTime_)
	{
		CurrentInterTime_ = ImageSpeed;
		++CurrentFrame_;
		if (2 < CurrentFrame_)
		{
			CurrentFrame_ = 0;
		}
	}
	CurrentImgScale_ = Baba_->GetCutScale(CurrentFrame_);
	CurrentImgPivot_ = Baba_->GetCutPivot(CurrentFrame_);
}

void PlayAndMainLevelMenu::Update()
{
	{
		CurrentStage_ = static_cast<PlayLevel*>(GetLevel())->GetCurrentStage();
		switch (CurrentStage_)
		{
		case Stage::MainStage:
			StageNameImage_ = GameEngineImageManager::GetInst()->Find("MainMap_Map.bmp");
			break;
		case Stage::Stage0:
			StageNameImage_ = GameEngineImageManager::GetInst()->Find("Baba_Is_You.bmp");
			break;
		case Stage::Stage1:
			StageNameImage_ = GameEngineImageManager::GetInst()->Find("Where_Do_I_Go.bmp");
			break;
		case Stage::Stage2:
			StageNameImage_ = GameEngineImageManager::GetInst()->Find("Now_What_Is_This.bmp");
			break;
		case Stage::Stage3:
			StageNameImage_ = GameEngineImageManager::GetInst()->Find("Out_Of_Reach.bmp");
			break;
		case Stage::Stage4:
			StageNameImage_ = GameEngineImageManager::GetInst()->Find("Still_Out_Of_Reach.bmp");
			break;
		case Stage::Stage5:
			StageNameImage_ = GameEngineImageManager::GetInst()->Find("VOLCANO.bmp");
			break;
		case Stage::Stage6:
			StageNameImage_ = GameEngineImageManager::GetInst()->Find("OFF_LIMITS.bmp");
			break;
		case Stage::Stage7:
			StageNameImage_ = GameEngineImageManager::GetInst()->Find("Grass_Yard.bmp");
			break;
		default:
			break;
		}
	}
	BabaAnimation();
}

void PlayAndMainLevelMenu::KeyPush()
{
	if (GameEngineInput::GetInst()->IsDown("Up"))
	{
		if (InOption_ == true)
		{
			switch (CurrentOption_)
			{
			case MainOption::EnableGrid:
				CurrentOption_ = MainOption::ReturnOption;
				break;
			case MainOption::DisableParticleEffects:
				CurrentOption_ = MainOption::EnableGrid;
				break;
			case MainOption::DisableScreenshake:
				CurrentOption_ = MainOption::DisableParticleEffects;
				break;
			case MainOption::ReturnOption:
				CurrentOption_ = MainOption::DisableScreenshake;
				break;
			default:
				break;
			}
		}
		else
		{
			switch (CurrentMenu_)
			{
			case MainMenu::Resume:
				CurrentMenu_ = MainMenu::ReturnToMenu;
				break;
			case MainMenu::ReturnToMap:
				CurrentMenu_ = MainMenu::Resume;
				break;
			case MainMenu::ReStart:
				if (GetLevel()->GetNameConstRef() == "MainLevel")
				{
					CurrentMenu_ = MainMenu::Resume;
					break;
				}
				else
				{
					CurrentMenu_ = MainMenu::ReturnToMap;
				}
				break;
			case MainMenu::Setting:
				CurrentMenu_ = MainMenu::ReStart;
				break;
			case MainMenu::ReturnToMenu:
				CurrentMenu_ = MainMenu::Setting;
				break;
			default:
				break;
			}
		}
		GameEngineSound::SoundPlayOneShot("select5.ogg");
	}
	if (GameEngineInput::GetInst()->IsDown("Down"))
	{
		if (InOption_ == true)
		{
			switch (CurrentOption_)
			{
			case MainOption::EnableGrid:
				CurrentOption_ = MainOption::ReturnOption;
				break;
			case MainOption::DisableParticleEffects:
				CurrentOption_ = MainOption::EnableGrid;
				break;
			case MainOption::DisableScreenshake:
				CurrentOption_ = MainOption::DisableParticleEffects;
				break;
			case MainOption::ReturnOption:
				CurrentOption_ = MainOption::DisableScreenshake;
				break;
			default:
				break;
			}
		}
		else
		{
			switch (CurrentMenu_)
			{
			case MainMenu::Resume:
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
			case MainMenu::ReturnToMap:
				CurrentMenu_ = MainMenu::ReStart;
				break;
			case MainMenu::ReStart:
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
		GameEngineSound::SoundPlayOneShot("select2.ogg");
	}

}



void PlayAndMainLevelMenu::Render()
{
	GameEngine::BackBufferImage()->AlphaCopy(AlphaBackGround_, float4::ZERO, GameEngineWindow::GetScale(), float4::ZERO, AlphaBackGround_->GetScale(), 120);
	
	if (InOption_ == true)
	{

	}
	else
	{
		GameEngine::BackBufferImage()->TransCopy(StageNameImage_, { GameEngineWindow::GetScale().Half().x - StageNameImage_->GetScale().Half().x, 30}, StageNameImage_->GetScale(), float4::ZERO, StageNameImage_->GetScale(), RGB(255, 0, 255));
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
				GameEngine::BackBufferImage()->TransCopy(Baba_, GetPosition() - Resume_ON_->GetScale().Half() + ResumePos_ + BabaLocate_, CurrentImgScale_, CurrentImgPivot_, CurrentImgScale_, RGB(255, 0, 255));

				break;
			case MainMenu::ReStart:
				GameEngine::BackBufferImage()->TransCopy(Resume_OFF_, GetPosition() - Resume_OFF_->GetScale().Half() + ResumePos_, Resume_OFF_->GetScale(), float4::ZERO, Resume_OFF_->GetScale(), RGB(255, 0, 255));
				GameEngine::BackBufferImage()->TransCopy(ReStart_ON_, GetPosition() - ReStart_ON_->GetScale().Half() + ReStartPos_, ReStart_ON_->GetScale(), float4::ZERO, ReStart_ON_->GetScale(), RGB(255, 0, 255));
				GameEngine::BackBufferImage()->TransCopy(ReturnToMap_Disabled_, GetPosition() - ReturnToMap_Disabled_->GetScale().Half() + ReturnToMapPos_, ReturnToMap_Disabled_->GetScale(), float4::ZERO, ReturnToMap_Disabled_->GetScale(), RGB(255, 0, 255));
				GameEngine::BackBufferImage()->TransCopy(Setting_OFF_, GetPosition() - Setting_OFF_->GetScale().Half() + SettingPos_, Setting_OFF_->GetScale(), float4::ZERO, Setting_OFF_->GetScale(), RGB(255, 0, 255));
				GameEngine::BackBufferImage()->TransCopy(ReturnToTitle_OFF_, GetPosition() - ReturnToTitle_OFF_->GetScale().Half() + ReturnToTitlePos_, ReturnToTitle_OFF_->GetScale(), float4::ZERO, ReturnToTitle_OFF_->GetScale(), RGB(255, 0, 255));
				GameEngine::BackBufferImage()->TransCopy(Baba_, GetPosition() - ReStart_ON_->GetScale().Half() + ReStartPos_ + BabaLocate_, CurrentImgScale_, CurrentImgPivot_, CurrentImgScale_, RGB(255, 0, 255));

				break;
			case MainMenu::Setting:
				GameEngine::BackBufferImage()->TransCopy(Resume_OFF_, GetPosition() - Resume_OFF_->GetScale().Half() + ResumePos_, Resume_OFF_->GetScale(), float4::ZERO, Resume_OFF_->GetScale(), RGB(255, 0, 255));
				GameEngine::BackBufferImage()->TransCopy(ReStart_OFF_, GetPosition() - ReStart_OFF_->GetScale().Half() + ReStartPos_, ReStart_OFF_->GetScale(), float4::ZERO, ReStart_OFF_->GetScale(), RGB(255, 0, 255));
				GameEngine::BackBufferImage()->TransCopy(ReturnToMap_Disabled_, GetPosition() - ReturnToMap_Disabled_->GetScale().Half() + ReturnToMapPos_, ReturnToMap_Disabled_->GetScale(), float4::ZERO, ReturnToMap_Disabled_->GetScale(), RGB(255, 0, 255));
				GameEngine::BackBufferImage()->TransCopy(Setting_ON_, GetPosition() - Setting_ON_->GetScale().Half() + SettingPos_, Setting_ON_->GetScale(), float4::ZERO, Setting_ON_->GetScale(), RGB(255, 0, 255));
				GameEngine::BackBufferImage()->TransCopy(ReturnToTitle_OFF_, GetPosition() - ReturnToTitle_OFF_->GetScale().Half() + ReturnToTitlePos_, ReturnToTitle_OFF_->GetScale(), float4::ZERO, ReturnToTitle_OFF_->GetScale(), RGB(255, 0, 255));
				GameEngine::BackBufferImage()->TransCopy(Baba_, GetPosition() - Setting_ON_->GetScale().Half() + SettingPos_ + BabaLocate_, CurrentImgScale_, CurrentImgPivot_, CurrentImgScale_, RGB(255, 0, 255));

				break;
			case MainMenu::ReturnToMenu:
				GameEngine::BackBufferImage()->TransCopy(Resume_OFF_, GetPosition() - Resume_OFF_->GetScale().Half() + ResumePos_, Resume_OFF_->GetScale(), float4::ZERO, Resume_OFF_->GetScale(), RGB(255, 0, 255));
				GameEngine::BackBufferImage()->TransCopy(ReStart_OFF_, GetPosition() - ReStart_OFF_->GetScale().Half() + ReStartPos_, ReStart_OFF_->GetScale(), float4::ZERO, ReStart_OFF_->GetScale(), RGB(255, 0, 255));
				GameEngine::BackBufferImage()->TransCopy(ReturnToMap_Disabled_, GetPosition() - ReturnToMap_Disabled_->GetScale().Half() + ReturnToMapPos_, ReturnToMap_Disabled_->GetScale(), float4::ZERO, ReturnToMap_Disabled_->GetScale(), RGB(255, 0, 255));
				GameEngine::BackBufferImage()->TransCopy(Setting_OFF_, GetPosition() - Setting_OFF_->GetScale().Half() + SettingPos_, Setting_OFF_->GetScale(), float4::ZERO, Setting_OFF_->GetScale(), RGB(255, 0, 255));
				GameEngine::BackBufferImage()->TransCopy(ReturnToTitle_ON_, GetPosition() - ReturnToTitle_ON_->GetScale().Half() + ReturnToTitlePos_, ReturnToTitle_ON_->GetScale(), float4::ZERO, ReturnToTitle_ON_->GetScale(), RGB(255, 0, 255));
				GameEngine::BackBufferImage()->TransCopy(Baba_, GetPosition() - ReturnToTitle_ON_->GetScale().Half() + ReturnToTitlePos_ + BabaLocate_, CurrentImgScale_, CurrentImgPivot_, CurrentImgScale_, RGB(255, 0, 255));

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
				GameEngine::BackBufferImage()->TransCopy(Baba_, GetPosition() - Resume_ON_->GetScale().Half() + ResumePos_ + BabaLocate_, CurrentImgScale_, CurrentImgPivot_, CurrentImgScale_, RGB(255, 0, 255));
				break;
			case MainMenu::ReStart:
				GameEngine::BackBufferImage()->TransCopy(Resume_OFF_, GetPosition() - Resume_OFF_->GetScale().Half() + ResumePos_, Resume_OFF_->GetScale(), float4::ZERO, Resume_OFF_->GetScale(), RGB(255, 0, 255));
				GameEngine::BackBufferImage()->TransCopy(ReStart_ON_, GetPosition() - ReStart_ON_->GetScale().Half() + ReStartPos_, ReStart_ON_->GetScale(), float4::ZERO, ReStart_ON_->GetScale(), RGB(255, 0, 255));
				GameEngine::BackBufferImage()->TransCopy(ReturnToMap_OFF_, GetPosition() - ReturnToMap_OFF_->GetScale().Half() + ReturnToMapPos_, ReturnToMap_OFF_->GetScale(), float4::ZERO, ReturnToMap_OFF_->GetScale(), RGB(255, 0, 255));
				GameEngine::BackBufferImage()->TransCopy(Setting_OFF_, GetPosition() - Setting_OFF_->GetScale().Half() + SettingPos_, Setting_OFF_->GetScale(), float4::ZERO, Setting_OFF_->GetScale(), RGB(255, 0, 255));
				GameEngine::BackBufferImage()->TransCopy(ReturnToTitle_OFF_, GetPosition() - ReturnToTitle_OFF_->GetScale().Half() + ReturnToTitlePos_, ReturnToTitle_OFF_->GetScale(), float4::ZERO, ReturnToTitle_OFF_->GetScale(), RGB(255, 0, 255));
				GameEngine::BackBufferImage()->TransCopy(Baba_, GetPosition() - ReStart_ON_->GetScale().Half() + ReStartPos_ + BabaLocate_, CurrentImgScale_, CurrentImgPivot_, CurrentImgScale_, RGB(255, 0, 255));

				break;
			case MainMenu::ReturnToMap:
				GameEngine::BackBufferImage()->TransCopy(Resume_OFF_, GetPosition() - Resume_OFF_->GetScale().Half() + ResumePos_, Resume_OFF_->GetScale(), float4::ZERO, Resume_OFF_->GetScale(), RGB(255, 0, 255));
				GameEngine::BackBufferImage()->TransCopy(ReStart_OFF_, GetPosition() - ReStart_OFF_->GetScale().Half() + ReStartPos_, ReStart_OFF_->GetScale(), float4::ZERO, ReStart_OFF_->GetScale(), RGB(255, 0, 255));
				GameEngine::BackBufferImage()->TransCopy(ReturnToMap_ON_, GetPosition() - ReturnToMap_ON_->GetScale().Half() + ReturnToMapPos_, ReturnToMap_ON_->GetScale(), float4::ZERO, ReturnToMap_ON_->GetScale(), RGB(255, 0, 255));
				GameEngine::BackBufferImage()->TransCopy(Setting_OFF_, GetPosition() - Setting_OFF_->GetScale().Half() + SettingPos_, Setting_OFF_->GetScale(), float4::ZERO, Setting_OFF_->GetScale(), RGB(255, 0, 255));
				GameEngine::BackBufferImage()->TransCopy(ReturnToTitle_OFF_, GetPosition() - ReturnToTitle_OFF_->GetScale().Half() + ReturnToTitlePos_, ReturnToTitle_OFF_->GetScale(), float4::ZERO, ReturnToTitle_OFF_->GetScale(), RGB(255, 0, 255));
				GameEngine::BackBufferImage()->TransCopy(Baba_, GetPosition() - ReturnToMap_ON_->GetScale().Half() + ReturnToMapPos_ + BabaLocate_, CurrentImgScale_, CurrentImgPivot_, CurrentImgScale_, RGB(255, 0, 255));

				break;
			case MainMenu::Setting:
				GameEngine::BackBufferImage()->TransCopy(Resume_OFF_, GetPosition() - Resume_OFF_->GetScale().Half() + ResumePos_, Resume_OFF_->GetScale(), float4::ZERO, Resume_OFF_->GetScale(), RGB(255, 0, 255));
				GameEngine::BackBufferImage()->TransCopy(ReStart_OFF_, GetPosition() - ReStart_OFF_->GetScale().Half() + ReStartPos_, ReStart_OFF_->GetScale(), float4::ZERO, ReStart_OFF_->GetScale(), RGB(255, 0, 255));
				GameEngine::BackBufferImage()->TransCopy(ReturnToMap_OFF_, GetPosition() - ReturnToMap_OFF_->GetScale().Half() + ReturnToMapPos_, ReturnToMap_OFF_->GetScale(), float4::ZERO, ReturnToMap_OFF_->GetScale(), RGB(255, 0, 255));
				GameEngine::BackBufferImage()->TransCopy(Setting_ON_, GetPosition() - Setting_ON_->GetScale().Half() + SettingPos_, Setting_ON_->GetScale(), float4::ZERO, Setting_ON_->GetScale(), RGB(255, 0, 255));
				GameEngine::BackBufferImage()->TransCopy(ReturnToTitle_OFF_, GetPosition() - ReturnToTitle_OFF_->GetScale().Half() + ReturnToTitlePos_, ReturnToTitle_OFF_->GetScale(), float4::ZERO, ReturnToTitle_OFF_->GetScale(), RGB(255, 0, 255));
				GameEngine::BackBufferImage()->TransCopy(Baba_, GetPosition() - Setting_ON_->GetScale().Half() + SettingPos_ + BabaLocate_, CurrentImgScale_, CurrentImgPivot_, CurrentImgScale_, RGB(255, 0, 255));

				break;
			case MainMenu::ReturnToMenu:
				GameEngine::BackBufferImage()->TransCopy(Resume_OFF_, GetPosition() - Resume_OFF_->GetScale().Half() + ResumePos_, Resume_OFF_->GetScale(), float4::ZERO, Resume_OFF_->GetScale(), RGB(255, 0, 255));
				GameEngine::BackBufferImage()->TransCopy(ReStart_OFF_, GetPosition() - ReStart_OFF_->GetScale().Half() + ReStartPos_, ReStart_OFF_->GetScale(), float4::ZERO, ReStart_OFF_->GetScale(), RGB(255, 0, 255));
				GameEngine::BackBufferImage()->TransCopy(ReturnToMap_OFF_, GetPosition() - ReturnToMap_OFF_->GetScale().Half() + ReturnToMapPos_, ReturnToMap_OFF_->GetScale(), float4::ZERO, ReturnToMap_OFF_->GetScale(), RGB(255, 0, 255));
				GameEngine::BackBufferImage()->TransCopy(Setting_OFF_, GetPosition() - Setting_OFF_->GetScale().Half() + SettingPos_, Setting_OFF_->GetScale(), float4::ZERO, Setting_OFF_->GetScale(), RGB(255, 0, 255));
				GameEngine::BackBufferImage()->TransCopy(ReturnToTitle_ON_, GetPosition() - ReturnToTitle_ON_->GetScale().Half() + ReturnToTitlePos_, ReturnToTitle_ON_->GetScale(), float4::ZERO, ReturnToTitle_ON_->GetScale(), RGB(255, 0, 255));
				GameEngine::BackBufferImage()->TransCopy(Baba_, GetPosition() - ReturnToTitle_ON_->GetScale().Half() + ReturnToTitlePos_ + BabaLocate_, CurrentImgScale_, CurrentImgPivot_, CurrentImgScale_, RGB(255, 0, 255));
				break;
			default:
				break;
			}

		}
		
	}
}

void PlayAndMainLevelMenu::SetMenuOn()
{
	CurrentMenu_ = MainMenu::Resume;
	CurrentOption_ = MainOption::EnableGrid;
	InOption_ = false;
	On();
}

void PlayAndMainLevelMenu::SetMenuOff()
{

	Off();
}