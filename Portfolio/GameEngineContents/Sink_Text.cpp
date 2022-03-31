#include "Sink_Text.h"

Sink_Text* Sink_Text::Inst_ = new Sink_Text();

Sink_Text::Sink_Text()
{
}

Sink_Text::~Sink_Text()
{
}

void Sink_Text::SettingImg()
{
	Name_ = ObjectName::Sink_Text;
	Image_ = GameEngineImageManager::GetInst()->Find("text_sink_sheet.bmp");
}