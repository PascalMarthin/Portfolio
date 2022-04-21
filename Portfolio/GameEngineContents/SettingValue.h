#pragma once

// Ό³Έν :
class SettingValue
{
public:
	// constrcuter destructer
	SettingValue();
	~SettingValue();

	// delete Function
	SettingValue(const SettingValue& _Other) = delete;
	SettingValue(SettingValue&& _Other) noexcept = delete;
	SettingValue& operator=(const SettingValue& _Other) = delete;
	SettingValue& operator=(SettingValue&& _Other) noexcept = delete;

	static float BackGroudSoundVolume_;
	static float EffectSoundVolume_;
protected:

private:

};

