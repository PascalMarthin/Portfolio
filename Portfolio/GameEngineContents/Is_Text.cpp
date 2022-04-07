#include "Is_Text.h"

Is_Text* Is_Text::Inst_ = new Is_Text();

Is_Text::Is_Text()
{
}

Is_Text::~Is_Text()
{
}

void Is_Text::SettingAbility()
{
	Name_ = ObjectName::Is_Text;
	Type_ = ObjectType::Text;
	TextType_ = TextType::Verb_Text;

	Image_ = GameEngineImageManager::GetInst()->Find("text_is_sheet.bmp");
	AnimationTake_["Is_Text_OFF"].push_back(std::make_pair(0, 2));
	AnimationTake_["Is_Text_ON"].push_back(std::make_pair(3, 5));

}

const std::vector<std::pair<int, int>>* Is_Text::GetAnimationTake(Direction _Dir)
{
	switch (_Dir)
	{
	case Direction::Right:
	case Direction::Up:
		return &AnimationTake_["Is_Text_ON"];
		break;
	case Direction::Left:
	case Direction::Down:
		return &AnimationTake_["Is_Text_OFF"];
		break;
	default:
		MsgBoxAssert("Flagtext�� ���⼳���� �ȵǾ��ֽ��ϴ�");
		return nullptr;
		break;
	}
}