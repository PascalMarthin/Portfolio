#include "Water.h"

Water_Unit* Water_Unit::Inst_ = new Water_Unit();
Water_Text* Water_Text::Inst_ = new Water_Text();


Water_Unit::Water_Unit()
{
}

Water_Unit::~Water_Unit()
{
}

void Water_Unit::SettingImg()
{
}

Water_Text::Water_Text()
{
}

Water_Text::~Water_Text()
{
}

void Water_Text::SettingImg()
{
	Name_ = ObjectName::Water_Text;
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_water_F_1.bmp"));
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_water_F_2.bmp"));
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_water_F_3.bmp"));
	MoveImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_water_0_1.bmp"));
	MoveImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_water_0_2.bmp"));
	MoveImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_water_0_3.bmp"));
}