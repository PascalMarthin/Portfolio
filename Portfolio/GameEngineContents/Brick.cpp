#include "Brick.h"

Brick_Unit* Brick_Unit::Inst_ = new Brick_Unit();
Brick_Text* Brick_Text::Inst_ = new Brick_Text();


Brick_Unit::Brick_Unit()
{
}

Brick_Unit::~Brick_Unit()
{
}

void Brick_Unit::SettingAbility()
{
	Name_ = ObjectName::Brick_Unit;
	Type_ = ObjectType::Unit;

	Image_ = GameEngineImageManager::GetInst()->Find("unit_brick_sheet.bmp");
	AnimationTake_["Brick_Unit"].push_back(std::make_pair(0, 2));
	AnimationTake_["Brick_Unit"].push_back(std::make_pair(3, 5));
	AnimationTake_["Brick_Unit"].push_back(std::make_pair(6, 8));
	AnimationTake_["Brick_Unit"].push_back(std::make_pair(9, 11));
	AnimationTake_["Brick_Unit"].push_back(std::make_pair(12, 14));
	AnimationTake_["Brick_Unit"].push_back(std::make_pair(15, 17));
	AnimationTake_["Brick_Unit"].push_back(std::make_pair(18, 20));
	AnimationTake_["Brick_Unit"].push_back(std::make_pair(21, 23));
	AnimationTake_["Brick_Unit"].push_back(std::make_pair(24, 26));
	AnimationTake_["Brick_Unit"].push_back(std::make_pair(27, 29));
	AnimationTake_["Brick_Unit"].push_back(std::make_pair(30, 32));
	AnimationTake_["Brick_Unit"].push_back(std::make_pair(33, 35));
	AnimationTake_["Brick_Unit"].push_back(std::make_pair(36, 38));
	AnimationTake_["Brick_Unit"].push_back(std::make_pair(39, 41));
	AnimationTake_["Brick_Unit"].push_back(std::make_pair(42, 44));
	AnimationTake_["Brick_Unit"].push_back(std::make_pair(45, 47));
}

const std::vector<std::pair<int, int>>* Brick_Unit::GetAnimationTake(Direction _Dir)
{
	return &AnimationTake_["Brick_Unit"];
}

Brick_Text::Brick_Text()
{
}

Brick_Text::~Brick_Text()
{
}

void Brick_Text::SettingAbility()
{
	Name_ = ObjectName::Brick_Text;
	Type_ = ObjectType::Text;
	TextType_ = TextType::Unit_Text;
	TextUnit_ = Brick_Unit::GetInst();

	Image_ = GameEngineImageManager::GetInst()->Find("text_brick_sheet.bmp");
	AnimationTake_["Brick_Text_OFF"].push_back(std::make_pair(0, 2));
	AnimationTake_["Brick_Text_ON"].push_back(std::make_pair(3, 5));

}

const std::vector<std::pair<int, int>>* Brick_Text::GetAnimationTake(Direction _Dir)
{
	switch (_Dir)
	{
	case Direction::Right:
	case Direction::Up:
		return &AnimationTake_["Brick_Text_ON"];
		break;
	case Direction::Left:
	case Direction::Down:
		return &AnimationTake_["Brick_Text_OFF"];
		break;
	default:
		MsgBoxAssert("Flagtext의 방향설정이 안되어있습니다");
		return nullptr;
		break;
	}
}