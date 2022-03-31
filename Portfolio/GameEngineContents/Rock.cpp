#include "Rock.h"


Rock_Unit* Rock_Unit::Inst_ = new Rock_Unit();
Rock_Text* Rock_Text::Inst_ = new Rock_Text();


Rock_Unit::Rock_Unit()
{
}

Rock_Unit::~Rock_Unit()
{
}

void Rock_Unit::SettingImg()
{
	Name_ = ObjectName::Rock_Unit;
	Image_ = GameEngineImageManager::GetInst()->Find("unit_rock_sheet.bmp");
}

Rock_Text::Rock_Text()
{
}

Rock_Text::~Rock_Text()
{
}

void Rock_Text::SettingImg()
{
	Name_ = ObjectName::Rock_Text;
	Image_ = GameEngineImageManager::GetInst()->Find("text_rock_sheet.bmp");
}
