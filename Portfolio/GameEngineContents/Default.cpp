#include "Default.h"

Default* Default::Inst_ = new Default();

Default::Default() 
{
}

Default::~Default() 
{
}

void Default::SettingAbility()
{
	Name_ = ObjectName::Default;
	Type_ = ObjectType::Unit;
	Image_ = GameEngineImageManager::GetInst()->Find("Main_stage_sheet.bmp");
	AnimationTake_["Default"].push_back(std::make_pair(0, 2));
}

const std::vector<std::pair<int, int>>* Default::GetAnimationTake(Direction _Dir)
{
	switch (_Dir)
	{
	case Direction::Right:
	case Direction::Up:
	case Direction::Left:
	case Direction::Down:
		return &AnimationTake_["Default"];
		break;
	default:
		MsgBoxAssert("디폴트 설정이 잘못되어있습니다");
		return nullptr;
		break;
	}
}
