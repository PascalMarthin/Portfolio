#include "Water.h"

Water_Unit* Water_Unit::Inst_ = new Water_Unit();
Water_Text* Water_Text::Inst_ = new Water_Text();


Water_Unit::Water_Unit()
{
}

Water_Unit::~Water_Unit()
{
}

void Water_Unit::SettingImg()
{
	Name_ = ObjectName::Water_Unit;
	Type_ = ObjectType::Unit;
	Image_ = GameEngineImageManager::GetInst()->Find("unit_water_sheet.bmp");
}

Water_Text::Water_Text()
{
}

Water_Text::~Water_Text()
{
}

void Water_Text::SettingImg()
{
	Name_ = ObjectName::Water_Text;
	Type_ = ObjectType::Text;
	TextType_ = TextType::Unit_Text;

	Image_ = GameEngineImageManager::GetInst()->Find("text_water_sheet.bmp");
}