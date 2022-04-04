#include "Melt_Text.h"

Melt_Text* Melt_Text::Inst_ = new Melt_Text();

Melt_Text::Melt_Text()
{
}

Melt_Text::~Melt_Text()
{
}

void Melt_Text::SettingAbility()
{
	Name_ = ObjectName::Melt_Text;
	Type_ = ObjectType::Text;
	TextType_ = TextType::Stat_Text;
	Stat_ = StatName::Melt;

	Image_ = GameEngineImageManager::GetInst()->Find("text_melt_sheet.bmp");
	AnimationTake_["Melt_Text_OFF"].push_back(std::make_pair(0, 2));
	AnimationTake_["Melt_Text_ON"].push_back(std::make_pair(3, 5));

}