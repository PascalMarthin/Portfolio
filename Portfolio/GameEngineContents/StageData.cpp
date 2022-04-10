#include "StageData.h"

StageData* StageData::Inst_ = new StageData();

StageData::StageData() 
{
	MainStage();
	Stage0();
	Stage1();
	Stage2();
}

StageData::~StageData() 
{
}

void StageData::MainStage()
{
	Scale_[Stage::MainStage] = { 33, 18 };
	StageData_[Stage::MainStage][15][9] = ObjectName::Default;
	StageData_[Stage::MainStage][15][10] = ObjectName::Line;
	StageData_[Stage::MainStage][14][10] = ObjectName::Line;
	StageData_[Stage::MainStage][13][10] = ObjectName::Default;
	StageData_[Stage::MainStage][12][10] = ObjectName::Default;
	StageData_[Stage::MainStage][11][10] = ObjectName::Default;
	StageData_[Stage::MainStage][11][11] = ObjectName::Default;
	StageData_[Stage::MainStage][12][11] = ObjectName::Default;
	StageData_[Stage::MainStage][13][11] = ObjectName::Default;
	StageData_[Stage::MainStage][13][12] = ObjectName::Line;
	StageData_[Stage::MainStage][12][12] = ObjectName::Default;
	StageData_[Stage::MainStage][11][12] = ObjectName::Line;

}
void StageData::Stage0()
{
	Scale_[Stage::Stage0] = { 33, 18 };
	StageData_[Stage::Stage0][6][11] = ObjectName::Baba_Text;
	StageData_[Stage::Stage0][6][12] = ObjectName::Is_Text;
	StageData_[Stage::Stage0][6][13] = ObjectName::You_Text;
	StageData_[Stage::Stage0][6][19] = ObjectName::Flag_Text;
	StageData_[Stage::Stage0][6][20] = ObjectName::Is_Text;
	StageData_[Stage::Stage0][6][21] = ObjectName::Win_Text;
	StageData_[Stage::Stage0][8][11] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage0][8][12] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage0][8][13] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage0][8][14] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage0][8][15] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage0][8][16] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage0][8][17] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage0][8][18] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage0][8][19] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage0][8][20] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage0][8][21] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage0][9][11] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage0][9][12] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage0][9][13] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage0][9][14] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage0][9][15] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage0][9][16] = ObjectName::Rock_Unit;
	StageData_[Stage::Stage0][9][17] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage0][9][18] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage0][9][19] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage0][9][20] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage0][9][21] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage0][10][11] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage0][10][12] = ObjectName::Baba_Unit;
	StageData_[Stage::Stage0][10][13] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage0][10][14] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage0][10][15] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage0][10][16] = ObjectName::Rock_Unit;
	StageData_[Stage::Stage0][10][17] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage0][10][18] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage0][10][19] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage0][10][20] = ObjectName::Flag_Unit;
	StageData_[Stage::Stage0][10][21] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage0][11][11] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage0][11][12] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage0][11][13] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage0][11][14] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage0][11][15] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage0][11][16] = ObjectName::Rock_Unit;
	StageData_[Stage::Stage0][11][17] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage0][11][18] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage0][11][19] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage0][11][20] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage0][11][21] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage0][12][11] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage0][12][12] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage0][12][13] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage0][12][14] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage0][12][15] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage0][12][16] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage0][12][17] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage0][12][18] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage0][12][19] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage0][12][20] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage0][12][21] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage0][14][11] = ObjectName::Wall_Text;
	StageData_[Stage::Stage0][14][12] = ObjectName::Is_Text;
	StageData_[Stage::Stage0][14][13] = ObjectName::Stop_Text;
	StageData_[Stage::Stage0][14][19] = ObjectName::Rock_Text;
	StageData_[Stage::Stage0][14][20] = ObjectName::Is_Text;
	StageData_[Stage::Stage0][14][21] = ObjectName::Push_Text;
}

