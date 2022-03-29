#include "Defeat_Text.h"

Defeat_Text* Defeat_Text::Inst_ = new Defeat_Text();

Defeat_Text::Defeat_Text()
{
}

Defeat_Text::~Defeat_Text()
{
}

void Defeat_Text::SettingImg()
{
	Name_ = ObjectName::Defeat_Text;
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_defeat_F_1.bmp"));
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_defeat_F_2.bmp"));
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_defeat_F_3.bmp"));
	MoveImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_defeat_0_1.bmp"));
	MoveImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_defeat_0_2.bmp"));
	MoveImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_defeat_0_3.bmp"));
}