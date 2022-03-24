#include "CoordinateManagement.h"
#include <GameEngineBase/GameEngineDebug.h>


CoordinateManagement::CoordinateManagement() 
{
}

CoordinateManagement::~CoordinateManagement() 
{
}

void CoordinateManagement::Create(const StageData* _Data)
{
	// �ߺ� üũ
	if (_Data == nullptr)
	{
		MsgBoxAssert("StageData�� �Էµ��� ���� ä CoordinateManagement�� Create�� �Ϸ����߽��ϴ�");
		return;
	}
	MapScale_ = _Data->GetScale();
	Stage_ = _Data->GetStage();

	if (ScanData(_Data) == false)
	{
		MsgBoxAssert("�� -> ������ ��ĵ ����");
	}

}

bool CoordinateManagement::ScanData(const StageData* _Data)
{
	
}