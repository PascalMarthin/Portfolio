#include "Sink_Text.h"

Sink_Text* Sink_Text::Inst_ = new Sink_Text();

Sink_Text::Sink_Text()
{
}

Sink_Text::~Sink_Text()
{
}

void Sink_Text::SettingAbility()
{
	Name_ = ObjectName::Sink_Text;
	Type_ = ObjectType::Text;
	TextType_ = TextType::Stat_Text;
	Stat_ = StatName::Sink;

	Image_ = GameEngineImageManager::GetInst()->Find("text_sink_sheet.bmp");
	AnimationTake_["Sink_Text_OFF"].push_back(std::make_pair(0, 2));
	AnimationTake_["Sink_Text_ON"].push_back(std::make_pair(3, 5));

}

std::vector<std::pair<int, int>>* Sink_Text::GetAnimationTake(Direction _Dir)
{
	switch (_Dir)
	{
	case Direction::Right:
	case Direction::Up:
		return &AnimationTake_["Sink_Text_ON"];
		break;
	case Direction::Left:
	case Direction::Down:
		return &AnimationTake_["Sink_Text_OFF"];
		break;
	default:
		MsgBoxAssert("Stop_Text의 방향설정이 안되어있습니다");
		return nullptr;
		break;
	}
}