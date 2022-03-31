#include "Win_Text.h"

Win_Text* Win_Text::Inst_ = new Win_Text();

Win_Text::Win_Text()
{
}

Win_Text::~Win_Text()
{
}

void Win_Text::SettingImg()
{
	Name_ = ObjectName::Win_Text;
	Image_ = GameEngineImageManager::GetInst()->Find("text_win_sheet.bmp");
}