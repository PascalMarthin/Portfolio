#include "Is_Text.h"

Is_Text* Is_Text::Inst_ = new Is_Text();

Is_Text::Is_Text()
{
}

Is_Text::~Is_Text()
{
}

void Is_Text::SettingImg()
{
	Name_ = ObjectName::Is_Text;
	Image_ = GameEngineImageManager::GetInst()->Find("text_is_sheet.bmp");
}