#include "Tile.h"

Tile_Unit* Tile_Unit::Inst_ = new Tile_Unit();

Tile_Unit::Tile_Unit()
{
}

Tile_Unit::~Tile_Unit()
{
}

void Tile_Unit::SettingAbility()
{
	Name_ = ObjectName::Tile_Unit;
	Type_ = ObjectType::Unit;

	Image_ = GameEngineImageManager::GetInst()->Find("unit_tile_sheet.bmp");
	AnimationTake_["Tile_Unit"].push_back(std::make_pair(0, 2));

}