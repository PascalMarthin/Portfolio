#include "Push_Text.h"

Push_Text* Push_Text::Inst_ = new Push_Text();

Push_Text::Push_Text()
{
}

Push_Text::~Push_Text()
{
}

void Push_Text::SettingImg()
{
	Name_ = ObjectName::Push_Text;
	Image_ = GameEngineImageManager::GetInst()->Find("text_push_sheet.bmp");
}