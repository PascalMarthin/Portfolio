#include "Glass.h"

Grass_Unit* Grass_Unit::Inst_ = new Grass_Unit();

Grass_Unit::Grass_Unit()
{
}

Grass_Unit::~Grass_Unit()
{
}

void Grass_Unit::SettingImg()
{
	Name_ = ObjectName::Grass_Unit;
	Type_ = ObjectType::Unit;

	Image_ = GameEngineImageManager::GetInst()->Find("unit_grass_sheet.bmp");
}