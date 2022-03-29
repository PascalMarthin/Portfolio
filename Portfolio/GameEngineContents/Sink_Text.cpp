#include "Sink_Text.h"

Sink_Text* Sink_Text::Inst_ = new Sink_Text();

Sink_Text::Sink_Text()
{
}

Sink_Text::~Sink_Text()
{
}

void Sink_Text::SettingImg()
{
	Name_ = ObjectName::Sink_Text;
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_sink_F_1.bmp"));
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_sink_F_2.bmp"));
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_sink_F_3.bmp"));
	MoveImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_sink_0_1.bmp"));
	MoveImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_sink_0_2.bmp"));
	MoveImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_sink_0_3.bmp"));
}