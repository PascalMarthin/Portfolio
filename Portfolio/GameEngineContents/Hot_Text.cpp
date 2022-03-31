#include "Hot_Text.h"

Hot_Text* Hot_Text::Inst_ = new Hot_Text();

Hot_Text::Hot_Text()
{
}

Hot_Text::~Hot_Text()
{
}

void Hot_Text::SettingImg()
{
	Name_ = ObjectName::Hot_Text;
	Image_ = GameEngineImageManager::GetInst()->Find("text_hot_sheet.bmp");
}