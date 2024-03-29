#include "StageData.h"

StageData* StageData::Inst_ = new StageData();

StageData::StageData() 
{
	MainStage();
	Stage0();
	Stage1();
	Stage2();
	Stage3();
	Stage4();
	Stage5();
	Stage6();
	Stage7();
	DebugStage();
}

StageData::~StageData() 
{
}

void StageData::DebugStage()
{
	Scale_[Stage::DebugStage] = { 33, 18 };
	StageData_[Stage::DebugStage][0][3] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][0][4] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][0][5] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][0][6] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][0][7] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][0][8] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][0][9] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][0][10] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][0][27] = ObjectName::Grass_Unit;
	StageData_[Stage::DebugStage][0][28] = ObjectName::Grass_Unit;
	StageData_[Stage::DebugStage][0][29] = ObjectName::Grass_Unit;
	StageData_[Stage::DebugStage][0][30] = ObjectName::Grass_Unit;

	StageData_[Stage::DebugStage][1][3] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][1][10] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][1][11] = ObjectName::Grass_Unit;
	StageData_[Stage::DebugStage][1][19] = ObjectName::Grass_Unit;
	StageData_[Stage::DebugStage][1][20] = ObjectName::Grass_Unit;
	StageData_[Stage::DebugStage][1][21] = ObjectName::Grass_Unit;
	StageData_[Stage::DebugStage][1][28] = ObjectName::Grass_Unit;
	StageData_[Stage::DebugStage][1][29] = ObjectName::Grass_Unit;

	StageData_[Stage::DebugStage][2][2] = ObjectName::Grass_Unit;
	StageData_[Stage::DebugStage][2][3] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][2][9] = ObjectName::Brick_Unit;
	StageData_[Stage::DebugStage][2][10] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][2][11] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][2][12] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][2][18] = ObjectName::Grass_Unit;
	StageData_[Stage::DebugStage][2][19] = ObjectName::Grass_Unit;
	StageData_[Stage::DebugStage][2][20] = ObjectName::Grass_Unit;
	StageData_[Stage::DebugStage][2][21] = ObjectName::Grass_Unit;
	StageData_[Stage::DebugStage][2][22] = ObjectName::Grass_Unit;

	StageData_[Stage::DebugStage][3][2] = ObjectName::Grass_Unit;
	StageData_[Stage::DebugStage][3][3] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][3][4] = ObjectName::Brick_Unit;
	StageData_[Stage::DebugStage][3][8] = ObjectName::Brick_Unit;
	StageData_[Stage::DebugStage][3][9] = ObjectName::Brick_Unit;
	StageData_[Stage::DebugStage][3][10] = ObjectName::Brick_Unit;
	StageData_[Stage::DebugStage][3][11] = ObjectName::Brick_Unit;
	StageData_[Stage::DebugStage][3][12] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][3][19] = ObjectName::Grass_Unit;
	StageData_[Stage::DebugStage][3][20] = ObjectName::Grass_Unit;
	StageData_[Stage::DebugStage][3][21] = ObjectName::Grass_Unit;
	StageData_[Stage::DebugStage][3][27] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][3][28] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][3][29] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][3][30] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][3][31] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][3][32] = ObjectName::Wall_Unit;

	StageData_[Stage::DebugStage][4][0] = ObjectName::Grass_Unit;
	StageData_[Stage::DebugStage][4][1] = ObjectName::Grass_Unit;
	StageData_[Stage::DebugStage][4][2] = ObjectName::Grass_Unit;
	StageData_[Stage::DebugStage][4][3] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][4][4] = ObjectName::Brick_Unit;
	StageData_[Stage::DebugStage][4][5] = ObjectName::Brick_Unit;
	StageData_[Stage::DebugStage][4][7] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][4][8] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][4][9] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][4][10] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][4][11] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][4][12] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][4][19] = ObjectName::Grass_Unit;
	StageData_[Stage::DebugStage][4][20] = ObjectName::Grass_Unit;
	StageData_[Stage::DebugStage][4][27] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][4][28] = ObjectName::Brick_Unit;
	StageData_[Stage::DebugStage][4][29] = ObjectName::Brick_Unit;
	StageData_[Stage::DebugStage][4][30] = ObjectName::Brick_Unit;
	StageData_[Stage::DebugStage][4][31] = ObjectName::Brick_Unit;
	StageData_[Stage::DebugStage][4][32] = ObjectName::Wall_Unit;

	StageData_[Stage::DebugStage][5][0] = ObjectName::Grass_Unit;
	StageData_[Stage::DebugStage][5][1] = ObjectName::Grass_Unit;
	StageData_[Stage::DebugStage][5][2] = ObjectName::Grass_Unit;
	StageData_[Stage::DebugStage][5][3] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][5][4] = ObjectName::Brick_Unit;
	StageData_[Stage::DebugStage][5][5] = ObjectName::Brick_Unit;
	StageData_[Stage::DebugStage][5][5] = ObjectName::Brick_Unit;
	StageData_[Stage::DebugStage][5][7] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][5][27] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][5][28] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][5][29] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][5][30] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][5][31] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][5][32] = ObjectName::Wall_Unit;

	StageData_[Stage::DebugStage][6][0] = ObjectName::Grass_Unit;
	StageData_[Stage::DebugStage][6][1] = ObjectName::Grass_Unit;
	StageData_[Stage::DebugStage][6][2] = ObjectName::Grass_Unit;
	StageData_[Stage::DebugStage][6][3] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][6][4] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][6][5] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][6][6] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][6][7] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][6][13] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][6][14] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][6][15] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][6][16] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][6][17] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][6][18] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][6][19] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][6][20] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][6][21] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][6][22] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][6][23] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][6][24] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][6][31] = ObjectName::Grass_Unit;
	StageData_[Stage::DebugStage][6][32] = ObjectName::Grass_Unit;

	StageData_[Stage::DebugStage][7][0] = ObjectName::Grass_Unit;
	StageData_[Stage::DebugStage][7][1] = ObjectName::Grass_Unit;
	StageData_[Stage::DebugStage][7][2] = ObjectName::Grass_Unit;
	StageData_[Stage::DebugStage][7][3] = ObjectName::Grass_Unit;
	StageData_[Stage::DebugStage][7][4] = ObjectName::Grass_Unit;
	StageData_[Stage::DebugStage][7][12] = ObjectName::Grass_Unit;
	StageData_[Stage::DebugStage][7][13] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][7][14] = ObjectName::Brick_Unit;
	StageData_[Stage::DebugStage][7][15] = ObjectName::Brick_Unit;
	StageData_[Stage::DebugStage][7][21] = ObjectName::Brick_Unit;
	StageData_[Stage::DebugStage][7][22] = ObjectName::Brick_Unit;
	StageData_[Stage::DebugStage][7][23] = ObjectName::Brick_Unit;
	StageData_[Stage::DebugStage][7][24] = ObjectName::Wall_Unit;

	StageData_[Stage::DebugStage][8][13] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][8][14] = ObjectName::Brick_Unit;
	StageData_[Stage::DebugStage][8][24] = ObjectName::Wall_Unit;

	StageData_[Stage::DebugStage][9][13] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][9][24] = ObjectName::Wall_Unit;

	StageData_[Stage::DebugStage][10][13] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][10][24] = ObjectName::Wall_Unit;

	StageData_[Stage::DebugStage][11][0] = ObjectName::Grass_Unit;
	StageData_[Stage::DebugStage][11][1] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][11][2] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][11][3] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][11][10] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][11][11] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][11][12] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][11][13] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][11][24] = ObjectName::Wall_Unit;

	StageData_[Stage::DebugStage][12][1] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][12][2] = ObjectName::Grass_Unit;
	StageData_[Stage::DebugStage][12][3] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][12][4] = ObjectName::Grass_Unit;
	StageData_[Stage::DebugStage][12][10] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][12][22] = ObjectName::Grass_Unit;
	StageData_[Stage::DebugStage][12][23] = ObjectName::Grass_Unit;
	StageData_[Stage::DebugStage][12][24] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][12][25] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][12][26] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][12][27] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][12][28] = ObjectName::Wall_Unit;

	StageData_[Stage::DebugStage][13][1] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][13][2] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][13][3] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][13][4] = ObjectName::Grass_Unit;
	StageData_[Stage::DebugStage][13][5] = ObjectName::Grass_Unit;
	StageData_[Stage::DebugStage][13][10] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][13][11] = ObjectName::Brick_Unit;
	StageData_[Stage::DebugStage][13][12] = ObjectName::Brick_Unit;
	StageData_[Stage::DebugStage][13][15] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][13][16] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][13][17] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][13][18] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][13][19] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][13][20] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][13][21] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][13][22] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][13][23] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][13][24] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][13][28] = ObjectName::Wall_Unit;

	StageData_[Stage::DebugStage][14][3] = ObjectName::Grass_Unit;
	StageData_[Stage::DebugStage][14][4] = ObjectName::Grass_Unit;
	StageData_[Stage::DebugStage][14][10] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][14][11] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][14][12] = ObjectName::Brick_Unit;
	StageData_[Stage::DebugStage][14][13] = ObjectName::Brick_Unit;
	StageData_[Stage::DebugStage][14][15] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][14][18] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][14][19] = ObjectName::Brick_Unit;
	StageData_[Stage::DebugStage][14][20] = ObjectName::Brick_Unit;
	StageData_[Stage::DebugStage][14][27] = ObjectName::Brick_Unit;
	StageData_[Stage::DebugStage][14][28] = ObjectName::Wall_Unit;

	StageData_[Stage::DebugStage][15][11] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][15][12] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][15][13] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][15][14] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][15][15] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][15][18] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][15][19] = ObjectName::Brick_Unit;
	StageData_[Stage::DebugStage][15][26] = ObjectName::Brick_Unit;
	StageData_[Stage::DebugStage][15][27] = ObjectName::Brick_Unit;
	StageData_[Stage::DebugStage][15][28] = ObjectName::Wall_Unit;

	StageData_[Stage::DebugStage][16][18] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][16][19] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][16][20] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][16][21] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][16][24] = ObjectName::Brick_Unit;
	StageData_[Stage::DebugStage][16][25] = ObjectName::Brick_Unit;
	StageData_[Stage::DebugStage][16][26] = ObjectName::Brick_Unit;
	StageData_[Stage::DebugStage][16][27] = ObjectName::Brick_Unit;
	StageData_[Stage::DebugStage][16][28] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][16][29] = ObjectName::Grass_Unit;
	StageData_[Stage::DebugStage][16][30] = ObjectName::Grass_Unit;

	StageData_[Stage::DebugStage][17][21] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][17][22] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][17][23] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][17][24] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][17][25] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][17][26] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][17][27] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][17][28] = ObjectName::Wall_Unit;
	StageData_[Stage::DebugStage][17][29] = ObjectName::Grass_Unit;
	StageData_[Stage::DebugStage][17][30] = ObjectName::Grass_Unit;


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
	StageLevelString_[Stage::Stage0] = "Stage 0";
	StageNameString_[Stage::Stage0] = "Baba Is You";
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
	StageLevelString_[Stage::Stage1] = "Stage 1";
	StageNameString_[Stage::Stage1] = "Where Do I Go?";
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
	StageLevelString_[Stage::Stage2] = "Stage 2";
	StageNameString_[Stage::Stage2] = "Now What Is This?";
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
	StageLevelString_[Stage::Stage3] = "Stage 3";
	StageNameString_[Stage::Stage3] = "Out Of Reach";
	Scale_[Stage::Stage3] = { 22, 16 };

	StageData_[Stage::Stage3][0][0] = ObjectName::Baba_Text;
	StageData_[Stage::Stage3][0][1] = ObjectName::Wall_Text;
	StageData_[Stage::Stage3][0][2] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage3][0][16] = ObjectName::Grass_Unit;

	StageData_[Stage::Stage3][1][0] = ObjectName::Is_Text;
	StageData_[Stage::Stage3][1][1] = ObjectName::Is_Text;
	StageData_[Stage::Stage3][1][2] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage3][1][4] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage3][1][7] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage3][1][8] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage3][1][9] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage3][1][10] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage3][1][11] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage3][1][12] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage3][1][13] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage3][1][14] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage3][1][16] = ObjectName::Grass_Unit;

	StageData_[Stage::Stage3][2][0] = ObjectName::You_Text;
	StageData_[Stage::Stage3][2][1] = ObjectName::Stop_Text;
	StageData_[Stage::Stage3][2][2] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage3][2][7] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage3][2][8] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage3][2][9] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage3][2][10] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage3][2][11] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage3][2][12] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage3][2][13] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage3][2][14] = ObjectName::Wall_Unit;

	StageData_[Stage::Stage3][3][0] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage3][3][1] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage3][3][2] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage3][3][5] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage3][3][7] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage3][3][8] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage3][3][9] = ObjectName::Baba_Unit;
	StageData_[Stage::Stage3][3][10] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage3][3][11] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage3][3][12] = ObjectName::Rock_Unit;
	StageData_[Stage::Stage3][3][13] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage3][3][14] = ObjectName::Wall_Unit;


	StageData_[Stage::Stage3][4][6] = ObjectName::Water_Text;
	StageData_[Stage::Stage3][4][7] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage3][4][8] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage3][4][9] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage3][4][10] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage3][4][11] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage3][4][12] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage3][4][13] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage3][4][14] = ObjectName::Wall_Unit;

	StageData_[Stage::Stage3][5][3] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage3][5][4] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage3][5][6] = ObjectName::Is_Text;
	StageData_[Stage::Stage3][5][7] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage3][5][8] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage3][5][9] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage3][5][10] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage3][5][11] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage3][5][12] = ObjectName::Rock_Unit;
	StageData_[Stage::Stage3][5][13] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage3][5][14] = ObjectName::Wall_Unit;

	StageData_[Stage::Stage3][6][6] = ObjectName::Sink_Text;
	StageData_[Stage::Stage3][6][7] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage3][6][8] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage3][6][9] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage3][6][10] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage3][6][11] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage3][6][12] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage3][6][13] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage3][6][14] = ObjectName::Wall_Unit;

	StageData_[Stage::Stage3][7][0] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage3][7][4] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage3][7][5] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage3][7][6] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage3][7][7] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage3][7][8] = ObjectName::Water_Unit;
	StageData_[Stage::Stage3][7][9] = ObjectName::Water_Unit;
	StageData_[Stage::Stage3][7][10] = ObjectName::Water_Unit;
	StageData_[Stage::Stage3][7][11] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage3][7][12] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage3][7][13] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage3][7][14] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage3][7][15] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage3][7][16] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage3][7][17] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage3][7][19] = ObjectName::Grass_Unit;

	StageData_[Stage::Stage3][8][1] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage3][8][4] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage3][8][11] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage3][8][17] = ObjectName::Wall_Unit;

	StageData_[Stage::Stage3][9][4] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage3][9][11] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage3][9][13] = ObjectName::Rock_Text;
	StageData_[Stage::Stage3][9][14] = ObjectName::Is_Text;
	StageData_[Stage::Stage3][9][15] = ObjectName::Push_Text;
	StageData_[Stage::Stage3][9][17] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage3][9][20] = ObjectName::Grass_Unit;

	StageData_[Stage::Stage3][10][4] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage3][10][11] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage3][10][17] = ObjectName::Wall_Unit;

	StageData_[Stage::Stage3][11][4] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage3][11][5] = ObjectName::Water_Unit;
	StageData_[Stage::Stage3][11][6] = ObjectName::Water_Unit;
	StageData_[Stage::Stage3][11][7] = ObjectName::Water_Unit;
	//StageData_[Stage::Stage3][11][9] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage3][11][17] = ObjectName::Wall_Unit;

	StageData_[Stage::Stage3][12][1] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage3][12][2] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage3][12][4] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage3][12][5] = ObjectName::Water_Unit;
	StageData_[Stage::Stage3][12][6] = ObjectName::Water_Unit;
	StageData_[Stage::Stage3][12][7] = ObjectName::Water_Unit;
	StageData_[Stage::Stage3][12][11] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage3][12][13] = ObjectName::Flag_Text;
	StageData_[Stage::Stage3][12][14] = ObjectName::Is_Text;
	StageData_[Stage::Stage3][12][15] = ObjectName::Win_Text;
	StageData_[Stage::Stage3][12][17] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage3][13][18] = ObjectName::Grass_Unit;

	StageData_[Stage::Stage3][13][1] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage3][13][2] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage3][13][4] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage3][13][5] = ObjectName::Flag_Unit;
	StageData_[Stage::Stage3][13][6] = ObjectName::Water_Unit;
	StageData_[Stage::Stage3][13][7] = ObjectName::Water_Unit;
	StageData_[Stage::Stage3][13][11] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage3][13][17] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage3][13][20] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage3][13][21] = ObjectName::Grass_Unit;


	StageData_[Stage::Stage3][14][4] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage3][14][5] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage3][14][6] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage3][14][7] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage3][14][8] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage3][14][9] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage3][14][10] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage3][14][11] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage3][14][12] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage3][14][13] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage3][14][14] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage3][14][15] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage3][14][16] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage3][14][17] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage3][14][20] = ObjectName::Grass_Unit;
}
void StageData::Stage4()
{
	StageLevelString_[Stage::Stage4] = "Stage 4";
	StageNameString_[Stage::Stage4] = "Still Out Of Reach";
	Scale_[Stage::Stage4] = { 24, 14 };

	StageData_[Stage::Stage4][0][0] = ObjectName::Flag_Text;
	StageData_[Stage::Stage4][0][1] = ObjectName::Is_Text;
	StageData_[Stage::Stage4][0][2] = ObjectName::Win_Text;

	StageData_[Stage::Stage4][1][0] = ObjectName::Baba_Text;
	StageData_[Stage::Stage4][1][1] = ObjectName::Is_Text;
	StageData_[Stage::Stage4][1][2] = ObjectName::You_Text;

	StageData_[Stage::Stage4][3][13] = ObjectName::Skull_Unit;
	StageData_[Stage::Stage4][3][14] = ObjectName::Skull_Unit;
	StageData_[Stage::Stage4][3][15] = ObjectName::Skull_Unit;
	StageData_[Stage::Stage4][3][16] = ObjectName::Skull_Unit;
	StageData_[Stage::Stage4][3][17] = ObjectName::Skull_Unit;
	StageData_[Stage::Stage4][3][18] = ObjectName::Skull_Unit;
	StageData_[Stage::Stage4][3][19] = ObjectName::Skull_Unit;
	StageData_[Stage::Stage4][3][20] = ObjectName::Skull_Unit;
	StageData_[Stage::Stage4][3][21] = ObjectName::Skull_Unit;

	StageData_[Stage::Stage4][4][13] = ObjectName::Skull_Unit;
	StageData_[Stage::Stage4][4][21] = ObjectName::Skull_Unit;

	StageData_[Stage::Stage4][5][2] = ObjectName::Rock_Text;
	StageData_[Stage::Stage4][5][3] = ObjectName::Is_Text;
	StageData_[Stage::Stage4][5][4] = ObjectName::Push_Text;
	StageData_[Stage::Stage4][5][13] = ObjectName::Skull_Unit;
	StageData_[Stage::Stage4][5][15] = ObjectName::Skull_Text;
	StageData_[Stage::Stage4][5][21] = ObjectName::Skull_Unit;

	StageData_[Stage::Stage4][6][13] = ObjectName::Skull_Unit;
	StageData_[Stage::Stage4][6][15] = ObjectName::Is_Text;
	StageData_[Stage::Stage4][6][21] = ObjectName::Skull_Unit;

	StageData_[Stage::Stage4][7][5] = ObjectName::Skull_Unit;
	StageData_[Stage::Stage4][7][7] = ObjectName::Skull_Unit;
	StageData_[Stage::Stage4][7][13] = ObjectName::Skull_Unit;
	StageData_[Stage::Stage4][7][15] = ObjectName::Defeat_Text;
	StageData_[Stage::Stage4][7][21] = ObjectName::Skull_Unit;

	StageData_[Stage::Stage4][8][5] = ObjectName::Skull_Unit;
	StageData_[Stage::Stage4][8][6] = ObjectName::Rock_Unit;
	StageData_[Stage::Stage4][8][7] = ObjectName::Skull_Unit;
	StageData_[Stage::Stage4][8][13] = ObjectName::Skull_Unit;
	StageData_[Stage::Stage4][8][21] = ObjectName::Skull_Unit;

	StageData_[Stage::Stage4][9][3] = ObjectName::Skull_Unit;
	StageData_[Stage::Stage4][9][4] = ObjectName::Skull_Unit;
	StageData_[Stage::Stage4][9][5] = ObjectName::Skull_Unit;
	StageData_[Stage::Stage4][9][6] = ObjectName::Rock_Unit;
	StageData_[Stage::Stage4][9][7] = ObjectName::Skull_Unit;
	StageData_[Stage::Stage4][9][8] = ObjectName::Skull_Unit;
	StageData_[Stage::Stage4][9][9] = ObjectName::Skull_Unit;
	StageData_[Stage::Stage4][9][13] = ObjectName::Skull_Unit;
	StageData_[Stage::Stage4][9][18] = ObjectName::Flag_Unit;
	StageData_[Stage::Stage4][9][21] = ObjectName::Skull_Unit;

	StageData_[Stage::Stage4][10][3] = ObjectName::Skull_Unit;
	StageData_[Stage::Stage4][10][6] = ObjectName::Rock_Unit;
	StageData_[Stage::Stage4][10][9] = ObjectName::Skull_Unit;
	StageData_[Stage::Stage4][10][13] = ObjectName::Skull_Unit;
	StageData_[Stage::Stage4][10][21] = ObjectName::Skull_Unit;


	StageData_[Stage::Stage4][11][3] = ObjectName::Skull_Unit;
	StageData_[Stage::Stage4][11][9] = ObjectName::Skull_Unit;
	StageData_[Stage::Stage4][11][13] = ObjectName::Skull_Unit;
	StageData_[Stage::Stage4][11][14] = ObjectName::Skull_Unit;
	StageData_[Stage::Stage4][11][15] = ObjectName::Skull_Unit;
	StageData_[Stage::Stage4][11][16] = ObjectName::Skull_Unit;
	StageData_[Stage::Stage4][11][17] = ObjectName::Skull_Unit;
	StageData_[Stage::Stage4][11][18] = ObjectName::Skull_Unit;
	StageData_[Stage::Stage4][11][19] = ObjectName::Skull_Unit;
	StageData_[Stage::Stage4][11][20] = ObjectName::Skull_Unit;
	StageData_[Stage::Stage4][11][21] = ObjectName::Skull_Unit;

	StageData_[Stage::Stage4][12][3] = ObjectName::Skull_Unit;
	StageData_[Stage::Stage4][12][6] = ObjectName::Baba_Unit;
	StageData_[Stage::Stage4][12][9] = ObjectName::Skull_Unit;

	StageData_[Stage::Stage4][13][3] = ObjectName::Skull_Unit;
	StageData_[Stage::Stage4][13][9] = ObjectName::Skull_Unit;
}
void StageData::Stage5()
{
	StageLevelString_[Stage::Stage5] = "Stage 5";
	StageNameString_[Stage::Stage5] = "VOLCANO";
	Scale_[Stage::Stage5] = { 33, 18 };

	StageData_[Stage::Stage5][0][0] = ObjectName::Wall_Text;
	StageData_[Stage::Stage5][0][1] = ObjectName::Is_Text;
	StageData_[Stage::Stage5][0][2] = ObjectName::Stop_Text;
	StageData_[Stage::Stage5][0][3] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][0][4] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][0][6] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage5][0][12] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage5][0][16] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage5][0][20] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][0][21] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][0][22] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][0][23] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][0][24] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][0][25] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][0][26] = ObjectName::Lava_Unit;

	StageData_[Stage::Stage5][1][0] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][1][1] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][1][2] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][1][3] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][1][6] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage5][1][14] = ObjectName::Baba_Unit;
	StageData_[Stage::Stage5][1][16] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage5][1][19] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][1][20] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][1][21] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][1][22] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][1][23] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][1][24] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][1][25] = ObjectName::Lava_Unit;

	StageData_[Stage::Stage5][2][0] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][2][1] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][2][6] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage5][2][12] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage5][2][16] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage5][2][19] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][2][20] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][2][21] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][2][22] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][2][23] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][2][24] = ObjectName::Lava_Unit;

	StageData_[Stage::Stage5][3][0] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][3][6] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage5][3][8] = ObjectName::Baba_Text;
	StageData_[Stage::Stage5][3][9] = ObjectName::Is_Text;
	StageData_[Stage::Stage5][3][10] = ObjectName::You_Text;
	StageData_[Stage::Stage5][3][12] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage5][3][13] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage5][3][14] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage5][3][15] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage5][3][16] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage5][3][18] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][3][19] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][3][20] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][3][21] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][3][22] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][3][23] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][3][24] = ObjectName::Lava_Unit;

	StageData_[Stage::Stage5][4][6] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage5][4][7] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage5][4][11] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage5][4][12] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage5][4][18] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][4][19] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][4][20] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][4][21] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][4][22] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][4][23] = ObjectName::Lava_Unit;

	StageData_[Stage::Stage5][5][6] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage5][5][12] = ObjectName::Rock_Unit;
	StageData_[Stage::Stage5][5][18] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][5][19] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][5][20] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][5][21] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][5][22] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][5][23] = ObjectName::Lava_Unit;

	StageData_[Stage::Stage5][6][6] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage5][6][7] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage5][6][8] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage5][6][9] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage5][6][10] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage5][6][11] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage5][6][12] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage5][6][17] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][6][18] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][6][19] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][6][20] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][6][21] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][6][22] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][6][23] = ObjectName::Lava_Unit;

	StageData_[Stage::Stage5][7][6] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage5][7][7] = ObjectName::Rock_Text;
	StageData_[Stage::Stage5][7][8] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage5][7][17] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][7][18] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][7][19] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][7][20] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][7][21] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][7][22] = ObjectName::Lava_Unit;

	StageData_[Stage::Stage5][8][7] = ObjectName::Is_Text;
	StageData_[Stage::Stage5][8][17] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][8][18] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][8][19] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][8][20] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][8][21] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][8][22] = ObjectName::Lava_Unit;

	StageData_[Stage::Stage5][9][7] = ObjectName::Push_Text;
	StageData_[Stage::Stage5][9][16] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][9][17] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][9][18] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][9][19] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][9][20] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][9][21] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][9][22] = ObjectName::Lava_Unit;

	StageData_[Stage::Stage5][10][12] = ObjectName::Lava_Text;
	StageData_[Stage::Stage5][10][16] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][10][17] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][10][18] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][10][19] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][10][20] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][10][21] = ObjectName::Lava_Unit;

	StageData_[Stage::Stage5][11][15] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][11][16] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][11][17] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][11][18] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][11][19] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][11][20] = ObjectName::Lava_Unit;

	StageData_[Stage::Stage5][12][7] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage5][12][8] = ObjectName::Baba_Text;
	StageData_[Stage::Stage5][12][9] = ObjectName::Is_Text;
	StageData_[Stage::Stage5][12][10] = ObjectName::Melt_Text;
	StageData_[Stage::Stage5][12][11] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage5][12][15] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][12][16] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][12][17] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][12][18] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][12][19] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][12][20] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][12][26] = ObjectName::Flag_Unit;

	StageData_[Stage::Stage5][13][7] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage5][13][8] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage5][13][9] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage5][13][10] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage5][13][11] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage5][13][14] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][13][15] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][13][16] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][13][17] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][13][18] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][13][19] = ObjectName::Lava_Unit;

	StageData_[Stage::Stage5][14][7] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage5][14][8] = ObjectName::Lava_Text;
	StageData_[Stage::Stage5][14][9] = ObjectName::Is_Text;
	StageData_[Stage::Stage5][14][10] = ObjectName::Hot_Text;
	StageData_[Stage::Stage5][14][11] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage5][14][14] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][14][15] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][14][16] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][14][17] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][14][18] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][14][25] = ObjectName::Flag_Text;
	StageData_[Stage::Stage5][14][26] = ObjectName::Is_Text;
	StageData_[Stage::Stage5][14][27] = ObjectName::Win_Text;

	StageData_[Stage::Stage5][15][7] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage5][15][8] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage5][15][9] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage5][15][10] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage5][15][11] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage5][15][13] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][15][14] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][15][15] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][15][16] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][15][17] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][15][18] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][15][32] = ObjectName::Lava_Unit;

	StageData_[Stage::Stage5][16][12] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][16][13] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][16][14] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][16][15] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][16][16] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][16][17] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][16][31] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][16][32] = ObjectName::Lava_Unit;

	StageData_[Stage::Stage5][17][12] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][17][13] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][17][14] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][17][15] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][17][16] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][17][17] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][17][30] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][17][31] = ObjectName::Lava_Unit;
	StageData_[Stage::Stage5][17][32] = ObjectName::Lava_Unit;


}
void StageData::Stage6()
{
	StageLevelString_[Stage::Stage6] = "Stage 6";
	StageNameString_[Stage::Stage6] = "OFF LIMITS";
	Scale_[Stage::Stage6] = { 24, 14 };

	StageData_[Stage::Stage6][0][0] = ObjectName::Rock_Text;
	StageData_[Stage::Stage6][0][1] = ObjectName::Is_Text;
	StageData_[Stage::Stage6][0][2] = ObjectName::Push_Text;
	StageData_[Stage::Stage6][0][4] = ObjectName::Rock_Unit;
	StageData_[Stage::Stage6][0][5] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage6][0][6] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage6][0][7] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage6][0][8] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage6][0][9] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage6][0][12] = ObjectName::Skull_Unit;
	StageData_[Stage::Stage6][0][21] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage6][0][22] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage6][0][23] = ObjectName::Grass_Unit;

	StageData_[Stage::Stage6][1][4] = ObjectName::Rock_Unit;
	StageData_[Stage::Stage6][1][6] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage6][1][7] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage6][1][8] = ObjectName::Flower_Unit;
	StageData_[Stage::Stage6][1][10] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage6][1][11] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage6][1][12] = ObjectName::Skull_Unit;
	StageData_[Stage::Stage6][1][13] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage6][1][14] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage6][1][15] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage6][1][16] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage6][1][17] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage6][1][18] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage6][1][19] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage6][1][22] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage6][1][23] = ObjectName::Grass_Unit;

	StageData_[Stage::Stage6][2][0] = ObjectName::Skull_Text;
	StageData_[Stage::Stage6][2][1] = ObjectName::Is_Text;
	StageData_[Stage::Stage6][2][2] = ObjectName::Defeat_Text;
	StageData_[Stage::Stage6][2][4] = ObjectName::Rock_Unit;
	StageData_[Stage::Stage6][2][9] = ObjectName::Brick_Unit;
	StageData_[Stage::Stage6][2][10] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage6][2][12] = ObjectName::Skull_Unit;
	StageData_[Stage::Stage6][2][15] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage6][2][16] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage6][2][17] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage6][2][18] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage6][2][19] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage6][2][23] = ObjectName::Grass_Unit;

	StageData_[Stage::Stage6][3][4] = ObjectName::Rock_Unit;
	StageData_[Stage::Stage6][3][8] = ObjectName::Brick_Unit;
	StageData_[Stage::Stage6][3][9] = ObjectName::Brick_Unit;
	StageData_[Stage::Stage6][3][10] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage6][3][12] = ObjectName::Skull_Unit;
	StageData_[Stage::Stage6][3][16] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage6][3][17] = ObjectName::Flag_Unit;
	StageData_[Stage::Stage6][3][18] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage6][3][19] = ObjectName::Wall_Unit;

	StageData_[Stage::Stage6][4][0] = ObjectName::Flag_Text;
	StageData_[Stage::Stage6][4][1] = ObjectName::Is_Text;
	StageData_[Stage::Stage6][4][2] = ObjectName::Win_Text;
	StageData_[Stage::Stage6][4][4] = ObjectName::Rock_Unit;
	StageData_[Stage::Stage6][4][6] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage6][4][7] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage6][4][8] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage6][4][9] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage6][4][10] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage6][4][12] = ObjectName::Skull_Unit;
	StageData_[Stage::Stage6][4][15] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage6][4][16] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage6][4][17] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage6][4][18] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage6][4][19] = ObjectName::Wall_Unit;

	StageData_[Stage::Stage6][5][4] = ObjectName::Rock_Unit;
	StageData_[Stage::Stage6][5][6] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage6][5][7] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage6][5][8] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage6][5][9] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage6][5][10] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage6][5][12] = ObjectName::Skull_Unit;
	StageData_[Stage::Stage6][5][15] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage6][5][16] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage6][5][17] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage6][5][18] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage6][5][19] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage6][5][22] = ObjectName::Flower_Unit;

	StageData_[Stage::Stage6][6][0] = ObjectName::Rock_Unit;
	StageData_[Stage::Stage6][6][1] = ObjectName::Rock_Unit;
	StageData_[Stage::Stage6][6][2] = ObjectName::Rock_Unit;
	StageData_[Stage::Stage6][6][3] = ObjectName::Rock_Unit;
	StageData_[Stage::Stage6][6][4] = ObjectName::Rock_Unit;
	StageData_[Stage::Stage6][6][6] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage6][6][7] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage6][6][8] = ObjectName::Baba_Unit;
	StageData_[Stage::Stage6][6][9] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage6][6][12] = ObjectName::Skull_Unit;
	StageData_[Stage::Stage6][6][13] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage6][6][14] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage6][6][15] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage6][6][16] = ObjectName::Brick_Unit;
	StageData_[Stage::Stage6][6][17] = ObjectName::Brick_Unit;

	StageData_[Stage::Stage6][7][3] = ObjectName::Flower_Unit;
	StageData_[Stage::Stage6][7][6] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage6][7][7] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage6][7][8] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage6][7][9] = ObjectName::Tile_Unit;
	StageData_[Stage::Stage6][7][10] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage6][7][12] = ObjectName::Skull_Unit;
	StageData_[Stage::Stage6][7][13] = ObjectName::Skull_Unit;
	StageData_[Stage::Stage6][7][14] = ObjectName::Skull_Unit;
	StageData_[Stage::Stage6][7][15] = ObjectName::Skull_Unit;
	StageData_[Stage::Stage6][7][16] = ObjectName::Skull_Unit;
	StageData_[Stage::Stage6][7][17] = ObjectName::Skull_Unit;
	StageData_[Stage::Stage6][7][18] = ObjectName::Skull_Unit;
	StageData_[Stage::Stage6][7][19] = ObjectName::Skull_Unit;
	StageData_[Stage::Stage6][7][20] = ObjectName::Skull_Unit;
	StageData_[Stage::Stage6][7][21] = ObjectName::Skull_Unit;
	StageData_[Stage::Stage6][7][22] = ObjectName::Skull_Unit;
	StageData_[Stage::Stage6][7][23] = ObjectName::Skull_Unit;

	StageData_[Stage::Stage6][8][6] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage6][8][7] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage6][8][8] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage6][8][9] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage6][8][10] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage6][8][15] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage6][8][16] = ObjectName::Brick_Unit;
	StageData_[Stage::Stage6][8][17] = ObjectName::Brick_Unit;

	StageData_[Stage::Stage6][9][2] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage6][9][10] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage6][9][12] = ObjectName::Wall_Text;
	StageData_[Stage::Stage6][9][13] = ObjectName::Is_Text;
	StageData_[Stage::Stage6][9][14] = ObjectName::Stop_Text;
	StageData_[Stage::Stage6][9][15] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage6][9][16] = ObjectName::Brick_Unit;
	StageData_[Stage::Stage6][9][21] = ObjectName::Flower_Unit;

	StageData_[Stage::Stage6][10][1] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage6][10][2] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage6][10][3] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage6][10][8] = ObjectName::Baba_Text;
	StageData_[Stage::Stage6][10][10] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage6][10][15] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage6][10][19] = ObjectName::Flower_Unit;

	StageData_[Stage::Stage6][11][2] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage6][11][3] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage6][11][8] = ObjectName::Is_Text;
	StageData_[Stage::Stage6][11][10] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage6][11][11] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage6][11][12] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage6][11][13] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage6][11][14] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage6][11][15] = ObjectName::Wall_Unit;

	StageData_[Stage::Stage6][12][8] = ObjectName::You_Text;
	StageData_[Stage::Stage6][12][17] = ObjectName::Flower_Unit;
	StageData_[Stage::Stage6][12][21] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage6][12][22] = ObjectName::Grass_Unit;

	StageData_[Stage::Stage6][13][18] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage6][13][19] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage6][13][20] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage6][13][21] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage6][13][22] = ObjectName::Grass_Unit;
}
void StageData::Stage7()
{
	StageLevelString_[Stage::Stage7] = "Stage 7";
	StageNameString_[Stage::Stage7] = "Grass Yard";
	Scale_[Stage::Stage7] = { 24, 14 };

	StageData_[Stage::Stage7][2][5] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage7][2][6] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage7][2][7] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage7][2][8] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage7][2][9] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage7][2][10] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage7][2][11] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage7][2][12] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage7][2][13] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage7][2][14] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage7][2][15] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage7][2][16] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage7][2][17] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage7][2][18] = ObjectName::Wall_Unit;

	StageData_[Stage::Stage7][3][5] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage7][3][10] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage7][3][18] = ObjectName::Wall_Unit;

	StageData_[Stage::Stage7][4][5] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage7][4][7] = ObjectName::Baba_Text;
	StageData_[Stage::Stage7][4][8] = ObjectName::Is_Text;
	StageData_[Stage::Stage7][4][9] = ObjectName::You_Text;
	StageData_[Stage::Stage7][4][16] = ObjectName::Flag_Unit;
	StageData_[Stage::Stage7][4][18] = ObjectName::Wall_Unit;

	StageData_[Stage::Stage7][5][5] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage7][5][6] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage7][5][13] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage7][5][18] = ObjectName::Wall_Unit;

	StageData_[Stage::Stage7][6][5] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage7][6][14] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage7][6][16] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage7][6][18] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage7][6][23] = ObjectName::Grass_Text;

	StageData_[Stage::Stage7][7][5] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage7][7][9] = ObjectName::Baba_Unit;
	StageData_[Stage::Stage7][7][12] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage7][7][15] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage7][7][17] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage7][7][18] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage7][7][23] = ObjectName::Is_Text;

	StageData_[Stage::Stage7][8][5] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage7][8][6] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage7][8][12] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage7][8][14] = ObjectName::Flag_Text;
	StageData_[Stage::Stage7][8][16] = ObjectName::Win_Text;
	StageData_[Stage::Stage7][8][18] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage7][8][23] = ObjectName::Stop_Text;

	StageData_[Stage::Stage7][9][5] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage7][9][7] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage7][9][12] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage7][9][15] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage7][9][18] = ObjectName::Wall_Unit;

	StageData_[Stage::Stage7][10][5] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage7][10][10] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage7][10][13] = ObjectName::Grass_Unit;
	StageData_[Stage::Stage7][10][18] = ObjectName::Wall_Unit;

	StageData_[Stage::Stage7][11][5] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage7][11][6] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage7][11][7] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage7][11][8] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage7][11][9] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage7][11][10] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage7][11][11] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage7][11][12] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage7][11][13] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage7][11][14] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage7][11][15] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage7][11][16] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage7][11][17] = ObjectName::Wall_Unit;
	StageData_[Stage::Stage7][11][18] = ObjectName::Wall_Unit;
}