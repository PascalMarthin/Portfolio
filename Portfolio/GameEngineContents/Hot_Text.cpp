#include "Hot_Text.h"

Hot_Text* Hot_Text::Inst_ = new Hot_Text();

Hot_Text::Hot_Text()
{
}

Hot_Text::~Hot_Text()
{
}

void Hot_Text::SettingAbility()
{
	Name_ = ObjectName::Hot_Text;
	Type_ = ObjectType::Text;
	TextType_ = TextType::Stat_Text;

	Image_ = GameEngineImageManager::GetInst()->Find("text_hot_sheet.bmp");
}

void Hot_Text::StatHot()
{
	//보글보글거리는 이펙트가 추가
	//자신과 같은 칸에 존재하는 MELT 속성의 개체를 모두 파괴한다
}