#pragma once
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineActor.h>
#include <GameEngineBase/GameEngineSound.h>
#include <map>
class SoundVolumeManager : public GameEngineActor
{
public:
	SoundVolumeManager();
	~SoundVolumeManager();

	SoundVolumeManager(const SoundVolumeManager& _Other) = delete;
	SoundVolumeManager(SoundVolumeManager&& _Other) noexcept = delete;
	SoundVolumeManager& operator=(const SoundVolumeManager& _Other) = delete;
	SoundVolumeManager& operator=(SoundVolumeManager&& _Other) noexcept = delete;

	void VolumeUp(GameEngineSoundPlayer* _Control);
	void VolumeDown(GameEngineSoundPlayer* _Control);

protected:
	void Start() override;
	void Update() override;

private:

	std::list<std::map<GameEngineSoundPlayer*,float>> UpList_;
	std::list< std::map<GameEngineSoundPlayer*,float>> DownList_;

};

