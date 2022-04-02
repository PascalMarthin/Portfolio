#include "Sink_Text.h"

Sink_Text* Sink_Text::Inst_ = new Sink_Text();

Sink_Text::Sink_Text()
{
}

Sink_Text::~Sink_Text()
{
}

void Sink_Text::SettingAbility()
{
	Name_ = ObjectName::Sink_Text;
	Type_ = ObjectType::Text;
	TextType_ = TextType::Stat_Text;

	Image_ = GameEngineImageManager::GetInst()->Find("text_sink_sheet.bmp");
}