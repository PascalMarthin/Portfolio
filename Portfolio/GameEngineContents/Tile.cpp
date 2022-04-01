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
	Type_ = ObjectType::Unit;

	Image_ = GameEngineImageManager::GetInst()->Find("unit_tile_sheet.bmp");
}