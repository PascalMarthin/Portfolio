#include "Defeat_Text.h"

Defeat_Text* Defeat_Text::Inst_ = new Defeat_Text();

Defeat_Text::Defeat_Text()
{
}

Defeat_Text::~Defeat_Text()
{
}

void Defeat_Text::SettingAbility()
{
	Name_ = ObjectName::Defeat_Text;
	Type_ = ObjectType::Text;
	TextType_ = TextType::Stat_Text;
	Stat_ = StatName::Defeat;
	//StatFunction = StatDefeat;

	Image_ = GameEngineImageManager::GetInst()->Find("text_defeat_sheet.bmp");
	AnimationTake_["Defeat_Text_OFF"].push_back(std::make_pair(0, 2));
	AnimationTake_["Defeat_Text_ON"].push_back(std::make_pair(3, 5));

}


	//you와 같이 있을경우 you를 파괴
