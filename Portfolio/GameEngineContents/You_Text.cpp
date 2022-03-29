#include "You_Text.h"

You_Text* You_Text::Inst_ = new You_Text();

You_Text::You_Text()
{
}

You_Text::~You_Text()
{
}

void You_Text::SettingImg()
{
	Name_ = ObjectName::You_Text;
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_you_F_1.bmp"));
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_you_F_2.bmp"));
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_you_F_3.bmp"));
	MoveImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_you_0_1.bmp"));
	MoveImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_you_0_2.bmp"));
	MoveImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_you_0_3.bmp"));
}