#include "Lava.h"

Lava_Unit* Lava_Unit::Inst_ = new Lava_Unit();
Lava_Text* Lava_Text::Inst_ = new Lava_Text();


Lava_Unit::Lava_Unit()
{
}

Lava_Unit::~Lava_Unit()
{
}

void Lava_Unit::SettingImg()
{
	Name_ = ObjectName::Lava_Unit;
	Image_ = GameEngineImageManager::GetInst()->Find("unit_lava_sheet.bmp");
}

Lava_Text::Lava_Text()
{
}

Lava_Text::~Lava_Text()
{
}

void Lava_Text::SettingImg()
{
	Name_ = ObjectName::Lava_Text;
	Image_ = GameEngineImageManager::GetInst()->Find("text_lava_sheet.bmp");
}
