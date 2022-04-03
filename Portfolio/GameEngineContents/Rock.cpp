#include "Rock.h"


Rock_Unit* Rock_Unit::Inst_ = new Rock_Unit();
Rock_Text* Rock_Text::Inst_ = new Rock_Text();


Rock_Unit::Rock_Unit()
{
}

Rock_Unit::~Rock_Unit()
{
}

void Rock_Unit::SettingAbility()
{
	Name_ = ObjectName::Rock_Unit;
	Type_ = ObjectType::Unit;

	Image_ = GameEngineImageManager::GetInst()->Find("unit_rock_sheet.bmp");
}

Rock_Text::Rock_Text()
{
}

Rock_Text::~Rock_Text()
{
}

void Rock_Text::SettingAbility()
{
	Name_ = ObjectName::Rock_Text;
	Type_ = ObjectType::Text;
	TextType_ = TextType::Unit_Text;
	TextUnit_ = Rock_Unit::GetInst();

	Image_ = GameEngineImageManager::GetInst()->Find("text_rock_sheet.bmp");
}
