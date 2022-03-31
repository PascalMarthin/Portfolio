#include "Skull.h"

Skull_Unit* Skull_Unit::Inst_ = new Skull_Unit();
Skull_Text* Skull_Text::Inst_ = new Skull_Text();


Skull_Unit::Skull_Unit()
{
}

Skull_Unit::~Skull_Unit()
{
}

void Skull_Unit::SettingImg()
{
	Name_ = ObjectName::Skull_Unit;
	Image_ = GameEngineImageManager::GetInst()->Find("unit_skull_sheet.bmp");
}

Skull_Text::Skull_Text()
{
}

Skull_Text::~Skull_Text()
{
}

void Skull_Text::SettingImg()
{
	Name_ = ObjectName::Skull_Text;
	Image_ = GameEngineImageManager::GetInst()->Find("text_skull_sheet.bmp");
}
