#include "Glass.h"

Grass_Unit* Grass_Unit::Inst_ = new Grass_Unit();
Grass_Text* Grass_Text::Inst_ = new Grass_Text();

Grass_Unit::Grass_Unit()
{
}

Grass_Unit::~Grass_Unit()
{
}

void Grass_Unit::SettingAbility()
{
	Name_ = ObjectName::Grass_Unit;
	Type_ = ObjectType::Unit;

	Image_ = GameEngineImageManager::GetInst()->Find("unit_grass_sheet.bmp");
	AnimationTake_["Grass_Unit"].push_back(std::make_pair(0, 2));
	AnimationTake_["Grass_Unit"].push_back(std::make_pair(3, 5));
	AnimationTake_["Grass_Unit"].push_back(std::make_pair(6, 8));
	AnimationTake_["Grass_Unit"].push_back(std::make_pair(9, 11));
	AnimationTake_["Grass_Unit"].push_back(std::make_pair(12, 14));
	AnimationTake_["Grass_Unit"].push_back(std::make_pair(15, 17));
	AnimationTake_["Grass_Unit"].push_back(std::make_pair(18, 20));
	AnimationTake_["Grass_Unit"].push_back(std::make_pair(21, 23));
	AnimationTake_["Grass_Unit"].push_back(std::make_pair(24, 26));
	AnimationTake_["Grass_Unit"].push_back(std::make_pair(27, 29));
	AnimationTake_["Grass_Unit"].push_back(std::make_pair(30, 32));
	AnimationTake_["Grass_Unit"].push_back(std::make_pair(33, 35));
	AnimationTake_["Grass_Unit"].push_back(std::make_pair(36, 38));
	AnimationTake_["Grass_Unit"].push_back(std::make_pair(39, 41));
	AnimationTake_["Grass_Unit"].push_back(std::make_pair(42, 44));
	AnimationTake_["Grass_Unit"].push_back(std::make_pair(45, 47));
}

const std::vector<std::pair<int, int>>* Grass_Unit::GetAnimationTake(Direction _Dir)
{
	return &AnimationTake_["Grass_Unit"];
}

Grass_Text::Grass_Text()
{
}

Grass_Text::~Grass_Text()
{
}

void Grass_Text::SettingAbility()
{
	Name_ = ObjectName::Grass_Text;
	Type_ = ObjectType::Text;
	TextType_ = TextType::Unit_Text;
	TextUnit_ = Grass_Unit::GetInst();

	Image_ = GameEngineImageManager::GetInst()->Find("text_Grass_Sheet.bmp");
	AnimationTake_["Grass_Text_OFF"].push_back(std::make_pair(0, 2));
	AnimationTake_["Grass_Text_ON"].push_back(std::make_pair(3, 5));

}

const std::vector<std::pair<int, int>>* Grass_Text::GetAnimationTake(Direction _Dir)
{
	switch (_Dir)
	{
	case Direction::Right:
	case Direction::Up:
		return &AnimationTake_["Grass_Text_ON"];
		break;
	case Direction::Left:
	case Direction::Down:
		return &AnimationTake_["Grass_Text_OFF"];
		break;
	default:
		MsgBoxAssert("Grasstext의 방향설정이 안되어있습니다");
		return nullptr;
		break;
	}
}