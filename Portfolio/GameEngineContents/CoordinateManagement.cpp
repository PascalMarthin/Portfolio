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
	// 중복 체크
	if (_Data == nullptr)
	{
		MsgBoxAssert("StageData가 입력되지 않은 채 CoordinateManagement의 Create을 하려고했습니다");
		return;
	}
	MapScale_ = _Data->GetScale();
	Stage_ = _Data->GetStage();

	if (ScanData(_Data) == false)
	{
		MsgBoxAssert("맵 -> 데이터 스캔 실패");
	}

}

bool CoordinateManagement::ScanData(const StageData* _Data)
{
	
}