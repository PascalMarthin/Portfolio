#include "Tile.h"

Tile_Unit* Tile_Unit::Inst_ = new Tile_Unit();

Tile_Unit::Tile_Unit()
{
}

Tile_Unit::~Tile_Unit()
{
}

void Tile_Unit::SettingAbility()
{
	Name_ = ObjectName::Tile_Unit;
	Type_ = ObjectType::Unit;

	Image_ = GameEngineImageManager::GetInst()->Find("unit_tile_sheet.bmp");
	AnimationTake_["Tile_Unit"].push_back(std::make_pair(0, 2));

}
const std::vector<std::pair<int, int>>* Tile_Unit::GetAnimationTake(Direction _Dir)
{
	switch (_Dir)
	{
	case Direction::Right:
	case Direction::Up:
	case Direction::Left:
	case Direction::Down:
		return &AnimationTake_["Tile_Unit"];
		break;
	default:
		MsgBoxAssert("바바의 방향설정이 안되어있습니다");
		return nullptr;
		break;
	}
}
