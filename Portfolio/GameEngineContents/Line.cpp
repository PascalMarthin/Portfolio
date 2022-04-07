#include "Line.h"

Line* Line::Inst_ = new Line();

Line::Line() 
{
}

Line::~Line() 
{
}

void Line::SettingAbility()
{
	Name_ = ObjectName::Line;
	Type_ = ObjectType::Unit;
	Image_ = GameEngineImageManager::GetInst()->Find("unit_line_sheet.bmp");
	AnimationTake_["Line_48"].push_back(std::make_pair(0, 2));
	AnimationTake_["Line_28"].push_back(std::make_pair(3, 5));
	AnimationTake_["Line_68"].push_back(std::make_pair(6, 8));
}

const std::vector<std::pair<int, int>>* Line::GetAnimationTake(Direction _Dir)
{
	switch (_Dir)
	{
	case Direction::Right:
	case Direction::Up:
		return &AnimationTake_["Line_48"];
		break;
	case Direction::Left:
		return &AnimationTake_["Line_28"];
		break;
	case Direction::Down:
		return &AnimationTake_["Line_68"];
		break;
	default:
		MsgBoxAssert("디폴트 설정이 잘못되어있습니다");
		return nullptr;
		break;
	}
}
