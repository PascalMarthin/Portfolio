#include "You_Text.h"

You_Text* You_Text::Inst_ = new You_Text();

You_Text::You_Text()
{
}

You_Text::~You_Text()
{
}

void You_Text::SettingImg()
{
	Name_ = ObjectName::You_Text;
	Type_ = ObjectType::Text;
	TextType_ = TextType::Stat_Text;

	Image_ = GameEngineImageManager::GetInst()->Find("text_you_sheet.bmp");
}