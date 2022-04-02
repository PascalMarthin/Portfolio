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
	//StatFunction = StatDefeat;

	Image_ = GameEngineImageManager::GetInst()->Find("text_defeat_sheet.bmp");
}

void Defeat_Text::StatDefeat()
{
	//you와 같이 있을경우 you를 파괴
}