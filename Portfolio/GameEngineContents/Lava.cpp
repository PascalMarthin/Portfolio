#include "Lava.h"

Lava_Unit* Lava_Unit::Inst_ = new Lava_Unit();
Lava_Text* Lava_Text::Inst_ = new Lava_Text();


Lava_Unit::Lava_Unit()
{
}

Lava_Unit::~Lava_Unit()
{
}

void Lava_Unit::SettingImg()
{
	Name_ = ObjectName::Lava_Unit;
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("lava_0_1.bmp"));
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("lava_0_2.bmp"));
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("lava_0_3.bmp"));
}

Lava_Text::Lava_Text()
{
}

Lava_Text::~Lava_Text()
{
}

void Lava_Text::SettingImg()
{
	Name_ = ObjectName::Lava_Text;
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_lava_F_1.bmp"));
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_lava_F_2.bmp"));
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_lava_F_3.bmp"));
	MoveImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_lava_0_1.bmp"));
	MoveImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_lava_0_2.bmp"));
	MoveImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_lava_0_3.bmp"));
}
