#pragma once
#include "GamePlayEnum.h"
#include "GamePlayObject.h"
#include <map>


// 설명 : 찾기 귀찮아서 만든 클래스
class GamePlayGobal
{
private:
	static GamePlayGobal* Inst_;

public:
	static GamePlayGobal* GetInst()
	{
		return Inst_;
	}

	static void Destroy()
	{
		Inst_->DestroyName();

		if (nullptr == Inst_)
		{
			return;
		}

		delete Inst_;
		Inst_ = nullptr;
	}

	GamePlayObject* Find(ObjectName _Name);
	void SetName();
	void SettingAbility();
	void ReSetStat();
	void DestroyName();


	// Option
	static bool Screenshake_;
	static bool EnableGrid_;
	static bool ParticleEffects_;
protected:

private:
	std::map<ObjectName, GamePlayObject*> ObjectName_;

	GamePlayGobal();
	~GamePlayGobal();

	GamePlayGobal(const GamePlayGobal& _Other) = delete;
	GamePlayGobal(GamePlayGobal&& _Other) noexcept = delete;
	GamePlayGobal& operator=(const GamePlayGobal& _Other) = delete;
	GamePlayGobal& operator=(GamePlayGobal&& _Other) noexcept = delete;

};

