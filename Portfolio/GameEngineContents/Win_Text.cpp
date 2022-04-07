#include "Win_Text.h"

Win_Text* Win_Text::Inst_ = new Win_Text();

Win_Text::Win_Text()
{
}

Win_Text::~Win_Text()
{
}

void Win_Text::SettingAbility()
{
	Name_ = ObjectName::Win_Text;
	Type_ = ObjectType::Text;
	TextType_ = TextType::Stat_Text;
	Stat_ = StatName::Win;

	Image_ = GameEngineImageManager::GetInst()->Find("text_win_sheet.bmp");
	AnimationTake_["Win_Text_OFF"].push_back(std::make_pair(0, 2));
	AnimationTake_["Win_Text_ON"].push_back(std::make_pair(3, 5));

}

const std::vector<std::pair<int, int>>* Win_Text::GetAnimationTake(Direction _Dir)
{
	switch (_Dir)
	{
	case Direction::Right:
	case Direction::Up:
		return &AnimationTake_["Win_Text_ON"];
		break;
	case Direction::Left:
	case Direction::Down:
		return &AnimationTake_["Win_Text_OFF"];
		break;
	default:
		MsgBoxAssert("Flagtext의 방향설정이 안되어있습니다");
		return nullptr;
		break;
	}
}