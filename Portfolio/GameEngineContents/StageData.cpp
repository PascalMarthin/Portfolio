#include "StageData.h"

StageData* StageData::Inst_ = new StageData();

StageData::StageData() 
{
	MainStage();
	Stage0();
}

StageData::~StageData() 
{
}

void StageData::MainStage()
{
	Scale_[0] = { 33, 18 };
	StageData_[0][15][9] = ObjectName::Default;
	StageData_[0][15][10] = ObjectName::Line;
	StageData_[0][14][10] = ObjectName::Line;
	StageData_[0][13][10] = ObjectName::Default;
	StageData_[0][12][10] = ObjectName::Default;
	StageData_[0][11][10] = ObjectName::Default;
	StageData_[0][11][11] = ObjectName::Default;
	StageData_[0][12][11] = ObjectName::Default;
	StageData_[0][13][11] = ObjectName::Default;
	StageData_[0][13][12] = ObjectName::Line;
	StageData_[0][12][12] = ObjectName::Default;
	StageData_[0][11][12] = ObjectName::Line;

}
void StageData::Stage0()
{
	Scale_[1] = { 33, 18 };
	StageData_[1][6][11] = ObjectName::Baba_Text;
	StageData_[1][6][12] = ObjectName::Is_Text;
	StageData_[1][6][13] = ObjectName::You_Text;
	StageData_[1][6][19] = ObjectName::Flag_Text;
	StageData_[1][6][20] = ObjectName::Is_Text;
	StageData_[1][6][21] = ObjectName::Win_Text;
	StageData_[1][8][11] = ObjectName::Wall_Unit;
	StageData_[1][8][12] = ObjectName::Wall_Unit;
	StageData_[1][8][13] = ObjectName::Wall_Unit;
	StageData_[1][8][14] = ObjectName::Wall_Unit;
	StageData_[1][8][15] = ObjectName::Wall_Unit;
	StageData_[1][8][16] = ObjectName::Wall_Unit;
	StageData_[1][8][17] = ObjectName::Wall_Unit;
	StageData_[1][8][18] = ObjectName::Wall_Unit;
	StageData_[1][8][19] = ObjectName::Wall_Unit;
	StageData_[1][8][20] = ObjectName::Wall_Unit;
	StageData_[1][8][21] = ObjectName::Wall_Unit;
	StageData_[1][9][11] = ObjectName::Tile_Unit;
	StageData_[1][9][12] = ObjectName::Tile_Unit;
	StageData_[1][9][13] = ObjectName::Tile_Unit;
	StageData_[1][9][14] = ObjectName::Tile_Unit;
	StageData_[1][9][15] = ObjectName::Tile_Unit;
	StageData_[1][9][16] = ObjectName::Rock_Unit;
	StageData_[1][9][17] = ObjectName::Tile_Unit;
	StageData_[1][9][18] = ObjectName::Tile_Unit;
	StageData_[1][9][19] = ObjectName::Tile_Unit;
	StageData_[1][9][20] = ObjectName::Tile_Unit;
	StageData_[1][9][21] = ObjectName::Tile_Unit;
	StageData_[1][10][11] = ObjectName::Tile_Unit;
	StageData_[1][10][12] = ObjectName::Baba_Unit;
	StageData_[1][10][13] = ObjectName::Tile_Unit;
	StageData_[1][10][14] = ObjectName::Tile_Unit;
	StageData_[1][10][15] = ObjectName::Tile_Unit;
	StageData_[1][10][16] = ObjectName::Rock_Unit;
	StageData_[1][10][17] = ObjectName::Tile_Unit;
	StageData_[1][10][18] = ObjectName::Tile_Unit;
	StageData_[1][10][19] = ObjectName::Tile_Unit;
	StageData_[1][10][20] = ObjectName::Flag_Unit;
	StageData_[1][10][21] = ObjectName::Tile_Unit;
	StageData_[1][11][11] = ObjectName::Tile_Unit;
	StageData_[1][11][12] = ObjectName::Tile_Unit;
	StageData_[1][11][13] = ObjectName::Tile_Unit;
	StageData_[1][11][14] = ObjectName::Tile_Unit;
	StageData_[1][11][15] = ObjectName::Tile_Unit;
	StageData_[1][11][16] = ObjectName::Rock_Unit;
	StageData_[1][11][17] = ObjectName::Tile_Unit;
	StageData_[1][11][18] = ObjectName::Tile_Unit;
	StageData_[1][11][19] = ObjectName::Tile_Unit;
	StageData_[1][11][20] = ObjectName::Tile_Unit;
	StageData_[1][11][21] = ObjectName::Tile_Unit;
	StageData_[1][12][11] = ObjectName::Wall_Unit;
	StageData_[1][12][12] = ObjectName::Wall_Unit;
	StageData_[1][12][13] = ObjectName::Wall_Unit;
	StageData_[1][12][14] = ObjectName::Wall_Unit;
	StageData_[1][12][15] = ObjectName::Wall_Unit;
	StageData_[1][12][16] = ObjectName::Wall_Unit;
	StageData_[1][12][17] = ObjectName::Wall_Unit;
	StageData_[1][12][18] = ObjectName::Wall_Unit;
	StageData_[1][12][19] = ObjectName::Wall_Unit;
	StageData_[1][12][20] = ObjectName::Wall_Unit;
	StageData_[1][12][21] = ObjectName::Wall_Unit;
	StageData_[1][14][11] = ObjectName::Wall_Text;
	StageData_[1][14][12] = ObjectName::Is_Text;
	StageData_[1][14][13] = ObjectName::Stop_Text;
	StageData_[1][14][19] = ObjectName::Rock_Text;
	StageData_[1][14][20] = ObjectName::Is_Text;
	StageData_[1][14][21] = ObjectName::Push_Text;
}