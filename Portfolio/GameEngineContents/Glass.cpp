#include "Glass.h"

Grass_Unit* Grass_Unit::Inst_ = new Grass_Unit();

Grass_Unit::Grass_Unit()
{
}

Grass_Unit::~Grass_Unit()
{
}

void Grass_Unit::SettingAbility()
{
	Name_ = ObjectName::Grass_Unit;
	Type_ = ObjectType::Unit;

	Image_ = GameEngineImageManager::GetInst()->Find("unit_grass_sheet.bmp");
	AnimationTake_["Grass_Unit_5"].push_back(std::make_pair(0, 2));
	AnimationTake_["Grass_Unit_6"].push_back(std::make_pair(3, 5));
	AnimationTake_["Grass_Unit_8"].push_back(std::make_pair(6, 8));
	AnimationTake_["Grass_Unit_68"].push_back(std::make_pair(9, 11));
	AnimationTake_["Grass_Unit_4"].push_back(std::make_pair(12, 14));
	AnimationTake_["Grass_Unit_46"].push_back(std::make_pair(15, 17));
	AnimationTake_["Grass_Unit_48"].push_back(std::make_pair(18, 20));
	AnimationTake_["Grass_Unit_468"].push_back(std::make_pair(21, 23));
	AnimationTake_["Grass_Unit_2"].push_back(std::make_pair(24, 26));
	AnimationTake_["Grass_Unit_26"].push_back(std::make_pair(27, 29));
	AnimationTake_["Grass_Unit_28"].push_back(std::make_pair(30, 32));
	AnimationTake_["Grass_Unit_268"].push_back(std::make_pair(33, 35));
	AnimationTake_["Grass_Unit_24"].push_back(std::make_pair(36, 38));
	AnimationTake_["Grass_Unit_246"].push_back(std::make_pair(39, 41));
	AnimationTake_["Grass_Unit_248"].push_back(std::make_pair(42, 44));
	AnimationTake_["Grass_Unit_55"].push_back(std::make_pair(45, 47));
}