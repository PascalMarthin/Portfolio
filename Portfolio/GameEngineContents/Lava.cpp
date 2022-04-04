#include "Lava.h"

Lava_Unit* Lava_Unit::Inst_ = new Lava_Unit();
Lava_Text* Lava_Text::Inst_ = new Lava_Text();


Lava_Unit::Lava_Unit()
{
}

Lava_Unit::~Lava_Unit()
{
}

void Lava_Unit::SettingAbility()
{
	Name_ = ObjectName::Lava_Unit;
	Type_ = ObjectType::Unit;

	Image_ = GameEngineImageManager::GetInst()->Find("unit_lava_sheet.bmp");
	AnimationTake_["Lava_Unit_5"].push_back(std::make_pair(0, 2));
	AnimationTake_["Lava_Unit_6"].push_back(std::make_pair(3, 5));
	AnimationTake_["Lava_Unit_8"].push_back(std::make_pair(6, 8));
	AnimationTake_["Lava_Unit_68"].push_back(std::make_pair(9, 11));
	AnimationTake_["Lava_Unit_4"].push_back(std::make_pair(12, 14));
	AnimationTake_["Lava_Unit_46"].push_back(std::make_pair(15, 17));
	AnimationTake_["Lava_Unit_48"].push_back(std::make_pair(18, 20));
	AnimationTake_["Lava_Unit_468"].push_back(std::make_pair(21, 23));
	AnimationTake_["Lava_Unit_2"].push_back(std::make_pair(24, 26));
	AnimationTake_["Lava_Unit_26"].push_back(std::make_pair(27, 29));
	AnimationTake_["Lava_Unit_28"].push_back(std::make_pair(30, 32));
	AnimationTake_["Lava_Unit_268"].push_back(std::make_pair(33, 35));
	AnimationTake_["Lava_Unit_24"].push_back(std::make_pair(36, 38));
	AnimationTake_["Lava_Unit_246"].push_back(std::make_pair(39, 41));
	AnimationTake_["Lava_Unit_248"].push_back(std::make_pair(42, 44));
	AnimationTake_["Lava_Unit_55"].push_back(std::make_pair(45, 47));
}

Lava_Text::Lava_Text()
{
}

Lava_Text::~Lava_Text()
{
}

void Lava_Text::SettingAbility()
{
	Name_ = ObjectName::Lava_Text;
	Type_ = ObjectType::Text;
	TextType_ = TextType::Unit_Text;

	Image_ = GameEngineImageManager::GetInst()->Find("text_lava_sheet.bmp");
	AnimationTake_["Lava_Text_OFF"].push_back(std::make_pair(0, 2));
	AnimationTake_["Lava_Text_ON"].push_back(std::make_pair(3, 5));

}
