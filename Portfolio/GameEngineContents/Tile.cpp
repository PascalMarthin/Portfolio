#include "Tile.h"

Tile_Unit* Tile_Unit::Inst_ = new Tile_Unit();

Tile_Unit::Tile_Unit()
{
}

Tile_Unit::~Tile_Unit()
{
}

void Tile_Unit::SettingImg()
{
	Name_ = ObjectName::Tile_Unit;
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("tile_0_1.bmp"));
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("tile_0_2.bmp"));
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("tile_0_3.bmp"));
}