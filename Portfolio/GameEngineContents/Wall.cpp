#include "Wall.h"

Wall_Unit* Wall_Unit::Inst_ = new Wall_Unit();
Wall_Text* Wall_Text::Inst_ = new Wall_Text();


Wall_Unit::Wall_Unit()
{
}

Wall_Unit::~Wall_Unit()
{
}

void Wall_Unit::SettingImg()
{
	Name_ = ObjectName::Wall_Unit;
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("wall_0_1.bmp"));
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("wall_0_2.bmp"));
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("wall_0_3.bmp"));
	StopImage_[1].push_back(GameEngineImageManager::GetInst()->Find("wall_1_1.bmp"));
	StopImage_[1].push_back(GameEngineImageManager::GetInst()->Find("wall_1_2.bmp"));
	StopImage_[1].push_back(GameEngineImageManager::GetInst()->Find("wall_1_3.bmp"));
	StopImage_[2].push_back(GameEngineImageManager::GetInst()->Find("wall_2_1.bmp"));
	StopImage_[2].push_back(GameEngineImageManager::GetInst()->Find("wall_2_2.bmp"));
	StopImage_[2].push_back(GameEngineImageManager::GetInst()->Find("wall_2_3.bmp"));
	StopImage_[3].push_back(GameEngineImageManager::GetInst()->Find("wall_3_1.bmp"));
	StopImage_[3].push_back(GameEngineImageManager::GetInst()->Find("wall_3_2.bmp"));
	StopImage_[3].push_back(GameEngineImageManager::GetInst()->Find("wall_3_3.bmp"));
	StopImage_[4].push_back(GameEngineImageManager::GetInst()->Find("wall_4_1.bmp"));
	StopImage_[4].push_back(GameEngineImageManager::GetInst()->Find("wall_4_2.bmp"));
	StopImage_[4].push_back(GameEngineImageManager::GetInst()->Find("wall_4_3.bmp"));
	StopImage_[5].push_back(GameEngineImageManager::GetInst()->Find("wall_5_1.bmp"));
	StopImage_[5].push_back(GameEngineImageManager::GetInst()->Find("wall_5_2.bmp"));
	StopImage_[5].push_back(GameEngineImageManager::GetInst()->Find("wall_5_3.bmp"));
	StopImage_[6].push_back(GameEngineImageManager::GetInst()->Find("wall_6_1.bmp"));
	StopImage_[6].push_back(GameEngineImageManager::GetInst()->Find("wall_6_2.bmp"));
	StopImage_[6].push_back(GameEngineImageManager::GetInst()->Find("wall_6_3.bmp"));
	StopImage_[7].push_back(GameEngineImageManager::GetInst()->Find("wall_7_1.bmp"));
	StopImage_[7].push_back(GameEngineImageManager::GetInst()->Find("wall_7_2.bmp"));
	StopImage_[7].push_back(GameEngineImageManager::GetInst()->Find("wall_7_3.bmp"));
	StopImage_[8].push_back(GameEngineImageManager::GetInst()->Find("wall_8_1.bmp"));
	StopImage_[8].push_back(GameEngineImageManager::GetInst()->Find("wall_8_2.bmp"));
	StopImage_[8].push_back(GameEngineImageManager::GetInst()->Find("wall_8_3.bmp"));
	StopImage_[9].push_back(GameEngineImageManager::GetInst()->Find("wall_9_1.bmp"));
	StopImage_[9].push_back(GameEngineImageManager::GetInst()->Find("wall_9_2.bmp"));
	StopImage_[9].push_back(GameEngineImageManager::GetInst()->Find("wall_9_3.bmp"));
	StopImage_[10].push_back(GameEngineImageManager::GetInst()->Find("wall_10_1.bmp"));
	StopImage_[10].push_back(GameEngineImageManager::GetInst()->Find("wall_10_2.bmp"));
	StopImage_[10].push_back(GameEngineImageManager::GetInst()->Find("wall_10_3.bmp"));
	StopImage_[11].push_back(GameEngineImageManager::GetInst()->Find("wall_11_1.bmp"));
	StopImage_[11].push_back(GameEngineImageManager::GetInst()->Find("wall_11_2.bmp"));
	StopImage_[11].push_back(GameEngineImageManager::GetInst()->Find("wall_11_3.bmp"));
	StopImage_[12].push_back(GameEngineImageManager::GetInst()->Find("wall_12_1.bmp"));
	StopImage_[12].push_back(GameEngineImageManager::GetInst()->Find("wall_12_2.bmp"));
	StopImage_[12].push_back(GameEngineImageManager::GetInst()->Find("wall_12_3.bmp"));
	StopImage_[13].push_back(GameEngineImageManager::GetInst()->Find("wall_13_1.bmp"));
	StopImage_[13].push_back(GameEngineImageManager::GetInst()->Find("wall_13_2.bmp"));
	StopImage_[13].push_back(GameEngineImageManager::GetInst()->Find("wall_13_3.bmp"));
	StopImage_[14].push_back(GameEngineImageManager::GetInst()->Find("wall_14_1.bmp"));
	StopImage_[14].push_back(GameEngineImageManager::GetInst()->Find("wall_14_2.bmp"));
	StopImage_[14].push_back(GameEngineImageManager::GetInst()->Find("wall_14_3.bmp"));
	StopImage_[15].push_back(GameEngineImageManager::GetInst()->Find("wall_15_1.bmp"));
	StopImage_[15].push_back(GameEngineImageManager::GetInst()->Find("wall_15_2.bmp"));
	StopImage_[15].push_back(GameEngineImageManager::GetInst()->Find("wall_15_3.bmp"));

}

Wall_Text::Wall_Text()
{
}

Wall_Text::~Wall_Text()
{
}

void Wall_Text::SettingImg()
{
	Name_ = ObjectName::Wall_Text;
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_wall_F_1.bmp"));
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_wall_F_2.bmp"));
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_wall_F_3.bmp"));
	MoveImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_wall_0_1.bmp"));
	MoveImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_wall_0_2.bmp"));
	MoveImage_[0].push_back(GameEngineImageManager::GetInst()->Find("text_wall_0_3.bmp"));
}
