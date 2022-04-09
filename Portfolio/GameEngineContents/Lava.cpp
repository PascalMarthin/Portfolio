#include "Lava.h"

Lava_Unit* Lava_Unit::Inst_ = new Lava_Unit();
Lava_Text* Lava_Text::Inst_ = new Lava_Text();


Lava_Unit::Lava_Unit()
{
}

Lava_Unit::~Lava_Unit()
{
}

void Lava_Unit::SettingAbility()
{
	Name_ = ObjectName::Lava_Unit;
	Type_ = ObjectType::Unit;

	Image_ = GameEngineImageManager::GetInst()->Find("unit_lava_sheet.bmp");
	AnimationTake_["Lave_Unit"].push_back(std::make_pair(0, 2));
	AnimationTake_["Lave_Unit"].push_back(std::make_pair(3, 5));
	AnimationTake_["Lave_Unit"].push_back(std::make_pair(6, 8));
	AnimationTake_["Lave_Unit"].push_back(std::make_pair(9, 11));
	AnimationTake_["Lave_Unit"].push_back(std::make_pair(12, 14));
	AnimationTake_["Lave_Unit"].push_back(std::make_pair(15, 17));
	AnimationTake_["Lave_Unit"].push_back(std::make_pair(18, 20));
	AnimationTake_["Lave_Unit"].push_back(std::make_pair(21, 23));
	AnimationTake_["Lave_Unit"].push_back(std::make_pair(24, 26));
	AnimationTake_["Lave_Unit"].push_back(std::make_pair(27, 29));
	AnimationTake_["Lave_Unit"].push_back(std::make_pair(30, 32));
	AnimationTake_["Lave_Unit"].push_back(std::make_pair(33, 35));
	AnimationTake_["Lave_Unit"].push_back(std::make_pair(36, 38));
	AnimationTake_["Lave_Unit"].push_back(std::make_pair(39, 41));
	AnimationTake_["Lave_Unit"].push_back(std::make_pair(42, 44));
	AnimationTake_["Lave_Unit"].push_back(std::make_pair(45, 47));
}

const std::vector<std::pair<int, int>>* Lava_Unit::GetAnimationTake(Direction _Dir)
{
	return &AnimationTake_["Lave_Unit"];
}

Lava_Text::Lava_Text()
{
}

Lava_Text::~Lava_Text()
{
}

void Lava_Text::SettingAbility()
{
	Name_ = ObjectName::Lava_Text;
	Type_ = ObjectType::Text;
	TextType_ = TextType::Unit_Text;

	Image_ = GameEngineImageManager::GetInst()->Find("text_lava_sheet.bmp");
	AnimationTake_["Lava_Text_OFF"].push_back(std::make_pair(0, 2));
	AnimationTake_["Lava_Text_ON"].push_back(std::make_pair(3, 5));

}

const std::vector<std::pair<int, int>>* Lava_Text::GetAnimationTake(Direction _Dir)
{
	switch (_Dir)
	{
	case Direction::Right:
	case Direction::Up:
		return &AnimationTake_["Lava_Text_ON"];
		break;
	case Direction::Left:
	case Direction::Down:
		return &AnimationTake_["Lava_Text_OFF"];
		break;
	default:
		MsgBoxAssert("Flagtext의 방향설정이 안되어있습니다");
		return nullptr;
		break;
	}
}