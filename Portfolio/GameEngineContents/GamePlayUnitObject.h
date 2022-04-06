#pragma once
#include "GamePlayObject.h"

class GamePlayTextStat;
class GamePlayUnitObject : public GamePlayObject
{
public:
	GamePlayUnitObject();
	virtual ~GamePlayUnitObject();

	GamePlayUnitObject(const GamePlayUnitObject& _Other) = delete;
	GamePlayUnitObject(GamePlayUnitObject&& _Other) noexcept = delete;
	GamePlayUnitObject& operator=(const GamePlayUnitObject& _Other) = delete;
	GamePlayUnitObject& operator=(GamePlayUnitObject&& _Other) noexcept = delete;

	virtual void SettingAbility() {}
	virtual void Destroy() {}

	void UnitObjectFucntion() override;


	void ApplyStat(const GamePlayTextStat* _Stat);
	inline unsigned __int64& GetAllStat()
	{
		return AllStat_;
	}

	void Reset();
	bool FindStat(unsigned __int64 _Idx);

protected:
	unsigned __int64 AllStat_;

private:

};

