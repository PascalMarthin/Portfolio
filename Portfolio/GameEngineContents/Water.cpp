#include "Water.h"

Water_Unit* Water_Unit::Inst_ = new Water_Unit();
Water_Text* Water_Text::Inst_ = new Water_Text();


Water_Unit::Water_Unit()
{
}

Water_Unit::~Water_Unit()
{
}

void Water_Unit::SettingAbility()
{
	Name_ = ObjectName::Water_Unit;
	Type_ = ObjectType::Unit;

	Image_ = GameEngineImageManager::GetInst()->Find("unit_water_sheet.bmp");
	AnimationTake_["Water_Unit_5"].push_back(std::make_pair(0, 2));
	AnimationTake_["Water_Unit_6"].push_back(std::make_pair(3, 5));
	AnimationTake_["Water_Unit_8"].push_back(std::make_pair(6, 8));
	AnimationTake_["Water_Unit_68"].push_back(std::make_pair(9, 11));
	AnimationTake_["Water_Unit_4"].push_back(std::make_pair(12, 14));
	AnimationTake_["Water_Unit_46"].push_back(std::make_pair(15, 17));
	AnimationTake_["Water_Unit_48"].push_back(std::make_pair(18, 20));
	AnimationTake_["Water_Unit_468"].push_back(std::make_pair(21, 23));
	AnimationTake_["Water_Unit_2"].push_back(std::make_pair(24, 26));
	AnimationTake_["Water_Unit_26"].push_back(std::make_pair(27, 29));
	AnimationTake_["Water_Unit_28"].push_back(std::make_pair(30, 32));
	AnimationTake_["Water_Unit_268"].push_back(std::make_pair(33, 35));
	AnimationTake_["Water_Unit_24"].push_back(std::make_pair(36, 38));
	AnimationTake_["Water_Unit_246"].push_back(std::make_pair(39, 41));
	AnimationTake_["Water_Unit_248"].push_back(std::make_pair(42, 44));
	AnimationTake_["Water_Unit_55"].push_back(std::make_pair(45, 47));
}

Water_Text::Water_Text()
{
}

Water_Text::~Water_Text()
{
}

void Water_Text::SettingAbility()
{
	Name_ = ObjectName::Water_Text;
	Type_ = ObjectType::Text;
	TextType_ = TextType::Unit_Text;
	TextUnit_ = Water_Unit::GetInst();

	Image_ = GameEngineImageManager::GetInst()->Find("text_water_sheet.bmp");
	AnimationTake_["Water_Text_OFF"].push_back(std::make_pair(0, 2));
	AnimationTake_["Water_Text_ON"].push_back(std::make_pair(3, 5));

}

const std::vector<std::pair<int, int>>* Water_Text::GetAnimationTake(Direction _Dir)
{
	switch (_Dir)
	{
	case Direction::Right:
	case Direction::Up:
		return &AnimationTake_["Water_Text_ON"];
		break;
	case Direction::Left:
	case Direction::Down:
		return &AnimationTake_["Water_Text_OFF"];
		break;
	default:
		MsgBoxAssert("Flagtext의 방향설정이 안되어있습니다");
		return nullptr;
		break;
	}
}