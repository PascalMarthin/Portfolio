#pragma once
#include "GamePlayUnitObject.h"
#include "GamePlayTextObject.h"

// Ό³Έν :
class Tile_Unit : public GamePlayUnitObject
{
	static Tile_Unit* Inst_;

public:
	static Tile_Unit* GetInst()
	{
		return Inst_;
	}

	static void Destroy()
	{
		if (nullptr == Inst_)
		{
			return;
		}

		delete Inst_;
		Inst_ = nullptr;
	}
	void SettingImg() override;

private:
	Tile_Unit();
	~Tile_Unit();

	Tile_Unit(const Tile_Unit& _Other) = delete;
	Tile_Unit(Tile_Unit&& _Other) noexcept = delete;
	Tile_Unit& operator=(const Tile_Unit& _Other) = delete;
	Tile_Unit& operator=(Tile_Unit&& _Other) noexcept = delete;

};
