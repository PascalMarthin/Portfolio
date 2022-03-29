#include "Stop_Text.h"

Stop_Text* Stop_Text::Inst_ = new Stop_Text();

Stop_Text::Stop_Text()
{
}

Stop_Text::~Stop_Text()
{
}

void Stop_Text::SettingImg()
{
	Name_ = ObjectName::Stop_Text;
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_stop_F_1.bmp"));
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_stop_F_2.bmp"));
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_stop_F_3.bmp"));
	MoveImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_stop_0_1.bmp"));
	MoveImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_stop_0_2.bmp"));
	MoveImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_stop_0_3.bmp"));
}