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
		MsgBoxAssert("���� ũ�Ⱑ 0�� ���Դϴ�");
		return;
	}
	SetMapData();
	FillObject(ObjectName::Empty_Object);
	// ������� �ʴٸ� Error�� ä���־��
	CheckError();
	return;
}

void StageData::SetMapData()
{
	Map_ = Data_;
}

void StageData::FillObject(const ObjectName _Value)
{
	std::vector<ObjectName>::iterator StartVector;
	for (int i = 0; i < GetScale_().iy(); i++)
	{
		for (int j = 0; j < GetScale_().ix(); j++)
		{
			StartVector = Map_[i][j].begin();
			if (StartVector == Map_[i][j].end())
			{
				Map_[i][j].push_back(_Value);
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
			StartVector = Map_[i][j].begin();
			if (StartVector == Map_[i][j].end() || *StartVector == ObjectName::Error)
			{
				MsgBoxAssert("�� �˻� �� Error Ȥ�� �ʱ�ȭ�� ���� ���� ����� �߰� �Ͽ����ϴ�");
				return true;
			}
		}
	}
	return false;
}
