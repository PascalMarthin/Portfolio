#include "Flower.h"

Flower_Unit* Flower_Unit::Inst_ = new Flower_Unit();

Flower_Unit::Flower_Unit()
{
}

Flower_Unit::~Flower_Unit()
{
}


void Flower_Unit::SettingAbility()
{
	Name_ = ObjectName::Flower_Unit;
	Type_ = ObjectType::Unit;

	Image_ = GameEngineImageManager::GetInst()->Find("unit_flower_sheet.bmp");
	AnimationTake_["Flower_Unit"].push_back(std::make_pair(0, 2));

}
const std::vector<std::pair<int, int>>* Flower_Unit::GetAnimationTake(Direction _Dir)
{
	switch (_Dir)
	{
	case Direction::Right:
	case Direction::Up:
	case Direction::Left:
	case Direction::Down:
		return &AnimationTake_["Flower_Unit"];
		break;
	default:
		MsgBoxAssert("바바의 방향설정이 안되어있습니다");
		return nullptr;
		break;
	}
}
