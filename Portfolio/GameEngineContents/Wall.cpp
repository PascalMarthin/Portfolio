#include "Wall.h"

Wall_Unit* Wall_Unit::Inst_ = new Wall_Unit();
Wall_Text* Wall_Text::Inst_ = new Wall_Text();


Wall_Unit::Wall_Unit()
{
}

Wall_Unit::~Wall_Unit()
{
}

void Wall_Unit::SettingAbility()
{
	Name_ = ObjectName::Wall_Unit;
	Type_ = ObjectType::Unit;

	Image_ = GameEngineImageManager::GetInst()->Find("unit_wall_sheet.bmp");
	AnimationTake_["Wall_Unit"].push_back(std::make_pair(0, 2));
	AnimationTake_["Wall_Unit"].push_back(std::make_pair(3, 5));
	AnimationTake_["Wall_Unit"].push_back(std::make_pair(6, 8));
	AnimationTake_["Wall_Unit"].push_back(std::make_pair(9, 11));
	AnimationTake_["Wall_Unit"].push_back(std::make_pair(12, 14));
	AnimationTake_["Wall_Unit"].push_back(std::make_pair(15, 17));
	AnimationTake_["Wall_Unit"].push_back(std::make_pair(18, 20));
	AnimationTake_["Wall_Unit"].push_back(std::make_pair(21, 23));
	AnimationTake_["Wall_Unit"].push_back(std::make_pair(24, 26));
	AnimationTake_["Wall_Unit"].push_back(std::make_pair(27, 29));
	AnimationTake_["Wall_Unit"].push_back(std::make_pair(30, 32));
	AnimationTake_["Wall_Unit"].push_back(std::make_pair(33, 35));
	AnimationTake_["Wall_Unit"].push_back(std::make_pair(36, 38));
	AnimationTake_["Wall_Unit"].push_back(std::make_pair(39, 41));
	AnimationTake_["Wall_Unit"].push_back(std::make_pair(42, 44));
	AnimationTake_["Wall_Unit"].push_back(std::make_pair(45, 47));

	//AnimationTake_["Wall_Unit_5"].push_back(std::make_pair(0, 2));
	//AnimationTake_["Wall_Unit_6"].push_back(std::make_pair(3, 5));
	//AnimationTake_["Wall_Unit_8"].push_back(std::make_pair(6, 8));
	//AnimationTake_["Wall_Unit_68"].push_back(std::make_pair(9, 11));
	//AnimationTake_["Wall_Unit_4"].push_back(std::make_pair(12, 14));
	//AnimationTake_["Wall_Unit_46"].push_back(std::make_pair(15, 17));
	//AnimationTake_["Wall_Unit_48"].push_back(std::make_pair(18, 20));
	//AnimationTake_["Wall_Unit_468"].push_back(std::make_pair(21, 23));
	//AnimationTake_["Wall_Unit_2"].push_back(std::make_pair(24, 26));
	//AnimationTake_["Wall_Unit_26"].push_back(std::make_pair(27, 29));
	//AnimationTake_["Wall_Unit_28"].push_back(std::make_pair(30, 32));
	//AnimationTake_["Wall_Unit_268"].push_back(std::make_pair(33, 35));
	//AnimationTake_["Wall_Unit_24"].push_back(std::make_pair(36, 38));
	//AnimationTake_["Wall_Unit_246"].push_back(std::make_pair(39, 41));
	//AnimationTake_["Wall_Unit_248"].push_back(std::make_pair(42, 44));
	//AnimationTake_["Wall_Unit_55"].push_back(std::make_pair(45, 47));
}

const std::vector<std::pair<int, int>>* Wall_Unit::GetAnimationTake(Direction _Dir)
{
	return &AnimationTake_["Wall_Unit"];
}

Wall_Text::Wall_Text()
{
}

Wall_Text::~Wall_Text()
{
}

void Wall_Text::SettingAbility()
{
	Name_ = ObjectName::Wall_Text;
	Type_ = ObjectType::Text;
	TextType_ = TextType::Unit_Text;
	TextUnit_ = Wall_Unit::GetInst();

	Image_ = GameEngineImageManager::GetInst()->Find("text_wall_sheet.bmp");
	AnimationTake_["Wall_Text_OFF"].push_back(std::make_pair(0, 2));
	AnimationTake_["Wall_Text_ON"].push_back(std::make_pair(3, 5));


}

const std::vector<std::pair<int, int>>* Wall_Text::GetAnimationTake(Direction _Dir)
{
	switch (_Dir)
	{
	case Direction::Right:
	case Direction::Up:
		return &AnimationTake_["Wall_Text_ON"];
		break;
	case Direction::Left:
	case Direction::Down:
		return &AnimationTake_["Wall_Text_OFF"];
		break;
	default:
		MsgBoxAssert("Flagtext의 방향설정이 안되어있습니다");
		return nullptr;
		break;
	}
}