#include "StageData.h"

StageData* StageData::Inst_ = new StageData();

StageData::StageData() 
{
	Stage0();
	MainStage();
}

StageData::~StageData() 
{
}

void StageData::MainStage()
{

	std::map<int, std::map<int, std::vector<ObjectName>>> MainData_;
	MainData_[15][9].push_back(ObjectName::Default);
	MainData_[15][9].push_back(ObjectName::Stage00);
	MainData_[15][10].push_back(ObjectName::Stage00);

}
void StageData::Stage0()
{
	Scale_[0] = { 33, 18 };
	std::map<int, std::map<int, ObjectName>> Data;
	Data[6][11] = ObjectName::Baba_Text;
	Data[6][12] = ObjectName::Is_Text;
	Data[6][13] = ObjectName::You_Text;
	Data[6][19] = ObjectName::Flag_Text;
	Data[6][20] = ObjectName::Is_Text;
	Data[6][21] = ObjectName::Win_Text;
	Data[8][11] = ObjectName::Wall_Unit;
	Data[8][12] = ObjectName::Wall_Unit;
	Data[8][13] = ObjectName::Wall_Unit;
	Data[8][14] = ObjectName::Wall_Unit;
	Data[8][15] = ObjectName::Wall_Unit;
	Data[8][16] = ObjectName::Wall_Unit;
	Data[8][17] = ObjectName::Wall_Unit;
	Data[8][18] = ObjectName::Wall_Unit;
	Data[8][19] = ObjectName::Wall_Unit;
	Data[8][20] = ObjectName::Wall_Unit;
	Data[8][21] = ObjectName::Wall_Unit;
	Data[9][11] = ObjectName::Tile_Unit;
	Data[9][12] = ObjectName::Tile_Unit;
	Data[9][13] = ObjectName::Tile_Unit;
	Data[9][14] = ObjectName::Tile_Unit;
	Data[9][15] = ObjectName::Tile_Unit;
	Data[9][16] = ObjectName::Rock_Unit;
	Data[9][17] = ObjectName::Tile_Unit;
	Data[9][18] = ObjectName::Tile_Unit;
	Data[9][19] = ObjectName::Tile_Unit;
	Data[9][20] = ObjectName::Tile_Unit;
	Data[9][21] = ObjectName::Tile_Unit;
	Data[10][11] = ObjectName::Tile_Unit;
	Data[10][12] = ObjectName::Baba_Unit;
	Data[10][13] = ObjectName::Tile_Unit;
	Data[10][14] = ObjectName::Tile_Unit;
	Data[10][15] = ObjectName::Tile_Unit;
	Data[10][16] = ObjectName::Rock_Unit;
	Data[10][17] = ObjectName::Tile_Unit;
	Data[10][18] = ObjectName::Tile_Unit;
	Data[10][19] = ObjectName::Tile_Unit;
	Data[10][20] = ObjectName::Flag_Unit;
	Data[10][21] = ObjectName::Tile_Unit;
	Data[11][11] = ObjectName::Tile_Unit;
	Data[11][12] = ObjectName::Tile_Unit;
	Data[11][13] = ObjectName::Tile_Unit;
	Data[11][14] = ObjectName::Tile_Unit;
	Data[11][15] = ObjectName::Tile_Unit;
	Data[11][16] = ObjectName::Rock_Unit;
	Data[11][17] = ObjectName::Tile_Unit;
	Data[11][18] = ObjectName::Tile_Unit;
	Data[11][19] = ObjectName::Tile_Unit;
	Data[11][20] = ObjectName::Tile_Unit;
	Data[11][21] = ObjectName::Tile_Unit;
	Data[12][11] = ObjectName::Wall_Unit;
	Data[12][12] = ObjectName::Wall_Unit;
	Data[12][13] = ObjectName::Wall_Unit;
	Data[12][14] = ObjectName::Wall_Unit;
	Data[12][15] = ObjectName::Wall_Unit;
	Data[12][16] = ObjectName::Wall_Unit;
	Data[12][17] = ObjectName::Wall_Unit;
	Data[12][18] = ObjectName::Wall_Unit;
	Data[12][19] = ObjectName::Wall_Unit;
	Data[12][20] = ObjectName::Wall_Unit;
	Data[12][21] = ObjectName::Wall_Unit;
	Data[14][11] = ObjectName::Wall_Text;
	Data[14][12] = ObjectName::Is_Text;
	Data[14][13] = ObjectName::Stop_Text;
	Data[14][19] = ObjectName::Rock_Text;
	Data[14][20] = ObjectName::Is_Text;
	Data[14][21] = ObjectName::Push_Text;
	StageData_[0] = Data;
}