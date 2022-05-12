#pragma once
#include <GameEngine/GameEngineActor.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineImage.h>
#include <GameEngineBase/GameEngineSound.h>
#include "GamePlayEnum.h"

// Ό³Έν :
class PlayAndMainLevelMenu : public GameEngineActor
{
public:

	PlayAndMainLevelMenu();
	~PlayAndMainLevelMenu();


	PlayAndMainLevelMenu(const PlayAndMainLevelMenu& _Other) = delete;
	PlayAndMainLevelMenu(PlayAndMainLevelMenu&& _Other) noexcept = delete;
	PlayAndMainLevelMenu& operator=(const PlayAndMainLevelMenu& _Other) = delete;
	PlayAndMainLevelMenu& operator=(PlayAndMainLevelMenu&& _Other) noexcept = delete;

	void SetMenuOn();
	void SetMenuOff();

	inline bool IsInOption() const
	{
		return InOption_;
	}

	inline void IntotheOption()
	{
		InOption_ = true;
	}

	inline void OuttotheOption()
	{
		InOption_ = false;
	}

	void KeyPush();

	inline MainMenu GetCurrentMenu() const
	{
		return CurrentMenu_;
	}

	inline MainOption GetCurrentMenuOption() const
	{
		return CurrentOption_;
	}
protected:
	void Start() override;
	void Update() override;
	void Render() override;

private:
	GameEngineImage* Resume_ON_;
	GameEngineImage* Resume_OFF_;
	GameEngineImage* ReStart_ON_;
	GameEngineImage* ReStart_OFF_;
	GameEngineImage* ReturnToMap_ON_;
	GameEngineImage* ReturnToMap_OFF_;
	GameEngineImage* ReturnToMap_Disabled_;
	GameEngineImage* Setting_ON_;
	GameEngineImage* Setting_OFF_;
	GameEngineImage* ReturnToTitle_ON_;
	GameEngineImage* ReturnToTitle_OFF_;
	GameEngineImage* Baba_;
	GameEngineImage* AlphaBackGround_;

	float4 ResumePos_;
	float4 ReStartPos_;
	float4 ReturnToMapPos_;
	float4 SettingPos_;
	float4 ReturnToTitlePos_;



	GameEngineImage* Setting_Word_;
	GameEngineImage* Enable_Grid_ON_;
	GameEngineImage* Enable_Grid_OFF_;
	GameEngineImage* Enable_Grid_Able_ON_;
	GameEngineImage* Enable_Grid_Able_OFF_;
	GameEngineImage* Disable_Particle_Effects_ON_;
	GameEngineImage* Disable_Particle_Effects_OFF_;
	GameEngineImage* Disable_Particle_Effects_Able_ON_;
	GameEngineImage* Disable_Particle_Effects_Able_OFF_;
	GameEngineImage* Disable_Screenshake_ON_;
	GameEngineImage* Disable_Screenshake_OFF_;
	GameEngineImage* Disable_Screenshake_Able_ON_;
	GameEngineImage* Disable_Screenshake_Able_OFF_;
	GameEngineImage* Return_Option_ON_;
	GameEngineImage* Return_Option_OFF_;

	float4 EnableGridPos_;
	float4 DisableParticleEffectsPos_;
	float4 DisableScreenshakePos_;
	float4 ReturnOptionPos_;


	MainMenu CurrentMenu_;
	MainOption CurrentOption_;
	Stage CurrentStage_;
	GameEngineImage* StageNameImage_;
	//

	void BabaAnimation();
	float CurrentInterTime_;
	int CurrentFrame_;
	float4 CurrentImgScale_;
	float4 CurrentImgPivot_;
	float4 BabaLocate_;
	bool InOption_;

};