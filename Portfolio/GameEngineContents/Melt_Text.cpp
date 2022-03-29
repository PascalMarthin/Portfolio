#include "Melt_Text.h"

Melt_Text* Melt_Text::Inst_ = new Melt_Text();

Melt_Text::Melt_Text()
{
}

Melt_Text::~Melt_Text()
{
}

void Melt_Text::SettingImg()
{
	Name_ = ObjectName::Melt_Text;
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_melt_F_1.bmp"));
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_melt_F_2.bmp"));
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_melt_F_3.bmp"));
	MoveImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_melt_0_1.bmp"));
	MoveImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_melt_0_2.bmp"));
	MoveImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_melt_0_3.bmp"));
}