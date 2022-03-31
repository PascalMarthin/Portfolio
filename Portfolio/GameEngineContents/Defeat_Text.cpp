#include "Defeat_Text.h"

Defeat_Text* Defeat_Text::Inst_ = new Defeat_Text();

Defeat_Text::Defeat_Text()
{
}

Defeat_Text::~Defeat_Text()
{
}

void Defeat_Text::SettingImg()
{
	Name_ = ObjectName::Defeat_Text;
	Image_ = GameEngineImageManager::GetInst()->Find("text_defeat_sheet.bmp");
}