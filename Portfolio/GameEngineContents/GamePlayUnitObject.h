#pragma once
#include "GamePlayObject.h"
#include "GamePlayStatManager.h"

class GamePlayUnitObject : public GamePlayObject, public GamePlayStatManager
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

	inline std::vector<StatName>& GetApplyStat()
	{
		return ApplyStat_;
	}

	void UnitObjectFucntion() override;

protected:

private:
	std::vector<StatName> ApplyStat_;

};

