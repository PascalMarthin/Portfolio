#include "CoordinateManagement.h"
#include <GameEngineBase/GameEngineDebug.h>


CoordinateManagement::CoordinateManagement() 
{
}

CoordinateManagement::~CoordinateManagement() 
{
}

void CoordinateManagement::Create(StageData* _Data)
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

bool CoordinateManagement::ScanData(StageData* _Data)
{
	Map_[6][11] = new Coordinate(ObjectName::Baba_Text);
	Map_[6][12] = new Coordinate(ObjectName::Is_Text);
	Map_[6][13] = new Coordinate(ObjectName::You_Text);
	Map_[6][19] = new Coordinate(ObjectName::Flag_Text);
	Map_[6][20] = new Coordinate(ObjectName::Is_Text);
	Map_[6][21] = new Coordinate(ObjectName::Win_Text);
	Map_[8][11] = new Coordinate(ObjectName::Wall_Object);
	Map_[8][12] = new Coordinate(ObjectName::Wall_Object);
	Map_[8][13] = new Coordinate(ObjectName::Wall_Object);
	Map_[8][14] = new Coordinate(ObjectName::Wall_Object);
	Map_[8][15] = new Coordinate(ObjectName::Wall_Object);
	Map_[8][16] = new Coordinate(ObjectName::Wall_Object);
	Map_[8][17] = new Coordinate(ObjectName::Wall_Object);
	Map_[8][18] = new Coordinate(ObjectName::Wall_Object);
	Map_[8][19] = new Coordinate(ObjectName::Wall_Object);
	Map_[8][20] = new Coordinate(ObjectName::Wall_Object);
	Map_[8][21] = new Coordinate(ObjectName::Wall_Object);
	Map_[9][11] = new Coordinate(ObjectName::Tile_Object);
	Map_[9][12] = new Coordinate(ObjectName::Tile_Object);
	Map_[9][13] = new Coordinate(ObjectName::Tile_Object);
	Map_[9][14] = new Coordinate(ObjectName::Tile_Object);
	Map_[9][15] = new Coordinate(ObjectName::Tile_Object);
	Map_[9][16] = new Coordinate(ObjectName::Rock_Object);
	Map_[9][17] = new Coordinate(ObjectName::Tile_Object);
	Map_[9][18] = new Coordinate(ObjectName::Tile_Object);
	Map_[9][19] = new Coordinate(ObjectName::Tile_Object);
	Map_[9][20] = new Coordinate(ObjectName::Tile_Object);
	Map_[9][21] = new Coordinate(ObjectName::Tile_Object);
	Map_[10][11]= new Coordinate(ObjectName::Tile_Object);
	Map_[10][12]= new Coordinate(ObjectName::Baba_Object);
	Map_[10][13]= new Coordinate(ObjectName::Tile_Object);
	Map_[10][14]= new Coordinate(ObjectName::Tile_Object);
	Map_[10][15]= new Coordinate(ObjectName::Tile_Object);
	Map_[10][16]= new Coordinate(ObjectName::Rock_Object);
	Map_[10][17]= new Coordinate(ObjectName::Tile_Object);
	Map_[10][18]= new Coordinate(ObjectName::Tile_Object);
	Map_[10][19]= new Coordinate(ObjectName::Tile_Object);
	Map_[10][20]= new Coordinate(ObjectName::Flag_Object);
	Map_[10][21]= new Coordinate(ObjectName::Tile_Object);
	Map_[11][11]= new Coordinate(ObjectName::Tile_Object);
	Map_[11][12]= new Coordinate(ObjectName::Tile_Object);
	Map_[11][13]= new Coordinate(ObjectName::Tile_Object);
	Map_[11][14]= new Coordinate(ObjectName::Tile_Object);
	Map_[11][15]= new Coordinate(ObjectName::Tile_Object);
	Map_[11][16]= new Coordinate(ObjectName::Rock_Object);
	Map_[11][17]= new Coordinate(ObjectName::Tile_Object);
	Map_[11][18]= new Coordinate(ObjectName::Tile_Object);
	Map_[11][19]= new Coordinate(ObjectName::Tile_Object);
	Map_[11][20]= new Coordinate(ObjectName::Tile_Object);
	Map_[11][21]= new Coordinate(ObjectName::Tile_Object);
	Map_[12][11]= new Coordinate(ObjectName::Wall_Object);
	Map_[12][12]= new Coordinate(ObjectName::Wall_Object);
	Map_[12][13]= new Coordinate(ObjectName::Wall_Object);
	Map_[12][14]= new Coordinate(ObjectName::Wall_Object);
	Map_[12][15]= new Coordinate(ObjectName::Wall_Object);
	Map_[12][16]= new Coordinate(ObjectName::Wall_Object);
	Map_[12][17]= new Coordinate(ObjectName::Wall_Object);
	Map_[12][18]= new Coordinate(ObjectName::Wall_Object);
	Map_[12][19]= new Coordinate(ObjectName::Wall_Object);
	Map_[12][20]= new Coordinate(ObjectName::Wall_Object);
	Map_[12][21]= new Coordinate(ObjectName::Wall_Object);
	Map_[14][11]= new Coordinate(ObjectName::Wall_Text);
	Map_[14][12]= new Coordinate(ObjectName::Is_Text);
	Map_[14][13]= new Coordinate(ObjectName::Stop_Text);
	Map_[14][19]= new Coordinate(ObjectName::Rock_Text);
	Map_[14][20]= new Coordinate(ObjectName::Is_Text);
	Map_[14][21]= new Coordinate(ObjectName::Push_Text);

	for (int y = 0; y < MapScale_.iy(); ++y)
	{
		for (int x = 0; x < MapScale_.ix(); ++x)
		{
			if (Map_[y][x] == nullptr)
			{
				Map_[y][x] = new Coordinate(ObjectName::Empty_Object);
			}
			Map_[y][x]->SetStage(Stage_);
			Map_[y][x]->SetPos((float)x, (float)y);
		}
	}
	return true;
}