#include "Skull.h"

Skull_Unit* Skull_Unit::Inst_ = new Skull_Unit();
Skull_Text* Skull_Text::Inst_ = new Skull_Text();


Skull_Unit::Skull_Unit()
{
}

Skull_Unit::~Skull_Unit()
{
}

void Skull_Unit::SettingImg()
{
	Name_ = ObjectName::Skull_Unit;
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("skull_0_1.bmp"));
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("skull_0_2.bmp"));
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("skull_0_3.bmp"));
}

Skull_Text::Skull_Text()
{
}

Skull_Text::~Skull_Text()
{
}

void Skull_Text::SettingImg()
{
	Name_ = ObjectName::Skull_Text;
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_skull_F_1.bmp"));
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_skull_F_2.bmp"));
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_skull_F_3.bmp"));
	MoveImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_skull_0_1.bmp"));
	MoveImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_skull_0_2.bmp"));
	MoveImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_skull_0_3.bmp"));
}
