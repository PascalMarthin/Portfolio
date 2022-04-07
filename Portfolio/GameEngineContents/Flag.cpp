#include "Flag.h"

Flag_Unit* Flag_Unit::Inst_ = new Flag_Unit();
Flag_Text* Flag_Text::Inst_ = new Flag_Text();


Flag_Unit::Flag_Unit()
{
}

Flag_Unit::~Flag_Unit()
{
}

void Flag_Unit::SettingAbility()
{
	Name_ = ObjectName::Flag_Unit;
	Type_ = ObjectType::Unit;

	Image_ = GameEngineImageManager::GetInst()->Find("unit_flag_Sheet.bmp");
	AnimationTake_["Flag_Unit"].push_back(std::make_pair(0, 2));
}


const std::vector<std::pair<int, int>>* Flag_Unit::GetAnimationTake(Direction _Dir)
{
	switch (_Dir)
	{
	case Direction::Right:
	case Direction::Up:
	case Direction::Left:
	case Direction::Down:
		return &AnimationTake_["Flag_Unit"];
		break;
	default:
		MsgBoxAssert("바바의 방향설정이 안되어있습니다");
		return nullptr;
		break;
	}
}


Flag_Text::Flag_Text()
{
}

Flag_Text::~Flag_Text()
{
}

void Flag_Text::SettingAbility()
{
	Name_ = ObjectName::Flag_Text;
	Type_ = ObjectType::Text;
	TextType_ = TextType::Unit_Text;
	TextUnit_ = Flag_Unit::GetInst();

	Image_ = GameEngineImageManager::GetInst()->Find("text_flag_Sheet.bmp");
	AnimationTake_["Flag_Text_OFF"].push_back(std::make_pair(0, 2));
	AnimationTake_["Flag_Text_ON"].push_back(std::make_pair(3, 5));

}

const std::vector<std::pair<int, int>>* Flag_Text::GetAnimationTake(Direction _Dir)
{
	switch (_Dir)
	{
	case Direction::Right:
	case Direction::Up:
		return &AnimationTake_["Flag_Text_ON"];
		break;
	case Direction::Left:
	case Direction::Down:
		return &AnimationTake_["Flag_Text_OFF"];
		break;
	default:
		MsgBoxAssert("Flagtext의 방향설정이 안되어있습니다");
		return nullptr;
		break;
	}
}