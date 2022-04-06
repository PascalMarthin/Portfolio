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
	Stat_ = StatName::Push;

	Image_ = GameEngineImageManager::GetInst()->Find("text_push_sheet.bmp");
	AnimationTake_["Push_Text_OFF"].push_back(std::make_pair(0, 2));
	AnimationTake_["Push_Text_ON"].push_back(std::make_pair(3, 5));

}

std::vector<std::pair<int, int>>* Push_Text::GetAnimationTake(Direction _Dir)
{
	switch (_Dir)
	{
	case Direction::Right:
	case Direction::Up:
		return &AnimationTake_["Push_Text_ON"];
		break;
	case Direction::Left:
	case Direction::Down:
		return &AnimationTake_["Push_Text_OFF"];
		break;
	default:
		MsgBoxAssert("Stop_Text의 방향설정이 안되어있습니다");
		return nullptr;
		break;
	}
}