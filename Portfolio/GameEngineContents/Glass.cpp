#include "Glass.h"

Grass_Unit* Grass_Unit::Inst_ = new Grass_Unit();

Grass_Unit::Grass_Unit()
{
}

Grass_Unit::~Grass_Unit()
{
}

void Grass_Unit::SettingImg()
{
	Name_ = ObjectName::Grass_Unit;
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("grass_0_1.bmp"));
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("grass_0_2.bmp"));
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("grass_0_3.bmp"));
}