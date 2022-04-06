#include "Rock.h"


Rock_Unit* Rock_Unit::Inst_ = new Rock_Unit();
Rock_Text* Rock_Text::Inst_ = new Rock_Text();


Rock_Unit::Rock_Unit()
{
}

Rock_Unit::~Rock_Unit()
{
}

void Rock_Unit::SettingAbility()
{
	Name_ = ObjectName::Rock_Unit;
	Type_ = ObjectType::Unit;

	Image_ = GameEngineImageManager::GetInst()->Find("unit_rock_sheet.bmp");
	AnimationTake_["Rock_Unit"].push_back(std::make_pair(0, 2));
}

std::vector<std::pair<int, int>>* Rock_Unit::GetAnimationTake(Direction _Dir)
{
	switch (_Dir)
	{
	case Direction::Right:
	case Direction::Up:
	case Direction::Left:
	case Direction::Down:
		return &AnimationTake_["Rock_Unit"];
		break;
	default:
		MsgBoxAssert("바바의 방향설정이 안되어있습니다");
		return nullptr;
		break;
	}
}


Rock_Text::Rock_Text()
{
}

Rock_Text::~Rock_Text()
{
}

void Rock_Text::SettingAbility()
{
	Name_ = ObjectName::Rock_Text;
	Type_ = ObjectType::Text;
	TextType_ = TextType::Unit_Text;
	TextUnit_ = Rock_Unit::GetInst();

	Image_ = GameEngineImageManager::GetInst()->Find("text_rock_sheet.bmp");
	AnimationTake_["Rock_Text_OFF"].push_back(std::make_pair(0, 2));
	AnimationTake_["Rock_Text_ON"].push_back(std::make_pair(3, 5));

}

std::vector<std::pair<int, int>>* Rock_Text::GetAnimationTake(Direction _Dir)
{
	switch (_Dir)
	{
	case Direction::Right:
	case Direction::Up:
		return &AnimationTake_["Rock_Text_ON"];
		break;
	case Direction::Left:
	case Direction::Down:
		return &AnimationTake_["Rock_Text_OFF"];
		break;
	default:
		MsgBoxAssert("Flagtext의 방향설정이 안되어있습니다");
		return nullptr;
		break;
	}
}