#include "Push_Text.h"

Push_Text* Push_Text::Inst_ = new Push_Text();

Push_Text::Push_Text()
{
}

Push_Text::~Push_Text()
{
}

void Push_Text::SettingImg()
{
	Name_ = ObjectName::Push_Text;
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_push_F_1.bmp"));
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_push_F_2.bmp"));
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_push_F_3.bmp"));
	MoveImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_push_0_1.bmp"));
	MoveImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_push_0_2.bmp"));
	MoveImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_push_0_3.bmp"));
}