#include "Hot_Text.h"

Hot_Text* Hot_Text::Inst_ = new Hot_Text();

Hot_Text::Hot_Text()
{
}

Hot_Text::~Hot_Text()
{
}

void Hot_Text::SettingAbility()
{
	Name_ = ObjectName::Hot_Text;
	Type_ = ObjectType::Text;
	TextType_ = TextType::Stat_Text;

	Image_ = GameEngineImageManager::GetInst()->Find("text_hot_sheet.bmp");
}

void Hot_Text::StatHot()
{
	//���ۺ��۰Ÿ��� ����Ʈ�� �߰�
	//�ڽŰ� ���� ĭ�� �����ϴ� MELT �Ӽ��� ��ü�� ��� �ı��Ѵ�
}