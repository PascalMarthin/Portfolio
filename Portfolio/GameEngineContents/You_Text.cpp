#include "You_Text.h"

You_Text* You_Text::Inst_ = new You_Text();

You_Text::You_Text()
{
}

You_Text::~You_Text()
{
}

void You_Text::SettingAbility()
{
	Name_ = ObjectName::You_Text;
	Type_ = ObjectType::Text;
	TextType_ = TextType::Stat_Text;
	Stat_ = StatName::You;

	Image_ = GameEngineImageManager::GetInst()->Find("text_you_sheet.bmp");
	AnimationTake_["You_Text_OFF"].push_back(std::make_pair(0, 2));
	AnimationTake_["You_Text_ON"].push_back(std::make_pair(3, 5));

}