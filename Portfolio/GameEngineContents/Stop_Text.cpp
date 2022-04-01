#include "Stop_Text.h"

Stop_Text* Stop_Text::Inst_ = new Stop_Text();

Stop_Text::Stop_Text()
{
}

Stop_Text::~Stop_Text()
{
}

void Stop_Text::SettingImg()
{
	Name_ = ObjectName::Stop_Text;
	Type_ = ObjectType::Text;
	TextType_ = TextType::Stat_Text;

	Image_ = GameEngineImageManager::GetInst()->Find("text_stop_sheet.bmp");
}