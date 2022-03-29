#include "Is_Text.h"

Is_Text* Is_Text::Inst_ = new Is_Text();

Is_Text::Is_Text()
{
}

Is_Text::~Is_Text()
{
}

void Is_Text::SettingImg()
{
	Name_ = ObjectName::Is_Text;
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_is_F_1.bmp"));
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_is_F_2.bmp"));
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_is_F_3.bmp"));
	MoveImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_is_0_1.bmp"));
	MoveImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_is_0_2.bmp"));
	MoveImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_is_0_3.bmp"));
}