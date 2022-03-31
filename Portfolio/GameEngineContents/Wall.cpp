#include "Wall.h"

Wall_Unit* Wall_Unit::Inst_ = new Wall_Unit();
Wall_Text* Wall_Text::Inst_ = new Wall_Text();


Wall_Unit::Wall_Unit()
{
}

Wall_Unit::~Wall_Unit()
{
}

void Wall_Unit::SettingImg()
{
	Name_ = ObjectName::Wall_Unit;
	Image_ = GameEngineImageManager::GetInst()->Find("unit_wall_sheet.bmp");

}

Wall_Text::Wall_Text()
{
}

Wall_Text::~Wall_Text()
{
}

void Wall_Text::SettingImg()
{
	Name_ = ObjectName::Wall_Text;
	Image_ = GameEngineImageManager::GetInst()->Find("text_wall_sheet.bmp");

}
