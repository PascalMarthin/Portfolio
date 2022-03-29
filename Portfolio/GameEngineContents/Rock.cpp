#include "Rock.h"


Rock_Unit* Rock_Unit::Inst_ = new Rock_Unit();
Rock_Text* Rock_Text::Inst_ = new Rock_Text();


Rock_Unit::Rock_Unit()
{
}

Rock_Unit::~Rock_Unit()
{
}

void Rock_Unit::SettingImg()
{
	Name_ = ObjectName::Rock_Unit;
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("rock_0_1.bmp"));
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("rock_0_2.bmp"));
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("rock_0_3.bmp"));
}

Rock_Text::Rock_Text()
{
}

Rock_Text::~Rock_Text()
{
}

void Rock_Text::SettingImg()
{
	Name_ = ObjectName::Rock_Text;
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_rock_F_1.bmp"));
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_rock_F_2.bmp"));
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_rock_F_3.bmp"));
	MoveImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_rock_0_1.bmp"));
	MoveImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_rock_0_2.bmp"));
	MoveImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_rock_0_3.bmp"));
}
