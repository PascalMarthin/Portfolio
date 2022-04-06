#include "Skull.h"

Skull_Unit* Skull_Unit::Inst_ = new Skull_Unit();
Skull_Text* Skull_Text::Inst_ = new Skull_Text();


Skull_Unit::Skull_Unit()
{
}

Skull_Unit::~Skull_Unit()
{
}

void Skull_Unit::SettingAbility()
{
	Name_ = ObjectName::Skull_Unit;
	Type_ = ObjectType::Unit;

	Image_ = GameEngineImageManager::GetInst()->Find("unit_skull_sheet.bmp");
	AnimationTake_["Skull_Unit_Right"].push_back(std::make_pair(0, 2));
	AnimationTake_["Skull_Unit_Up"].push_back(std::make_pair(3, 5));
	AnimationTake_["Skull_Unit_Left"].push_back(std::make_pair(6, 8));
	AnimationTake_["Skull_Unit_Down"].push_back(std::make_pair(9, 11));
}

std::vector<std::pair<int, int>>* Skull_Unit::GetAnimationTake(Direction _Dir)
{
	switch (_Dir)
	{
	case Direction::Right:
		return &AnimationTake_["Skull_Unit_Right"];
		break;
	case Direction::Up:
		return &AnimationTake_["Skull_Unit_Up"];
		break;
	case Direction::Left:
		return &AnimationTake_["Skull_Unit_Left"];
		break;
	case Direction::Down:
		return &AnimationTake_["Skull_Unit_Down"];
		break;
	default:
		MsgBoxAssert("바바의 방향설정이 안되어있습니다");
		return nullptr;
		break;
	}
}

Skull_Text::Skull_Text()
{
}

Skull_Text::~Skull_Text()
{
}

void Skull_Text::SettingAbility()
{
	Name_ = ObjectName::Skull_Text;
	Type_ = ObjectType::Text;
	TextType_ = TextType::Unit_Text;
	TextUnit_ = Skull_Unit::GetInst();

	Image_ = GameEngineImageManager::GetInst()->Find("text_skull_sheet.bmp");
	AnimationTake_["Skull_Text_OFF"].push_back(std::make_pair(0, 2));
	AnimationTake_["Skull_Text_ON"].push_back(std::make_pair(3, 5));

}

std::vector<std::pair<int, int>>* Skull_Text::GetAnimationTake(Direction _Dir)
{
	switch (_Dir)
	{
	case Direction::Right:
	case Direction::Up:
		return &AnimationTake_["Skull_Text_ON"];
		break;
	case Direction::Left:
	case Direction::Down:
		return &AnimationTake_["Skull_Text_OFF"];
		break;
	default:
		MsgBoxAssert("Flagtext의 방향설정이 안되어있습니다");
		return nullptr;
		break;
	}
}