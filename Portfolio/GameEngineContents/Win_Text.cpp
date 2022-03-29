#include "Win_Text.h"

Win_Text* Win_Text::Inst_ = new Win_Text();

Win_Text::Win_Text()
{
}

Win_Text::~Win_Text()
{
}

void Win_Text::SettingImg()
{
	Name_ = ObjectName::Win_Text;
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_win_F_1.bmp"));
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_win_F_2.bmp"));
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_win_F_3.bmp"));
	MoveImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_win_0_1.bmp"));
	MoveImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_win_0_2.bmp"));
	MoveImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_win_0_3.bmp"));
}