#include "Stop_Text.h"

Stop_Text* Stop_Text::Inst_ = new Stop_Text();

Stop_Text::Stop_Text()
{
}

Stop_Text::~Stop_Text()
{
}

void Stop_Text::SettingAbility()
{
	Name_ = ObjectName::Stop_Text;
	Type_ = ObjectType::Text;
	TextType_ = TextType::Stat_Text;
	Stat_ = StatName::Stop;

	Image_ = GameEngineImageManager::GetInst()->Find("text_stop_sheet.bmp");
	AnimationTake_["Stop_Text_OFF"].push_back(std::make_pair(0, 2));
	AnimationTake_["Stop_Text_ON"].push_back(std::make_pair(3, 5));

}

const std::vector<std::pair<int, int>>* Stop_Text::GetAnimationTake(Direction _Dir)
{
	switch (_Dir)
	{
	case Direction::Right:
	case Direction::Up:
		return &AnimationTake_["Stop_Text_ON"];
		break;
	case Direction::Left:
	case Direction::Down:
		return &AnimationTake_["Stop_Text_OFF"];
		break;
	default:
		MsgBoxAssert("Stop_Text의 방향설정이 안되어있습니다");
		return nullptr;
		break;
	}
}