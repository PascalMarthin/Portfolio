#include "Baba.h"

Baba_Unit::Baba_Unit()
{
	Name_ = ObjectName::Baba_Object;
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("baba_0_1.bmp"));
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("baba_0_2.bmp"));
	StopImage_[0].push_back(GameEngineImageManager::GetInst()->Find("baba_0_3.bmp"));

	StopImage_[1].push_back(GameEngineImageManager::GetInst()->Find("baba_1_1.bmp"));
	StopImage_[1].push_back(GameEngineImageManager::GetInst()->Find("baba_1_2.bmp"));
	StopImage_[1].push_back(GameEngineImageManager::GetInst()->Find("baba_1_3.bmp"));

	StopImage_[2].push_back(GameEngineImageManager::GetInst()->Find("baba_2_1.bmp"));
	StopImage_[2].push_back(GameEngineImageManager::GetInst()->Find("baba_2_2.bmp"));
	StopImage_[2].push_back(GameEngineImageManager::GetInst()->Find("baba_2_3.bmp"));

	StopImage_[3].push_back(GameEngineImageManager::GetInst()->Find("baba_7_1.bmp"));
	StopImage_[3].push_back(GameEngineImageManager::GetInst()->Find("baba_7_2.bmp"));
	StopImage_[3].push_back(GameEngineImageManager::GetInst()->Find("baba_7_3.bmp"));

	StopImage_[4].push_back(GameEngineImageManager::GetInst()->Find("baba_8_1.bmp"));
	StopImage_[4].push_back(GameEngineImageManager::GetInst()->Find("baba_8_2.bmp"));
	StopImage_[4].push_back(GameEngineImageManager::GetInst()->Find("baba_8_3.bmp"));

	StopImage_[5].push_back(GameEngineImageManager::GetInst()->Find("baba_9_1.bmp"));
	StopImage_[5].push_back(GameEngineImageManager::GetInst()->Find("baba_9_2.bmp"));
	StopImage_[5].push_back(GameEngineImageManager::GetInst()->Find("baba_9_3.bmp"));

	StopImage_[6].push_back(GameEngineImageManager::GetInst()->Find("baba_10_1.bmp"));
	StopImage_[6].push_back(GameEngineImageManager::GetInst()->Find("baba_10_2.bmp"));
	StopImage_[6].push_back(GameEngineImageManager::GetInst()->Find("baba_10_3.bmp"));

	StopImage_[7].push_back(GameEngineImageManager::GetInst()->Find("baba_11_1.bmp"));
	StopImage_[7].push_back(GameEngineImageManager::GetInst()->Find("baba_11_2.bmp"));
	StopImage_[7].push_back(GameEngineImageManager::GetInst()->Find("baba_11_3.bmp"));

	StopImage_[8].push_back(GameEngineImageManager::GetInst()->Find("baba_15_1.bmp"));
	StopImage_[8].push_back(GameEngineImageManager::GetInst()->Find("baba_15_2.bmp"));
	StopImage_[8].push_back(GameEngineImageManager::GetInst()->Find("baba_15_3.bmp"));

	StopImage_[9].push_back(GameEngineImageManager::GetInst()->Find("baba_16_1.bmp"));
	StopImage_[9].push_back(GameEngineImageManager::GetInst()->Find("baba_16_2.bmp"));
	StopImage_[9].push_back(GameEngineImageManager::GetInst()->Find("baba_16_3.bmp"));

	StopImage_[10].push_back(GameEngineImageManager::GetInst()->Find("baba_17_1.bmp"));
	StopImage_[10].push_back(GameEngineImageManager::GetInst()->Find("baba_17_2.bmp"));
	StopImage_[10].push_back(GameEngineImageManager::GetInst()->Find("baba_17_3.bmp"));

	StopImage_[11].push_back(GameEngineImageManager::GetInst()->Find("baba_18_1.bmp"));
	StopImage_[11].push_back(GameEngineImageManager::GetInst()->Find("baba_18_2.bmp"));
	StopImage_[11].push_back(GameEngineImageManager::GetInst()->Find("baba_18_3.bmp"));

	StopImage_[12].push_back(GameEngineImageManager::GetInst()->Find("baba_19_1.bmp"));
	StopImage_[12].push_back(GameEngineImageManager::GetInst()->Find("baba_19_2.bmp"));
	StopImage_[12].push_back(GameEngineImageManager::GetInst()->Find("baba_19_3.bmp"));

	StopImage_[13].push_back(GameEngineImageManager::GetInst()->Find("baba_23_1.bmp"));
	StopImage_[13].push_back(GameEngineImageManager::GetInst()->Find("baba_23_2.bmp"));
	StopImage_[13].push_back(GameEngineImageManager::GetInst()->Find("baba_23_3.bmp"));

	StopImage_[14].push_back(GameEngineImageManager::GetInst()->Find("baba_24_1.bmp"));
	StopImage_[14].push_back(GameEngineImageManager::GetInst()->Find("baba_24_2.bmp"));
	StopImage_[14].push_back(GameEngineImageManager::GetInst()->Find("baba_24_3.bmp"));

	StopImage_[15].push_back(GameEngineImageManager::GetInst()->Find("baba_25_1.bmp"));
	StopImage_[15].push_back(GameEngineImageManager::GetInst()->Find("baba_25_2.bmp"));
	StopImage_[15].push_back(GameEngineImageManager::GetInst()->Find("baba_25_3.bmp"));

	StopImage_[16].push_back(GameEngineImageManager::GetInst()->Find("baba_26_1.bmp"));
	StopImage_[16].push_back(GameEngineImageManager::GetInst()->Find("baba_26_2.bmp"));
	StopImage_[16].push_back(GameEngineImageManager::GetInst()->Find("baba_26_3.bmp"));

	StopImage_[17].push_back(GameEngineImageManager::GetInst()->Find("baba_27_1.bmp"));
	StopImage_[17].push_back(GameEngineImageManager::GetInst()->Find("baba_27_2.bmp"));
	StopImage_[17].push_back(GameEngineImageManager::GetInst()->Find("baba_27_3.bmp"));

	StopImage_[18].push_back(GameEngineImageManager::GetInst()->Find("baba_31_1.bmp"));
	StopImage_[18].push_back(GameEngineImageManager::GetInst()->Find("baba_31_2.bmp"));
	StopImage_[18].push_back(GameEngineImageManager::GetInst()->Find("baba_31_3.bmp"));
}

Baba_Unit::~Baba_Unit()
{
}


Baba_Text::Baba_Text() 
{
}

Baba_Text::~Baba_Text() 
{
}

