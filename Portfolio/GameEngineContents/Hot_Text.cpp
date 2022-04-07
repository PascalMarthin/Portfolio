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
	Stat_ = StatName::Hot;

	Image_ = GameEngineImageManager::GetInst()->Find("text_hot_sheet.bmp");
	AnimationTake_["Hot_Text_OFF"].push_back(std::make_pair(0, 2));
	AnimationTake_["Hot_Text_ON"].push_back(std::make_pair(3, 5));
}

const std::vector<std::pair<int, int>>* Hot_Text::GetAnimationTake(Direction _Dir)
{
	switch (_Dir)
	{
	case Direction::Right:
	case Direction::Up:
		return &AnimationTake_["Hot_Text_ON"];
		break;
	case Direction::Left:
	case Direction::Down:
		return &AnimationTake_["Hot_Text_OFF"];
		break;
	default:
		MsgBoxAssert("Stop_Text의 방향설정이 안되어있습니다");
		return nullptr;
		break;
	}
}