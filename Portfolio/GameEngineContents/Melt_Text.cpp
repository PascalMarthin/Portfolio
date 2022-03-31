#include "Melt_Text.h"

Melt_Text* Melt_Text::Inst_ = new Melt_Text();

Melt_Text::Melt_Text()
{
}

Melt_Text::~Melt_Text()
{
}

void Melt_Text::SettingImg()
{
	Name_ = ObjectName::Melt_Text;
	Image_ = GameEngineImageManager::GetInst()->Find("text_melt_sheet.bmp");
}