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

}