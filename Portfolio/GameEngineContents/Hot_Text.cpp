#include "Hot_Text.h"

Hot_Text* Hot_Text::Inst_ = new Hot_Text();

Hot_Text::Hot_Text()
{
}

Hot_Text::~Hot_Text()
{
}

void Hot_Text::SettingImg()
{
	Name_ = ObjectName::Hot_Text;
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_hot_F_1.bmp"));
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_hot_F_2.bmp"));
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_hot_F_3.bmp"));
	MoveImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_hot_0_1.bmp"));
	MoveImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_hot_0_2.bmp"));
	MoveImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_hot_0_3.bmp"));
}