void StageData::Stage1()
{
	Scale_[Stage::Stage1] = { 24, 18 };
	StageData_[Stage::Stage1][1][7] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage1][2][9] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage1][2][10] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage1][2][11] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage1][2][12] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage1][2][13] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage1][2][14] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage1][2][15] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage1][2][16] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage1][2][22] = ObjectName::Grass_Unit;

	StageData_[Stage::Stage1][3][9] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage1][3][16] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage1][3][17] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage1][4][9] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage1][4][11] = ObjectName::Is_Text;
	StageData_[Stage::Stage1][4][16] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage1][4][18] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage1][5][9] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage1][5][16] = ObjectName::Wall_Unit;

	StageData_[Stage::Stage1][6][5] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage1][6][6] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage1][6][7] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage1][6][8] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage1][6][9] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage1][6][14] = ObjectName::Win_Text;
	StageData_[Stage::Stage1][6][16] = ObjectName::Wall_Unit;

	StageData_[Stage::Stage1][7][5] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage1][7][7] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage1][7][8] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage1][7][9] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage1][7][6] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage1][7][16] = ObjectName::Wall_Unit;

	StageData_[Stage::Stage1][8][1] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage1][8][5] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage1][8][6] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage1][8][7] = ObjectName::Flag_Text;
	StageData_[Stage::Stage1][8][8] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage1][8][9] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage1][8][11] = ObjectName::Flag_Unit;
	StageData_[Stage::Stage1][8][16] = ObjectName::Wall_Unit;

	StageData_[Stage::Stage1][9][2] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage1][9][5] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage1][9][7] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage1][9][8] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage1][9][9] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage1][9][6] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage1][9][16] = ObjectName::Wall_Unit;

	StageData_[Stage::Stage1][10][5] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage1][10][6] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage1][10][7] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage1][10][8] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage1][10][9] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage1][10][10] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage1][10][11] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage1][10][12] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage1][10][13] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage1][10][14] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage1][10][15] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage1][10][16] = ObjectName::Wall_Unit;

	StageData_[Stage::Stage1][11][9] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage1][11][16] = ObjectName::Wall_Unit;

	StageData_[Stage::Stage1][12][6] = ObjectName::Baba_Text;
	StageData_[Stage::Stage1][12][9] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage1][12][11] = ObjectName::Wall_Text;
	StageData_[Stage::Stage1][12][16] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage1][12][21] = ObjectName::Grass_Unit;

	StageData_[Stage::Stage1][13][6] = ObjectName::Is_Text;
	StageData_[Stage::Stage1][13][9] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage1][13][11] = ObjectName::Is_Text;
	StageData_[Stage::Stage1][13][14] = ObjectName::Baba_Unit;
	StageData_[Stage::Stage1][13][16] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage1][13][20] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage1][13][21] = ObjectName::Grass_Unit;

	StageData_[Stage::Stage1][14][6] = ObjectName::You_Text;
	StageData_[Stage::Stage1][14][9] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage1][14][11] = ObjectName::Stop_Text;
	StageData_[Stage::Stage1][14][16] = ObjectName::Wall_Unit;

	StageData_[Stage::Stage1][15][2] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage1][15][9] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage1][15][16] = ObjectName::Wall_Unit;

	StageData_[Stage::Stage1][16][9] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage1][16][10] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage1][16][11] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage1][16][12] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage1][16][13] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage1][16][14] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage1][16][15] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage1][16][16] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage1][16][19] = ObjectName::Grass_Unit;

}


