#include "Is_Text.h"

Is_Text* Is_Text::Inst_ = new Is_Text();

Is_Text::Is_Text()
{
}

Is_Text::~Is_Text()
{
}

void Is_Text::SettingAbility()
{
	Name_ = ObjectName::Is_Text;
	Type_ = ObjectType::Text;
	TextType_ = TextType::Verb_Text;

	Image_ = GameEngineImageManager::GetInst()->Find("text_is_sheet.bmp");
	AnimationTake_["Is_Text_OFF"].push_back(std::make_pair(0, 2));
	AnimationTake_["Is_Text_ON"].push_back(std::make_pair(3, 5));

}