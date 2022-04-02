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
}