void StageData::Stage2()
{
	Scale_[Stage::Stage2] = { 24, 18 };
	StageData_[Stage::Stage2][1][7] = ObjectName::Tile_Unit;

	StageData_[Stage::Stage2][2][2] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage2][2][9] = ObjectName::Flag_Unit;
	StageData_[Stage::Stage2][2][10] = ObjectName::Flag_Unit;
	StageData_[Stage::Stage2][2][11] = ObjectName::Flag_Unit;
	StageData_[Stage::Stage2][2][12] = ObjectName::Flag_Unit;
	StageData_[Stage::Stage2][2][13] = ObjectName::Flag_Unit;
	StageData_[Stage::Stage2][2][14] = ObjectName::Flag_Unit;
	StageData_[Stage::Stage2][2][15] = ObjectName::Flag_Unit;
	StageData_[Stage::Stage2][2][16] = ObjectName::Flag_Unit;
	StageData_[Stage::Stage2][2][22] = ObjectName::Tile_Unit;

	StageData_[Stage::Stage2][3][5] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage2][3][9] = ObjectName::Flag_Unit;
	StageData_[Stage::Stage2][3][16] = ObjectName::Flag_Unit;
	StageData_[Stage::Stage2][3][17] = ObjectName::Tile_Unit;

	StageData_[Stage::Stage2][4][5] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage2][4][9] = ObjectName::Flag_Unit;
	StageData_[Stage::Stage2][4][11] = ObjectName::Is_Text;
	StageData_[Stage::Stage2][4][16] = ObjectName::Flag_Unit;
	StageData_[Stage::Stage2][4][18] = ObjectName::Tile_Unit	;

	StageData_[Stage::Stage2][5][9] = ObjectName::Flag_Unit;
	StageData_[Stage::Stage2][5][16] = ObjectName::Flag_Unit;

	StageData_[Stage::Stage2][6][5] = ObjectName::Flag_Unit;
	StageData_[Stage::Stage2][6][6] = ObjectName::Flag_Unit;
	StageData_[Stage::Stage2][6][7] = ObjectName::Flag_Unit;
	StageData_[Stage::Stage2][6][8] = ObjectName::Flag_Unit;
	StageData_[Stage::Stage2][6][9] = ObjectName::Flag_Unit;
	StageData_[Stage::Stage2][6][14] = ObjectName::Win_Text;
	StageData_[Stage::Stage2][6][16] = ObjectName::Flag_Unit;

	StageData_[Stage::Stage2][7][5] = ObjectName::Flag_Unit;
	StageData_[Stage::Stage2][7][7] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage2][7][8] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage2][7][9] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage2][7][6] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage2][7][16] = ObjectName::Flag_Unit;

	StageData_[Stage::Stage2][8][2] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage2][8][5] = ObjectName::Flag_Unit;
	StageData_[Stage::Stage2][8][6] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage2][8][7] = ObjectName::Baba_Text;
	StageData_[Stage::Stage2][8][8] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage2][8][9] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage2][8][16] = ObjectName::Flag_Unit;

	StageData_[Stage::Stage2][9][1] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage2][9][5] = ObjectName::Flag_Unit;
	StageData_[Stage::Stage2][9][7] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage2][9][8] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage2][9][9] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage2][9][6] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage2][9][16] = ObjectName::Flag_Unit;
	StageData_[Stage::Stage2][9][20] = ObjectName::Tile_Unit;

	StageData_[Stage::Stage2][10][5] = ObjectName::Flag_Unit;
	StageData_[Stage::Stage2][10][6] = ObjectName::Flag_Unit;
	StageData_[Stage::Stage2][10][7] = ObjectName::Flag_Unit;
	StageData_[Stage::Stage2][10][8] = ObjectName::Flag_Unit;
	StageData_[Stage::Stage2][10][9] = ObjectName::Flag_Unit;
	StageData_[Stage::Stage2][10][10] = ObjectName::Flag_Unit;
	StageData_[Stage::Stage2][10][11] = ObjectName::Flag_Unit;
	StageData_[Stage::Stage2][10][12] = ObjectName::Flag_Unit;
	StageData_[Stage::Stage2][10][13] = ObjectName::Flag_Unit;
	StageData_[Stage::Stage2][10][14] = ObjectName::Flag_Unit;
	StageData_[Stage::Stage2][10][15] = ObjectName::Flag_Unit;
	StageData_[Stage::Stage2][10][16] = ObjectName::Flag_Unit;

	StageData_[Stage::Stage2][11][9] = ObjectName::Flag_Unit;
	StageData_[Stage::Stage2][11][16] = ObjectName::Flag_Unit;

	StageData_[Stage::Stage2][12][6] = ObjectName::Wall_Text;
	StageData_[Stage::Stage2][12][9] = ObjectName::Flag_Unit;
	StageData_[Stage::Stage2][12][11] = ObjectName::Flag_Text;
	StageData_[Stage::Stage2][12][16] = ObjectName::Flag_Unit;


	StageData_[Stage::Stage2][13][6] = ObjectName::Is_Text;
	StageData_[Stage::Stage2][13][9] = ObjectName::Flag_Unit;
	StageData_[Stage::Stage2][13][11] = ObjectName::Is_Text;
	StageData_[Stage::Stage2][13][14] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage2][13][16] = ObjectName::Flag_Unit;


	StageData_[Stage::Stage2][14][4] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage2][14][6] = ObjectName::You_Text;
	StageData_[Stage::Stage2][14][9] = ObjectName::Flag_Unit;
	StageData_[Stage::Stage2][14][11] = ObjectName::Stop_Text;
	StageData_[Stage::Stage2][14][16] = ObjectName::Flag_Unit;
	StageData_[Stage::Stage2][14][18] = ObjectName::Tile_Unit;

	StageData_[Stage::Stage2][15][2] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage2][15][9] = ObjectName::Flag_Unit;
	StageData_[Stage::Stage2][15][13] = ObjectName::Flag_Unit;
	StageData_[Stage::Stage2][15][14] = ObjectName::Flag_Unit;
	StageData_[Stage::Stage2][15][15] = ObjectName::Flag_Unit;
	StageData_[Stage::Stage2][15][16] = ObjectName::Flag_Unit;
	StageData_[Stage::Stage2][15][17] = ObjectName::Tile_Unit;

	StageData_[Stage::Stage2][16][4] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage2][16][9] = ObjectName::Flag_Unit;
	StageData_[Stage::Stage2][16][10] = ObjectName::Flag_Unit;
	StageData_[Stage::Stage2][16][11] = ObjectName::Flag_Unit;
	StageData_[Stage::Stage2][16][12] = ObjectName::Flag_Unit;
	StageData_[Stage::Stage2][16][13] = ObjectName::Flag_Unit;
	StageData_[Stage::Stage2][16][17] = ObjectName::Tile_Unit;


}
void StageData::Stage3()
{
	Scale_[Stage::Stage3] = { 24, 18 };
}
void StageData::Stage4()
{
	Scale_[Stage::Stage4] = { 24, 18 };
}
void StageData::Stage5()
{
	Scale_[Stage::Stage5] = { 24, 18 };
}
void StageData::Stage6()
{
	Scale_[Stage::Stage6] = { 24, 18 };
}
void StageData::Stage7()
{
	Scale_[Stage::Stage7] = { 24, 18 };
}