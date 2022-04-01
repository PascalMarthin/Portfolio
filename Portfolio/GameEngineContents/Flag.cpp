#include "Flag.h"

Flag_Unit* Flag_Unit::Inst_ = new Flag_Unit();
Flag_Text* Flag_Text::Inst_ = new Flag_Text();


Flag_Unit::Flag_Unit()
{
}

Flag_Unit::~Flag_Unit()
{
}

void Flag_Unit::SettingImg()
{
	Name_ = ObjectName::Flag_Unit;
	Type_ = ObjectType::Unit;

	Image_ = GameEngineImageManager::GetInst()->Find("unit_flag_Sheet.bmp");
}

Flag_Text::Flag_Text()
{
}

Flag_Text::~Flag_Text()
{
}

void Flag_Text::SettingImg()
{
	Name_ = ObjectName::Flag_Text;
	Type_ = ObjectType::Text;
	TextType_ = TextType::Unit_Text;

	Image_ = GameEngineImageManager::GetInst()->Find("text_flag_Sheet.bmp");
}
