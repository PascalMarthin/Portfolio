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

const std::vector<std::pair<int, int>>* You_Text::GetAnimationTake(Direction _Dir)
{
	switch (_Dir)
	{
	case Direction::Right:
	case Direction::Up:
		return &AnimationTake_["You_Text_ON"];
		break;
	case Direction::Left:
	case Direction::Down:
		return &AnimationTake_["You_Text_OFF"];
		break;
	default:
		MsgBoxAssert("Flagtext의 방향설정이 안되어있습니다");
		return nullptr;
		break;
	}
}