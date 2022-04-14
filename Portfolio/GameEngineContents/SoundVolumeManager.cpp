#include "SoundVolumeManager.h"
#include <GameEngineBase/GameEngineWindow.h>

SoundVolumeManager::SoundVolumeManager() 
{
}

SoundVolumeManager::~SoundVolumeManager() 
{
}



void SoundVolumeManager::Start()
{

}

void SoundVolumeManager::Update()
{
	CurrentInterTime_ -= GameEngineTime::GetDeltaTime();
	
}

void SoundVolumeManager::VolumeUp(GameEngineSoundPlayer* _Control, const float& _VolumeLevel, const float& _Time)
{
	_Control->SetVolume()
}
void SoundVolumeManager::VolumeDown(GameEngineSoundPlayer* _Control, const float& _VolumeLevel, const float& _Time)
{

}
