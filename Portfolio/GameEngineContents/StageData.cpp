#include "StageData.h"

StageData::StageData() 
	: MapScale_()
{
}

StageData::~StageData() 
{

}

void StageData::CreateMap()
{
	
	if (MapScale_.ix() == 0 || MapScale_.iy() == 0)
	{
		MsgBoxAssert("맵의 크기가 0인 맵입니다");
		return;
	}
	FillObject(ObjectName::Empty_Object);
	// 맵 생성이 되었는지 체크
	if (CheckError())
	{
		MsgBoxAssert("맵의 크기가 0인 맵입니다");
	}
	return;
}


void StageData::FillObject(const ObjectName _Value)
{
	std::vector<ObjectName>::iterator StartVector;
	for (int i = 0; i < GetScale_().iy(); i++)
	{
		for (int j = 0; j < GetScale_().ix(); j++)
		{
			StartVector = Data_[i][j].begin();
			if (StartVector == Data_[i][j].end())
			{
				Data_[i][j].push_back(_Value);
			}
		}
	}
	return;
}

bool StageData::CheckError()
{
	std::vector<ObjectName>::iterator StartVector;
	for (int i = 0; i < GetScale_().iy(); i++)
	{
		for (int j = 0; j < GetScale_().ix(); j++)
		{
			StartVector = Data_[i][j].begin();
			if (StartVector == Data_[i][j].end() || *StartVector == ObjectName::Error)
			{
				MsgBoxAssert("맵 검사 중 Error 혹은 초기화가 되지 않은 블록을 발견 하였습니다");
				return true;
			}
		}
	}
	return false;
}
