#pragma once
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineActor.h>
#include <GameEngineBase/GameEngineSound.h>
class SoundVolumeManager : public GameEngineActor
{
public:
	SoundVolumeManager();
	~SoundVolumeManager();

	SoundVolumeManager(const SoundVolumeManager& _Other) = delete;
	SoundVolumeManager(SoundVolumeManager&& _Other) noexcept = delete;
	SoundVolumeManager& operator=(const SoundVolumeManager& _Other) = delete;
	SoundVolumeManager& operator=(SoundVolumeManager&& _Other) noexcept = delete;

	void VolumeUp(GameEngineSoundPlayer* _Control, const float& _VolumeLevel, const float& _Time = 0.0f);
	void VolumeDown(GameEngineSoundPlayer* _Control, const float& _VolumeLevel, const float& _Time = 0.0f);

protected:
	void Start() override;
	void Update() override;

private:
	float CurrentInterTime_;

};

