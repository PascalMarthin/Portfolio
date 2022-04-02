#include "Push_Text.h"

Push_Text* Push_Text::Inst_ = new Push_Text();

Push_Text::Push_Text()
{
}

Push_Text::~Push_Text()
{
}

void Push_Text::SettingAbility()
{
	Name_ = ObjectName::Push_Text;
	Type_ = ObjectType::Text;
	TextType_ = TextType::Stat_Text;

	Image_ = GameEngineImageManager::GetInst()->Find("text_push_sheet.bmp");
}