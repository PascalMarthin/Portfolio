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
	void ApplyStat(int _idx);
	inline unsigned __int64& GetAllStat()
	{
		return AllStat_;
	}

	virtual void Reset()
	{
		AllStat_ = 0;
	}
	bool FindStat(unsigned __int64 _Idx);

protected:
	unsigned __int64 AllStat_;

private:

};

