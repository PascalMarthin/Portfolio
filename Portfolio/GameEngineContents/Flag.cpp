#include "Flag.h"

Flag_Unit* Flag_Unit::Inst_ = new Flag_Unit();
Flag_Text* Flag_Text::Inst_ = new Flag_Text();


Flag_Unit::Flag_Unit()
{
}

Flag_Unit::~Flag_Unit()
{
}

void Flag_Unit::SettingImg()
{
	Name_ = ObjectName::Flag_Unit;
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("flag_0_1.bmp"));
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("flag_0_2.bmp"));
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("flag_0_3.bmp"));
}

Flag_Text::Flag_Text()
{
}

Flag_Text::~Flag_Text()
{
}

void Flag_Text::SettingImg()
{
	Name_ = ObjectName::Flag_Text;
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_flag_F_1.bmp"));
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_flag_F_2.bmp"));
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_flag_F_3.bmp"));
	MoveImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_flag_0_1.bmp"));
	MoveImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_flag_0_2.bmp"));
	MoveImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_flag_0_3.bmp"));
}
